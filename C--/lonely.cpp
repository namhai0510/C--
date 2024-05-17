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
const int base = 31;

ll n, l[maxn + 2], r[maxn + 2];
string s;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
	cin >> n;
	cin >> s;

	int p = 1;
	for(int i = 1 ; i < n; i++){
		if(s[i] == s[i-1]) {
			l[i] = 0;
			p++;
		}
		else{
			l[i] = p;
			p = 1;
		}
	}
	p = 1;
	for(int i = n - 2 ; i >= 0; --i){
		if(s[i] == s[i + 1]) {
			r[i] = 0;
			p++;
		}
		else{
			r[i] = p;
			p = 1;
		}
	}
	ll ans = 0;
	
	for (int i = 0; i < n; ++i) {
		ans += l[i] * r[i];
		if (l[i] > 0)
			ans += l[i] - 1;
		if (r[i] > 0)
			ans += r[i] - 1;
	}
	cout << ans;
	
    return 0;
}
