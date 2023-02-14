// If you change anything in this file, your changes will be ignored 
// in your homework submission.
// Chekout TEST_F functions bellow to learn what is being tested.
#include <gtest/gtest.h>
#include "../code_1/LinkedList.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <array>
#include <vector>
#include "test_helpers.hpp"

using namespace std;

class test_x : public ::testing::Test {
protected:
	// This function runs only once before any TEST_F function
	static void SetUpTestCase(){
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)0;
			outgrade.close();
		}
	}

	// This function runs after all TEST_F functions have been executed
	static void TearDownTestCase(){
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)std::ceil(100*total_grade/max_grade);
			outgrade.close();
			std::cout << "Total Grade is : " << (int)std::ceil(100*total_grade/max_grade) << std::endl;
		}
	}

	void add_points_to_grade(double points){
		if(!::testing::Test::HasFailure()){
			total_grade += points;
		}
	}

	// this function runs before every TEST_F function
	void SetUp() override {}

	// this function runs after every TEST_F function
	void TearDown() override {
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)std::ceil(100*total_grade/max_grade);
			outgrade.close();
		}
	}
	
	static double total_grade;
	static double max_grade;
};

double test_x::total_grade = 0;
double test_x::max_grade = 50;




/////////////////////////////////////////
// Tests start here
/////////////////////////////////////////

TEST_F(test_x, TestMoveMinToHead){
    
    string expected_array, result;
    int arr1[] = {4,2,6,3,1};
    int len1 = 5;
    result = test_moveMinToHead(arr1, len1);
    expected_array = "Printing the list before swapping\n4 -> 2 -> 6 -> 3 -> 1\nPrinting the list after swapping\n1 -> 4 -> 2 -> 6 -> 3\nNode swappeed correctly done\n";
    ASSERT_EQ(expected_array, result);
    add_points_to_grade(10);
    
    int arr2[] = {4,2,6,3,1};
    int len2 = 0;
    result = test_moveMinToHead(arr2,  len2);
    expected_array = "Printing the list before swapping\nPrinting the list after swapping\n";
    ASSERT_EQ(expected_array, result);
    add_points_to_grade(10);
    
    int arr3[] = {4,2,1,3,1};
    int len3 = 5;
    result = test_moveMinToHead(arr3,  len3);
    expected_array = "Printing the list before swapping\n4 -> 2 -> 1 -> 3 -> 1\nPrinting the list after swapping\n1 -> 4 -> 2 -> 3 -> 1\nNode swappeed correctly done\n";
    ASSERT_EQ(expected_array, result);
    add_points_to_grade(10);
    
    int arr4[] = {4,2,1,3,1};
    int len4 = 1;
    result = test_moveMinToHead(arr4,  len4);
    expected_array = "Printing the list before swapping\n4\nPrinting the list after swapping\n4\n";
    ASSERT_EQ(expected_array, result);
    add_points_to_grade(10);
    
    
    int arr5[] = {4,4,4,4,4};
    int len5 = 5;
    result = test_moveMinToHead(arr5,  len5);
    expected_array = "Printing the list before swapping\n4 -> 4 -> 4 -> 4 -> 4\nPrinting the list after swapping\n4 -> 4 -> 4 -> 4 -> 4\n";
    ASSERT_EQ(expected_array, result);
    add_points_to_grade(10);

}

