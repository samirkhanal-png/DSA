
/**
Brute Force Solution
Time Complexity:O(max-mini)*O(n)

**/
class Solution {
public:
    bool possible(vector<int>&arr,int days,int m,int k){
        int cnt=0,nBoquets=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=days)cnt++;
            else{
                cnt=0;
            }
            if(cnt==k){
                nBoquets++;
                cnt=0;
                }
        }
        if(nBoquets>=m)return true; //return nBoquets>=m
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        if(m*k>bloomDay.size())return -1;

        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());

        for(int i=low;i<=high;i++){
            if(possible(bloomDay,i,m,k)) return i;
        }

        return -1;
    }
};

//Optimal Solution
/*
 Time Complexity:O(n)*O[log(max-mini+1)]
*/
    int minDays(vector<int>& bloomDay, int m, int k) {

        if(m>bloomDay.size()/k)return -1; //Integer overflow occured here [Original condition m*k>bloomDay.size()]

        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k)){ //Possible function is same for both brute force and optimal approach
             ans=min(ans,mid);
             high=mid-1;
            }
            else low=mid+1;
        }

        return ans;
    }
};
/*
bloomDay=[7,7,7,7,13,11,12,7]   m=2,k=3

All the flowers are bloomed in the 13th day i.e(max day)
There are two boquets.

Taking 7th day the min in the arr.

Only one boquet can be made.

After day 13(max) everything blooms but we want the min(so  excluding range after that)

If we take lower than 7 nothing is possible for sure because it will not even be present in the array.

Impossible case:[1,10,3,10,2] m=3,k=2

m*k>arr.size() so not possible

bloomDay=[7 7 7 7 13 11 12 7]   m=2 k=3
mini=7
max=13

ans lies in the range of 7 to 13

7   8  9  10 11 12 13
low       mid      high(possible for sure) due to polarity at last it points at the first value which is not possible
(may be possible/may be not so due to polarity it points to the first value in the possible zone)

7     8     9      10     11     12     13
low                mid                 high

mid 10 not possible so low=mid+1

7     8     9      10     11     12     13
X     X     X      X      low    mid    high

mid=12 possible so at its right all the values will be possible but they are higher and we want min so eliminating the right side.

7     8     9       10    11     12     13
X    X      X        X    low
                          high
                          mid

Not possible at 11 so low=mid+1 low points to 12 (low and high crosses Binary search stops)

low points the answer


*/
