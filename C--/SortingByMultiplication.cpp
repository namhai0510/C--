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
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

ll test;
ll n, a[maxn + 2];
ll cnt[2], ans;

void Input() {
	cin >> n;
	
	cnt[0] = cnt[1] = 0;
	ans = n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		
		if (i > 1 && a[i] <= a[i - 1]) cnt[0]++;
	}
}

void Process() {
	for (int i = 1; i <= n; ++i) {
		bool Mult = (i > 1);
		
		ans = min(ans, Mult + cnt[0] + cnt[1]);
		
		if (i + 1 <= n)
            cnt[0] -= (a[i] >= a[i + 1]);
        if (i >= 2)
            cnt[1] += (a[i - 1] <= a[i]);
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

// https://codeforces.com/problemset/problem/1861/D