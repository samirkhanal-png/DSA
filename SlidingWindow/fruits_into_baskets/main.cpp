#include <iostream>

using namespace std;

class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int l=0,r=0,maxLen=0;
        map<int,int>mpp;
        while(r<arr.size()){
            mpp[arr[r]]++;
            if(mpp.size()<=2){
                maxLen=max(maxLen,r-l+1);
            }
            if(mpp.size()>2){
                mpp[arr[l]]--; //l needs to starts from zero
                if(mpp[arr[l]]==0){
                    mpp.erase(arr[l]);
                }
                l++;
            }
            r++;
        }
        return maxLen;
    }
};
/*
In short finding the length of maximum length subarray with at most
two numbers.


Optimal solution:
Time complexity:O(n)
Space complexity:O(3)

Similar to the solution of maximum consecutive ones.
*/
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
