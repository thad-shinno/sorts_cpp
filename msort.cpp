#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

void msort(int[], int);
int* merge(int[], int[], int, int);

int main(int argc, char *argv[]) {
  // build array
  int size = argc - 1;
  int arr[size];
  for (int i = 0; i < size; i++) {
    arr[i] = atoi(argv[i+1]);
    cout << arr[i] << " ";
  }
  cout << endl;
  
  // sort the array
  msort(arr, size);
}

// recursive merge sort
void msort(int list[], int size) {
  // a list of size 1 is already sorted
  if (size <= 1) {
    return;
  }
  
  // get halves
  int sizeL = size / 2;
  int sizeR = size - sizeL;
  int left[sizeL];
  int right[sizeR];
  // get left half
  for (int i = 0; i < sizeL; i++) {
    left[i] = list[i];
  }
  // get right half
  for (int i = sizeL, j = 0; i < size; i++, j++) {
    right[j] = list[i];
  }
  
  // recursively sort the other halves
  msort(left, sizeL);
  msort(right, sizeR);

  // modify list
  int *tmp = merge(left, right, sizeL, sizeR);
  for (int i = 0; i < size; i++) {
    list[i] = tmp[i];
  }
}

// merge two halves together
int* merge(int *left, int *right, int sizeL, int sizeR) {
  // allocate array
  int *merged;
  merged = (int*)malloc((sizeL + sizeR)*sizeof(int));
 
  // print both halves
  cout << "\nleft:\t";
  for (int i = 0; i < sizeL; i ++) {
    cout << left[i] << " ";
  }
  cout << "\nright:\t";
  for (int i = 0; i < sizeR; i ++) {
    cout << right[i] << " ";
  }
  cout << endl; 

  // merge halves
  int l = 0, r = 0;
  for (int i = 0; i < sizeL + sizeR; i++) {
    // if left half has run out, merge from right
    if (l >= sizeL) {
      merged[i] = right[r];
      r++;
    }
    // if right half has run out, merge from left
    else if (r >= sizeR){
      merged[i] = left[l]; 
			l++;
		}
    // if the left side is smaller, merge from left
		else if (left[l] <= right[r]) {
			merged[i] = left[l];
			l++;
		}
    // else the right side is smaller so merge from right
		else {
			merged[i] = right[r];
			r++;
		}

  }
  // print merged halves
  for (int i = 0; i < sizeL + sizeR; i++) {
    cout << merged[i] << " ";
  }
  cout << endl;
  return merged;
}
