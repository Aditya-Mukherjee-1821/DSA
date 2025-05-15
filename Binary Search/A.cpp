/*
Binary Search in 1D array
2 3 6 7 8 19 23 34 45  --> #9

s = 0, e = 9 - 1
mid = (s + e)/2

check? is mid == the index I am finding?
1. trim upper space = hi = mid - 1
2. trim lower space = lo = mid + 1

Binary Search in 2D array
2 3 5  6
6 7 8  9
8 9 10 11

find out the row which contains the key

hi_i and lo_i
mid_i = (hi_i + lo_i) / 2

mid_i row: x y z q ..... b a
if our key lies in the range x to a
if our key < x --> hi_i = mid_i - 1
if our key > a --> lo_i = mid_i + 1

first of all we define the row where we can possibly find our key

after that normal 1D binsearch
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    // Your logic here
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int hi = n - 1, lo = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (a[mid] == k)
        {
            cout << mid << endl;
            return;
        }
        else if (a[mid] > k)
        {
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << -1 << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Uncomment below if multiple test cases are needed:
    // int t; cin >> t; while (t--) solve();

    solve();
    return 0;
}