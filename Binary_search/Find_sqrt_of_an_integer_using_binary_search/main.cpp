#include <iostream>

using namespace std;

int main()
{   int n;
    cin>>n;
    int ans=1;
    for(int i=1;i<=n/2;i++){ //4=>sqrt(n) 2  so the answer is always less than or equal to n/2 so running loop only upto n/2
        if(i*i<=n){
            ans=i;
        }
        else break; //when greater then break
    }
    cout<<"The square root of the number is"<<ans<<endl;
}


/*
T.C=>O(sqrt(n))
Brute Force: n=25
Question is basically:Find the max integers which on squaring is <=n
n=30  then sqrt=>5


1*1=1
2*2=4
3*3=9
4*4=16
5*5=25
Then XXXXXXX(answer not possible in this range)

n=30

1*1=1
2*2=4
3*3=9
4*4=16
5*5=25

6*6=36(X)


*/

// x: element to find square root
class Solution {
  public:
  long long int floorSqrt(long long int n) {
      long long int low = 0;
      long long int high = n;
      long long int ans = 1;
       while(low<=high){
          long long int mid = (low+high)/2;
           if(mid*mid<=n){  //possible answer is always less than or equal to mid*mid<=n
             ans=mid; //Updating answer only in the possible range
             low=mid+1;
           }
           else{
               high= mid-1;
           }
       }
       return ans;
    }
};

/*
Link:https://www.geeksforgeeks.org/problems/square-root/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=square-root
Rem:In this question, we are storing the answer in the ans variable
but one of the low or high will always be the answer

For n=28

low(0)           high(5) low(6) [at last]        high(28)
low is                                    high is always at non possible zone
always at
possible zone

low always move towards  this side->                 <-high always move towards this side to find the possible answer

at last high ends up pointing at the first place where answer is
possible

at last low ends up pointing at the last place where the answer is
not possible

BS->(answers)
If we know the range where the answer is possible and want to find the max or min
in this range then we apply binary search patterns.


*/


