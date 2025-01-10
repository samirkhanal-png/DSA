class Solution {
public:
    vector<int> findNSER(vector<int>& arr) {
        int size = arr.size();
        vector<int> ans(size);
        stack<int> st;

        for (int i = size - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = size; // Use size for "no element on the right"
            } else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> findNSEL(vector<int>& arr) {
        int size = arr.size();
        vector<int> ans(size);
        stack<int> st;

        for (int i = 0; i < size; i++) {
            while (!st.empty() && arr[st.top()] >=arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = -1; // Use -1 for "no element on the left"
            } else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> NSER = findNSER(arr);
        vector<int> NSEL = findNSEL(arr);
        int size = arr.size();
        int mod = (int)(1e9 + 7);

        long long total = 0; // Use long long to avoid overflow

        for (int i = 0; i < size; i++) {
            int left = i - NSEL[i];
            int right = NSER[i] - i;
            total = (total + (long long)left * right * arr[i]) % mod;
        }
        return (int)total;
    }
};
