/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Input:
3
4 8
3 6 7 11
5 5
30 11 23 4 20
5 6
30 11 23 4 20

Output:
4
30
23
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int check(vector<int> &piles, int h, int mid)
{
    int time = 0, n = piles.size();
    for (int i = 0; i < n; i++)
    {
        // try to finish one pile and move to the next
        time += ceil(double(piles[i]) / mid);
    }

    if (time <= h)
    {
        // cout << "mid=" << mid << " " << time << endl;
        return 1;
    }
    else
        return 0;
}

void solve()
{
    // Your logic here
    int n, h;
    cin >> n >> h;
    vector<int> piles(n);
    for (int i = 0; i < n; i++)
        cin >> piles[i];
    int lo = 0, hi = 1e9, ans = -1;
    while (lo <= hi)
    {
        int mid = (hi + lo) / 2;
        if (check(piles, h, mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
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