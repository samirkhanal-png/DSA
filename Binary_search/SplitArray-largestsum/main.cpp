class Solution {
public:
    int findNumPartition(vector<int>& arr,int sumAllowed){
      int currentPart=0;
      int nPartitions=1;
      for(int i=0;i<arr.size();i++){
        if(currentPart+arr[i]>sumAllowed){ ////only create a new partition when the current one  exceeds the sum limit not when equal to the largest sumAllowed
            nPartitions++;
            currentPart=arr[i]; //when exceeds starting for the new one
        }
        else currentPart+=arr[i];
      }
      return nPartitions;
    }

    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            int nPartitions=findNumPartition(nums,mid);

            if(nPartitions<=k){
                ans=mid;
                high=mid-1; //no of students is within the limit but we want the minimum largest sum so that no of partitions is within the limit
            }
            else low=mid+1;
        }
        return ans;
    }
};
