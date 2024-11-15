class Solution {
public:
    long long func(vector<int>&arr,int k){
        long long totalHrs=0;
        for(int i=0;i<arr.size();i++){
            totalHrs+=ceil((double)arr[i]/k);    //int/int returns int =>5/2=ceil(2) so,5.0/2=>ceil(2.5)=>3
            //1<=piles[i]<=10^9 so summing all these integer overflow may occur so taking long long
        }
        return totalHrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end()); //rate lies from the range of ` to max_element from array
        int rate=high; //initializing ans with max possible value
        while(low<=high){
            int mid=low+(high-low)/2; //results in same (low+high)/2 =>2low+high-low/2
            long long takenTime=func(piles,mid);
            if(takenTime<=h){
                rate=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return rate;
    }
};
/*
piles[]=[3,6,7,11]   h=8

k=2

In 3/2=1.5 even if Koko finishes 2 bananas in 1 hour and 1 banans in .5 hour but it waits for whole hour  i.e 2 hours

Answer lies from 1 to max element in the array.ie 11

Answer also lies after max_element 11 but we want the minimum so excluding after that.

Apply binary search on answers:

1      2      3    4     5    6    7    8     9      10       11
low                          mid                             high

piles[]=[3,6,7,11]    1+1+2+2=6<=8 possibleAns(within range)

Beyond it possible for sure but we want the lowest answer so moving towards left

high=mid-1

1      2      3     4     5
low          mid         high

3,6,7,11   |   1+2+3+4=>10>=8   SO NOT POSSIBLE AT RANGE LOWER THAN THIS

so low=mid+1


 3    4     5
     low    high

     mid=4

3,6,7,11 |   1+2+2+3=8 Possible at 4 ans=4

Want lower answers high=mid-1

3        4   5
high    low        at last low points to the correct answer

TC:O(n)*O(log(max))

*/

/*
Brute Force Approach
*/


class Solution {
public:
    long long func(vector<int>&arr,int k){
        long long totalHrs=0;
        for(int i=0;i<arr.size();i++){
            totalHrs+=ceil((double)arr[i]/k);    //int/int returns int =>5/2=ceil(2) so,5.0/2=>ceil(2.5)=>3
            //1<=piles[i]<=10^9 so summing all these integer overflow may occur so taking long long
        }
        return totalHrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
     int maxEl=*max_element(piles.begin(),piles.end());
     for(int i=1;i<=maxEl;i++){
        long long requiredTime=func(piles,i);
        if(requiredTime<=h)return i;
     }
    }
};

