class Solution {
public:
        vector<int> findPSE(vector<int>& arr) {
        int size = arr.size();
        vector<int> ans(size);
        stack<int> st;

        for (int i = 0; i < size; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findNSE(vector<int>& arr) {
        int size = arr.size();
        vector<int> ans(size);
        stack<int> st;

        for (int i = size - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? size: st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector<int> pse = findPSE(heights); 
        vector<int> nse = findNSE(heights); 
        int maxArea = 0;

        for (int i = 0; i < size; i++) {
            int width = (nse[i]-pse[i]-1);
            maxArea = max(maxArea, heights[i] * width);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int rows=matrix.size();
        int cols=matrix[0].size();
        int maxArea=0;//if there is noArea then 0 is the maxArea

        vector<int>height(cols);
        for(int i=0;i<cols;i++){
            height[i]=(matrix[0][i]=='1')?1:0;
        }
        maxArea=largestRectangleArea(height);

        for(int i=1;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='0')height[j]=0;
                else height[j]+=1;
            }
         maxArea=max(maxArea,largestRectangleArea(height));
        }
        return maxArea;
    }
};
