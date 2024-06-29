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

ll n, sum = 0, num[12];
string s;

bool cmp (ll A, ll B) {
	return A > B;
}

int main() {
    nothing
    if (fopen("MATMA.inp", "r")) {
        freopen("MATMA.inp", "r", stdin);
        freopen("MATMA.out", "w", stdout);
    }
    cin >> s;
    
    n = s.size();
    s = '#' + s;
    
    for (int i = 1; i <= n; ++i) num[s[i] - '0']++, sum += s[i] - '0';
    
    if (num[0] == 0 || sum % 3 != 0) cout << -1;
    else {
    	for (int i = 9; i >= 0; --i)
    		for (int j = 1; j <= num[i]; ++j) cout << i;
    }
    
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/th_thpt_22_c
