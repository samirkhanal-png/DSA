#include <iostream>
#include <vector>
using namespace std;

int main()
{   int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int flag=1;
    for(int i=1;i<n;i++)
    {if(arr[i]<arr[i-1]){    //Traversing from second index to the last and checking if previous one is greater than the current one
        flag=0;
        break;
    }}

    if(flag==1) cout<<"Sorted"<<endl;
    else cout<<"Not Sorted"<<endl;

    return 0;
}
