#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_
#include <vector>
#include "InsertionSort.h"
using namespace std;

void QS1(vector<int> &v, int left, int right)  
{  
    int i=left, j=right;  
    //i and j are used for simplicity
    int pivot = v[(i+j)/2];  
    //the pivot is chosen to be the middle element of the list
  
    while (i <= j) {  
        while (v[i] < pivot){  
            i += 1;  
        }
        while (v[j] > pivot){
            j -= 1;  
        }
        if (i <= j) {  
            int temp = v[i];  
            v[i] = v[j];  
            v[j] = temp;  
  
            i += 1;  
            j -= 1;  
        }  
    }
    //the vector is partitioned into two parts, the elements that are greater
    //than the pivot and the elements that are less than the pivot
  
    if (left < j){  
        QS1(v, left, j);
    }
    //the above and below if statements sort the two parts of the pivot
    //using the same quick sort algorithm
    if (i < right){  
        QS1(v, i, right);  
    }
}

void quickSort(vector<int> &v){
    int left = 0;
    int right = v.size() - 1;
    QS1(v, left, right);
    //based on the main program, there could only be one input, the vector
    //I made the quickSort function with just the vector input and used the size
    //of the vector to make variables to call the main QS1 function that
    //actually does the quicksort
    
}
#endif

