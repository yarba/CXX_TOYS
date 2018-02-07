#include <iostream>
#include <cstddef> // things like size_t, etc.

using namespace std;

class Node
{
    // NOTE; just make it all public, like a structure...


public:
     
    Node() : value(0), next(NULL) {}
    Node(int val) : value(val), next(NULL) {}
    Node( int val, Node* nxt ) : value(val), next(nxt) {}

    int   value;
    Node* next;
};

class LinkedList
{

public:
    LinkedList(int val);
    ~LinkedList();

    void append( int val ) ; // at the tail, I mean...

    void reverse();

    void walk_and_print();

private:
    Node* head;
    Node* tail;
    
};

LinkedList::LinkedList( int val )
{

    head = new Node(val);
    tail = head;

}

LinkedList::~LinkedList()
{
    // leave blank for now, will implement later...
}

void LinkedList::append( int val )
{

    // double check...
    //
    if ( head == NULL )
    {
	head = new Node(val);
	tail = head;
	// alternative way ???
	// tail = head = new Node(val) ;
    }
    else
    {
	tail->next = new Node(val);
	tail = tail->next;
    }

    return;
    
}

void LinkedList::reverse()
{

    if ( head == NULL ) return;

    Node* tmp = head;
    Node* rest = NULL;
    Node* next = NULL;

    // flip it over, now head will act as a tail
    //
    tail = head;

    rest = head->next;

    while ( rest != NULL )
    {
	// take out next node
	next = rest;
	// update the pointer of rest node after taking out the 1st
	rest = rest->next;
	// add the taken out node to the new list
	next->next = tmp;
	// update the tmp head
	tmp = next;
    }

    head = tmp;
    tail->next = NULL;

    return;

}

void LinkedList::walk_and_print()
{

    if ( head == NULL ) 
    {
	cout << "List is empty " << endl;
	return;
    }

    Node* p = head;

    cout << " Contents of the List: " << endl;
    while( p != NULL )
    {
	// cout << p->value << endl;
	cout << p->value << " " ;
	p = p->next;
    }
    cout << endl;

    return;
    
}

int main()
{

    LinkedList list(1);

    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    list.walk_and_print();

    list.reverse();

    cout << " After reversing... " << endl;
    list.walk_and_print();

    return 0;

}