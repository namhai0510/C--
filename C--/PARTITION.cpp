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
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll L, n, a[maxn + 2], sum = 0, ans = 0;

int main() {
    nothing
    if (fopen("PARTITION.inp", "r")) {
        freopen("PARTITION.inp", "r", stdin);
        freopen("PARTITION.out", "w", stdout);
    }
    cin >> L >> n;
    
	sum = 0;
	priority_queue<ll, vector <ll>, greater <ll>> p;
	
	for (int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
	sort(a + 1, a + 1 + n);
	
	if (sum != L){
		n++; 
		a[n] = L - sum;
	}
	
	for (int i = 1; i <= n; ++i) p.push(a[i]);
	while (p.size() > 1) {
		ll u, v;
		u = p.top(); 
		p.pop();
		v = p.top(); 
		p.pop();
		
		ans += u + v;
		p.push (u + v);
	}
	
	cout << ans << endl;
    return 0;
}
