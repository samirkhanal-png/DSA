#include <iostream>

using namespace std;


//Optimal solution
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        unordered_set<int> st;
      for(int i=0;i<n;i++){
        st.insert(nums[i]);
      }
      int longest=1; //at least if the array is not empty then it will be one length long
      for(auto &cvalue:st){
        if(st.find(cvalue-1)==st.end()){ //so this is the starting point if the current element -1 is not found then this is the starting point of the sequence
          int cnt=1;
          int x=cvalue;
          while(st.find(x+1)!=st.end()){
            cnt++;
            x++;
          } //sequence continues till the elements larger by 1 are found in the set
          longest=max(longest,cnt); //updating the count of the sequence if it exceeds the previous sequence
        }
      }
    return longest;
    }
};
/*
We are using set because it makes finding operations very easy and finding operations takes only O(1)
Time Complexity Analysis:
O(n) for iterating the vector and keeping in set
O(2n)=>O(n) for iterating through the set and O(n) for performing the finding operations

it only starts the inner loop at the starting of the seqeunce and not the other times
for eg:102, 4 , 100, 1, 101, 3, 2, 1, 1
keeping it in the set
102 4 100 1 101 3 2

finding operations in while
100   1
101   2
102   3
      4
O(7)=>O(n) operations

Overall O(3n) is the time complexity

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int longest=1,count=0,last_smaller=INT_MIN;
        for(int i=0;i<nums.size();i++){
          if(nums[i]-1==last_smaller){ //The old sequence continues with new element in the sequence and count goes on increasing and last_smaller goes on updating
            count++;
            last_smaller=nums[i];
          }    //if the old sequence breaks then it goes to this
          else if(nums[i]!=last_smaller){ //previous sequence breaks and new sequence has just begun// at the first element also this runs as arr[i-1]!=last_smaller and arr[i]!=last_smaller INT_MIN
            count=1;
            last_smaller=nums[i];
          }      //If the same element is repeated then that is considered as one single sequence/ no change occurs here count remains same so doing nothing
          longest=max(count,longest);
        }
        return longest;
    }
};

/*
Here we have to sort the array so the interviewer may not like this
O(nlogn) for sorting+ O(n)

Better approach
100 102 100 101 101 3 2 3 2 1 1 1 2

sort()
1 1 1 2 2 2 3 3 4 100 100 101 101 102

1-1=0 !-INT_MIN so the new sequence continues last_smaller=1 count=1

1 do nothing

1 do nothing

2-1=1(last_smaller) last_smaller=2 count=2

3 same

4 same

100-1=99 !=last_smaller (4) sequence does not continue with new element

100!=last_smaller sequence does not repeat also(with the same element)

so the new sequence starts

https://leetcode.com/problems/longest-consecutive-sequence/

*/

class Solution {
public:
bool ls(arr,num){
    for(int i=0;i<n;i++){
        if(arr[i]==num){
            return true;
        }
    }
    return false;
}

    int longestConsecutive(vector<int>& nums) {
        int count=1,longest;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            while(ls(nums,x+1)){
                x=x+1;
                count++;
            }
            longest=max(longest,count);
        }
        return longest;
    }
};

/*
O(n^3)

102 4 100 1 101 3 2 1 1
While iterating all the elements ,if the particular element is found only once and(element greater than that by 1 is not
found then no need to do anything for that) then for that we already have the longest one.
so no need to do anything when only that element is found longest remains 1


If elements greater than by it by 1 is found then go on finding elements greater by 1 one by one
in the array and increasing the count

102-> 103 is not found

4 -> 5 not found

100 -> 101 is found 102 is found count becomes 3

103 not found count of sequence is 3

keep track of the longest sequence

*/
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
