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
ll n, cntO[maxn + 2], cntL[maxn + 2], cntP[maxn + 2], r[4];
ll cnt = 0;

void Input() {
	cin >> s;
	
	n = s.size();
	s = '#' + s;
}

void Process() {
	for (int i = 1; i <= n; ++i) {
		cntO[i] = cntO[i - 1] + (s[i] == 'O');
		cntL[i] = cntL[i - 1] + (s[i] == 'L');
		cntP[i] = cntP[i - 1] + (s[i] == 'P');
	}
	cntO[n + 1] = cntL[n + 1] = cntP[n + 1] = +oo;
	
	for (int l = 1; l < n; ++l) {
		r[1] = lower_bound(cntO + l, cntO + 1 + n, cntO[l - 1] + 3) - cntO;
		r[2] = lower_bound(cntL + l, cntL + 1 + n, cntL[l - 1] + 3) - cntL;
		r[3] = lower_bound(cntP + l, cntP + 1 + n, cntP[l - 1] + 3) - cntP;
		
		// cout << l << " " << r[1] << " " << r[2] << " " << r[3] << endl;
		cnt += n - min({r[1], r[2], r[3]}) + 1;
	}
	
	cout << cnt << endl;
}
int main() {
    nothing
    if (fopen("BANGRON.inp", "r")) {
        freopen("BANGRON.inp", "r", stdin);
        freopen("BANGRON.out", "w", stdout);
    }
    
    Input();
    Process();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
