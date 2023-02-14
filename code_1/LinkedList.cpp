#include "LinkedList.hpp"

using namespace std;


void LinkedList::insert(int newKey){

  //Check if head is Null i.e list is empty
    Node* newNode = new Node;
    newNode->key = newKey;
    newNode->next = nullptr;
    
    
    if(head == NULL){
        head = newNode;
    }
    else{
        Node* temp = head;
        while(temp->next !=nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
     
}

// Print the keys in your list
void LinkedList::printList(){
    Node* temp = head;
    if(temp==nullptr)
    {
        return;
    }

    while(temp->next != NULL){
        cout<< temp->key <<" -> ";
        temp = temp->next;
      }

  cout<<temp->key<<endl;
}

LinkedList::~LinkedList()
{
    while(head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout<<"network deleted"<<endl;
    head = NULL;
}

void LinkedList::moveMinToHead()
{
    // Nodes needed: Current, Previous, and Next

    Node * current;
    Node * previous;
    Node * nextNode;
    Node * navigator;
    Node * anchorPrev;
    Node * anchorNext;

    // Initialize with Current = Head, Previous = NULL, and Next = Head.next (PUT CASE 1 BEFORE TO AVOID SEGFAULT)

    // Cases: 1. Is EMPTY, 2. ONLY HEAD, 3. Is HEAD, 4. Is TAIL, 5. ELSE

    // Case 1: If Head == NULL, return.

    // Case 2: If Head->next == NULL, return.

    if (head == NULL) {
        return;
    } else if (head->next == NULL) {
        return;
    }

    //cout << "CP 1" << endl;

    current = head;
    previous = NULL;
    nextNode = head->next;
    navigator = head;

    //cout << "CP 2" << endl;

    // Indexers needed: Minimum, Index, and Length
    // Initialize with Minimum = head->key, Index = 0, Length = 0

    int minimum, index, length;
    minimum = head->key;
    index = 0;
    length = 0;

    //cout << "CP 3" << endl;

    // Read List: While (Current != NULL):
    while (navigator->next != NULL) {
        // Minimum keeps track of smallest value.  
        // If Current->key == minimum, do not change index.  If Current->key < minimum, change Index to Length

        //cout << "CHECK MINIMUM PASSED" << endl;

        if (navigator->key < minimum) {
            index = length;
            minimum = navigator->key;
            current = navigator;
            anchorNext = nextNode;
            anchorPrev = previous;
        }

        // Previous = Current
        previous = navigator;

        //cout << "PREV = CURR" << endl;

        // Increment loop (Current = Current->next)
        navigator = navigator->next;

        //cout << "CURR = NEXT" << endl;

        // Next = Current->next;
        //if (current != NULL) {
        nextNode = navigator->next;
        //}

        //cout << "NEXT = CURRNEXT" << endl;

        // Increment length (Length++);
        length++;
    }

    //cout << "NAVIGATOR: " << navigator->key << "INDEX: " << index << "LENGTH: " << length << endl;;
    /*
    previous = navigator;
    if (navigator->key < minimum) {
        anchorPrev = previous;
        current = navigator;
        index = -10;
    }
    */

    //cout << "CP 4" << endl;

    // Decrement length because it overshoots the index.

    //length--;

    //cout << "LENGTH: " << length << endl;
    //cout << "KEY: " << navigator->key << endl;
    //cout << "PREVKEY: " << previous->key << endl;

    if (navigator->key < minimum) {
        current = navigator;
        anchorPrev = previous;
        index = length;
    }

    if (index == 0) {
        // Case 3: If Index == 0, return.

        //cout << "CASE 3" << endl;

        return;
    } else if (index == length) {
        // Case 4: If Index = Tail Previous points to NULL, Current->next points to head, Head = current.

        //cout << "CASE 4" << endl;

        anchorPrev->next = NULL;

        current->next = head;

        head = current;

    } else {
        // Case 5: Previous points to Next, Current->next = Head, Head = Current.

        //cout << "CASE 5" << endl;

        anchorPrev->next = anchorNext;
        current->next = head;
        head = current;
    }
    
    //cout << "CP 5" << endl;

}