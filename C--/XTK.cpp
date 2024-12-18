#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

ll res = 1;
ll cnt[28];
string s;

int main() {
    nothing
    if (fopen("XTK.inp", "r")) {
        freopen("XTK.inp", "r", stdin);
        freopen("XTK.out", "w", stdout);
    }
    cin >> s;
    
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'a' + 1]++;
        if (cnt[s[i] - 'a' + 1] > 1) {
            res++;
            fill(cnt + 1, cnt + 27, 0); // Reset count for all characters
            cnt[s[i] - 'a' + 1]++;
        }
    }
    
    cout << res << endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
