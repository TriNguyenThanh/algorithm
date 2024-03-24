#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};
struct LinkedList
{
	Node *head;
	Node *tail;
};

Node* creNode(int data);
void creLinkedList(LinkedList &l);
void addHead(LinkedList &l, Node *ptr);
void addTail(LinkedList &l, Node *ptr);
void add_after_Q(LinkedList &l, Node *Q, Node *ptr);
void reHead(LinkedList &l);
void remove_after_Q(LinkedList &l, Node *Q);
void removeLinkedList(LinkedList &l);
void ouput(LinkedList l);
Node* get(LinkedList l, int index);
Node* find(LinkedList l, int value);
int length(LinkedList l);

int main(){

	return 0;
}

Node* creNode(int n){
	Node *ptr = new Node;
	ptr->data = n;
	ptr->next = NULL;

	return ptr;
}

void creLinkedList(LinkedList &l){
	l.head = NULL;
	l.tail = NULL;
}
//Add
void addHead(LinkedList &l, Node *ptr){
	if (l.head == NULL){
		l.head = ptr;
		l.tail = ptr;
	}else{
		ptr->next = l.head;
		l.head = ptr;
	}
}

void addTail(LinkedList &l, Node *ptr){
	if (l.tail == NULL){
		l.head = ptr;
		l.tail = ptr;
	}else{
		l.tail->next = ptr;
		l.tail = ptr;
	}
}

void add_after_Q(LinkedList &l, Node *Q, Node *ptr){
	if(Q == NULL){
		addHead(l,ptr);
	}else{
		if (l.tail == Q){
			Q->next = ptr;
			l.tail = ptr;
		}else{
			ptr->next = Q->next;
			Q->next = ptr;
		}
	}
}
//remove
void removeHead(LinkedList &l){
	if(l.head != NULL){
		Node *temp = l.head;
		l.head = temp->next;

		if (l.head == NULL){
			l.tail = NULL;
		}
		delete temp;
	}
}

void remove_after_Q(LinkedList &l, Node *Q){
	if (Q != NULL && l.tail != Q){
		Node *temp = Q->next;
		if (temp->next == NULL){
			l.tail = Q;
			Q->next = NULL;
		}else{
			Q->next = temp->next;
		}
		delete temp;
	}
}

void removeLinkedList(LinkedList &l){
	while(l.head != NULL){
		Node *tmp = l.head;
		l.head = tmp->next;
		delete tmp;
	}
	l.tail = NULL;
}

//print linked list
void ouput(LinkedList l){
	if (l.head != NULL){
		Node *temp = l.head;
		cout << "["
		while(temp != NULL){
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << "]";
	}
}
//get node
Node* getNode(LinkedList l, int index){
	Node *tmp = l.head;
	int i = 0;
	while(tmp != NULL && i <= index){
		if(i == index) return tmp;
		else{
			tmp = tmp->next;
			i++;
		}
	}	
	return NULL

}
//find
Node* find(LinkedList l, int value){
	Node *tmp = l.head;
	while(tmp != NULL){
		if(tmp->data == value){
			return tmp;
		}else{
			tmp = tmp->next;
		}
	}
	return NULL;
}
//count
int length(LinkedList l){
	int d = 0;
	Node *tmp = l.head;
	while(tmp != NULL){
		d++;
		tmp = tmp->next;
	}
	return d;
}