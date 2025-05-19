/*
Given an array, rotated n times to the right, aim is to find an element k in the array

Input:
5 6
8 9 5 6 7

Output:
3
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
    while (hi >= lo)
    {
        int mid = (hi + lo) / 2;
        // if left half is sorted
        if (a[mid] == k)
        {
            cout << mid << endl;
            return;
        }
        if (a[lo] <= a[mid])
        {
            // check if there is a possibility of finding k in the range a[0] to a[mid]
            if (a[0] <= k && k <= a[mid])
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        // if right half is sorted
        else
        {
            // check if there is a possibility of finding k in the range a[mid] to a[n]
            if (a[mid] <= k && k <= a[n - 1])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
    }
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