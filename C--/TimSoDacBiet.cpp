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

ll n;
int P[maxn + 2];
vector<ll> Prime;

void Sieve() {
	memset(P, 1, sizeof(P));
	P[0] = P[1] = 0;
	
	for (int i = 2; i * i <= maxn; ++i) {
		if (P[i]) 
			for (int j = i * i; j <= maxn; j += i) P[j] = 0;
	}
	
	for (int i = 2; i <= maxn; ++i) if (P[i]) Prime.pb(P[i]);
}

bool Check(ll x) {
	ll ret = 0;
	
	while (x > 0) {
		ret += (x % 10) * (x % 10);
		x /= 10;
	}
	
	return (P[ret]);
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    Sieve();
    
    cin >> n;
    
    ++n;
    while (!Check(n)) ++n;
    
    cout << n << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
