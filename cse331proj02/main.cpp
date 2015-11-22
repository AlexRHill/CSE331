#include <iostream>
#include <stdlib.h>

#include "linkedlist.h" //single linked list
#include "random.h"     //random number generator

using namespace std;

int main(int argc, char* argv[]) {
	if(argc != 3) {
		cerr << "Incorrect nubmer of command line arguments." << endl;
		cerr << "Usage: " << argv[0] << " <N> <K>" << endl;
		exit(EXIT_FAILURE);
	}

	int N = atoi(argv[1]);        // number of elements in a list
	int K = atoi(argv[2]);        // k, for finding k-th element from the back of a list

	//random number generator - borrowed from Avida - written by CA OFRIA and modified by J STEDWICK - based on RNG from Numerical Recipes in C: The Art of Scientific Computing (Flannery et al.)
	RandomNumberGenerator rng;

	// using N as a random seed
	rng.ResetSeed(N); 

	// a linked list
	LinkedList ll;

	// initial data in a list
	for(unsigned i = N; i >= 1; i--) {
		ll.PushBack(rng.GetUInt(1,99));
	}

	// display elements in the initial linked list
	ll.PrintList();

	// find the kth_node and print it
 	Node* kth_node = ll.FindKthElementFromTail(K);
	ll.PrintNode(kth_node);
 
	// delete the kth_node and print the linked list
 	ll.Delete(kth_node);
	ll.PrintList();
 
	// reverse a list and print the linked list
	ll.ReverseList();
	ll.PrintList();
}
