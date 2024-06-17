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
const int maxn = 3e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ull test, n, k, P[maxn + 2], num = 0;
ull res = 0, prod = 1;
bool ok = 0;

bool Prime[maxn + 2];
void Init() {
	memset(Prime, 1, sizeof(Prime));
	Prime[0] = Prime[1] = 0;
	
	for (int i = 2; i * i <= maxn; ++i) {
		if (Prime[i]) {
			for (int j = i * i; j <= maxn; j += i) Prime[j] = 0;
		}
	}
	
	num = 0;
	for (int i = 2; i <= maxn; ++i) {
		if (Prime[i]) {
			num++;
			P[num] = i;
		}
	}
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
    	cin >> n >> k;
    	
    	res = 0;
    	
    	for (int i = 1; i <= num - k + 1; ++i) {
    		ok = 1;
    		prod = 1;
    		for (int j = i; j <= i + k - 1; ++j) {
	            if (prod > n / P[j]) {
	                ok = 0;
	                break;
	            }
	            
	            prod *= P[j];
	        }

	        if (ok && prod <= n && prod > res) res = prod;
    	}
    	
    	if (res == 0) cout << -1 << endl;
    	else cout << res << endl;
    }
    
    return 0;
}

// https://oj.vnoi.info/problem/c11pnum
