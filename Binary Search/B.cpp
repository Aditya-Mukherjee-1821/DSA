/*
0 0 0 0 0 0 0 1 1 1 1
lo = 0
hi = 10
mid = 5 -> 0 < key --> low space trim => lo = mid + 1 = 6

lo = 6
hi = 10
mid = 8 -> 1 == key --> high space trim as well as store the current index in ans => hi = mid - 1

0 0 0 0 0 0 0 0 1 1 4 4 4 4
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n';

void solve()
{
    // Your logic here
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int lo = 0, hi = n - 1, ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (a[mid] == k)
        {
            ans = mid;
            hi = mid - 1;
        }
        else if(a[mid] > k){
            hi = mid - 1;
        }
        else lo = mid + 1;
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