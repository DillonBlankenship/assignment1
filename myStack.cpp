#include <iostream>
#include "myStack.h"

using namespace std;

/*
 * Constructor
 * Usage: myStack(maxSz);
 * -------------------------
 * A new stack variable is initialized.  The initialized
 * stack is made empty.  maxSz is used to determine the
 * maximum number of character that can be held in the
 * stack.
 */

myStack::myStack(int maxSz) {
	contents = new int[maxSz];
    if(contents == NULL){
        cout << "Stack is unitialized, program will terminate. " << endl;
    }
    maxSize = maxSz;
    top = -1;
}

/* Destructor
 * Usage: delete ptr
 * -----------------------
 * This frees all memory associated with the stack.
 */

myStack::~myStack() {
	delete[] contents;
	contents = NULL;
	maxSize = 0;
	top = -1; //stack empty
}

/*
 * Functions: push, pop
 * Usage: s1.push(element); element = s1.pop();
 * --------------------------------------------
 * These are the fundamental stack operations that add an element to
 * the top of the stack and remove an element from the top of the stack.
 * A call to pop on an empty stack or to push on a full stack
 * is an error.  Make use of isEmpty()/isFull() (see below)
 * to avoid these errors.
 */

void myStack::push(int element) {
	if(isFull()){
	    cout << "Stack is at full capacity. " << endl;
	}
	    contents[top] = element; // Assign new content to element.
        top++;                   // Increment top...
}

int myStack::pop() {
	top--; //removes top element from stack.
	return contents[top];
}

/*
 * Functions: isEmpty, isFull
 * Usage: if (s1.isEmpty()) ...
 * -----------------------------------
 * These return a true value if the stack is empty
 * or full (respectively).
 */

bool myStack::isEmpty() const {
	return (this ->top == -1);
}

bool myStack::isFull() const {
	return (this ->top == maxSize -1);
}