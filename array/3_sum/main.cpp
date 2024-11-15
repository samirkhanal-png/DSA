#include <iostream>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> temp ={nums[i],nums[j],nums[k]}; //declaring the new vector so that every time we get an empty vector
                    sort(temp.begin(),temp.end()); //sorting the result so we can check if it is unique or not in the set
                    st.insert(temp);
                    }
                    }
                }
            }
        vector<vector<int>> ans(st.begin(),st.end()); //return type is vector<vector<int>> so returning by inserting the set in this
        return ans;
        }
    };
    /*
    Brute force solution
 Time Complexity=> O(n^3*logn) logn for inserting in set
    */

    class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
         set<vector<int>> st;
         int n=nums.size();
         for(int i=0;i<n;i++){
         //after every i maintain new hashset for the new subarray by declaring the new subarray
         set<int> hashset;
         for(int j=i+1;j<n;j++){
            int third=-(nums[i]+nums[j]);
            if(hashset.find(third)!=hashset.end()){ //if found in the hashset
                vector<int> temp={
                    nums[i],nums[j],third
                };
                sort(temp.begin(),temp.end()); //sorting the triplets so that we can check if it is unique triplets
                st.insert(temp);// inserting the triplets in the set
            }
            hashset.insert(nums[j]); //update j after the end of the previous j
         }
         }
         vector<vector<int>>ans(st.begin(),st.end()); //copying the result in the vector of vector
         return ans;
        }
    };
    /*
    Time Complexity:O(n^2)*log(set_size)) log(set_size)=> for find operations in hashset

    arr[i]+arr[j]+arr[k]=0
    arr[k]=-(arr[i]+arr[j])

    If we are able to find the arr[k] in the same array but different than arr[i] and arr[j]

    arr[]={-1,0,1,2,-1,-4}
                  i     j

    -(2-4)=>2 picking up 2 from the same array

    which is wrong

    since the element has to be different from arr[i] and arr[j]

    Put the element between arr[i] and arr[j] in the hashmap as we update the j in the subarray

    Update in this way
    -1 0 update 0 in the hashset 1 =>-(-1+1)=> 0 found in the hashset

     -1 0 1 2 -1 -4
      i     j         => -(-1+2)=>-1  -1 missed but found in next

      - 1 0 1 2 -1 -4   but will be foundin next step



    */

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
