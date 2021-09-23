//Kelly Wang
//Luis Valdivia
//Nov. 7th 2018

#include "bag.h"
#include "node.h"
#include <stdlib.h>
#include <iostream>
using namespace std; 

//default constructor
bag::bag(){
	//set default
	head = NULL; 
	num_nodes = 0; 
}

//copy constructor
bag::bag(const bag& src){
	list_copy(src.head, head);
	num_nodes = src.num_nodes;
}

//deconstructor
bag::~bag(){
	list_clear(head);
	num_nodes = 0; 
}

//inserts another node with a given value as a new head
void bag::insert(const value_type& entry){
	list_head_insert(head, entry);
	num_nodes++;
	return;
}



//erases the first occurrence of a node with the given value
bool bag::erase_one(const value_type& target){
//target cannot be found
	if(list_search(head, target) == NULL){
	 	return false; 
	}
	//target is the head
	else if(list_search(head, target) == head){
	 	list_head_remove(head);
	 	num_nodes--;
	}

	node* cursor = head;
	while(cursor->link() != list_search(cursor,target)){
		cursor = cursor->link();
	}
	list_remove(cursor);

	num_nodes--;
	return true;
}

//erases all occurrences of nodes with the given value
size_t bag::erase(const value_type& target){
	for(int i = 0; i < count(target); i++)
		erase_one(target); //call erase_one to delete all nodes with target

	num_nodes -= count(target);
	return count(target); //return total occurence of target
}

//count total occurrences of target
size_t bag::count(const value_type& target)const{
	size_t sum;
	node* node_count; 
	sum = 0; 

	node_count = list_search(head, target);
	while(node_count){
		sum++;
		node_count = node_count->link();
		node_count = list_search(node_count, target);
	}
	return sum;
}

int main(){
	return 0;
}
