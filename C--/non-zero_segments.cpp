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

ll n, a[maxn + 2], S = 0, ans = 0;
map<ll, ll> mark;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	S += a[i];
    	
    	if (S == 0 || mark[S] == 1) {
    		ans++;
    		mark.clear();
    		S = a[i];
    	}
    	mark[S] = 1;
    }
    
    cout << ans << endl;
    
    return 0;
}

// https://codeforces.com/problemset/problem/1426/D
