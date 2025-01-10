//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int size=mat.size();
        //int col=mat[0].size(); //row and colSize is same so no need to worry
        vector<int>OtherKnowMe(size);
        vector<int>iKnowOther(size);
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(mat[i][j]==1){
                    iKnowOther[i]++;
                    OtherKnowMe[j]++;
                }
            }
        }
        
        for(int i=0;i<size;i++){
            if(iKnowOther[i]==0&&OtherKnowMe[i]==size-1){
                return i; //there can be only one celebrity 
            }
        }
        return -1;
    }
};

/*
Brute force solution

Traversing over every row and items in every row

row=>I know other 

col=>others know Me

If I do not know anyone (that means in every row there is 0)

and n-1 people except me know me (that means in every items in the column there must be 1)

There can be min zero celebrity and at max one celebrity

why?
 0 1 2 3 
 0 0 0 0
 1 1 0 0 knows 1 can't be a celebrity
 2 1 0 0 knows 1 can't be a celebrity
 3 1 0 0

*/


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends
