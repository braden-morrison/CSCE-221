

//To remove the value at the node that the given pointer is assigned to, one could assign the values of the next node to the current node (data/next). 
//For example:
curr (pointer given to us, points to the node that should be deleted)
curr->data = curr->next->data;
curr->next = curr->next->next;
//This would copy the values over, and virtually remove the node that is desired to be removed from the list.
