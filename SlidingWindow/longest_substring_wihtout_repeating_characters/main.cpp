#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n=s.size();
      int l=0,r=0,maxlen=0; //maxlen is bydefault set to zero because if the string is empty then maxlen has garbage value and that will be returned
      vector<int> mpp(256,-1); //using vector as a map containing the element as key and index as the value

      /*for(int i=0;i<256;i++){
        mpp[i]=-1;
      }*/

      while(r<n){
       if(mpp[s[r]]!=-1 && mpp[s[r]]>=l) //if the current element is found inside the map and and lies in the current range of substring then update the l
        l=mpp[s[r]]+1;

       int len=r-l+1;
       maxlen=max(len,maxlen);
       mpp[s[r]]=r; //updating the index of the element
       r++;
       }
       return maxlen;
      }
};
/*
cadbzabcd
l    r

a is in the hashmap and in the current substring so
l=last_position_of_a+1

cadbzabcd
    l  r

r=> points to c and c is found in the map but it does not lie in the current substring
*/

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
