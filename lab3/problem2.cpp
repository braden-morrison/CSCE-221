#include<iostream>
using namespace std;


struct node {
    int data;
    struct node* next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};
 
struct LL {
    node* head;
    LL() { 
	head = NULL; 
	}
 
    void Reverse(){
// Initialize reverse pointers
	node* curr = head;
	node* prev = NULL;
	node* next = NULL;
 
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
 
//print function
    void print(){
        struct node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
		cout << endl;
    }

//add node function
    void newNode(int data)
    {
        node* temp = new node(data);
        temp->next = head;
        head = temp;
    }
};
 
int main(){
	
    LL ll;
    ll.newNode(4);
    ll.newNode(3);
    ll.newNode(2);
    ll.newNode(1);
	
	cout << "Original list: ";
    ll.print();
	
    ll.Reverse();
	
	cout << "Reversed list: ";
    ll.print();
	
	
    return 0;
}

	