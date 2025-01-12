class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size=nums.size();
        vector<int>result;
        for(int i=0;i<size;i++){
            int maxi=nums[i];
            for(int j=i;j<i+k;j++){
                maxi=max(maxi,nums[j]);
            }
            result.push_back(maxi);
        }
        return result;
    }
};

/*
Brute Force Solution
TC:O(n*k)
SC:O(n)
*/


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>deq;
        vector<int>result;
        int size=nums.size();
        for(int i=0;i<size;i++){
            while(!deq.empty()&&deq.front()<=i-k){
                deq.pop_front();
            }

            while(!deq.empty()&&nums[i]>=nums[deq.back()]){
                deq.pop_back();
            }
          //we are at i so if i is the max in the current window we do not 
          //need min elements before it since i is already max for current window

//if i is the lesser than the element in the deq.back() because it can be max
//next time
            deq.push_back(i);

            if(i>=k-1)result.push_back(nums[deq.front()]);

        }
        return result;
    }
};

/*
//to be in window the index must be greater than i-k+1 so removing all the elements which are not in the window
*/
