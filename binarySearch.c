/**
 * 
 Binary Search 
 Language: C
 
 ***** ARRAY MUST BE SORTED *****
 
 PARAMETERS: value, array[], n
	value =  item being searched for.
	array[] = array that is being searched.
	n = size of the array.
 
 Returns true (or the index) if value is found in the array, else return false (not found). 
	minIndex = 0 (first index in array) 
	maxIndex = n (max size of array).
	middleIndex is set to the average of min/max. (for each iteration)
 
 Loop thru and determine if the desired element is greater than or less than the current middleIndex. 
 
 If value is greater than the middleIndex (2nd half of array), create a new minIndex that is equal to
 the middle index just used + 1 (+1 because we just tested that specific index). This cuts the list in half by
 moving the next minIndex starting point up to the halfway point of the array. (only searches 2nd half next iteration)
 
 If value is less than middleIndex (1st half of array), set a new maxIndex equal to the the (middle - 1). By adjusting the max index
 we can cut the array in half. The next iteration will search from the same minIndex until it reaches the new maxIndex which cuts the
 list down to the first half.
 
 Else if the middle is not greater or less than (and the minIndex <= maxIndex loop has not terminated), the value was found. Return true.
 
 Return false if the loop terminates because the value was not found.
 */
 
 
 // ***** BOOLEAN RETURN TYPE *****  (return boolean if found (true)- or not found (false))
bool binarySearch(int value, int array[], int n)
{
    int middleIndex;
    int minIndex = 0;
    int maxIndex = n;
    
    while (minIndex <= maxIndex)
    {
        // Average the min/max to find middleIndex. min/max change each iteration.
		middleIndex = (minIndex + maxIndex) / 2;
		
		// If value is in 2nd half of array --> Adjust minIndex to middleIndex + 1.
        if (value > array[middleIndex])
        {
            minIndex = middleIndex + 1;  //minIndex for next iteration is now the middleIndex. Cut search in half.
        }
        // If value is in 1st half of array --> Adjust maxIndex to middleIndex - 1.
        else if (value < array[middleIndex])
        {
            maxIndex = middleIndex - 1;     //maxIndex for next iteration is now the middleIndex. Cut search in half.
        }
        // Else the value == middleIndex. It was found, return true.
        else
        {
            return true;
        }
    }
    
    // Value never found in the loop, return false.
    return false;
}



// ***** INTEGER RETURN TYPE *****  (return the integer index of the array where value was found)
int binarySearch(int value, int array[], int n)
{
	int middleIndex;
    int minIndex = 0;
    int maxIndex = n;
	
	while (minIndex <= maxIndex)
    {
        // Average the min/max to find middleIndex. min/max change each iteration.
        middleIndex = (minIndex + maxIndex) / 2;
        
		// If value is in 2nd half of array --> Adjust minIndex to middleIndex + 1.
		if (value > array[middleIndex])
        {
            minIndex = middleIndex + 1;  //minIndex for next iteration is now the middleIndex. Cut search in half.
        }
        // If value is in 1st half of array --> Adjust maxIndex to middleIndex - 1.
        else if (value < array[middleIndex])
        {
            maxIndex = middleIndex - 1;     //maxIndex for next iteration is now the middleIndex. Cut search in half.
        }
        // Else the value == middleIndex. It was found, return index.
        else
        {
            return middleIndex;
        }
    }
	
	// Value not found in the loop. Return -1.
	return -1;
	
}