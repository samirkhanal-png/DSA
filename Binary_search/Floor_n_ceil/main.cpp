#include <iostream>

using namespace std;

int floor(vector<int>& arr,int n,int key){
 int low=0,high=n-1,ans=-1;
 while(low<=high){
     int mid=(low+high)/2;
     if(arr[mid]<=key){
      ans=arr[mid];
      low=mid+1;
     }
     else high=mid-1;
 }
 return ans;
}

int ceil(vector<int>& arr,int n,int key){
 int low=0,high=n-1,ans=-1;
 while(low<=high){
     int mid=(low+high)/2;
     if(arr[mid]>=key){
      ans=arr[mid];
      high=mid-1;
     }
     else low=mid+1;
 }
 return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {

int floorValue=floor(a, n, x);
int ceilValue=ceil(a, n, x);
return {floorValue,ceilValue};

}

/*
Ceil
First number in array such that it is greater than or equal to target
For eg:arr={10,20,30,40,50}   target=25
30>=25

Ceil is similar to lowerbound

Floor
First number in an array such that it is less than or equal to target
For eg=>arr={10,20,30,40,50} target=25
Here 20<=30
floor=20

link:https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401?leftPanelTabValue=SUBMISSION
*/

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
