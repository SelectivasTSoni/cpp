// singly_linked.cpp

#include <iostream>

using namespace std;

class LinkedList 
{
	private:
	    struct Node 
	    {
	        int value;
			Node *next;
	        Node(int v, Node *n = nullptr);
	    };
		Node *head;
		int length;
	
	public:
	    LinkedList();

	    // method declarations
	    virtual int size();
	    virtual bool isEmpty();
	    virtual int peek();
	    virtual void addHead(int value);
	    virtual int removeHead();
	    
	    // Other linked list methods.
	    virtual bool find(int data);
	    virtual void addTail(int value);
	    virtual void print();
	    virtual void reverse();


};


// method definitions
LinkedList::Node::Node(int v, Node *n) 
{
	value = v;
	next = n; 
}


LinkedList::LinkedList()
{
    head = nullptr;
	length = 0; 
}


int LinkedList::size()
{
    return length;
}


bool LinkedList::isEmpty() 
{
    return length == 0;
}


int LinkedList::peek() 
{
    if (isEmpty()) 
    {
        throw("EmptyListException");
    }

    return head -> value;
}


void LinkedList::addHead(int value) 
{
    head = new Node(value, head);
    length++; 
}


int LinkedList::removeHead() 
{
    if (isEmpty()) {
        throw("EmptyListException");
    }
    
    Node *deleteMe = head;
    int value = head->value;
    head = head->next;
    length--;
    
    delete deleteMe;
    
    return value;
}


bool LinkedList::find(int data)
{
    Node *temp = head;
    while (temp != nullptr) 
    {
        if (temp->value == data) 
        {
            return true;
		}
        
        temp = temp->next;
    }

    return false;
}


void LinkedList::addTail(int value) 
{
    Node *newNode = new Node(value);
    Node *curr = head;
    if (head == nullptr)
    {
        head = newNode;
    }
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }

    curr->next = newNode;
}


void LinkedList::print() 
{
    Node *temp = head;
    while (temp != nullptr) 
    {
        cout << temp->value << " ";
        temp = temp->next;
    }

    cout << endl;
}


void LinkedList::reverse() 
{
    Node *curr = head;
    Node *prev = nullptr;
    Node *next = nullptr;
    
    while (curr != nullptr) 
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
	}
	
	head = prev; 
}


int main()
{	
	// instantiate a LinkedList object
	LinkedList *ll = new LinkedList();

	// call addHead method to add items
    ll->addHead(5);
    ll->addHead(4);
    ll->addHead(3);
    ll->addHead(2);
    ll->addHead(1);

    // call print method
    ll->print();

    //call reverse method
    ll->reverse();

    // call print to see reversed linked list
    ll->print();
    
	return 0;
}

