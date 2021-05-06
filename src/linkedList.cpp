#include "linkedList.h"

void linkedList::push(int value){
	//first, begin by finding out if the head is empty
	if (!this->head){ //if the head is empty...
		//create a new node to facilitate the head
		this->head = new node;
		this->head->data = value;
		this->head->next = NULL;
	}
	else{ //if the head is not empty...
		//create a temporary node to iterate to the end of the list
		node* temp = this->head; //the temp node is a reference to the head
		while (temp->next != NULL){ //iterate through the list until the end of the list is found
			temp = temp->next;		//the temporary reference to the head becomes the next reference to the end
		}
		//once the end of the list is found, place the data into the next position
		temp->next = new node;
		temp->next->data = value;
		temp->next->next = NULL;
	}
}

void linkedList::print(){
	//determine if the head is empty
	if (!this->head){	//if the head is empty, output that info
		std::cout << "The list is empty" << std::endl;
	}
	else{ //if the head isn't empty...
		//simply iterate to the end of the list, starting with the head
		node* temp = this->head; //use the temp node like before to iterate
		std::cout << "Data currently in the list: " << std::endl;
		while (temp != NULL){
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	}
}

unsigned int linkedList::length(){
	//get if the head is empty
	if (!this->head){
		//just return 0 if the head is empty
		return 0;
	}
	else{
		//create a temp node based on the head
		node* temp = this->head;
		unsigned int counter = 0; //this will be returned at the end
		while (temp != NULL){ //go through each node and count up the counter
			temp = temp->next;
			++counter;
		}
		return counter;
	}
}

int linkedList::get(unsigned int _at){
	if (_at >= this->length()){	//first, determine if the index we want is greater than the list length
		std::cout << "Index out of range" << std::endl;
		return -1; //-1 is a failure state
	}
	else{
		if (!this->head){		//if the head is empty, just return the failure state and a message
			std::cout << "The head is empty" << std::endl;
			return -1;
		}
		else{
			node* temp = this->head;	//use the temp once more as an iterator
			for (unsigned int i=0; i<_at; i++){	//use i as a limiter to stop the iteration where we need it
				temp = temp->next;
			}
			return temp->data;	//return the data at the specified index
		}
	}
}

void linkedList::set(unsigned int _at, int newdata){
	if (_at >= this->length()){	//first, determine if the index we want is greater than the list length
		std::cout << "Index out of range" << std::endl;
		return; //returns prematurely
	}
	else{
		if (!this->head){		//if the head is empty, just print a message
			std::cout << "The head is empty" << std::endl;
			return; //also returns prematurely
		}
		else{
			node* temp = this->head;	//use the temp once more as an iterator
			for (unsigned int i=0; i<_at; i++){	//use i as a limiter to stop the iteration where we need it
				temp = temp->next;
			}
			temp->data = newdata; //set the data within the node equal to the newdata parameter
			return;
		}
	}
}


void linkedList::pop(unsigned int _at){
	if (_at >= this->length()){	//first, determine if the index we want is greater than the string length
		std::cout << "The index is out of range" << std::endl;
		return;	//just quit out if our length is less than where we need the data
	}
	else{
		if (!this->head){		//if the head is empty, just print a message
			std::cout << "The head is empty" << std::endl;
			return;	//an empty head yields no data
		}
		else{
			if (_at == 0){	//if we're going to be popping the head...
				node* temp = this->head; //use the temp once more as an iterator
				temp = this->head->next; //make temp into the head's next node
				delete this->head;		//remove the head
				this->head = temp;		//set the head to temp, which was the head's next node
			}
			else{
				node* temp = this->head;	//use the temp once more as an iterator
				node* prev = temp;			//use previous to keep track of the previous node
				for (unsigned int i=0; i<_at; i++){	//use i as a limiter to stop the iteration where we need it
					prev = temp;
					temp = temp->next;
				}
				prev->next = temp->next;	//take the last node and set it to the node after the next node
				delete temp;				//then delete the current node
			}
		}
	}
}

void linkedList::clear(){
	//find if the head is empty
	if (!this->head){ //inform the frontend dev that the list is empty
		std::cout << "The list is empty" << std::endl;
	}
	else{
		//like before, use a temp node to iterate the list
		node* temp = this->head;
		while (this->head != NULL){ //pull back the list through the head and delete what's at the head
			temp = this->head->next; //the temp node will become the next node over from the head
			delete this->head;		//delete the head node, which is now separate from the list
			this->head = temp;		//the head becomes temp, which is currently the next node from the now deleted head
		}
		this->print();
	}
}

void linkedList::swap(unsigned int src, unsigned int dest){
	if (src >= this->length()){	//if the first element is out of range, output an error
		std::cout << "Index out of range" << std::endl;
		return;
	}
	if (dest >= this->length()){//if the second element is out of range, output an error
		std::cout << "Index out of range" << std::endl;
		return;
	}
	if (src >= dest){//if the first element is further out than the second element
		std::cout << "src index invalid" << std::endl;
		return;
	}
	//perform a basic swap between the src and dest values
	int swapval = this->get(src);
	this->set(src, this->get(dest));
	this->set(dest, swapval);
}

void linkedList::reverse(){
	//iterate through half the list, then swap from first and second until both ends meet at the center
	for (unsigned int i=0; i<(this->length())/2; i++){
		this->swap(i, this->length()-1-i); //perform a swap with just the data only
	}
}

linkedList::linkedList() {
	this->head = NULL;	//head is empty at start

}

linkedList::~linkedList() {
	this->clear(); //clear the list whenever the list is done being used
}

