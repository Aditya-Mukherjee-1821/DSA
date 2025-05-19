/*
Input:
1
15 7
1 2 2 2 4 5 6 7 7 7 9 20 20 100 120

Output:
7
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    // Your logic here
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // using binary search --> converting it into monotone space
    // function 1
    // lower_bound(x) --> first element's index which is lesser than equal to x
    cout << "Lower bound: " << lower_bound(a.begin(), a.end(), target) - a.begin() << endl;
    // function 2
    // upper_bound(x) --> first element's index which is strictly greater than x
    cout << "Upper bound: " << upper_bound(a.begin(), a.end(), target) - a.begin() << endl;
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