#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256,0);
        int l=0,r=0,minLen=INT_MAX,sIndex=-1,n=s.size(),m=t.size(),cnt=0;

        //maintatining the hashmap
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }

        while(r<s.size()){
            if(hash[s[r]]>0)cnt++;
            hash[s[r]]--;

            //when the substring is valid trying to find the minimum length so trimming the window
            while(cnt==m){
             if(r-l+1<minLen){
                minLen=r-l+1;
                sIndex=l;
             }

             hash[s[l]]++;

             if(hash[s[l]]>0)cnt--; //if preinserted then decreasing the count
             l++;
            }
         r++;
        }
     return sIndex==-1?"":s.substr(sIndex,minLen);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
