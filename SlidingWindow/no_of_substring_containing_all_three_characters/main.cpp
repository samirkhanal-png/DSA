#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            vector<int> hash(3,0);
            for(int j=i;j<s.size();j++){
                hash[s[j]-'a']=1;
                if(hash[0]+hash[1]+hash[2]==3){
                    //cnt++;
                    cnt=cnt+(n-j);
                    break;
                }
            }
        }
        return cnt;
    }
};
/*
abcabc
Generating all substrings
abcabc
hash[a]=1,hash[b]=1,hash[c]=1

bc hash 1   hash[a]=1

b found hash[b]=1   //hash ac=1 already

c same for it

Brute force solution
TC->O(n^2)
SC->O(3)

Better approach
The moment we get valid substring every string beyond this would be
valid.
  0123456   6-3=>3 substrings
s=bbacba

   bac
then bacb and also bacba (3) substrings


*/


/*
Optimal approach
minimum length of substring that has all the characters

Minimum window we can have

Minimum length of substring that all three characters can have

How to recognize this is the minimal window which has all
the three characters?
If there is valid substring we can add every character to the left
bbacba     leftmost index=>1  + 1 =>2
012345

bbac   store the latest index of abc
0123  bac123 found

min or left most index b =1

add 1 in it

*/

class Solution {
public:
    int numberOfSubstrings(string s) {
     int cnt=0;
     int lastSeen[3]={-1,-1,-1};
     for(int i=0;i<s.size();i++){
        lastSeen[s[i]-'a']=i;
        if(lastSeen[0]!=-1&&lastSeen[1]!=-1&&lastSeen[2]!=-1){ //if all three characters has been seen for the last time
         cnt=cnt+1+min(lastSeen[0],min(lastSeen[1],lastSeen[2]));
        }
     }
     return cnt;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
