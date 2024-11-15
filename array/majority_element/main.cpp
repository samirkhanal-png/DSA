#include <iostream>

using namespace std;

#include<bits/stdc++.h>
int majorityElement(vector<int> v) {
  map<int,int> mpp;
  for(int i=0;i<v.size();i++){
      mpp[v[i]]++;
  }
  for(auto &value:mpp){
      if(value.second>v.size()/2){
          return value.first;
      }
  }
}

#include<bits/stdc++.h>
class Solution {
public:
     int majorityElement(vector<int>& nums) {
        int cnt = 0, el;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {  // Reset candidate
                el = nums[i];
                cnt = 1;  // Correctly initialize count when choosing new candidate
            } else if (nums[i] == el) {  // Increment count if the same as candidate
                cnt++;
            } else {  // Decrement count if different
                cnt--;
            }
        }

        // Verify if the candidate is actually the majority element
        int cnt1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el) cnt1++;
        }

        if (cnt1 > nums.size() / 2) {
            return el;
        } else {
            return -1;  // No majority element exists
        }
    }
};
/*
We consider the first element as majority
Initially the count is set to zero count finds the occurence of element supposed as majority
On every element check
If the element matches then increase the count
If it does not match then decrease the count

Whenever the count becomes zero suppose the next element as majority
and repeat the same process for that element

Whatever element remains till the last as majority that is the majority element

But it may or may not be the majority element

Its occurence  may be just n/2

so we have to check this manually by counting the occurence of supposed majority element

If it is still the majority element then it is the majority element otherwise the
majority element does not exist


*/


/*
Better approach
Using hash
Time complexity:O(n)
Space complexity:  More since it uses map



*/
