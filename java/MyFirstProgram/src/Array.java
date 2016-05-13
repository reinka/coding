//Demonstrate 1-d array

class Array {
	public static void main(String args[]){
		int month_days[];
		month_days = new int[12];
		month_days[1] = 31;
		month_days[2] = 30;
		month_days[3] = 25;
		month_days[5] = 5;
		month_days[10] = 3;
		
		for(int i = 0; i < 12; i++)
			System.out.println(month_days[i]);
	}
}