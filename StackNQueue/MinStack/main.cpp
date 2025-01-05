class MinStack {
public:
    stack<pair<int,int>>st; //storing in pair of val and minimum
    int min=INT_MAX;
    MinStack() {

    }

    void push(int val) {
      if(st.empty()){
        st.push({val,val});
      }
      else if(val<st.top().second){
        st.push({val,val}); //when less than previous min  then current ele is the minimum element
      }
      else st.push({val,st.top().second}); //When val>=st.top().second previous Min is the min element for this also
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

class MinStack {
public:
    stack<long long>st;
    long long min=LLONG_MAX;
    MinStack() {

    }

    void push(int val) {
     if(st.empty()){
        min=val;
        st.push(val);
     }
     else if(val>=min){
        st.push(val);
     }
     else{
        st.push(2*val-min); //prevMin so updating the min below yippee
        min=val;
     }
    }

    void pop() {
        if(st.empty()){
          return;
        }
        else if(st.top()>=min){ //look here st.top()>=mini
          st.pop();
        }
        else{
         int newCurr=st.top();
         st.pop();
         min=2*min-newCurr; //newMini after popping for the subarray before it OK
        }
    }

    int top() {
      if(st.top()<min){
        return 2*min-st.top();
      }
      else return st.top();
    }

    int getMin() {
      return min;
    }
};
/*
Time Complexity:O(1)
Space Complexity:O(2N)

Interviewer may ask for better space complexity  then we can reduce it to O(N)

Using a single stack

Original values at the beginning
8       10     6        3       7
e            change  change
m=8    m=8    m=6     m=3      m=3   m=3    2*curr-prevMin

8       10     4     6-6=0     7           newCurr in the stack(while popping this is the current)

6<10
curr<mini
curr-mini<0
curr+curr-mini<curr
2curr-mini<curr
newVal<curr

        during pushing becomes the new Mini for the next element
newVal=2curr-prevMini
newCurr when popping

When modified during popping
we need  to find prevMini=2newMini-newCurr

For top
Whenever we modify min is the top value else curr element is

*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
