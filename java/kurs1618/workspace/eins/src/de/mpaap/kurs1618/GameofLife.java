package de.mpaap.kurs1618;

public class GameofLife {
    
    boolean [][] feld = {{false, false, false, false, false},
            {false, false, true, false, false}, 
            {false, false, true, false, false}, 
            {false, false, true, false, false},
            {false, false, false, false, false}
    };
    int ROW = feld.length;
    int COL = feld[0].length;

    public static void main(String[] args) {

        
        GameofLife myGame = new GameofLife();
        for (int i = 0; i < 10; i++) {
            myGame.nextGeneration();
            myGame.print();
            System.out.println();
        }
    }
    
    void print() {
        for (int i = 0; i < feld.length; i++) {
            for (int j = 0; j < feld[i].length; j++) {
                if (feld[i][j])
                    System.out.print("o ");
                else
                    System.out.print(". ");
            }
            System.out.println();

        }
    }
    
    
    /*
     *adjust width in case neighbour goes beyond the left/right margin
     */
    int adjustWidth(int celPos, int neighbourPos){
        neighbourPos *= celPos;
        if (neighbourPos < 0) {
            neighbourPos += COL;
        }
        else if (neighbourPos > COL - 1) {
            neighbourPos -= COL;
        }
        
        return neighbourPos;
    }
    
    
    /*
     *adjust height in case neighbour goes beyond the top/bottom margin
     */
    int adjustHeight(int celPos, int neighbourPos) {
        neighbourPos += celPos;
        if (neighbourPos < 0) {
            neighbourPos += ROW;
        }
        else if (neighbourPos > ROW - 1) {
            neighbourPos -= ROW;
        }
        
        return neighbourPos;
    }
    
    /*
     *gets the number of neighbours given a specific cell
     */
    int numberOfNeighbours(boolean board[][], int rowCoord, int colCoord){
        int count = 0;
        
        /*circle around cell*/
        
        for (int row = -1; row <= 1; row++) {
            for (int col = -1; col <= 1; col++) {
                
                /*exclude case where row = col = 0 (-> position of the cell being circled)*/
                
                if (row!=0 || col!=0) {
                    
                    /*count only living neighbours*/
                    
                    if (board[adjustHeight(rowCoord, row)][adjustWidth(colCoord, col)]) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
    
    /*
     * finally print the board of the next generation
     */
    void nextGeneration() {
        boolean temp [][] = feld;
        for (int rowCoord = 0;rowCoord < temp.length;rowCoord++) {
            for(int colCoord = 0; colCoord < temp[rowCoord].length; colCoord++) {
                int neighbours = numberOfNeighbours(temp,rowCoord,colCoord);
                
                switch (neighbours) {
                    case 2:     //this state depends on the current one, though it's irrelevant with the current method
                            if (temp[rowCoord][colCoord]) {
                            feld[rowCoord][colCoord] = true;
                            }
                            break;
                    case 3:     //this state is independent of the current one, will always lead to 1
                            feld[rowCoord][colCoord] = true;
                            break;
                    default:    //every other state ends with death
                            feld[rowCoord][colCoord] = false;
                            break;
                    }
                }
            }
        }
         
    }
