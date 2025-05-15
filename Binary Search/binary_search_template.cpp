/*
solution for the problems --> 

1. find the first occurence of 1
0 0 0 0 1 1 1 1

2. find the first occurence of 4
1 2 2 3 3 3 3 4 4 6 7 7
=> convert it into 0s and 1s
a[mid] >= k

3. find the number of times array has been rotated
1 2 3 4 5 6 => 6 5 1 2 3 4
=> trace the index of 1
=> convert it into 0s and 1s
a[n - 1] >= a[mid]

4. find the peak of an element
2 3 5 9 4 3 1
a[mid] > a[mid + 1]

***NOTE
we do use the check function, as if we would want to make the array by converting it into 0s and 1s
*/

#include <bits/stdc++.h>
using namespace std;

// check 1
// int check(int mid, vector<int> a, int k)
// {
//     if (a[mid] == k)
//         return 1;
//     else
//         return 0;
// }

//check 2
// int check(int mid, vector<int> a, int k)
// {
//     if (a[mid] >= k)
//         return 1;
//     else
//         return 0;
// }

//check 3
// int check(int mid, vector<int> a, int n)
// {
//     if (a[n - 1] >= a[mid])
//         return 1;
//     else
//         return 0;
// }

//check 4
int check(int mid, vector<int> a)
{
    // how would the array look if the last element was the peak
    if(mid == a.size() - 1) return 1; 
    if (a[mid] >= a[mid + 1])
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
        cin >> a[i];
    int low = 0, high = n - 1, ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(mid, a) == 1)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    // if(ans == -1) cout << 0 << endl; // check for problem 3
    if(ans == -1) cout << n - 1 << endl; // check for problem 4
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Uncomment below if multiple test cases are needed:
    int t; cin >> t; while (t--) solve();

    // solve();
    return 0;
}