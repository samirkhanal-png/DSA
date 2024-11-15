#include<bits/stdc++.h>
string read(int n, vector<int> book, int target)
{ //maintain the elements which are traversed already in hashmap and search the extra element required by subtracting the current element and search in the hashmap
 map <int,int> mpp;
 for(int i=0;i<n;i++)   {
   int more=target-book[i];
   if(mpp.find(more)!=mpp.end()){
      return "YES";
   }
   mpp[book[i]]=i; //maintaining the element and index in the hashmap
 }
 return "NO";
}
//TC O(n logn) n for n number of iterations and logn for ordered map for unordered map O(n) or O(n^2)
//for returning indices of if found return({mpp[moreNeeded],i}) else return {-1,-1}


string read(int n, vector<int> book, int target)
{
   int left=0,right=n-1;
   sort(book.begin(),book.end());
   while(left<right)    //cannot cross remember that because we need a pair
   {
      int sum=book[left]+book[right];
      if(sum==target){
         return "YES";
      }
      else if(sum<target) left++;  //sum less than target huda right ko badaune kuro vayena kinaki right ko pailai max xa so left ko badaune
      else right--; //when sum>target then obviously right side value is more so it has to be decreased
}

return "NO"; //during the whole iteration inside also if the value is not found then No

}

/*
Two sum problem

Better
//TC O(n logn) n for n number of iterations and logn for ordered map for unordered map O(n) or O(n^2)



Optimal
Time complexity=>O(n)+O(nlogn)

https://www.naukri.com/code360/problems/reading_6845742?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=PROBLEM
*/
