//
// All file writen by Zejia Zheng for CSE331
//
// Name :        main.cpp
// Description : Demonstration program that shows how to generate a random vector to be sorted
//

#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
#include "InsertionSort.h"	 // Edit your insertion sort code in that file
#include "QuickSort.h"		 // Edit your quick sort code in that file
#include "VerifySort.h"		 // Edit your code for verifying sort result in that file

using namespace std;

int main() {

    vector<int> x;
    time_t	t1, t2, ti = 0;
    srand (time(0)); 
    const int vsize = 50000;  // vector size
    const int times = 10;   // perform t times so we can see the difference
    bool result = 1;

//  quick sort
    for (int t = 0; t < times; t++)
    {
    x.clear();
    for (int i=0; i<vsize; i++)
        x.push_back(rand());

    t1 = time(0);
    quickSort(x);
    t2 = time(0);

    result *= verifySort(x);
    ti += t2-t1;
    }
    cout << "quick sort time : " << ti << "\n";
    cout << ((result==1)? "Success \n":"Fail\n");


//  insertion sort
    ti = 0; result = 1;
    for (int t = 0; t < times; t++)
    {
    x.clear();
    for (int i=0; i<vsize; i++)
        x.push_back(rand());
    t1 = time(0);
    insertionSort(x); // 
    t2 = time(0);

    result *= verifySort(x);
    ti += t2-t1;
    }
    cout << "insertion sort time : " << ti << "\n";
    cout << ((result==1)? "Success \n":"Fail\n");

    return 0;
}