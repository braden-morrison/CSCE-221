#include <iostream>
#include "StemAndLeaf.h"

int StemAndLeaf::getLeafUnit() const { 
	return leafUnit;
}


void StemAndLeaf::setLeafUnit(int leafUnit) {
	this->leafUnit = leafUnit;
}

int StemAndLeaf::getStemUnit() const { 
	return stemUnit;
}

void StemAndLeaf::setStemUnit(int stemUnit) {
	this->stemUnit = stemUnit;
} 

StemAndLeaf::StemAndLeaf() {
	leafUnit = 0;
	stemUnit = 0;
	head = nullptr;
	tail = nullptr;
	
}

StemAndLeaf::~StemAndLeaf() {
	head = nullptr;
	tail = nullptr;
}

void StemAndLeaf::addTerm(int term) {
	int stemVal = term / getStemUnit();
	int leafVal = term%(getStemUnit()*getLeafUnit());
	
	
	Stem *ptr = head;
	Stem *ptr2 = head;
		if (ptr == nullptr) { //empty
			Stem *x = new Stem;
			x->value = stemVal;
			x->insert(leafVal);
			x->next = nullptr;
			x->frequency++;
			head = x;
			tail = x;
		}
		else if(ptr->value == stemVal) {//equal to head
			head->frequency++;
			head->insert(leafVal);
		}
		else if(ptr->value > stemVal) {//before head
			Stem *x = new Stem;
			x->value = stemVal;
			x->insert(leafVal);
			head = x;
			x->next = ptr;
			tail = ptr;
			x->frequency++;
		}
		else if(ptr->next == nullptr) {//head but nothing else
			Stem *x = new Stem;
			x->value = stemVal;
			x->insert(leafVal);
			x->next = nullptr;
			x->frequency++;
			head->next = x;
			tail = x;
		}
		else {
		ptr = ptr->next;
			while (ptr != nullptr) {
				if (ptr->value == stemVal) { //found stem node
					ptr->frequency++;
					ptr->insert(leafVal);
					break;
				}
				else if (ptr->value > stemVal) { //before stem node
					Stem *x = new Stem;
					x->value = stemVal;
					x->insert(leafVal);
					x->frequency++;
					x->next = ptr;
					ptr2->next = x;
					break;
				}
				else if (ptr->next == nullptr) { //end of list and doesn't exist
					Stem *x = new Stem;
					x->value = stemVal;
					x->insert(leafVal);
					x->next = nullptr;
					x->frequency++;
					ptr->next = x;
					tail = x;
					break;
				}
				ptr = ptr->next;
				ptr2 = ptr2->next;
			}		
	}
}


bool StemAndLeaf::removeTerm(int term) {
    int stemVal = term / getStemUnit();
	int leafVal = term%(getStemUnit()*getLeafUnit());
	//traverse to see if it exists
	Stem *ptr = head;
	Stem *ptr2 = head;
	if (head->value == stemVal) {
		head->remove(leafVal);
		head->frequency--;
		if (head->frequency == 0) {
			head = ptr->next;
		}
		return true;
	} 
	else {
		ptr = ptr->next;
		
	while (ptr != nullptr) {
		
	if (ptr->value == stemVal) {
		ptr->remove(leafVal);
		ptr->frequency--;
		
		if (ptr->frequency == 0) {
			if (ptr == tail) {
				tail = ptr2;
			}
			ptr2->next = ptr->next;
			ptr->next = nullptr;
		}
			
		return true;
	}
	ptr = ptr->next;
	ptr2 = ptr2->next;
	}
	}
		
	return true;
}

// Don't modify
std::ostream &operator << (std::ostream &out, const StemAndLeaf &x) {
	// needs to go through the StemAndLeaf, one stem, then all leaves, then back to the next stem and it's leaves, and continue
    Stem * CURSTEM_ptr = x.head;
    while ( CURSTEM_ptr != nullptr )
    {
      out << *CURSTEM_ptr; 
      CURSTEM_ptr = CURSTEM_ptr -> next;
    }
    
	return out;
}

