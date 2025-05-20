/*
Given a string s and t. Find if t is a subsequence of s or not. 

Input: 
3
aabcdfgh acdf
abacbcbde abbe
acdegh acb

Output:
YES
YES
NO
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    // Your logic here
    string s, t;
    cin >> s >> t;
    int i = 0, j = 0;
    while(i < s.size() and j < t.size()){
        if(s[i] == t[j]){
            j++;
            i++;
        }
        else i++;
    }
    if(j >= t.size()) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Uncomment below if multiple test cases are needed:
    int t; cin >> t; while (t--) solve();

    //solve();
    return 0;
}