#include <iostream>

using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,maxlen=0,zeros=0;
        while(r<nums.size()){
            if(nums[r]==0) zeros++;

            if(zeros>k){
                if(nums[l]==0){
                    zeros--;
                }
                l++;
            }

            if(zeros<=k){
                int len=r-l+1;
                maxlen=max(len,maxlen);
            }
           r++;
        }
        return maxlen;
    }
};


/*
Optimal Solution
Time Complexity:n
  Space Complexity:O(n)

  Count zeroes first

  When zeros<=k
  len=r-l+1;
  maxlen

  When zeros>k
  if(arr[l]==0)zeros--;
    left++

    r++ //r is moved in every step in sliding window problem

     /*
  The sliding window algorithm can be used to solve this problem,
  in which two pointers are used to indicate a window of the array.
  For each 1 found, the end of the window can be expanded by one to
  include the next array element, and the length of consecutive 1's
  can be increased. When reaching a 0, as long as the number of
  zeroes in the list do not exceed the maximum specified by k,
  the end of the window can continue expanding by one.
  If the number of zeroes ("flipped") within the list reaches its
   maximum (specified by k), then the start of the window can be
    moved to the second zero in the window.
  */

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
