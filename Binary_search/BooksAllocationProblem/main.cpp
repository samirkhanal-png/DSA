int findStudents(vector<int>&arr,int pagesAllowed){
   int noStu=1;
   int currPages=0;
   for(int i=0;i<arr.size();i++){
         if(currPages+arr[i]<=pagesAllowed){
             currPages+=arr[i];
         }
         else{
             currPages=arr[i];
             noStu++;
         }
   }
   return noStu;
}

int findPages(vector<int>& arr, int n, int m) {
if(m>n)return -1;
int low=*max_element(arr.begin(),arr.end());
int high=accumulate(arr.begin(),arr.end(),0);
int ans=-1;
while(low<=high){
    int mid=low+(high-low)/2;
    int noStu=findStudents(arr,mid);
    if(noStu<=m){ //jun sign xa tei anusar page limit xa(just for remembereance shortcut)
        ans=mid;   //also i want the minimum page limit among all the valid limits so decreasing the page
        high=mid-1;   //decreasing the page so that no of students can be increased
    }
    else low=mid+1;  //increasing the pages so that no of Students can decrease
}
  return ans;
}

/* Time Complexity:O log(sumof(arr)-max(arr))*/
/*
Actually this problem is split the array into m or less than m subarrays such
that (maximum subarray sum) is minimum among all the possible cases where
the no of partitions is equal to m or less than m.

We want to find the least of all (maximum sum of subarrays) among all valid partitions

Books Allocation Problem

Allocate books in such a way that the maximum no of pages assigned to a
student is minimum.

noOfStudents<=m

Only one student can hold the pages upto the page limit.


if allocation is not possible return -1

25 | 46 | 28 | 49 24  =>sum=73

25 |46  28 | 49 | 24  =>sum=74

25 | 46 | 28 49 |24   =>sum=77

25 46 | 28 | 49 |24   =>sum=71

arr[]={25,46,28,49,24}
noStu=4

Even to hold 1 book min  24 pages should be the page limit for a student.

Max(49) All the books held at least for once.(but could be within the limit or exceed the limit of students)
1->25
2->46 (46+28>70)
3->28
4->49 (28+49>70)
5->24 (49+24>70)

greater than required so lets increase the page limit

Worst Case Scenario(Max possible case)
**************************************
Sum of all the pages then all books can be allocated to a single person.

If page limit is small more students are required to hold the book.

If page limit is more then less students are required to hold the book.

if less student required=>make page limit small

if more students required=>make page limit more

if no of Stu<=actualNo
ans=mid;    // we want the maximum page limit such that no of students is within the limit
high=mid-1;

if noofStu>actualNo  //if no of students is greater then page limit is increased so that no of students can be decreased within limit
low=mid+1

low started at (may be possible or may be not possible zone)

High started at possible zone

so at last low will point at the answer

Confusion cleared
 noStu < m
If noStu is less than m, it means that the page limit (mid) is large enough that fewer students are needed to allocate all the books. This is also valid because the problem doesn't insist that exactly m students must get books. It only requires that no more than m students are used.

*/
