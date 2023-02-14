#ifndef TEST_H__
#define TEST_H__
#include <string>
#include <iostream>
#include <fstream>
#include <array>

using namespace std;

// TODO add detailed explanation on what the function should do
std::string exec(const char* cmd);
std::string readFileIntoString(std::string fileName);
//string test_append(int totalElements, string expected_output);
string test_moveMinToHead(int* arr,  int len);


#endif // TEST_H__