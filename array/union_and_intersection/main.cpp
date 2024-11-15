#include<bits/stdc++.h>
using namespace std;
vector < int > sortedArray(vector < int > a, vector < int > b) {
    set<int> s;
    for(int i=0;i<a.size();i++){ //O(nlogn)
        s.insert(a[i]);
    }
    for(int i=0;i<b.size();i++){ //O(mlogn)
        s.insert(b[i]);
    }

    vector<int> result;
    for(auto &value:s){ //O(n1+n2) to return the answer
        result.push_back(value);
    }

    return result;
f
}

//Time complexity:O


int main() {
    // Read input
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    // Get the union of the two sorted arrays
    vector<int> result = sortedArray(a, b);

    // Print the result
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;}
