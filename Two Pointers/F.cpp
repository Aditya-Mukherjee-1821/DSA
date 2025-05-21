/*
Find number of subarrays having number of distinct elements less than k

Input:
5
3 2
1 2 3
3 2
3 2 2
5 0
2 1 0 4 0
7 3
1 2 1 0 1 0 2
10 5
1 0 7 1 10 2 4 10 1 3

Output:
5
6
0
28
46

Explanation
13 4
2 4 5 5 1 2 4 1 9 0 0 1 8

2 4 5 5 1 2 4 1 9 0 0 1 8, cnt = 0, map = {}
^
map = {(2 : 1)} --> unique keys = 1 < 4 --> cnt = 1 --> j++

2 4 5 5 1 2 4 1 9 0 0 1 8, cnt = 1, map = {(2 : 1)}
^ ^
map = {(2 : 1), (4 : 1)} --> unique keys = 2 < 4--> cnt = 2 --> j++

2 4 5 5 1 2 4 1 9 0 0 1 8, cnt = 2, map = {(2 : 1), (4 : 1)}
^   ^
map = {(2 : 1), (4 : 1), (5 : 1)} --> unique keys = 3 < 4 --> cnt = 3 --> j++

2 4 5 5 1 2 4 1 9 0 0 1 8, cnt = 3, map = {(2 : 1), (4 : 1), (5 : 1)}
^     ^
map = {(2 : 1), (4 : 1), (5 : 2)} --> unique keys = 3 < 4 --> cnt = 4 --> j++

2 4 5 5 1 2 4 1 9 0 0 1 8, cnt = 4, map = {(2 : 1), (4 : 1), (5 : 2)}
^       ^
map = {(2 : 0), (4 : 1), (5 : 2), (1 : 1)} --> unique keys = 4 < 4 --> i++

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    // Your logic here
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int i = 0, j = 0, cnt = 0;
    unordered_map<int, int> freq;
    if (k == 0)
    {
        cout << 0 << endl;
        return;
    }
    while (j < n)
    {
        // I am trying to add the j-th element
        if (freq.find(a[j]) != freq.end())
        {
            // then the j-th element is not unique
            // increement the frequency of element
            // increase window/subarray size
            freq[a[j]]++;
            cnt += (j - i + 1);
            j++;
        }
        else
        {
            // then the j-th element is unique
            if (freq.size() + 1 <= k)
            {
                freq[a[j]]++;
                cnt += (j - i + 1);
                j++;
            }
            else
            {
                // then the j-th element is not unique
                // decreement the frequency of i-th element
                freq[a[i]]--;
                if (freq[a[i]] == 0)
                    freq.erase(a[i]);
                i++;
            }
        }
    }

    cout << cnt << endl;
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