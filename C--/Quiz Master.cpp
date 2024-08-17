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

ll test, n, m;
ll cnt = 0, ans = +oo, res;
pair<ll, ll> a[maxn + 2];
ll fre[maxn + 2];
vector<ll> factors[maxn + 2];

void Init() {
	for (int i = 1; i <= maxn; ++i)
		for (int j = i; j <= maxn; j += i) factors[j].pb(i);
}

void Input() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i) cin >> a[i].fi, a[i].se = i;
	sort(a + 1, a + 1 + n);
	
	for (int i = 0; i <= m + 2; ++i) fre[i] = 0;
}

void Process() {
	ans = +oo;
	cnt = 0;
	
	ll l = 1;
	for (int r = 1; r <= n; ++r) {
		for (auto x : factors[a[r].fi]) {
            if (x > m) break;
            
            if (!fre[x]++) cnt++;
        }
        
        while (cnt == m) {
            res = a[r].fi - a[l].fi;
            if (res < ans) ans = res;
            
            for (auto x : factors[a[l].fi]) {
                if (x > m) break;
                
                if (--fre[x] == 0) cnt--;
            }
            
            l++;
        }
	}
	
	if (ans >= +oo) cout << -1 << endl;
	else cout << ans << endl;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    Init();
    cin >> test;
    
    while (test--) {
    	Input();
    	Process();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1777/C
