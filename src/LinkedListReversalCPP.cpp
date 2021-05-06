#include <iostream>
#include "linkedList.h"
using namespace std;

//This program demonstrates a linked list with a reverse function

int main() {
	//begin by creating a linked list instance
	linkedList mainList;
	//fill the list full of data and print it
	cout << "Inserting data into the linked list" << endl;
	for (unsigned int i=0;i<21;i++){
		mainList.push(i);
	}
	mainList.print();

	//use the reverse function to reverse the list, then print out the data
	cout << "Now reversing linked list" << endl;
	mainList.reverse();
	mainList.print();
	cout << "End of program" << endl;
	return 0;
}
