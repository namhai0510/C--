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

ll n, x[maxn + 2];
vector<ll> ans;

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> x[i];
}

void Process() {
	sort(x + 1, x + 1 + n);
	ans = {x[1]};
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 32; ++j) {
			ll L = x[i] - (1 << j);
			ll R = x[i] + (1 << j);
			
			bool existL = binary_search(x + 1, x + 1 + n, L);
			bool existR = binary_search(x + 1, x + 1 + n, R);
			if (existL && existR && ans.size() < 3)
				ans = {L, x[i], R};
			
			if (existL && ans.size() < 2)
				ans = {L, x[i]};
			
			if (existR && ans.size() < 2)
				ans = {x[i], R};
		}
	}
	
	cout << ans.size() << endl;
	for (auto val : ans) cout << val << " ";
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

// https://codeforces.com/problemset/problem/988/D
