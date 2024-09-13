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

ll n, x, y;
ll a[maxn + 2], fct[maxn + 2], cnt = 0;
map<ll, ll> mp;

void Sieve() {
	fct[0] = 0;
	for (int i = 1; i <= maxn; ++i) fct[i] = i;
	
	for (int i = 2; i * i <= maxn; ++i)
		if (fct[i] == i)
			for (int j = i * i; j <= maxn; j += i) 
				if (fct[j] == j) fct[j] = i;
}

void Input() {
	cin >> n >> x >> y;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
}

void Process() {
	for (int i = 1; i <= n; ++i)
		if (fct[a[i]] == a[i] && a[i] >= x && (a[i] - x) % y == 0) cnt++;
	
	cout << cnt << endl;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    Sieve();
    Input();
    Process();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
