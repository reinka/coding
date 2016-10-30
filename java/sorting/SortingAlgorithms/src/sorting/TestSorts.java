package sorting;

import java.util.Arrays;

public class TestSorts {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Sort apply = new Sort();
		
		int[] sorted = apply.countingSort(new int[] {4,1,3,4,3}, 5);
			
		System.out.println(Arrays.toString(sorted));
	}

}
