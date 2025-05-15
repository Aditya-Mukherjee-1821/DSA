/*
OG arr is a sorted arr = [1, 2, 3, 4, 5]; [8, 67, 100, 221, 500]
rotated twice
OG arr = [4, 5, 1, 2, 3]; [221, 500, 8, 67, 100] ==> arr size O(10^9)

It has been asked to find how many times the arr has been rotated?

check on every element x: if a[i] <= a[n - 1] => a[i] --> 1 or if false change it to 0
[0, 0, 1, 1, 1]

e.g. ==> [1, 2, 3, 4, 5]
tranf space ==> [0, 0, 0, 0, 0]
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int check(vector<int> a, int n, int x){
    if(a[n - 1] >= x) return 1;
    else return 0;
}

void solve() {
    // Your logic here
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int lo = 0, hi = n - 1, ans = -1;
    while(lo <= hi){
        int mid = (hi + lo) / 2;
        if(check(a, n, a[mid])) { // => key == a[mid], here my key is always 1, bcoz i am finding 1st occ of 1
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    if(ans == -1) cout << 0 << endl;

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Uncomment below if multiple test cases are needed:
    // int t; cin >> t; while (t--) solve();

    solve();
    return 0;
}