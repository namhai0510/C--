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

ll n, m, ans = 0;
string s;
ll a[maxn + 2], b[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> m;
    cin >> s;
	
	s = '#' + s;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = a[i];
	}
	
	for (int time = 1; time <= m; ++time) {
		for (int i = 1; i <= n; ++i) {
			if (b[i] == 0) continue;
			
			b[i]--;
			
			if (s[i] == 'L') {
				 if (i == 1) b[n]++;
				 else b[i - 1]++;
			}
			else {
				if (i == n) b[1]++;
				else b[i + 1]++;
			}
		}
		
		for (int i = 1; i <= n; ++i) {
			if (b[i] > a[i]) b[i] = a[i];
		}
		
		for (int i = 1; i <= n; ++i) cout << b[i] << " ";
		cout << endl;
	}
	
	for (int i = 1; i <= n; ++i) ans += b[i];
	
	cout << ans << endl;
    return 0;
}
