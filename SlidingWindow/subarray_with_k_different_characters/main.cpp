#include <iostream>

using namespace std;
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
     return atMostK(nums,k)-atMostK(nums,k-1);//I want only mpp.size()==k [including less than or equal to k - including less than k i.e k-1)
    }
private:
    int atMostK(vector<int>&nums,int k){
        int l=0,r=0,cnt=0;
        unordered_map<int,int>mpp;
        //solving by subarray with less than or equal to k different integers
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>k){ //when invalid having more than k different integers now we have to trim
             mpp[nums[l]]--;
             if(mpp[nums[l]]==0)mpp.erase(nums[l]);
             l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
/*
arr={2,1,1,1,3,4,3,2}
     1 pC+(no of elements from i to j) (r-l+1)

No of subarrays where different integers<=k

T.C->O(2n)
S.C->O(n) in worst case can contain all the characters

*/
