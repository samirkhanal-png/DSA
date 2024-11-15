#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the maximum subarray sum and print the subarray
long long maxSubarraySum(vector<int> arr, int n) {
    long long maxSum = LLONG_MIN, currentSum = 0;
    int start = 0, end = 0, tempStart = 0;

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];

        /*
        if(currentSum==0){
        tempStart=i;
        }

        */

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i; //when the latest maximum subarray sum ends then that is the ending of the subarray
        } //when max is updated only it is greater than previous one

        if (currentSum < 0) {
            currentSum = 0;
            tempStart=i+1; //whenever the sum is 0 then the new index is the starting point
        }
    }

    // Print the subarray
    cout << "The subarray yielding the maximum sum is: ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return maxSum;
}

int main() {
    // Sample input
    vector<int> arr = {1, 2, 7, -4, 3, 2, -10, 9, 1};
    int n = arr.size();

    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}
