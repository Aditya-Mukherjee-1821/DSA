/*
You are given an array of N integers. Find the length of the longest subarray with all distinct elements.

Input:
3
5
1 2 2 1 2
4
3 3 3 3
5
1 3 2 4 1

Output:
2
1
4

Explanation:
9
Itr: 1
3 2 1 1 2 5 4 1 2 max_len = -1e9, map = {()}
^
map = {(3 : 0)}, max_len = max(max_len, 0 - 0 + 1) ==> max_len = 1, j++
Itr: 2
3 2 1 1 2 5 4 1 2 max_len = 1, map = {(3 : 0)}
^ ^
map = {(3 : 0), (2 : 1)}, max_len = max(max_len, 1 - 0 + 1) ==> max_len = 2, j++
Itr: 3
3 2 1 1 2 5 4 1 2 max_len = 2, map = {(3 : 0), (2 : 1)}
^   ^
map = {(3 : 0), (2 : 1), (1 : 2)}, max_len = max(max_len, 12 - 0 + 1) ==> max_len = 3, j++
Itr: 4
3 2 1 1 2 5 4 1 2 max_len = 3, map = {(3 : 0), (2 : 1), (1 : 2)}
^     ^
map = {(3 : 0), (2 : 1), (1 : 2)}, i --> last_occurence[a[j]] + 1, drop all last_occurences from i to new i - 1


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
    int i = 0, j = 0, max_len = -1e9;
    unordered_map<int, int> last_occurence;
    while (j < n)
    {
        if (last_occurence.find(a[j]) == last_occurence.end())
        {
            // that means a[j] is unique
            // so add its occ in map
            // update the max_len
            last_occurence[a[j]] = j;
            max_len = max(max_len, j - i + 1);
            j++;
        }
        else
        {
            // then don't take risk
            // come to the last occurence of a[j] bhai
            // update i
            // remove all last occurences from i to new i - 1
            int p = i;
            i = last_occurence[a[j]] + 1;
            for (; p < i; p++)
            {
                last_occurence.erase(a[p]);
            }
            // last_occurence[a[j]] = j;
            // // update max_len
            // max_len = max(max_len, j - i + 1);
            // j++;
        }
    }

    cout << max_len << endl;
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