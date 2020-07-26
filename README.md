# sorts_cpp

**Merge Sort** is a recursive divide and conquer sorting algorithm.\
The terminating case is when the size of the array is one, since an array of size one is already sorted.\
When there is an array of more than one, split the array into two halves: *left* and *right*.\
Recursively call the merge sort on the left half as a list, then the right half as a list.\
Merge the two halves in a sorted manner into a temporary array.
  - *Both halves will be already sorted because of the recursive sort is stacked.*
  - If the left half is depleted, then move the right half in order into the temporary array.
  - If the right half is depleted, then move the left half in order into the temporary array.
  - If both halves contain elements at the front, pick the smaller front element to move into the array.
  - *This will merge the two halves into a single sorted array.*
  - Move the merged section back into the original array.
  
**Quick sort** is a recursive divide and qonquer sorting algorithm.\
There is no need for any temporary arrays, since all swaps happen in place.\
The terminating case is when the size of the array segment is one, since an segment size one is already sorted.\
When there is an array of more than one, there are three critical elements: *pivot*, *compare*, and *store*\
After sorting, all elements on the left half of the pivot will be less than the pivot.\
The pivot begins as the right end of the segment, while the compare and store begin on the left end of the segment.\
While the compare index is left of the pivot index,
  - If the compare element is less than the pivot element, swap the store element with the compare element and increment the swap index once to the right.
  - Then increment the compare index once to the right\

When the compare index reaches the pivot index, swap the store element with the pivot element.\
This swap makes it so all the elements on the left of the pivoted element are less than, while all the elements right of the pivoted element are greater than.\
Recursively call the quick sort on the segment to the left of the pivoted element (do not include the pivoted element).\
Recursively call the quick sort on the segment to the right of the pivoted element (do not include the pivoted element).
