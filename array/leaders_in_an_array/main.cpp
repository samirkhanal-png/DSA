#include <iostream>

using namespace std;
//Brute force solution TC:O(n^2)
vector<int> superiorElements(vector<int>&a) {
    vector<int> ans;
  for(int i=0;i<a.size()-1;i++){ //Traversing every elements
      int leader=1;
      for(int j=i;j<a.size()-1;j++){  //Traversing on the right side of all elements
        if(a[j]>a[i]){ //If any element on the right is greater then a[i] is not the leader
            leader=0;
            break;
        }
      }
      if(leader){
       ans.push_back(a[i]);
      }
  }
  return ans;
}
//TC:O(n^2) SC:O

//TC:O(n)
vector<int> superiorElements(vector<int>&a) {
    int maxi=INT_MIN;
    vector<int> ans;
for(int i=a.size()-1;i>=0;i--){
    if(a[i]>maxi){
        ans.push_back(a[i]);
        maxi=a[i];
    }

}
return ans;
}
/*
Optimal Solution:
Traverse from the back updating max on right and checking if every element
is greater than the max on the right.

TC:O(n)
*/

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

/*https://www.naukri.com/code360/problems/superior-elements_6783446*/
