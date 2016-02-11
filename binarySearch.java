/**
*
  Binary Search
  Language: Java

  ***** USES ARRAY LIST TYPE *****

  ***** ARRAY LIST MUST BE SORTED *****

  ***** MUST IMPORT: java.util.ArrayList *****

  PARAMETERS: value, array
  		value = item being searched for.
  		array = array list to be searched.

  Returns true (or the index) if the value is found in the array list, else return false (or -1) if not found.
  		minIndex = 0 	(first index in array list)
  		maxIndex = array.size() - 1		(size of the array minus 1 for zero start)
  		middleIndex is set to the average of min/max.  (for each iteration)

  Loop thru and determine if the desired element is greater than or less than the current middleIndex.

  If value is greater than the middleIndex (2nd half of array) create a new minIndex that is equal to the
  middle index just used + 1 (+1 because we just tested that specific index). This cuts the list in half by
  moving the next minIndex starting point up to the halfway point of the array. (only searches 2nd half next iteration)

  If value is less than middleIndex (1st half of array), set a new maxIndex equal to the middleIndex - 1. By adjusting
  the maxIndex we cut the array in half. The next iteration will search from the same minIndex until it reaches the new
  maxIndex, which means it will only search the 1st half of the array.

  Else if the middle is not greater or less than (and the minIndex <= maxIndex loop has not terminated), the value was found. Return.

  Return false (or -1) if the loop terminates without finding the value.

  ***** Current state searches for integers. Change the value data type accordingly. *****
*/



// ---------------- Boolean return search: (found/not found) ------------------->
public static boolean binarySearch(int value, ArrayList array)
	{
		int minIndex = 0;
		int maxIndex = array.size() - 1;
		int middleIndex = 0;

		while (minIndex <= maxIndex)
		{

			// Average minIndex and maxIndex for middleIndex each iteration.
			middleIndex = (minIndex + maxIndex) / 2;

			// If value is in 2nd half of array list.
			if (value > (int) array.get(middleIndex))
			{
				minIndex = middleIndex + 1;
			}

			// If value is in 1st half of array list.
			else if (value < (int) array.get(middleIndex))
			{
				maxIndex = middleIndex - 1;
			}

			// Value was found.
			else
			{
				return true;
			}
		}

		// Value not found during search loop.
		return false;
	}



// ---------------- Integer return search: (get value's index position in array) ------------------->
public static int binarySearchIndex(int value, ArrayList array)
	{

		int minIndex = 0;
		int maxIndex = array.size() - 1;
		int middleIndex = 0;

		while (minIndex <= maxIndex)
		{
			// Average minIndex and maxIndex for middleIndex each iteration.
			middleIndex = (minIndex + maxIndex) / 2;

			// If value is in 2nd half of array list.
			if (value > (int) array.get(middleIndex))
			{
				minIndex = middleIndex + 1;
			}

			// If value is in 1st half of array list.
			else if (value < (int) array.get(middleIndex))
			{
				maxIndex = middleIndex - 1;
			}

			// Value was found.
			else
			{
				return middleIndex;
			}
		}

		// Value not found during search loop.
		return -1;
	}