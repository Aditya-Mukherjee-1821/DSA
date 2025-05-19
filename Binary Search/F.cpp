/*
Binary search on answers
min of max
max of min
min
max

There are n machines and the total number of products to be made is t. There are different time requirements of every machine to complete a task. You can schedule tasks simultaneously and freely decide which machine is alloted which task. Calculate the minimum amount of time required to complete all tasks.

Input:
1
3 7
3 2 5

Output:
8
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int check(vector<int> &a, int mid, int t){
    // what do we need to check now?
    // each machine no gets some time = mid
    // we will check how many tasks each machine can do in that time
    // then we'll sum the tasks of all machines and see it is >= t
    int sum = 0;
    for(int i = 0; i < a.size(); i++){
        sum += (mid / a[i]);
    }
    return sum >= t;
}

void solve() {
    // Your logic here
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    // define our lo and hi pointer vals
    int lo = 0, hi = t * *(max_element(a.begin(), a.end())), ans = -1;
    while(lo <= hi){
        int mid = (hi + lo) / 2;
        if(check(a, mid, t)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }

    cout << ans << endl;
}

// void solve_using_for_loop(){
//     int n, t;
//     cin >> n >> t;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++) cin >> a[i];
//     int lo = 0, hi = t * *(max_element(a.begin(), a.end())), ans = -1e9;
//     for(int i = lo; i <= hi; i++){
//         int sum = 0;
//         for(int machine = 0; machine < a.size(); machine++){
//             sum += (i / a[machine]);
//         }
//         if(sum >= t){
//             cout << i << endl;
//             break;
//         }
//     }
// }

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Uncomment below if multiple test cases are needed:
    int t; cin >> t; while (t--) solve();
    // int t; cin >> t; while (t--) solve_using_for_loop();

    //solve();
    return 0;
}