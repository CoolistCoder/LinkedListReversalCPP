#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <cstddef>
#include <iostream>

//the node for which the linked list will be made from
struct node{
	node* next; //the node next to this node
	int data;	//the data located within the node
};

class linkedList{
private:
	node* head; //the very first node

public:
	void push(int);			//push data into the list
	void print(); 			//output the entire list to the terminal
	unsigned int length(); //retrieve the length of the linked list
	int get(unsigned int); //retrieve data from a node on the list
	void set(unsigned int, int); //set the data at the specified node on the list
	void pop(unsigned int);	//remove a node from the list
	void clear(); 			//clear the entire list
	void swap(unsigned int, unsigned int); //swap elements within the list
	void reverse(); 		//reverses the list
	linkedList();
	virtual ~linkedList();

};
#endif
