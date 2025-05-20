/*
Given an array, pick three distinct indices, such that sum of the three is closest to target. Length of array is bounded by 1000. Print the sum that is closest to target.

Input:
1
5 3
5 3 4 1 2

Output:
6
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
    int diff = 1e9, closest = -1;
    for (int i = 0; i < n; i++)
    {
        int hi = n - 1, lo = 0;
        while (lo < i and i < hi)
        {
            int sum = a[hi] + a[i] + a[lo];
            if (abs(sum - t) < diff)
            {
                closest = sum;
                diff = abs(sum - t);
            }
            if (sum > t)
                hi--;
            else if (sum < t)
                lo++;
        }
    }
    cout << closest << endl;
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