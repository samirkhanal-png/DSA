class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
    }
    
    int next(int price) {
        int spanVal=1;
        while(!st.empty()&&st.top().first<=price){
            st.pop();
            spanVal+=(st.top().second);
        }
        st.push({price,spanVal});
        return spanVal;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

 /*
 Input:100,80,60,70,60,75,85
 Output:1,1,1,2,1,4,6

 We must have past information. In such case stack helps

 85,5
 75,4 *
 60,1
 70,2   monotonic decreasing (here increased so popping and it stores the spanVal in it for elements less than it for future smaller elements greater than it)
 60,1 *
 80,1 *
 100,1

 Optimal Solution
 TC:O(n)
 SC:O(n)

 */

list<int>ans;
for(int i=0;i<size;i++)
{int cnt=1;
 int j=i-1;
 while(arr[j]<=arr[i])&&j>=0){
   cnt++;
   j--;
 }
 ans.add(cnt);
 return ans;
}
