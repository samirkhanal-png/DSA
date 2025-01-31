class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size=nums.size();
        vector<int>result(size);
        int posInd=0;
        int negInd=1;
        int index=0;
        while(index<size){
           if(nums[index]>0){
            result[posInd]=nums[index];
            posInd+=2;
           }
           else
           {
            result[negInd]=nums[index];
            negInd+=2;
            }
            index++;
        }
        return result;
    }
};

/*
Better Solution:
Take two arrays positive and negative.

Collect positive elements inside positive array and negative elements inside negative array.

Then place inside array turn by turn.

Optimal
Time Complexity:O(n)

SC:O(n)

This can't be done in inplace because 

nums={3,1,-2,-5,2,-4}
      0 1  2  3 4  5
      i            j

Arrange the positive and negative elements.

{3,1,2,-5,-2,-4}
 i      j

 {3,-5,1,-2,2,-4}
 Order broken.

 Can be done in O(n^2) inplace

*/
