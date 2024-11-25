#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e18;
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

ll n, x;
ll cnt = 0;

void Sub1() {
	for (ll i = 1; i <= n; ++i) {
		ll tmp = sqrt(x * i);
		if (tmp * tmp == x * i) cnt++;
	}
	
	cout << cnt << endl;
}

void Sub2() {
	
}

void Sub3() {
	
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n >> x;
    
    if (n <= 1000000) Sub1();
    else if (x <= 1000000) Sub2();
    else Sub3();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.codedream.edu.vn/problem/tht22skhnb2
