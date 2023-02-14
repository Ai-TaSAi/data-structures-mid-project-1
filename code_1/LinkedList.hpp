#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <iostream>

struct Node{
      int key;
      Node *next;
};

class LinkedList
{
  private:
    Node *head;

  public:
    LinkedList(){
    	head = NULL;
    }
    ~LinkedList();
    Node* getHead(){return head;}
    void insert(int newKey);
    void printList();
    void moveMinToHead(); // implement this function
};


#endif
