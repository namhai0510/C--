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
const int maxa = 1e3;
const int base = 31;

ll test, n;
ll dp[maxa + 2];

void Init() {
	dp[1] = 4;
	dp[2] = 7;
	
	for (int i = 3; i <= 1000; ++i) {
		if (i % 2 == 1) dp[i] = dp[i / 2] * 10 + 4;
		else dp[i] = dp[i / 2 - 1] * 10 + 7; 
	}
	
	// for (int i = 1; i <= 10; ++i) cout << dp[i] << " ";
	// cout << endl;
}

int main() {
    nothing
    if (fopen("FINDN.inp", "r")) {
        freopen("FINDN.inp", "r", stdin);
        freopen("FINDN.out", "w", stdout);
    }
    Init();
    
    cin >> test;
    
    while (test--) {
    	cin >> n;
    	
    	cout << dp[n] << endl;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
