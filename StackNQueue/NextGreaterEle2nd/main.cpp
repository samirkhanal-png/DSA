class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
     int size=nums.size();
     vector<int>nge(size,-1);
     for(int i=0;i<size;i++){
        for(int j=i+1;j<=i+size-1;j++){
         int index=j%size;
         if(nums[index]>nums[i]){
            nge[i]=nums[index];
            break;
         }
        }
     }
     return nge;
    }
};
/*
Traversing till i+n elements after this it will traverse from the current element to last and circle till its previous element.

1 2 3 4 3

At last 3 index=4

size=five

4+size-1=>8

8 percent five = 3

*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      int size=nums.size();
      vector<int>result(size,-1);
      stack<int>st;

      for(int i=size-1;i>=0;i--){
        st.push(nums[i]);
      }

      for(int i=size-1;i>=0;i--){
        while(!st.empty()&&st.top()<=nums[i]){
            st.pop();
        }
        if(!st.empty())
        result[i]=st.top();

        st.push(nums[i]);
      }
      return result;
    }
};
