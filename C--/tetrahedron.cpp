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

ll n, ans = 1, tmp = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	ll tmpD = (tmp * 3LL) % modd;
    	ll tmpABC = (tmp * 2LL + ans) % modd;
    	
    	ans = tmpD;
    	tmp = tmpABC;
    	
    }
    
    cout << ans << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/166/E
