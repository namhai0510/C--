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

ll n, p, sum;
pair<ll, ll> a[maxn + 2];
priority_queue<ll> q;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> p;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + 1 + n);
    
    for (int i = 1; i <= n; ++i) {
    	sum += a[i].se;
    	q.push(a[i].se);
    	if (a[i].fi * p < sum) {
    		sum -= q.top();
    		q.pop();
    	}
    }
    
    cout << q.size() << endl;
    
    return 0;
}
