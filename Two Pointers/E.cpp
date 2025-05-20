/*
Given an array, find the following in lesser than O(n^2) time
      max       (|j - i| * min(a[i], a[j]))
1 <= i < j <= n

Input:
2
6
2 3 9 81 1 4
9
1 8 6 2 5 4 8 3 7

Output:
12
49

Explanation:
2 3 9 81 1 4
^          ^
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    // Your logic here
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // sort(a.begin(), a.end());
    int hi = n - 1, lo = 0, ans = -1e9;
    while (lo < hi)
    {
        int val = (abs(hi - lo) * min(a[lo], a[hi]));
        ans = max(val, ans);
        
        if(a[lo] < a[hi]) lo++;
        else hi--;
    }
    cout << ans << endl;
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