class LinkedList {
private:
	struct node {
		int value=0;
		node * next =0;
	}; node s;
	 
	int listlength=0;
	struct node * head = new struct node;

public:

	void addToListAtPosition(int position, int value) {
		/*
		struct node insert;
		insert.value = value;
		insert.next = &s;
		listlength++;
		*/
		//s = *s.next;
		//
		
		
		
		//ok code
		int i = position;
		struct node * pos = new struct node;
		struct node * cur = new struct node;
		//i--; //because need to push the current position node one more
		if (i == 0) { 
			pos->next = head->next;
			pos->value = value;
			head->next = pos;
			s.next = pos;
		/*head->next = &s; 
		s.next = 0;
		s.value = value;*/
		listlength++;
		return;
		}
		//pos->next = head->next;
		//cur->next = head->next;
		pos = head;
		cur = head;
		while (i > 0) {
			//s = *s.next ; //index through the list until the desired position is found
			pos = pos->next;
			i--;
		}
		i = position;
		while (i > 1) {
			cur = cur->next;
			i--;
		}
		//pos->next = &s; //original s.next
		
		struct node * insert = new struct node;
		insert->value = value;
		insert->next = pos;
		cur->next = insert;
		//s.next = insert;
		listlength++;
		

	}
	void addToHead(int value) {
		struct node * insert = new struct node;
		//struct node * temp = new struct node;
		insert ->next = head -> next;
		insert->value = value;
		head->next = insert;
		listlength++;
		/*temp->next = &s;
		//head->next = insert;
		insert->value = value;
		
		s = *insert;
		s.next = temp;
		/*insert->value = value;
		insert->next = &s;
		head->next = &s;
		listlength++;*/
		
	}
	void appendToList(int value) {
		//go through the node array til reach a 0, or go thru pointers until reach a null pointer
		while (s.next != 0) {
			s.next -> next; //figure out how toindex thru the linked list
		}
		//create a pointer pointing to a new spot and fill that spot with a value
		struct node insert;
		s.next = &insert;
		insert.value = value;
		insert.next = 0;
	}
	void removeFromListAtPosition(int position) {
		//struct node hold;
		int i = position; 
		while (i > 0) {
			s= *s.next; //figure out how to index thru the linked list
			i--;
		}
	}
	void removeFromHead() {

	}
	void removeFromEnd() {
		int i = 0;
		while (s.next != 0) {
			s = *s.next; //figure out how to index thru the linked list
			i++;
		}
		//delete s;
		i--;
		while (i > 0) {

			i--;
		}
	}
	int find(int value) {
		//index thru the linked list checking each nodes value against the input value
		//if the value is found, return 1, if the while loop reaches the null pointer and no valiue, return 0 after the loop breaks
		s = *head;
		while (s.next != 0) {
			if (s.value == value) { return 1; }
			s = *s.next;
		}
		return 0;
	}
	void reverseList() {

	}
	int getListLength() {
		return listlength;
	}
	struct node * getHead() {
		return head->next;
	}
	LinkedList() {
		struct head {
			int value = -999;
			struct head * next = 0;
		};
	}
	
};

