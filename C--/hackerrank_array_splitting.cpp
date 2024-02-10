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

ll t, n, a[maxn + 2], ps[maxn + 2];

ll Counting(int l, int r) {
	if (l == r) return 0;
	
	ll S[3] = {0, 0, 0};
	S[1] = ps[r] - ps[l - 1];
	
	if (S[1] % 2) return 0;
	if (S[1] == 0) return r - l;
	
	int pos = l;
	
	while (S[2] < S[1] / 2) {
		S[2] += a[pos];
		pos++;
	}
	
	if (S[2] > S[1] / 2) return 0;
	
	// cout << l << " " << r << " " << pos - 1 << " " << S[1] << " " << S[2] << endl;
	return 1 + max(Counting(l, pos - 1), Counting(pos, r));
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    
    while (t--) {
    	cin >> n;

		ps[0] = 0;
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    		ps[i] = ps[i - 1] + a[i];
    	}
    	
    	cout << Counting(1, n) << endl;
    }
    return 0;
}

// https://www.hackerrank.com/challenges/array-splitting/problem?isFullScreen=true