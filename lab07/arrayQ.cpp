// arrayQ.cpp - implements queue as array
// Luis Valdivia, 2018 Nov. 16

#include "arrayQ.h"

Queue::Queue() {
	front = 0;
	rear = -1;
	size = 0;
}  

void Queue::enqueue(int n) {
    if (isFull())
        throw FullQueue();
	rear = (++rear) % CAPACITY;
	data[rear] = n;
	size++;
	return;
}

int Queue::dequeue() {
    if (isEmpty())
        throw EmptyQueue();
	int temp = data[front];
	data[front] = 0;
	front = (++front) % CAPACITY;
    size--;
    return temp; 
}

void Queue::clear() {
	front = 0;
	rear = -1;
	size = 0;
	return;	
}

bool Queue::isEmpty() const {
    return (size == 0); 
}

bool Queue::isFull() const {
    return (size == 10); 
}

int Queue::getSize() const {
    return size; 
}
