/*
bitonic array --> first is strictly increasing and then strictly decreasing
bitonic arr = [1, 2, 3, 6, 5, 2] --> 0, 1s array
find the peak element

a[i] >= a[i + 1] --> yes then 1 else 0 

0 0 0 1 1

e.g. 1 2 3 4 5 --> 0 0 0 0 1

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int check(vector<int> a, int n, int x)
{
    if (x == n - 1)
        return 1;
    if (a[x] > a[x + 1])
        return 1;
    else
        return 0;
}

void solve()
{
    // Your logic here
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int lo = 0, hi = n - 1, ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(a, n, mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    cout << ans << endl;
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