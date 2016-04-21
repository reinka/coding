/* Key difference: 

	size of static array is fixed while the size
	of the dynamic array can be adjusted once more space is needed.

*/

/*
	Complexity:

	size, get and set are O(1);

	remove, contains and insert are O(n), since the array has to be 
	iterated through at some kind in each of these functions.

*/

public class DynamicArray{
	private int[] data;
	public DynamicArray(){
		data = new int[1];
	}

	// Returns size of Array
	public int size(){
		return data.length;
	}
	/* *
	 * Returns element at index
	 * Throws exception if out of range
	 */
	public int get(int index){
		try{
			if(index < 0 || index >= data.length)
				throw new IndexOutOfBoundsException("Index out of range.");
			else
				return data[index];
		} catch (IndexOutOfBoundsException e) {
			System.out.println(e.getMessage());
			return 0;
		}
	}
	/* *
	 * Replaces element at index with element
	 * and returns the element formerly at index.
	 * Throws exception if index out of bounds. 
	 */
	public int set(int index, int element){
		try{
			if(index < 0 || index >= data.length)
				throw new IndexOutOfBoundsException("Index out of range.");
			else{
				int temp = data[index];
				data[index] = element;
				return temp;
			}
		} catch (IndexOutOfBoundsException e) {
			System.out.println(e.getMessage());
			return 0;
		}
	}
	/* *
	 * Removes and returns the element at index,
	 * moving all subsequent elements one index earlier;
	 * Exception if index is not in range
	 */
	public int remove(int index){
		try{
			if(index < 0 || index >= data.length)
				throw new IndexOutOfBoundsException("Index out of range.");
			else{
				int temp = data[index];
				// Copy all subsequent elements one index earlier into the array 
				System.arraycopy(data, index, data, index + 1, data.length - index);
				return temp;
			}
		} catch (IndexOutOfBoundsException e) {
			System.out.println(e.getMessage());
			return 0;
		}
	}
	/**
	 * Checks if array contains value
	 */
	public boolean contains(int value){
		for (int i: data) {
			if(i == value)
				return true;
		}
		return false;
	}

	/* *
	 * Inserts element at index. If index out of
	 * range, array will be expanded, until index is 
	 * within the range.
	 */
	public void insert(int index, int element){
		// Double array size first
		if (index >= data.length){
			int newSize = 2*data.length;
			// If still out of range, set size to 2x index range
			if (index >= newSize){
				newSize = 2*index;
			}
			int[] newData = new int[newSize];
			System.arraycopy(data, 0, newData, 0, data.length);
			data = newData;
			System.out.println("Size of dynamic array increased to " + newSize);
		}
	}
}