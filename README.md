# CSCI 2275 – Midterm 1, Part II: Coding Problem



Given a Singly Linked List class, implement a method `moveMinToHead` to find the node with the minimum integer key value and to move this node to the beginning of the list and make it the new `head`. 
 
Consider the following definition of the the linked list class: 
```
struct Node{
   string key; /* Key of the node */
   Node *next; /* Pointer to the next node in the list */
};

class LinkedList{
   private:
      Node* head; /* Pointer to the very first node in the list */

   public:
      LinkedList() {head = nullptr;}
      
      ...
      
      void moveMinToHead(); // implement this function
};
```

## Specifications
* You are required to actually move the node by exchanging pointers, not merely by swapping the key values.
* If there are more than one node with the minimum value, swap the head with the first such node.
* Consider all of the possible edge-cases and handle them appropriately.
* The `constructor`, `destructors`, and `insert` have been implemented for you and they are provided in `LinkedList.cpp` and `LinkedList.hpp` files in the `code_1` folder.
* Write your function with proper class scope and return type specifications.
* Your code should **not leak memory**.
* Make sure to address all the boundery cases.

See the diagrams in Examples A and B for a visual understanding. 

### Example A
Let `li` be an object of the `LinkedList` class. If `li` has the following initial configuration:

<img src="./images/ExampleA_before.png" width="600">

After a call to `li.moveMinToHead` it should look like:

<img src="./images/ExampleA_after.png" width="600">


### Example B
Let `li` be an object of the `LinkedList` class. If `li` has the following initial configuration:

<img src="./images/ExampleB.png" width="300">

After a call to `li.moveMinToHead` it should look like:

<img src="./images/ExampleB.png" width="300">

##  Instructions - Getting and submitting code

 1. Open up your Linux terminal, navigate to the build directory of this assignment (e.g. `cd build`).
 2. Run the `cmake ..` command.
 3. Run the `make` command.
 4. If there are no compilation errors, two executables will be generated within the build directory: `run_app_1` and `run_tests`.
 5. If you would like to run your program including your app implementation in the `main` function, execute `run_app_1` from the terminal by typing `./run_app_1`.
 6. To run the grading tests, execute `run_tests` from the terminal by typing `./run_tests`. 
 7. Your submission will be the code you commit and push by the exam end time. (Note: you do NOT need to paste your link back into Canvas.) Reminder. This is how you commit/push in git/GitHub:
 * Stage
     ```console
     $ git add ../code_1/LinkedList.cpp
     ```
 * Commit the changes to our local repository:
     ```console
     $ git commit -m 'this is my commit'
     ```
 * Push to GitHub 
     ```console
     $ git push
