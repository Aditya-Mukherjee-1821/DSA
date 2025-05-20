/*
Given an array of size 10^6. Find if the sum of two is equal to target or not.

Input:
2
10 13
3 4 7 2 9 1 6 8 5 3
5 10
2 4 8 9 1

1 2 3 3 4 5 6 7 8 9
^                 ^
1 2 3 3 4 5 6 7 8 9
  ^               ^
1 2 3 3 4 5 6 7 8 9
    ^             ^
1 2 3 3 4 5 6 7 8 9
      ^           ^
1 2 3 3 4 5 6 7 8 9
        ^         ^

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
    int hi = n - 1, lo = 0;
    while (lo < hi)
    {
        int sum = a[lo] + a[hi];
        if (sum < t)
            lo++;
        else if (sum > t)
            hi--;
        else
        {
            cout << "YES" << endl;
            return;
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