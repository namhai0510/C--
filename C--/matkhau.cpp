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

ll n, ans = 0, a = 0, b = 0, c = 0;
string s;

int main() {
    nothing
    if (fopen("matkhau.inp", "r")) {
        freopen("matkhau.inp", "r", stdin);
        freopen("matkhau.out", "w", stdout);
    }
    cin >> s;
	n = s.size();
	ll l = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] >= '0' && s[i]<= '9') a++;
		if (s[i] >= 'a' && s[i]<= 'z') b++;
		if (s[i] >= 'A' && s[i]<= 'Z') c++;
		
		while (a > 0 && b > 0 && c > 0) {
			if (a + b + c < 6) break;
			
			ans += (n - 1 - i + 1);
			if (s[l] >= '0' && s[l] <= '9') a--;
			if (s[l] >= 'a' && s[l] <= 'z') b--;
			if (s[l] >= 'A' && s[l] <= 'Z') c--;
			l++;
		}
	}
	
	cout << ans << endl;
    return 0;
}
