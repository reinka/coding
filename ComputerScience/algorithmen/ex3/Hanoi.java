/*

The objective of the puzzle is to move the entire stack (tower) to 
another rod, obeying the following simple rules:

1. Only one disk can be moved at a time.

2. Each move consists of taking the upper disk from one of 
the stacks and placing it on top of another stack i.e. a 
disk can only be moved if it is the uppermost disk on a stack.

3. No disk may be placed on top of a smaller disk.
*/

/* 

	PSEUDO CODE:

To move n discs from peg A to peg C:

1. move n−1 discs from A to B. This leaves disc n alone on peg A
2. move disc n from A to C
3. move n−1 discs from B to C so they sit on disc n

The above is a recursive algorithm, to carry out steps 1 and 3, 
apply the same algorithm again for n−1. The entire procedure is a 
finite number of steps, since at some point the algorithm 
will be required for n = 1.
*/

/*

	COMPLEXITY: 2^n - 1

Proof:

T(n) = 2*T(n-1) + 1

T(n) = 2 * ( 2 * T(n-2) + 1) + 1

T(n) = (2 ^ 2) * T(n-2) + 2^1 + 2^0

T(n) = (2^k) * T(n-k) + 2^(k-1) + 2^(k-2) + ... + 2^0

Solving this the closed from comes out to be

T(n) = (2^n) - 1 with T(0) = 0
*/


import java.util.Scanner;

public class Hanoi {
	int n;
	char a;
	char b;
	char c;

	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		System.out.print("Please enter amount of disks: ");
		while(!keyboard.hasNextInt()){ 
			System.out.println("Wrong input. Integer only. Try again.");
			keyboard.next();
		}
		int number = keyboard.nextInt();  // Save it in a local variable
    	keyboard.nextLine();  // Handle the end of line characters
    	keyboard.close();

    	Hanoi game = new Hanoi();
    	game.play(number, 'A', 'B', 'C');
	}

	Hanoi(){
	}

	private void play(int n, char a, char b, char c){
		if(n==0)
			return;
		else{
			this.play(n-1, a, c, b);
			System.out.printf("Move disk from pole %s to pole %s\n", a, c);
			this.play(n-1, b, a, c);
		}
	}
}

