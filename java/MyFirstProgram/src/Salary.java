// this class is used for calculation of pre tax and after tax values
public class Salary {
	// variable taxClass defines a tax classification depending on salary ranges
	private static int taxClass;

	// main method
	public static void main(final String[] args) {

		// list of salaries pre tax
		int[] salariesPreTax = new int[] { 450, 800, 1235, 2200, 2458, 3125, 3300, 4100, 4278, 5001, 5222, 5783, 6100, 14750, 18875, 20470 };

		// TODO: Define a list called "salariesAfterTax" to store the salaries after the tax
		double salariesAfterTax[] = new double[salariesPreTax.length];
		
		
		// TODO: For each entry in the salariesPreTax array, calculate the salaries after tax based on the values of the pre tax and the corresponding tax class
		for (int i = 0; i < salariesPreTax.length; i++) {
			int value = salariesPreTax[i];
			salariesAfterTax[i] = calculateSalary(value, getTaxClass(value));
		}

		// ******OUTPUT on console:******
		// NOTE: NO output should happen before!!

		// TODO: for every entry in the two arrays, output salary pre tax and according value after tax
		for (int i=0; i < salariesPreTax.length;i++) {
			System.out.println(" Salary pre tax: " + salariesPreTax[i] + " and after tax: " + salariesAfterTax[i]);
		}
	} // end main

	// this method calculates the salary after the tax regarding the tax class
	private static double calculateSalary(final int value, final int taxClass) {

		// initialize the valueAfterTax with negative value
		double valueAfterTax = -1.0d;

		// TODO: Use a switch statement for the taxClass to define the different calculation of the salary after tax
		switch(taxClass){
		// Use following scheme to perform the calculation:
		case 1: return value; 
		case 2: return value + valueAfterTax * value*.055;
		case 3: return value + valueAfterTax * value*.12; 
		case 4: return value + valueAfterTax * value*.18;
		case 5: return value + valueAfterTax * value*.2025;
		case 6: return value + valueAfterTax * value*.2575; 
		case 7: return value + valueAfterTax * value*.355; 
		default: valueAfterTax *= value*.015 + value;
		}
		// if none of the cases applies, return the initial value of the valueAfterTax variable
		return valueAfterTax;
	}

	// this method defines the tax class depending on the salary
	private static int getTaxClass(final int salaryPreTax) {

		// if the salary pre tax is lower than 800, the tax class is 1
		if (salaryPreTax < 800) {
			return 1;
		}

		// if the salary pre tax is between than 800 and 1200, the tax class is 2
		if (salaryPreTax >= 800 && salaryPreTax < 1200) {
			return 2;
		}

		// if the salary pre tax is between 1200 and 2100, the tax class is 3
		if (salaryPreTax >= 1200 && salaryPreTax < 2100) {
			return 3;
		}

		// if the salary pre tax is between 2100 and 3000, the tax class is 4
		if (salaryPreTax >= 2100 && salaryPreTax < 3000) {
			return 4;
		}

		// if the salary pre tax is between 3000 and 3800, the tax class is 5
		if (salaryPreTax >= 3000 && salaryPreTax < 3800) {
			return 5;
		}

		// if the salary pre tax is between 3800 and 5000, the tax class is 6
		if (salaryPreTax >= 3800 && salaryPreTax < 5000) {
			return 6;
		}

		// if the salary pre tax is higher than 5000 the tax class is 7
		if (salaryPreTax >= 5000) {
			return 7;
		}

		// if none of the values of the salary variable is covered by the if-cases, just return the taxClass value
		return taxClass;
	}
} // end class