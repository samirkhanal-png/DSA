#include <iostream>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
               int sum=0;
                for(int a=i;a<=j;a++){
                    sum+=nums[a]; //every time j changes and here we traverse the new subarray
                }
                    if(sum==k){  //after getting the sum of new subarray we increase the count of subarray with sum k
                     count++;
                    }
            }
        }
        return count;
    }
};

//Time complexity O(n^3)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
             sum+=nums[j];
             if(sum==k){
                count++;
             }
            }
        }
        return count;
    }
};


//Time Complexity O(n^2)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     map<int,int> mpp;
     mpp[0]=1;
     int prefixSum=0,cnt=0;
     for(int i=0;i<nums.size();i++){
        prefixSum+=nums[i];
        int remove=prefixSum-k;
        cnt+=mpp[remove];
        mpp[prefixSum]+=1; //Increase by 1

     }
     return cnt;
    }
};



/*
We are maintaining a map to keep previously traversed prefix sum and
its count

Initially map has prefix sum 0 and count=1 (Keeping ) is important) for the first time

Finding prefix sum

prefixSum-k search in the hashmap

increase the count by the count of the subarray



*/

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
