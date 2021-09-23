//Kelly Wang
//Luis Valdivia
//Nov. 7th 2018

#include "node.h"
#include <iostream>
using namespace std;

// Helper Methods for Linked List Toolkit

void reverse(node*& head){
	//create a node to traverse the linked list
		node* current_node = head;
		//create two nodes to keep track of other nodes
		node* temp = NULL;
		node* prev = NULL;
		while(current_node){
			temp = current_node -> link();
			current_node -> set_link(prev);			
			prev = current_node;
			current_node = temp;
		}
		//change the head pointer of the linked list
		head = prev;   
	}



int main(){
	node::value_type d = 1.0;
	node* n = new node(d);
	cout << "list with one node: " << endl;
	cout << n -> data() << endl;
	reverse(n);
	cout << "list with one node reversed: " << endl;
	cout << n -> data() << endl;

	node* p = new node(0);
	for(node::value_type d = 0.1; d < 5.0; d+=0.9){
		list_head_insert(p,d);
	}

	//printing
	cout << "\nlist with multiple nodes: " << endl;
	node* curr = p;
	while(curr){
		cout << curr -> data() << endl;
		curr = curr -> link();
	}
	
	reverse(p);

	//printing
	cout << "\nlist with multiple nodes reversed: " << endl;
	node* curry = p;
	while(curry){
		cout << curry -> data() << endl;
		curry = curry -> link();
	}


	node* g = new node();
	for(node::value_type d = 4.9; d > 0; d-=0.7){
		list_insert(g,d);
	}

	//printing
	cout << "\nlist with multiple nodes: " << endl;
	node* cur = g;
	while(cur){
		cout << cur -> data() << endl;
		cur = cur -> link();
	}
	
	reverse(g);

	//printing
	cout << "\nlist with multiple nodes reversed: " << endl;
	node* cury = g;
	while(cury){
		cout << cury -> data() << endl;
		cury = cury -> link();
	}


	return 0;
}



