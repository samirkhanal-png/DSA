#include <iostream>

using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     int left=0,right=0,index=0;
     int res[m+n];
     while(left<m&&right<n){ //till there exists both of the array we can compare and put in the merged array //even if one of the array is complete we cannot compare
         if(nums1[left]<=nums2[right]){
             res[index]=nums1[left];
             index++;
             left++;
         }
         else{
             res[index]=nums2[right];
             index++;
             right++;
         }
     }

     //if only one of the array is exhausted then the other one is remaining and it is in sorted form so storing it sequence wise inside the merged array

    while(left<m){ //If any of the array is not exhausted then storing it sequence wise without thinking anything
        res[index]=nums1[left];
        index++;
        left++;
    }

    while(right<n){
        res[index]=nums2[right];
        index++;
        right++;
    }

    for(int i=0;i<n+m;i++){  //since the return type is void so storing in the nums1 as said by the question
        nums1[i]=res[i];
    }

    }
};

/*
Time Complexity: O(n+m)+O(n+m) for sorting + for storing in nums1
Space complexity: O(n+M) for res array
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     int left=m-1,right=0;
     while(left>=0&&right<n){
        if(nums1[left]>nums2[right]){
            swap(nums1[left],nums2[right]);
            right++;
            left--;
        }
        else break;
     }
     sort(nums1.begin(),nums1.end());
     sort(nums2.begin(),nums2.end());

     for(int i=m;i<m+n;i++){
      nums1[i]=nums2[i-m];
     }
    }
};

/*
Optimal solution:
Time complexity:O(min(m,n)) + O(nlogn) + O(mlogm)
Either left or right(having minimum elements) will go false first and come out of while loop
rest is for sorting

We want to maintain all first m largest elements in the first array and all the elements greater
than the elements in the first array

Start with the largest of the first array and start with the smallest of the second array

If any element of the first array is bigger than the second array then swap

If any element of the second array is smaller or equal to the elements in the second array
then no need to check now since all the elements are in their correct place

Since both arrays are sorted
In the first array before this all the elements are either smaller or equal to this

In the second array after this all the elements are either equal or greater than this

Now sort both of them

space complexityO(1)
*/

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
