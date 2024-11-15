#include <iostream>

using namespace std;

bool validDistance(vector<int>arr,int dist,int cows){
    int countCows=1;
    int prevNum=arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]-prevNum>=dist){
            countCows++;
            prevNum=arr[i];
        }

        if(countCows==cows)return true;

    }
    return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{ sort(stalls.begin(),stalls.end());
  int low=1;
  int high=stalls[stalls.size() - 1] - stalls[0]; //after sorting first position contains min element and last contains max element
  int ans=-1;

  while(low<=high){
      int mid=(low+high)/2;
      if(validDistance(stalls,mid,k)){
        ans=mid;
        low=mid+1;
      }
      else high=mid-1;
  }
  return ans;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
