#include<bits/stdc++.h>
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{ /*int vis[m]={0};
  vector<int> inter;
  for(int i=0;i<arr1.size();i++){
	  for(int j=0;j<arr2.size();j++){
		  if(arr1[i]==arr2[j]&&vis[j]==0){
			  inter.push_back(arr1[i]);
			  vis[j]=1; //taken already
			  break;
		  }
		  if(arr2[j]>arr1[i])break;
	  }
  }
  return inter;*/

  //T.C O(n1*n2) large brute force

  int i=0,j=0;
  vector<int> ans;
  while(i<n&&j<m){
    if(arr1[i]<arr2[j]){
        i++;
    }
    else if(arr2[j]>arr1[i]){
        j++;
    }
    else{
        ans.push_back(arr1[i]);
        i++;
        j++;
    }
  }
  return ans;

}

//https://www.naukri.com/code360/problems/intersection-of-2-arrays_1082149?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=PROBLEM
