/*
Given an array of N integers, find the length of the smallest sub-array that contains all the distinct elements of the array.

Input:
6
5
1 1 3 2 3
5
1 2 3 4 5
6
1 2 2 3 3 4
6
1 2 1 3 2 4
5
1 1 1 1 1
1
1

Output:
3
5
6
4
1
1

Explanation
8
2 1 2 1 3 1 3 3

2 1 2 1 3 1 3 3, len = -1e9, map = {()}
^
map = {(2 : 0)}, len = max(-1e9, 0 - 0 + 1) = 1, j++

2 1 2 1 3 1 3 3, len = 1, map = {(2 : 0)}
^ ^
map = {(2 : 0), (1 : 1)}, len = max(1, 1 - 0 + 1) = 2, j++
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    // Your logic here
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Uncomment below if multiple test cases are needed:
    int t; cin >> t; while (t--) solve();

    //solve();
    return 0;
}