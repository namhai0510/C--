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

ll n, a[maxn + 2], b[maxn + 2], cnt = 0;
int main() {
    nothing
    if (fopen("GIDA.inp", "r")) {
        freopen("GIDA.inp", "r", stdin);
        freopen("GIDA.out", "w", stdout);
    }
    
    cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	
	sort (a + 1, a + 1 + n);
	sort (b + 1, b + 1 + n);
	
	ll i, j;
	i = j = 1;
	
	while (i <= n && j <= n) {
		if (b[i] > a[j])
		{
			cnt++;
			i++;
			j++;
		}
		else
		{
			i++;
		}
	}
	cout << cnt;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
