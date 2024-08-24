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

ll n, m, l[maxn + 2];
ll suf[maxn + 2];
void Input() {
	cin >> n >> m;
	
	for (int i = 1; i <= m; ++i) cin >> l[i];
}

void Process() {
	for (int i = 1; i <= m; ++i)
		if (l[i] + i - 1 > n) {
			cout << -1 << endl;
			return;
		}
	
	for (int i = m; i >= 1; --i)
		suf[i] = suf[i + 1] + l[i];
		
	if (suf[1] < n) {
		cout << -1 << endl;
		return;
	}
	
	for (int i = 1; i <= m; ++i) {
		cout << max(i * 1LL, n - suf[i] + 1) << " ";
	}
	cout << endl;
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

// https://codeforces.com/problemset/problem/1329/A
