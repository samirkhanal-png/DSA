class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
         int minimum=*min(arr.begin(),arr.end());
         if(k<minimum) return k;
         int low=0,high=arr.size()-1;
         while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]-mid-1>=k){
                high=mid-1;
            }
            else low=mid+1;
         }
         return low+k;
    }
};
/*
Optimal Solution:
BS on answers not possible It is only possible when we are looking for the missing
no not present in the array.

Can't apply typical binary search as we are looking for the missing
no not present in the array.

arr[]={1,2,3,4,5}  actual number should have been if there was no number missing

       0 1 2 3 4
arr[]={2,3,4,7,11}   k=5
       1 1 1 3  6    missing numbers till now

We want to find 7 , 11
                3   6    as it lies between 3 and 6

When no of missing number is less than k we move to the right since at the left side it is
more lower lower so moving right
low=mid+1

When no of missing number is more than k we try to find the lowest position where no of missing number is greater than k
high=mid-1
       0 1 2 3  4
arr[]={2,3,4,7,11} k=5
       1 1 1 3  6

low=0,high=4 ,mid=2

       0 1 2 3 4
arr[]={2,3,4,7,11}
           missing=4-2-1=1 number is missing which is less than k so the kth missing number does not lie here so moving to right
low=mid+1=3

       0 1 2 3 4
arr[]={2,3,4,7,11}
       1 1 1 3  6

low=3,high=4,mid=3

missing=7-3-1=3<5

so low=mid+1=4

high=4

mid=(4+4)/2=4

       0 1 2 3 4
arr[]={2,3,4,7,11}
       1 1 1 3 6

missing=11-4-1=6>k(5)
high=mid-1=3

low=4

Initially low was at the point where the missing no was lesser than k

At last low points to the first position where missing no is greater than k

At last high points to the first position where missing no is lesser than k.

This happens due to polarity.

ans[high]=7  missing=ans[high]-high-1=3 till here 3 numbers are missing and kth missing number lies after this so it is more=k-missing=5-3=2 than this present number

return ans[high]+more

ans[high]+k-missing
=>ans[high]+k-(ans[high]-high-1)
=>ans[high]+k-ans[high]+high+1
=>k+high+1
=>k+low (low=high+1) in this scenario

T.C=>O(logn)
*/
