#include <iostream>
#include <fstream>
#include "../code_1/LinkedList.hpp"
using namespace std;

void test_moveMinToHead(int* arr,  int len)
{
    LinkedList li;
    for(int i=0;i<len;i++)
        li.insert(arr[i]);
    cout<< "printing the list before swapping"<<endl;
    li.printList();
    li.moveMinToHead();
    cout<< "printing the list after swapping"<<endl;
    li.printList();
}

int main()
{
    int arr1[] = {22,44,11,11};
    int len1 = 4;
    test_moveMinToHead(arr1,  len1);
    
    int arr2[] = {4,2,6,3,1};
    int len2 = 0;
    test_moveMinToHead(arr2,  len2);
    
    
    int arr3[] = {4,2,1,3,1};
    int len3 = 5;
    test_moveMinToHead(arr3,  len3);

   return 0;


}