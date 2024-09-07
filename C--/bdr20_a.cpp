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

ll test;
ll n, x, ans = 0;

void Input() {
	cin >> n;
}

void Process() {
	if (n % 16 != 0) {
		cout << 0 << endl;
		return;
	}
	
	n /= 16;
	x = sqrtl(n);
	
	if (x * x != n) {
		cout << 0 << endl;
		return;
	}
	
	ans = 0;
    for (ll i = 1; i * i <= x; ++i) {
        if (x % i == 0) { 
            ++ans;
            if (i != x / i) ++ans;
        }
    }
    
    cout << ans << endl;
}


int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> test;
    
    while (test--) {
    	Input();
    	Process();
    }
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/bedao_r20_a
