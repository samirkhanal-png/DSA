class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        stack<int>st;
        vector<int>nse(n,-1); //allocate size so that we can access through the index

        for(int i=0;i<n;i++){
            while(!st.empty()&&st.top()>=a[i]){ //remove from stack till greater element is found
                st.pop();
            }
            nse[i]=st.empty()?-1:st.top();
            st.push(a[i]);
        }

        return nse;
    }
};

/*
TC:O(2N)
SC:O(2N)

*/
