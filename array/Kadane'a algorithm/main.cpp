#include <iostream>

using namespace std;

#include<bits/stdc++.h>
//Brute force solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxi=nums[0];
       for(int i=0;i<nums.size();i++){
        int sum=0;
        for(int j=i;j<nums.size();j++){
            for(int k=i;k<=j;k++){
                sum+=nums[k];
            }
           maxi=max(sum,maxi);
        }
       }
       return maxi;
    }
};
//T.C O(n^3)

//Better solution
#include<bits/stdc++.h>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int maxi=nums[0];
      for(int i=0;i<nums.size();i++){
        int sum=0;
        for(int j=i;j<nums.size();j++){
          sum+=nums[j]; //in each loop of j we are getting new subarray and its elements so calculating the maximum here only
          maxi=max(maxi,sum);
        }
      }
      return maxi;
    }
};
//T.C=>O(n^2)

//Optimal solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxi=nums[0];
        for(auto &value:nums){
          sum+=value;
          if(sum>maxi)maxi=sum;
          if(sum<0) sum=0;
        }
        return maxi;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

/*
Maximum Subarray Sum



Optimal Soution Time Complexity:O(n)

Kadane's algorithm

Carrying a subarray sum till it gives positive sum, if it gives negative sum
update sum to zero as negative sum has less chance of being maximum sum of subarray
and update max if it is greater than previous maximum value.

Steps:
First finding sum of subarray(one element or more)
Checking if it is greater than previous max and updating the max if it is
Updating the max before setting sum to zero eg: -3 -2 max=a[0] sum=-3 sum>max(a[0]) sum=0+-2 sum>previous_max max=-2 so setting max before setting sum to zero

If sum<0 negative then update sum to zero

*/
