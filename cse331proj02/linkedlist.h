//
// Description :  Single linked list
//
#include <iostream>
#include <list>
#include "node.h"

using namespace std;

class LinkedList
{
private:
	Node *head;     // a pointer pints to a head node
	Node *tail;     // a pointer pints to a tail node

public:
	// Constructor: initial value
	LinkedList() {
		// Initial head and tail pointers
		head=NULL;
		tail=NULL;
	}

	// Destructor: deletes everything in the list.
	~LinkedList() {
		Node* node;
		while (head!=NULL) {
			node=head->next;
			delete head;
			head=node;
		}
	}

	bool isEmpty();
	void PushFront(int t);
	void PushBack(int t);
	void PrintNode(Node* n);
	void PrintList();
	void PrintList(Node* startNode);

	Node* FindKthElementFromTail(unsigned int k);
	bool Delete(Node* node);
	void ReverseList();
};

// check if a linked list is empty
bool LinkedList::isEmpty() {
	if (head==NULL) return true;
	else return false;
}
// add a new element at the beginning of a list
void LinkedList::PushFront(int t)
{
	Node* newNode = new Node(t);
	if (isEmpty()) {
		head = newNode;
		tail = newNode;
	} else {
		newNode->next = head;
		head = newNode;
	}
}
// add a new element at the end of a list
void LinkedList::PushBack(int t) 
{
	Node* newNode = new Node(t);
	if (isEmpty()) {
		head = newNode;
		tail = newNode;
	}  else {
		tail->next = newNode;
		tail = newNode;
	}
}
// print the data in a node
void LinkedList::PrintNode(Node* n) 
{
	if (n!=NULL)
		cout << n->payload << endl;
	else
		cout << "NULL" << endl;
}
// print the data in a linked list
void LinkedList::PrintList()  
{
	Node *it = head;
	while (it!=NULL)  
	{
		cout << it->payload << ' ';
		it=it->next;
	}
	cout << endl;
}
// print the data in a linked list from a specific node
void LinkedList::PrintList(Node* startNode)  
{
	Node *it = startNode;
	while (it!=NULL)  
	{
		cout << it->payload << ' ';
		it=it->next;
	}
	cout << endl;
}
// function to reverse a list
void LinkedList::ReverseList(){
    if(head == NULL){
        //if it's empty, just return
        return;
    }

    Node *behind = NULL, *current = NULL, *next = NULL;
    current = head;
    while(current != NULL){
        //we iterate until we hit the end of the list
        next = current->next;
        //next now points to the next element after current
        current->next = behind;
        behind = current;
        current = next;
        //this swaps the head to the end of the list one by one
        //the rest of the list still stays in the reversed order
    }
    //the last element becomes the first to complete the reversal
    head = behind;
}

// function to find the k-th element from the back of a list
Node* LinkedList::FindKthElementFromTail(unsigned int k){
    Node *current;
    Node *behind;
    current = head;
    
    for(int i = 0; i < (k - 1); i += 1){
        if(current->next){
            current = current->next;
            //current goes down the list k elements 
        } 
        else {
            return NULL;
        }
    }

    behind = head;
    while(current->next){
        current = current->next;
        behind = behind->next;
        //behind goes down the list until current hits the tail
        //since current started at k elements deep, behind is at k elements from the tail
    }

    return behind;
}

// function to delete the specific node from a list
bool LinkedList::Delete (Node* node){
     if (head == node){
         head = head->next;
         //if the head is the node to delete, we just move the head pointer
         //to the next node. this also works with just 1 element (head = tail)
         return 1;
     }
     
     Node *current = head;
     while (current->next != 0 && current->next != node){
        current = current->next;
        //we iterate through the list until we find the node before the node to delete
     }
     if (current->next != 0){
        current->next = current->next->next;
        //we then change the current node to now link to 2 nodes past it
        //and it the next node is deleted
        return 1;
     }
     
     return 0;
     
}
