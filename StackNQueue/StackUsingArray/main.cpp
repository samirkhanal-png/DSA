//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class MyStack {
  private:
    int arr[1000];
    int top;

  public:
    MyStack() { top = -1; }

    int pop();
    void push(int);
};


// } Driver Code Ends
// Function to push an integer into the stack.

/*
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
*/

void MyStack ::push(int x) {
    if(top==999){ //when top==size-1 then stack is full and nothing can be stored in it
        return;
    }
    top++;
    arr[top]=x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    if(top==-1){ //when top=-1 then the stack is already empty no need to returns
        return -1;
    }
    return arr[top--];
}
/*
998 new top 999 kept in the array

now if 999 then return since array is full

999++ =>1000

exceeds the memory limit
*/
