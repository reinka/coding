package de.mpaap.test;

public class Hello {
	public static void main(String[] args) {
		System.out.println("Hello World");
		
		double cumsum = 0;
		for(int i = 0; i < args.length; i++) {
		    cumsum += Double.parseDouble(args[i]);
		    System.out.println(cumsum);
		}
	}
}
