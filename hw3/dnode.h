//Kelly Wang
//Luis Valdivia
//Nov 7th 2018

#include <cassert>
#include <cstdlib>
using namespace std;

// Homework Assignment #3: Toolkit for Doubly-linked list
class dnode
{
public:
    typedef double value_type;
    // constructor
    dnode(const value_type& d=value_type(), dnode* l=NULL, dnode* p=NULL)
    {
        data_field = d;
        link_field = l;
        prev_field = p;
    }
    
    // modifiers
    void set_data(const value_type& d){ data_field = d;}
    void set_link(dnode* l) {link_field = l;}
    void set_prev(dnode* p) {prev_field = p;}
    // observers
    value_type data() const {return data_field;}

    // forward links
    dnode* link() {return link_field;};
    const dnode* link() const {return link_field;};

    // backward links
    dnode* prev() {return prev_field;};
    const dnode* prev() const {return prev_field;};
    
private:
    value_type data_field;
    // forward pointer
    dnode* link_field;
    // backward pointer
    dnode* prev_field;
};

// Helper Methods
size_t list_length (dnode* head)
{
    dnode* temp_ptr=head;
    int count = 0;
    
    while (temp_ptr != NULL) {
        count++;
        temp_ptr = temp_ptr->link();
    }
    return count;
}

void list_head_insert(dnode*& head, const dnode::value_type& v){
    
    dnode* p;
    p = new dnode(v, head);
    head = p;
}


dnode* list_search(dnode* head, const dnode::value_type& v){
    
    dnode* cursor = head;
    
    if (cursor == NULL){
        return NULL;
    } else {
        while ((cursor!= NULL) && (cursor->data() != v)) {
            cursor = cursor->link();
        }
        return cursor;
    }
}

void list_insert(dnode* head, dnode* prev, const dnode::value_type& v){  
    dnode* q;
    q = new dnode(v, head, prev);
    // if we are inserting this as the new head
    if(prev == NULL){
        head -> set_prev(q);
        head = q;
    }
    //if we are inserting dnode somewhere after head
    else{
        q -> set_link(prev -> link());
        prev -> set_link(q);
        q -> link() -> set_prev(q);
    }
    //clean up memory 
    delete q;
    q = NULL;
}


void erase_one(dnode* head, dnode* target) {
    if (target == NULL)
        return;

    if (target -> link() != NULL) {
        if (target -> prev() != NULL)
            target -> prev() -> set_link(target -> link());
        else
             head = target -> link();
        target -> link() -> set_prev(target -> prev());
    }

    else{
        //if target is the tail 
        if (target -> prev() != NULL)
            target -> prev() -> set_link(NULL);
    }

   //clean up the memory or if the linked list only has one node and we want
   // to delete that node 
   target -> set_link(NULL);
   target -> set_prev(NULL);   
   delete target;
   target = NULL;
}



void reverse(dnode*& head){
    //create a dnode to traverse the linked list
    dnode* current_dnode = head;
    //create a dnode to keep track of other dnodes
    dnode* temp = NULL;

    while(current_dnode){
        temp = current_dnode -> link();
        current_dnode -> set_link(current_dnode -> prev());         
        current_dnode -> set_prev(temp);
            //change the head pointer of the doubly linked list
        if(temp == NULL)
            head = current_dnode;
        current_dnode = temp;
        }
}





