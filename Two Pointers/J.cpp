/*
Google OA

There is a n x m matrix. Choose one element from each row, such that
the (max - min) of numbers chosen is minimized.

Input:
2
3 4
2 5 7 6
2 3 8 9
2 3 9 3
2 2 
9 8 10
8 5 2
8 1 10

Explanation
(9 : 0), (8 : 0), (10 : 0), (8 : 1), (5 : 1), (2 : 1), (8 : 2), (1 : 2), (10 : 2)

First instance of 3 distinct elements
(1 : 2), (2 : 1), (5 : 1), (8 : 0), (8 : 1), (8 : 2), (9 : 0), (10 : 0), (10 : 2)

Second instance of 3 distinct elements
(1 : 2), (2 : 1), (5 : 1), (8 : 0), (8 : 1), (8 : 2), (9 : 0), (10 : 0), (10 : 2)
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