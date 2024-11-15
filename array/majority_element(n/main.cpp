#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mpp; //by default all the elements in map have its key value 0 i.e count=>0
        vector<int> list;
        int min=nums.size()/3+1;

        for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++; //increasing the count of the element in the hashmap when they are found

        if(mpp[nums[i]]==min){
          list.push_back(nums[i]);
        }

        if(list.size()==2) break;

        }
        return list;
    }
};

/*
Time Complexity:O(n)
We have to return all the elements that are appearing more than n/3 times.

At max, there will only be just 2 elements greater than n/3 because
suppose there are 9 elements
9/3=>3 so element must occur more than 3 times ie 4 times

//Note so break the for loop after 2 elements are found as majority

4+4=>8 so 2 elements can occur in majority and 1 elements in minority as it
is present only once.

appears more than n/3 means appears 1 times greater than n/3 times
int min=(n/3)+1
==(n/3)+1

When elements count becomes greater than min then no need to perform any operations on it after that since it is already considered as majority element.

Better=> O(n)

*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    int cnt1=0,cnt2=0,el1=INT_MIN,el2=INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(cnt1==0&&nums[i]!=el2){
            cnt1=1;
            el1=nums[i];
        }
        else if(cnt2==0&&nums[i]!=el1){
            cnt2=1;
            el2=nums[i];
        }
        else if(el1==nums[i]){
            cnt1++;
        }
        else if(el2==nums[i]){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }

    vector<int> ans;
    cnt1=0,cnt2=0;
    for(int i=0;i<nums.size();i++){
     if(el1==nums[i]) cnt1++;
     if(el2==nums[i]) cnt2++;
    }
     int mini=(int)(nums.size()/3)+1;
     if(cnt1>=mini) ans.push_back(el1);
     if(cnt2>=mini) ans.push_back(el2);
     sort(ans.begin(),ans.end());
     return ans;
    }
};

/*
Optimal solution:O(n)
Moores voting algorithm
For(n/3) there are only 2 majority elements

So apply moore's voting algorithm for 2 elements
 if(cnt1==0&&nums[i]!=el2){
            cnt1=1;
            el1=nums[i];
        }
        else if(cnt2==0&&nums[i]!=el1){
            cnt2=1;
            el2=nums[i];
        }

when we are resetting the el1 then it may take the element same to el2
and that will surely result in error so checking

*/

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

