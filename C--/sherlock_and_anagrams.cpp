#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
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

ll q;
string s;

bool Check(int i, int j, int l) {
	char a[maxa + 2], b[maxa + 2];
	strncpy(&a[1], &s[i], l);
	strncpy(&b[1], &s[j], l);
	
	
	ll x[30], y[30], it = 1;
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	
	while (it <= l) {
		x[a[it] - 'a' + 1]++;
		++it;
	}
	it = 1;
	while (it <= l) {
		y[b[it] - 'a' + 1]++;
		++it;
	}
	
	for (it = 1; it <= 'z' - 'a' + 1; ++it) {
		if (x[it] != y[it]) return false;
	}
	
	return true;
}

void Solve() {
	ll cnt = 0;
	for (int leng = 1; leng < s.size(); ++leng) {
		for (int i = 1; i < s.size() - leng; ++i) {
			for (int j = i + 1; j < s.size() - leng + 1; ++j) {
				if (Check(i, j, leng) == 1) cnt++;
			}
		}
	}
	
	cout << cnt << endl;
}

int main() {
    nothing
    if (fopen("saa.inp", "r")) {
        freopen("saa.inp", "r", stdin);
        freopen("saa.out", "w", stdout);
    }
    cin >> q;
    while (q--) {
    	cin >> s;
    	s = '#' + s;
    	Solve();
    }
    return 0;
}
