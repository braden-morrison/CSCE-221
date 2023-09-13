#include <iostream>
#include "Leaf.h"
#include "Stem.h"

Stem::Stem() {
front = nullptr;
back = nullptr;
value = 0;
frequency = 0;
next = nullptr;
}

Stem::~Stem() {

}

bool Stem::insert(int value) {
	Leaf *x = new Leaf;
	x->value = value;
	x->count++;
	//stem is empty
	if (front == nullptr) {
		x->next = nullptr;
		front = x;
		back = x;
		return true;
	}	
	if (front->value == value) {
		front->count++;
		return true;
	}
	//stem isn't empty
	if (front->value > value) {	//node goes before front
			x->next = front;
			front = x;
			return true;
	} 
	
	if (front->value < value) {	//node goes after front
			//find location
			if(front->next == nullptr) { //only one node (front) existed
				front->next = x;
				x->next = nullptr;
				back = x;
			} 
			else {
				Leaf *ptr = front->next;
				Leaf *ptr2 = front;
				//traverse list;
				
				while (ptr != nullptr) {
					if (ptr->value == value){ //leaf exists
						ptr->count++;
						return true;
					}
					if(ptr->value > value) { //goes before node
						ptr2->next = x;
						x->next = ptr;
						return true;
					}
					if(ptr->next == nullptr) { //back of list
						ptr->next = x;
						back = x;
						x->next = nullptr;
						return true;
					}
				ptr = ptr->next;
				ptr2 = ptr2->next;
				} 
			}
	}
	return true;
}

// return true is a leaf is deleted 
bool Stem::remove(int target) {
	//std::cout << "front value: " << front->value << std::endl;
	Leaf *ptr = front;
	Leaf *ptr2 = front;
	if (front->value == target && front->count == 1) { //is front and count is 1
	front = ptr->next;
	ptr->next = nullptr;
	ptr = nullptr;
	ptr2 = nullptr;
	return true;
	} else if (front->value == target && front->count >= 2) { //is front and count is 2
		front->count--;
		ptr = nullptr;
		ptr2 = nullptr;
		return true;
	}
	
	else {
	
		ptr = ptr->next;
		while (ptr != nullptr) {
			if (ptr->value == target && ptr->count == 1) { //count is 1
				ptr2->next = ptr->next;
				ptr->next = nullptr;
				ptr = nullptr;
				ptr2 = nullptr;
				return true;
			} else if (ptr->value == target && ptr->count >= 2) { //count is more than two
				ptr->count -= 1;
				ptr = nullptr;
				ptr2 = nullptr;
				return true;
			} else {
				ptr = ptr->next;
				ptr2 = ptr2->next;
			}
		}
	}
			return true;
}

// Don't modify
std::ostream &operator << (std::ostream &out, const Stem &x) {
  out << x.value <<" | ";
  Leaf *CURLEAF_ptr = x.front;  

  while ( CURLEAF_ptr != nullptr )
  {
    out << *CURLEAF_ptr <<" ";
    CURLEAF_ptr = CURLEAF_ptr -> next;
  }
  out << std::endl;

  return out;
}

