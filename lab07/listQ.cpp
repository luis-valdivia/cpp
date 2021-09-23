// listQ.cpp - implements queue as linked list
// Luis Valdivia, 16 Nov. 2018

#include "listQ.h"

Queue::Queue() { 
	size = 0;
	front = 0;
	rear = 0;
}  

Queue::~Queue() {
	node* temp;
	while(front){
		front -> data = 0;
		temp = front -> next;
		front -> next = 0;
		front = temp;
	}
}

void Queue::enqueue(int n) {
	node* newNode = new node(n);
	if(isEmpty())
		front = newNode;
	else
		rear -> next = newNode;
	rear = newNode;
	size++;
}

int Queue::dequeue() {
    if (isEmpty())
        throw EmptyQueue();
	int temp = front -> data;
	node* tempNode = front -> next;
	front -> data = 0;
	front -> next = 0;
	front = tempNode;
	size--;
    return temp; 
}

void Queue::clear() {
	this -> ~Queue();
	size = 0;
	front = 0;
	rear = 0;
}

bool Queue::isEmpty() const {
    return (size == 0); 
}

int Queue::getSize() const {
    return size; 
}