#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll n, a[maxn + 2];
ll ps[maxn + 2], ans = 0;
unordered_set<ll> s;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    ps[0] = 0;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	ps[i] = ps[i - 1] + a[i];
    }
    
    ll l = 1, r = 1;
    s.insert(0);
    
    while (l <= n) {
    	while (r <= n && !s.count(ps[r])) {
            ++r;
            s.insert(ps[r - 1]);
        }
        
        ans += r - l;
        s.erase(ps[l - 1]);
        ++l;
    }
    
    cout << ans << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/1333/C
