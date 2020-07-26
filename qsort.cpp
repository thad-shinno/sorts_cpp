#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

void qsort(int[], int, int, int);

int main(int argc, char *argv[]) {
  // build array
  int len = argc - 1;
  int arr[argc - 1];
  for (int i = 1; i < argc; i++) {
    arr[i - 1] = atoi(argv[i]);
    cout << arr[i-1] << " ";
  }
  cout << endl;
  
  qsort(arr, 0, len - 1, len);
  
  // print array
  for(int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void qsort(int list[], int low, int high, int len) {
  if (high - low <= 0) {
    return;
  }

  // store important indexes
  int pivot = high;
  int compare = low;
  int store = low;

  int tmp;
  while (compare < pivot) {
    if (list[compare] < list[pivot]) {
      // swap store and compare
      tmp = list[store];
      list[store] = list[compare];
      list[compare] = tmp;
      store++;
      for(int i = 0; i < len; i++) {
        cout << list[i] << " ";
      }
      cout << endl;
    }
    compare++;
  }
  
  // swap store and pivot
  tmp = list[store];
  list[store] = list[pivot];
  list[pivot] = tmp;
  qsort(list, low, store - 1, len);
  qsort(list, store + 1, high, len);
}
