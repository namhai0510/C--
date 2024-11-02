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

ll n, Time, cur;
pair<ll, ll> a[maxn + 2];
priority_queue<ll> p;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n;
    
    for (int i = 1; i <= n; ++i) cin >> a[i].fi;
    for (int i = 1; i <= n; ++i) cin >> a[i].se;
    
    Time = a[1].se;
    p.push(a[1].se);
    
    for (int i = 2; i <= n; ++i) {
    	cur = p.top();
    	
    	if (Time <= a[i].fi) {
    		p.push(a[i].se);
    		Time += a[i].se;
    	}
    	else if (Time > Time - cur + a[i].se) {
            Time = Time - cur + a[i].se;
            p.pop();
            p.push(a[i].se);
        }
    }
    
    cout << p.size() << endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
