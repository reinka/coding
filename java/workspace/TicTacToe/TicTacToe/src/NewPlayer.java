import de.ovgu.dke.teaching.ml.tictactoe.api.IBoard;
import de.ovgu.dke.teaching.ml.tictactoe.api.IPlayer;
import de.ovgu.dke.teaching.ml.tictactoe.api.IllegalMoveException;
import de.ovgu.dke.teaching.ml.tictactoe.game.Move;
import java.util.*;

/**
 * Some comments ...
 * 
 * @author Andrei Poehlmann
 */
public class NewPlayer implements IPlayer {
	private double EPSILON = 0.2, ALPHA = 0.1;
	private Map<String, HashMap<Integer, Double>> qvalues = new HashMap<String, HashMap<Integer, Double>>();
	private int reward = 0;
	private Random rand = new Random();
	
	private String stateKey;
	private int action;
			
			
	public String getName() {
		return "Q-learner";
	}

	public int[] makeMove(IBoard board) {
		
		
		// create a clone of the board that can be modified
		IBoard copy = board.clone();
		
		// map current board to a 1D matrix
		int[] curState = this.getActions(copy); 
		
		// create key for current board state
		stateKey = makeKey(curState);
		
		// get action based on current board state
		action = chooseAction(stateKey, curState);
		
		// convert int representation of action into 3D
		int[] move = this.convertAction(action);
		
		
		// do a move using the cloned board
		try {
			copy.makeMove(new Move(this, move));
		} catch (IllegalMoveException e) {
			// move was not allowed
		}

		// return your final decision for your next move
		return move;
	}
	
	
	/**
	 * Flattens the 3D board to a 1D matrix (125x1) which
	 * indicates free positions on the board. 
	 * IMPORTANT:
	 * Here I assumed a fixed board size of dim 5x5x5.
	 * 
	 * @param	copy of current board
	 * @return	1D Array (125x1) with 0s and 1s,
	 * 			where 1 indicates a free position.
	 */
	private int[] getActions(IBoard board){
		int[] actions = new int[5*5*5];
		
		IBoard copy = board.clone();
		int m,n= 1;
		for(int i = 0; i < 5; i++){
			
			for(int j = 0; j < 5; j++){
				switch (j){
				case 0: n = 0; break;
				case 1: n = 5; break;
				case 2: n = 10; break;
				case 3: n = 15; break;
				case 4: n = 20; break;
				default: n = 1999;
			}
				for(int k = 0; k < 5; k++){
					switch (k){
					case 0: m = 0; break;
					case 1: m = 25; break;
					case 2: m = 50; break;
					case 3: m = 75; break;
					case 4: m = 100; break;
					default: m = 1000;
				}
					if(copy.getFieldValue(new int[] {i,j,k}) == null){
						actions[m + n + i ] = 1;
					}
				}
			}
		}
		
		return actions;
	}
	
	
	/**
	 * Calculates the according 3D board position
	 * given a action between 0 and 124.
	 * This is basically a reversed action to 
	 * the above, where the 3D board is mapped
	 * to a 1D representation.
	 * 
	 * @param action	int between 0 and 124
	 * @return			3D representation of action as array
	 * 					with 3 values [i, j, k] 
	 */
	private int[] convertAction(int action){
		int i, j, k;
		
		/*
		 * Here we assume the board is of dim 5x5x5
		 * Each board position can be represented 
		 * as an array of the from [i, j, k].
		 * 
		 * From the value of the action we can infer
		 * its k-th value of the 3D representation
		 * as following:
		 */
		
		// k must be 0
		if(action < 25){
			k = 0;
		}
		// k must be 1 
		else if(action < 50){
			action -= 25; // for further calculations, see below
			k = 1;
		}
		// k must be 2
		else if(action < 75){
			action -= 50;
			k = 2;
		} 
		// k must be 3
		else if(action < 100){
			action -= 75;
			k = 3; 
		} else { // k must be 4
			action -= 100;
			k = 4;
		}
		
		/*
		 * Since our action is now in the range of
		 * 0-24 we get the j-th column value by
		 * dividing action with 5 and the i-th
		 * row value by computing the modulo of 5
		 */
		// compute j-th value == column
		j = action / 5;
		
		// compute i-th value == row
		i = action % 5;
		
		return new int[] {i, j, k};
	}
	
	
	
	/**
	 * Updates Q-table for given state of board based on the 
	 * reward of the according action taken. 
	 * @param stateKey	key that represents the current state of the board
	 * @param action	action taken
	 * @param reward	reward, that resulted from the taken action
	 */
	private void updateQValue(String stateKey, int action, double reward){
		
		// grab qvalue from previous action
		double q = getQ(stateKey, action); 
		
		q += ALPHA * (reward - q); // update Rule
		
		// update Q-table
		setQ(stateKey, action, q); 
		
	}
	
	/**
	 * Epsilon-greedy exploration algorithm. 
	 * Agent chooses the (perceived)  
	 * optimal action for a proportion of 1−epsilon 
	 * of its moves, and a random action otherwise.  
	 * @param stateKey 	current state Key
	 * @param curState	current state of the board represented as a 125x1 matrix
	 * @return			epsilon-greedy decision (either random move or action with max Q-value 
	 */
	private int chooseAction(String stateKey, int[] curState){
		// learning
		// (1-EPSILON) % of the time choose greedy policy
		if(rand.nextDouble() > EPSILON) {
			return getMaxQAction(stateKey);
		}
		// EPSILON % of the time choose random action
		else {
			return randomMove(curState);
		}
	}

	/**
	 * Creates keys for the hash map, that represents the Q-table. 
	 * For each possible board state there is a key 
	 * @param state		state of the board represented as a 125x1 matrix
	 * @return			Q-table key for given board state
	 */
	private String makeKey(int[] state){
		String key = Arrays.toString(state);
		// if key not in the table then add key
		Map<Integer, Double> thisKeyEntry = qvalues.get(key);
		if(thisKeyEntry == null) {
			// create hash map of all valid actions in this state and random initial qvalues
			HashMap<Integer, Double> vals = new HashMap<Integer, Double>();
			for(int i = 0; i < state.length; i++) {
				if(state[i] == 1)
					vals.put(i, (rand.nextDouble()*0.3)-0.15); // random [-0.15, 0.15] 
			}
			// add the hashmap to qvalues hashmap
			qvalues.put(key, vals);
		}
		return key;
	}
	
	/**
	 * Function to generate random move
	 * @param state	Board represented as 125x1 matrix
	 * @return	random action based on the still available moves 
	 */
	private int randomMove(int[] state)
	{
		ArrayList<Integer> moveList = new ArrayList<Integer>();
		for(int i = 0; i < state.length; i++)
			// check whether board position is free
			if(state[i] == 1) 
				moveList.add(i); 
		// return random pick from available board positions
		return moveList.get(rand.nextInt(moveList.size()));
	}
	
	/**
	 * Get action with max Q-value
	 * @param stateKey		String representing current board state
	 * @return bestAction	integer representing best action
	 */
	private int getMaxQAction(String stateKey)
	{
		double maxValue = -1.0;
		int bestAction = -1;
		Map<Integer, Double> vals = qvalues.get(stateKey);
		for(Map.Entry<Integer, Double> entry : vals.entrySet()) {
			if(entry.getValue() > maxValue) {
				maxValue = entry.getValue();
				bestAction = entry.getKey();
			}  
		}
		return bestAction;
	}

	/**
	 * Set Q-value of Q-table for given key, action, value
	 * @param key		String, key representing state of board
	 * @param action	integer, representing board position
	 * @param value		double, representing reward/q-value
	 */
	private void setQ(String key, int action, double value)
	{
		// overwrite previous q value
		qvalues.get(key).put(action, value);
	}
	
	/**
	 * get Q-value of given key and action
	 * @param key		String, representing board state
	 * @param action	int, representing board position
	 * @return double	Q-value
	 */
	private double getQ(String key, int action)
	{
		return qvalues.get(key).get(action);
	}


	public void onMatchEnds(IBoard board) {
		IPlayer winner = board.getWinner();
		/*set reward: 	 0 if draw
						 1 if win
						-1 if lose
		*/
		if(winner == null){
			reward = 0;
		} else if(winner == this){
			reward =  1;
		} else{
			reward = -1;
		}
		
		//finally update Q-Table
		updateQValue(stateKey, action, reward);
	}
}
