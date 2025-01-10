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

 Since one element is known by every other element except itself 
 every other element except itself can't satisfy the condition that it must not know anyone 

 

*/

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int size=mat.size();
        int top=0;
        int down=mat.size()-1;
        while(top<down){
            if(mat[top][down]==1){
                top++;
            }
            else if(mat[down][top]==1){
                down--;
            }
            else{ //if both are zero
                top++;
                down--;
            }
        }
        
        if(top>down)return -1;
        
        //if top==down
        //this may or maynot be the celebrity
        for(int i=0;i<size;i++){
           if(i==top)continue;
           if(mat[top][i]==0&&mat[i][top]==1){}
           else return -1;
        }
        return top;
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
 0 0 0 0   top
 1 1 0 0 knows 1 can't be a celebrity
 2 1 0 0 knows 1 can't be a celebrity
 3 1 0 0   down
 
 In optimal solution we use the idea of elimination
 
 making top and down looks at every possible combination of it if it accepted and not eliminated
 
 One among mat[top][down] or mat[down][top] must be 1 and other must be 0 to be a celebrity
 
 The one having 0 and 1 may be a celebrity 
 
 It signifies may be it does not know anyone but is known by other 
 
 If one of them is 1 it means he is not a celebrity for sure 
 
 so eliminating
 
 If both are 0 then maybe it does not know anyone but it is not known by element except itself
 
 at last top crosses down or top and down becomes same
 
 if crosses then return -1 there is no celebrity
 
 else there is no solution

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
