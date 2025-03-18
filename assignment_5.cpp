// singly_linked.cpp

#include <iostream>

using namespace std;

class LinkedList 
{
	private:
	    struct Node 
	    {
            // simple declarations
            // "hey, we are gonna use these."

            // the value held by the node
	        int value;

            // a pointer of type Node named next 
			Node *next;
            
            // the node method signature
	        Node(int v, Node *n = nullptr);
	    };

        // a pointer of type Node named head 
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

        // Methods added for assignment_5
        virtual int nthNodeFromStart(int index);
        virtual bool compareList(LinkedList *ll);
        virtual bool compareList(Node *head1, Node *head2);
        virtual bool compareList2(LinkedList *ll);
        virtual bool compareList2(Node *head1, Node *head2);
        virtual void insert(int value, int postion);
        virtual void insert_2(int value, int position);
        virtual void sortedInsert(int value);

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
    if (isEmpty()) 
    {
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


int LinkedList::nthNodeFromStart(int index) 
{
    if (index > size() || index < 1) 
    {
        throw("Index not in range.");
    }
    
    int count = 0;
    Node *curr = head;
    while (curr != nullptr && count < index - 1) 
    {
        count++;
        curr = curr->next;
    }
    
    return curr->value;
}


// recursive compare
bool LinkedList::compareList(LinkedList *ll)
{
    return compareList(head, ll->head);
}


bool LinkedList::compareList(Node *head1, Node *head2) 
{
    if (head1 == nullptr && head2 == nullptr)
    {
        return true;
    } 
    else if ((head1 == nullptr) || (head2 == nullptr)
            || (head1->value != head2->value)) 
    {
        return false;
    } 

    else 
    {
        return compareList(head1->next, head2->next);
    } 
}


// inerative compare
bool LinkedList::compareList2(LinkedList *ll) 
{
    return compareList2(head, ll->head);
}


bool LinkedList::compareList2(Node *head1, Node *head2) 
{
    while (head1 != nullptr && head2 != nullptr) 
    {
        if (head1->value != head2->value)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    
    if (head1 == nullptr && head2 == nullptr) 
    {
        return true;
    }
    
    return false;
}


void LinkedList::insert(int value, int position)
{
    // create new node which holds value and default pointer
    Node *newNode = new Node(value);

    // curr is a Node type pointer to *head defined in the LinkedList class. It is a pointer to a pointer.
    Node *curr = head;

    if (head == nullptr)
    {
        head = newNode;
    }

    // advance *curr to position
    for (int i=0; i < position - 1; i++)
    {
        curr = curr->next;
    }

    // when it gets to position, assign newNode
    //doesn't work quite right
    curr->next = newNode;

    return;
}

void LinkedList::insert_2(int value, int position)
{
    // create new node which holds value and default pointer
    Node *newNode = new Node(value);

    // curr is a Node type pointer to *head defined in the LinkedList class. It is a pointer to a pointer.
    Node *curr = head;

    if (head == nullptr)
    {
        head = newNode;
    }

    // advance *curr to position
    for (int i=0; i < position - 1; i++)
    {
        curr = curr->next;
    }

    // when it gets to position, assign newNode
    //doesn't work quite right
    //curr->next = newNode;

    newNode->next = head;
    head = newNode;

    newNode->next = curr->next;
    curr->next = newNode;

    return;

}


void LinkedList::sortedInsert(int value) 
{
    Node *newNode = new Node(value);
    Node *curr = head;
    
    if (curr == nullptr || curr->value > value) 
    {
        // This is the insertion mechanism
        newNode->next = head;
        head = newNode;
        return;
    }
    
    while (curr->next != nullptr && curr->next->value < value) 
    {
        curr = curr->next;
    }
    
    // This is the advancment mechanism
    newNode->next = curr->next;
    curr->next = newNode;
}


/////////////////////////////
////////////////////////////


int main()
{	
    /*

        A pointer is an object that holds a memory address as the value it contains.

        A pointer should point to the address of an object: 
            int x{ 5 };
            int* ptr{ &x }; // ptr holds the address of x
        
        cout << *ptr << '\n'; // use dereference operator to print the value at the address that ptr is holding (which is x's address)

        <type>* <name> declares a pointer object of <type> called <name>

        *<name> with * as the dereference operator prints the value of the address the pointer is pointing to

        & is the 'addresss-of' operator.

        -> member access/selection from pointer operator, sometimes called the arrow operator.
    */
    cout << "******************" << endl;

    // experimental 
    cout << "Experimental Code: " << endl;
    cout << "==================" << endl;
    // create an integer object
    int x {5}; 
    cout << "integer: " << x << endl;
    cout << "address of x: " << &x << endl;


    // create a pointer the object using the 'address of operatory' to get the address of x, so we know which address to point to
    int* my_pointer {&x};
    cout << "value pointed to by my_pointer: " << my_pointer << endl;

    // dereference should return value
    int val {*my_pointer};
    cout << "Value of address my_pointer points to: " << x << endl;

    // Does my_pointer still point to a location? yes it does. So we use the 'dereference operator to get the value, but he pointer still remains pointing to it.'
    cout << "my_pointer after de-referencing: " << my_pointer << endl;




    // 1. insert an element at the kth position from the start of the linked list. Return true if successful. If the list is not long enough return -1. Hint: take a pointer to the head then advance it by k steps forward to insert the node.
    cout << "******************" << endl;
    cout << "Problem 1, Attempt 1: " << endl;
    cout << "==================" << endl;

    LinkedList *ll_1 = new LinkedList(); 

    ll_1->addHead(7);
    ll_1->addHead(6);
    ll_1->addHead(5);
    ll_1->addHead(4);
    ll_1->addHead(3);
    ll_1->addHead(2);
    ll_1->addHead(1);

    cout << "Original list ll_1: ";
    ll_1->print();

    int value {100};
    int position {5};
    
    //use insert method
    ll_1->insert(value, position);

    cout << "Updated list ll_1: ";
    ll_1->print();

    /////////////////////////////////////

    cout << "******************" << endl;
    cout << "Problem 1, Attempt 2: " << endl;
    cout << "==================" << endl;
    
    LinkedList *ll_1b = new LinkedList(); 

    ll_1b->addHead(7);
    ll_1b->addHead(6);
    ll_1b->addHead(5);
    ll_1b->addHead(4);
    ll_1b->addHead(3);
    ll_1b->addHead(2);
    ll_1b->addHead(1);

    cout << "Original list ll_1b: ";
    ll_1b->print();
    cout << endl;

    //use insert method
    ll_1->insert_2(value, position);

    cout << "Updated list ll_1: ";
    ll_1->print();




    // 2. given wo linked lists, determine if the data in one is the reverse of the data in the other.
    cout << "******************" << endl;
    cout << "Problem 2: " << endl;
    cout << "==================" << endl;

    // instantite two LinkedList objects
    LinkedList *ll_2 = new LinkedList();
    LinkedList *ll_2b = new LinkedList();

    // make two lists using addHead method
    ll_2->addHead(7);
    ll_2->addHead(6);
    ll_2->addHead(5);
    ll_2->addHead(4);
    ll_2->addHead(3);
    ll_2->addHead(2);
    ll_2->addHead(1);

    ll_2b->addHead(1);
    ll_2b->addHead(2);
    ll_2b->addHead(3);
    ll_2b->addHead(4);
    ll_2b->addHead(5);
    ll_2b->addHead(6);
    ll_2b->addHead(7);

    // output original lists
    cout << "ll_2 address: " << ll_2 << endl;
    cout << "ll_2 value: ";
    ll_2->print();

    cout << "ll_2b address: " << ll_2b << endl;
    cout << "ll_2b value: ";
    ll_2b->print();


    // reverse one of them
    ll_2b->reverse();
    
    bool result = ll_2 -> compareList(ll_2b);

    if (result == 1)
    {   
        cout << "Boolean: " << result << endl;
        cout << "One list is the reverse of the other." << endl;
    }
    else 
    {
        cout << "Boolean: " << result << endl;
        cout << "One list is not the reverse of the other." << endl;
    }
    
    //cout << "Result from compareList: " << result << endl;
    //compare
    //cout << "Result from compareList: " << ll_2 -> compareList(ll_2b) << endl;




    // 3. find the middle element in a singly linked list. Explain the complextiy of your solution. Use {1, 2, 3, 4, 5, 6, 7}
    cout << "******************" << endl;
    cout << "Problem 3: " << endl;
    cout << "==================" << endl;
    // instantiate a LinkedList object
    LinkedList *ll_3 = new LinkedList();

    // call addHead method to add items
    ll_3->addHead(7);
    ll_3->addHead(6);
    ll_3->addHead(5);
    ll_3->addHead(4);
    ll_3->addHead(3);
    ll_3->addHead(2);
    ll_3->addHead(1);

    // call print method
    ll_3->print();

    // call_3 size method
    int size {ll_3 -> size()};

    // find middle element
    int mid_index {(size/2)+1};

    
    // if (size % 2 == 0)
    // {
    //     // there is not true middle for an even list so we'll get the value before where the middle should be. 
    //     int mid_index {(size/2)};
    // }
    // else if (size % 2 != 0)
    // {   
    //     // if odd, add one to get middle position
    //     int mid_index {(size/2)+1};
    // }

    int mid_value {ll_3->nthNodeFromStart(mid_index)};
    cout << "Middle element of singly liked list: " << mid_index << endl;

    // explain complexity
    cout << "Complexity of O(k) when searching for position k in list of length n." << endl;


    // 4. print list in reverse order.
    cout << "******************" << endl;
    cout << "Problem 4: " << endl;

    // instantiate a LinkedList object
    LinkedList *ll_4 = new LinkedList();

    // add items to list
    ll_4->addHead(7);
    ll_4->addHead(6);
    ll_4->addHead(5);
    ll_4->addHead(4);
    ll_4->addHead(3);
    ll_4->addHead(2);
    ll_4->addHead(1);

    // call print to see original linked list
    cout << "Original: ";
    ll_4->print();

    //call reverse method
    ll_4->reverse();

    // call print to see reversed linked list
    cout << "Reversed: ";
    ll_4->print();
    
    // end of output
    cout << "******************" << endl;
    
	return 0;
}

