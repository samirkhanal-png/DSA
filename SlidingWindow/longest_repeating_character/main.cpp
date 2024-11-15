#include <iostream>

using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,max_len=0,maxf=0;
        vector<int>hash(26);
        while(r<s.size()){
           hash[s[r]-'A']++;
           maxf=max(maxf,hash[s[r]-'A']);
           //when invalid trimming from the beginning
           while((r-l+1)-maxf>k){
            hash[s[l]-'A']--;
            maxf=0; //to cancel the previous max frequency and update if after trimming
            //Once we have trimmed we have to update the maximum
            for(int i=0;i<26;i++){
                maxf=max(maxf,hash[i]);
            }
            l++;
           }

           //if valid then while loop does not exist
           if((r-l+1)-maxf<=k){
            max_len=max(max_len,r-l+1);
           }
            r++;
        }
        return max_len;
    }
};
/*
Longest subarray in which all the characters are equal with k replacement

we should convert the characters except the one having max frequency so that there is min conversions

for eg: AABAB here it is optimal to convert B into A rather than A into B

len-maxf is the number of characters that we need to convert

We want to minimize the conversions


*/

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
