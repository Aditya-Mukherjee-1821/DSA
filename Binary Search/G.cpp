/*
You are given an array containing n positive integers.
Your task is to divide the array into k subarrays so that the maximum sum in a subarray is as small as possible.

Input

The first input line contains two integers n and k: the size of the array and the number of subarrays in the division.
The next line contains n integers the contents of the array.

Output
Print one integer; the maximum sum in a subarray in the optimal division.

Example

Input:
1
5 3 
2 4 7 3 5

Output:
8

Sweep line technique
mid = 5, k = 3
3 2 1 2 3
3 2 | 1 2 | 3

mid = 5, k = 3
3 2 1 2 2
3 2 | 1 2 2 
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// sweep line technique
int check(vector<int> a, int k, int mid){
    int sum = 0, cnt = 0;
    for(int i = 0; i < a.size(); i++){
        if(sum + a[i] <= mid){
            sum += a[i];
        }
        else{
            cnt++;
            sum = a[i];
        }
    }
    cnt++; // considering the last batch
    if(cnt <= k) return 1;
    else return 0;
}

void solve()
{
    // Your logic here
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int lo = 0, hi = accumulate(a.begin(), a.end(), 0), ans = -1;
    while (lo <= hi)
    {
        int mid = (hi + lo) / 2;
        if (check(a, k, mid))
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
    int t;
    cin >> t;
    while (t--)
        solve();

    // solve();
    return 0;
}