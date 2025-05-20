/*
Leetcode: 3sum not threesome X
Given an array, find if the sum of three distinct elements is equal to target or not. You may assume the length of the array is bounded by 1000.

Input:
2
10 15
3 4 7 2 9 1 6 8 5 3
5 13
2 4 8 9 1

Output:
YES
YES
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    // Your logic here
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        int hi = n - 1, lo = 0;
        while (lo < i and i < hi)
        {
            int sum = a[hi] + a[i] + a[lo];
            if (sum > t)
                hi--;
            else if (sum < t)
                lo++;
            else
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Uncomment below if multiple test cases are needed:
    int t;
    cin >> t;
    while (t--)
        solve();

    // solve();
    return 0;
}