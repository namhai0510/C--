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

ll n, k, cnt = 0;
bool P[maxn + 2];

void Sieve() {
	memset(P, 1, sizeof(P));
	
	P[0] = P[1] = 0;
	for (int i = 2; i * i <= maxn; ++i) {
		if (P[i])
			for (int j = i * i; j <= maxn; j += i) P[j] = 0;
	}
}
int main() {
    nothing
    if (fopen("PAIR.inp", "r")) {
        freopen("PAIR.inp", "r", stdin);
        freopen("PAIR.out", "w", stdout);
    }
    Sieve();
    
    cin >> n >> k;
    
    for (int i = 2; i <= n - k; ++i) {
    	// cout << i << " " << i + k << " " << P[i] << " " << P[i + k] << endl;
    	if (i + k <= n && P[i] == 1 && P[i + k] == 1) cnt++;
    }
    
    cout << cnt << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
