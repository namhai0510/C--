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

string s;
ll a, b, c = 0, d = 1, n;
ll pf[maxn + 2];

void Input() {
	cin >> s >> a >> b;
	
	n = s.size();
}

void Process() {
	c = 0;
	for (int i = 0; i < n; ++i) 
		pf[i] = (c = (c * 10 + s[i]- 48) % a) || s[i + 1] == '0';
	
	c = 0;
	d = 1;
	for (int i = n - 1; i >= 1; --i, d = 10 * d  % b) {
		if (!(c = (c + (s[i] - 48) * d) % b) && !pf[i - 1]) {
			cout << "YES" << endl;
			for (int j = 0; j < i; ++j) cout << s[j];
			cout << endl;
			for (int j = i; j < n; ++j) cout << s[j];
			return;
		}
	}
	
	cout << "NO" << endl;
	return;
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

// https://codeforces.com/problemset/problem/490/C
