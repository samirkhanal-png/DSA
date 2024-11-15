#include <iostream>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int rsum=0,lsum=0,maxSum=0;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
            maxSum=max(lsum,maxSum);
        }

        int rindex=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            lsum=lsum-cardPoints[i];
            rsum+=cardPoints[rindex];
            maxSum=max(maxSum,lsum+rsum);
            rindex--;
        }
        return maxSum;
    }
};
/*
Asked in flipkart online assessment

Pick up k cards in any possible way either from front or from back consecutively

arr={6,2,3,4,7,2,1,7,1} k=4

lsum=15 rsum=10 sum=15 {6,2,3,4}
lsum=11 rsum=1  sum=12 {6,2,3......1}
lsum=8  rsum=8  sum=16 {6,2    back 1 7}
lsum=8  rsum=9  sum=15 {6 back 1 7 1}

*/

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
