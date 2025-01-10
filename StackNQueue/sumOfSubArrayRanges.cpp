class Solution {
public:
    vector<int> findNSELeft(vector<int>& arr) {
        int size = arr.size();
        vector<int> ans(size);
        stack<int> st;
        for (int i = 0; i < size; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> findNSERight(vector<int>& arr) {
        int size = arr.size();
        vector<int> ans(size);
        stack<int> st;
        for (int i = size - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = size;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    long long findMinSum(vector<int> arr) {
        int size = arr.size();
        vector<int> NSEL = findNSELeft(arr);
        vector<int> NSER = findNSERight(arr);
        long long sum = 0;
        for (int i = 0; i < size; i++) {
            int right = NSER[i] - i;
            int left = i - NSEL[i];
            sum += (long long)left * right * arr[i];
        }
        return sum;
    }

    vector<int> findNMELeft(vector<int>& arr) {
        int size = arr.size();
        vector<int> ans(size);
        stack<int> st;
        for (int i = 0; i < size; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> findNMERight(vector<int>& arr) {
        int size = arr.size();
        vector<int> ans(size);
        stack<int> st;
        for (int i = size - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = size;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    long long findMaxSum(vector<int> arr) {
        int size = arr.size();
        vector<int> NMEL = findNMELeft(arr);
        vector<int> NMER = findNMERight(arr);
        long long sum = 0;
        for (int i = 0; i < size; i++) {
            int right = NMER[i] - i;
            int left = i - NMEL[i];
            sum += (long long)left * right * arr[i];
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long minSumSubArr = findMinSum(nums);
        long long maxSumSubArr = findMaxSum(nums);
        long long sumSubArrRange = maxSumSubArr - minSumSubArr;
        return sumSubArrRange;
    }
};
