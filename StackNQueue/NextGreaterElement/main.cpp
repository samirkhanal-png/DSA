class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
            auto pos=find(nums2.begin(),nums2.end(),nums1[i]);
            int index=distance(nums2.begin(),pos);
            for(int j=index+1;j<nums2.size();j++){
                if(nums2[j]>nums1[i]){
                    ans[i]=nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
};

/*
Time Complexity:O(N square)

Space Complexity:O(N)

Lets save time complexity

If we know the numbers right to it then we do not need to run the inner loop

For that we traverse from back and store all the previous elements in the stack

We compare the elements in array to the stack whichever is small we delete it since
it does not matter for the next elements and when we find the greater elements we stop
there and push it in the answer

This is a monotonic stack it stores the elements in particular order

3 1 2 4 SIX

3
1              From 1 to six in increasing order  but after 3 comes becomes decreasing so deleting those elements
2
4
SIX

Intuition comes from human eyes
                    i
                i   i
            i   i i i
 Human      i i i i i

 Cannot see the elements in middle does not matter

*/

class Solution {
public: //Just a little twist
    vector<int>greaterElements(vector<int>nums2){
        vector<int> ans(nums2.size());
        stack<int> s;
        s.push(-1);

        for(int i = nums2.size() - 1; i >= 0; i--){
            while(s.top() != -1 && nums2[i] > s.top()){
                s.pop();
            }
            ans[i] = s.top(); //storing from back
            s.push(nums2[i]);
        }
        return ans;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        vector<int>nextGreaterElementsArr(nums2.size());
        nextGreaterElementsArr=greaterElements(nums2);
        for(int i=0;i<nums1.size();i++){
            auto it=find(nums2.begin(),nums2.end(),nums1[i]);

            if(it!=nums2.end()){
                int index=distance(nums2.begin(),it);
                ans.push_back(nextGreaterElementsArr[index]);//same index has that nextGreater element
            }

        }
        return ans;
    }
};
