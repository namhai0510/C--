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

ll n, ans = 0;
pair<ll, ll> x[maxn + 2];
priority_queue<ll, vector<ll>, greater<ll>> p;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) cin >> x[i].fi;
    for (int i = 1; i <= n; ++i) cin >> x[i].se;
    
    sort(x + 1, x + 1 + n);
    
    for (int i = 1; i <= n; ++i) {
    	if (x[i].fi > p.size()) p.push(x[i].se);
    	else if (p.top() < x[i].se){
    		p.pop();
    		p.push(x[i].se);
    	}
    }
    
    while (p.size()) {
    	ans += p.top();
    	p.pop();
    }
    
    cout << ans << endl;
    
    return 0;
}

// https://oj.vnoi.info/problem/bedao_r18_c