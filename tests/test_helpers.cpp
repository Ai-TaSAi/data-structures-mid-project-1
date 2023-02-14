#include <gtest/gtest.h>
#include "test_helpers.hpp"
#include "../code_1/LinkedList.hpp"


std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::string readFileIntoString(std::string fileName){
	std::string line, out;
  	ifstream A;
  	A.open(fileName);
  	if(!A){throw std::runtime_error("could not open file: " + fileName);}
	while(getline(A,line)){
		out = out+line+"\n";
	}
	return out;
}


string test_moveMinToHead(int* arr,  int len)
{
    testing::internal::CaptureStdout();
    LinkedList li;
    for(int i=0;i<len;i++)
        li.insert(arr[i]);
    
    Node* min = li.getHead();
    Node* temp = li.getHead();
    Node* prev_min = nullptr;
    Node* prev = nullptr;
    while(temp)
    {
        if(min->key > temp->key)
        {
            min = temp;
            prev_min = prev;
        }
        prev = temp;
        temp = temp->next;
    }
    
    cout<< "Printing the list before swapping"<<endl;
    li.printList();
    Node* b4head = li.getHead();
    li.moveMinToHead();
    cout<< "Printing the list after swapping"<<endl;
    li.printList();
    Node* aftrHead = li.getHead();
    
    if(min!=b4head && min==aftrHead )
    {
        cout<< "Node swappeed correctly done"<<endl;
    }
    
    string output = testing::internal::GetCapturedStdout();
    return output;
}



