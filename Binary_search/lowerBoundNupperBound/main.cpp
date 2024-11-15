#include <iostream>
#include <vector>

using namespace std;

// Function to find lower bound
int lb(vector<int>& arr, int n, int key) {
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= key) {
            ans = mid; // Store the index, not the value
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// Function to find upper bound
int ub(vector<int>& arr, int n, int key) {
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > key) {
            ans = mid; // Store the index, not the value
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {2, 3, 6, 7, 8, 8, 11, 11, 11, 12};
    int n = arr.size();

    int key1 = 6;
    int lb_index1 = lb(arr, n, key1);
    int ub_index1 = ub(arr, n, key1);

    cout << "For key = " << key1 << ":\n";
    cout << "Lower bound index = " << lb_index1 << ", Value = " << (lb_index1 != -1 ? arr[lb_index1] : -1) << endl;
    cout << "Upper bound index = " << ub_index1 << ", Value = " << (ub_index1 != -1 ? arr[ub_index1] : -1) << endl;

    int key2 = 11;
    int lb_index2 = lb(arr, n, key2);
    int ub_index2 = ub(arr, n, key2);

    cout << "\nFor key = " << key2 << ":\n";
    cout << "Lower bound index = " << lb_index2 << ", Value = " << (lb_index2 != -1 ? arr[lb_index2] : -1) << endl;
    cout << "Upper bound index = " << ub_index2 << ", Value = " << (ub_index2 != -1 ? arr[ub_index2] : -1) << endl;

    int key3 = 9;
    int lb_index3 = lb(arr, n, key3);
    int ub_index3 = ub(arr, n, key3);

    cout << "\nFor key = " << key3 << ":\n";
    cout << "Lower bound index = " << lb_index3 << ", Value = " << (lb_index3 != -1 ? arr[lb_index3] : -1) << endl;
    cout << "Upper bound index = " << ub_index3 << ", Value = " << (ub_index3 != -1 ? arr[ub_index3] : -1) << endl;

    return 0;
}


/*
***LowerBound******
lower_bound is the smallest index such that arr[ind]>=x
          0 1 2 3 4 5 6   7  8  9
eg:arr[]={2,3,6,7,8,8,11,11,11,12}

x=6 then index=3

x=11 then index=6 points to the first in case of duplicates

x=9 then points to 11 with index=11

lower_bound always points to the first element in case of duplicates

lb=lower_bound(arr.begin(),arr.end(),n)-arr.begin() #index of lower_bound

***Upperbound******
upper bound is the smallest index such that arr[ind]>x

in the same array

x=6 (points to 7) ind=3

x=11 ind=9 (pointing to 12)

See ub-1 points to the last element in case of duplicates

ub=upper_bound(arr.begin(),arr.end(),n)-arr.begin() #index of upper bounded elements

*/
