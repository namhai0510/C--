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

ll test;
ll n, x, y, cnt0 = 0, szx, szy, st;
ll a[maxn + 2];

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
}

void Process() {
	sort(a + 1, a + 1 + n);
	
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0) continue;
		
		st = i;
	}
	
	cnt0 = st - 1;
	
	x = y = 0;
	szx = szy = 1;
	
	x = x * 10 + a[st];
	st++;
	y = y * 10 + a[st];
	st++;
	
	
	while (cnt0 > 0) {
		if (szx >= szy) {
			x *= 10;
			szx++;
		}
		else {
			y *= 10;
			szy++;
		}
		
		cnt0--;
	}
	
	bool O = 1;
	for (int i = st; i <= n; ++i) {
		if (O) x = x * 10 + a[i];
		else y = y * 10 + a[i];
		
		O = !O;
	}
	
	cout << x + y << endl;
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
