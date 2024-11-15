class Solution {
public:
    bool isValidCapacity(vector<int>&arr,int cap,int days){
     int sum=0;
     int cnt=1;
     for(int i=0;i<arr.size();i++){
        if(sum+arr[i]<=cap){
            sum+=arr[i];
        }
        else{
            sum=0;
            sum+=arr[i];
            cnt++;
        }
     }
     return cnt<=days;
    }
//Optimal Approach TC:Olog(sum-max_el)*O(n)
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(isValidCapacity(weights,mid,days)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
      return ans;
    }

    //Brute force approach O(sum-maxi)*O(n)
        int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int ans=high;
        for(int i=low;i<=high;i++){
            if(isValidCapacity(weights,i,days)){
                return i;
            }
        }
        return ans;
    }


};

/*
Note:Cargo must be shipped in order

Least capacity to ship packages withing D days

1 ship runs once per day

capacity means in one day at max it can transfer this much weights.

weights[]=[1,2,3,4,5,6,7,8,9,10]

Capacity at highest can be the sum of all the weights
Here sum=55 If the capacity of the ship is 55 then it can be transferred in 1 day

days can be at minimum 1(so this capacity falls within days)

Since the cargo must contain all the packages the minimum capacity must be equal to the max weight at minimum since no weights can be left.

If the capacity at the present pos (mid) is valid then eliminate the right half since all the elements in right half are valid but they are not the least
so for searching for the least (high=mid-1)

If the capacity at the present pos (mid) is invalid then eliminate the left half since all the elements in left half are invalid since they are invalid
because in lesser capacity than this it will take more days than the current limit of days

Low started at (may or may not be possible zone)

High started at possible zone

But at the end high will point at the first not possible answer
and low will points at the first possible answer.

Note:We can also return low at the answer

*/

