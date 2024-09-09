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

ll n, a[maxn + 2], cnt = 0;
map<ll, ll> mp;

ll ret = 1;

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mp[a[i]]++;
		
		ret &= (mp[a[i]] <= 2);
	}
	sort(a + 1, a + 1 + n);
}

void Process() {
	cnt = 0;
	for (auto val : mp) cnt += (val.se >= 2);
	
	ret &= (cnt <= 1);
	
	for (auto val : mp) {
		if (val.se == 2) {
			ret &= (mp.count(val.fi - 1) == 0);
			if (val.fi == 0) ret = 0;
		}
	}
	
	if (!ret) {
		cout << "cslnb" << endl;
		return;
	}
	
	ret = 0;
	for (int i = 1; i <= n; ++i) ret += a[i] - (i - 1);
	ret %= 2;
	
	if (ret) cout << "sjfnb" << endl;
	else cout << "cslnb" << endl;
	
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    Input();
    Process();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1190/B
