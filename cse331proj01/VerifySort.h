#ifndef _VERIFYSORT_H_
#define _VERIFYSORT_H_
#include <vector>
using namespace std;

bool verifySort(vector<int> &v){
    int length = v.size();
    int i = 1;
    int j = 0;
    
    while(i < length){
        if(v[i] < v[j]){
            return 0;
        }
        i += 1;
        j += 1;
    }
    
    //this is very simple
    //for the whole size of the vector, each element is checked 
    //if it is less than or equal to the element to the right, it's fine
    //otherwise, the vector is not verified as sorted
    
    return 1;
}

#endif