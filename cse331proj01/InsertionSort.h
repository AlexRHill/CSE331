#ifndef _INSERTIONSORT_H_
#define _INSERTIONSORT_H_
#include <vector>

using namespace std;
using std::vector;

void insertionSort(vector<int> &v){
    int length = v.size();
    int i = 1;
    int j = 0;
    int temp = 0;
    
    //this insertion sort only sorts ints, shouldn't be a problem based on our main
    
    while(i < length){
        //we iterate from 0 through the length of the vector
        j = i;
        while(j > 0 && v[j-1] > v[j]){
            //elements are swapped until they are put into the correct space
            temp = v[j];
            v[j] = v[j-1];
            v[j-1] = temp;
            j -= 1;
            //j decreases by 1 to check the next element to the left and compare with it
        }
        i += 1;
        //i increases by one to put the next element into the correct spot
    }
    return;
}


#endif