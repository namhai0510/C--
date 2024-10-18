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

string s;
ll cnt[2][2], res[2];

void Process() {
	s = '#' + s;
	for (int i = 1; i < s.size(); ++i) {
		int x = s[i] - 'a';
		if (i % 2) {
			res[1] += cnt[1][x];
			res[0] += cnt[0][x];
			
			cnt[1][x]++;
		}
		else {
			res[0] += cnt[1][x];
			res[1] += cnt[0][x];
			
			cnt[0][x]++;
		}
	}
	
	res[1] += s.size() - 1;
	
	cout << res[0] << " " << res[1] << endl;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> s;
    
    Process();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/451/D
