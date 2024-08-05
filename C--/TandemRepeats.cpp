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

ll test, n, cnt = 0, ans = 0;
string s;

void Process() {
	ans = 0;
	n = s.size();
	
	for (int i = n / 2; i >= 0; --i) {
		cnt = 0;
		
		for (int j = 0; j < n - i; ++j) {
			if (s[j] != '?' && s[j + i] != '?' && s[j] != s[j + i]) cnt = 0;
			else {
				cnt++;
				
				if (cnt == i) {
					ans = i * 2;
					break;
				}
			}
		}
		
		if (ans) break;
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
		cin >> s;
		Process();
	}    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1948/D
