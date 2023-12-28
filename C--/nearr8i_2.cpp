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

ll n, m, stage = 0, sum = 0;
ll st[maxn + 2], num[maxn + 2], l[maxn + 2], w[maxn + 2];

ll Calc(ll x, ll y) {
	return min({n - y + 1, y * 1LL, m - x + 1, x *1LL});
}
void PreCal() {
	// danh dau so thu tu cua lop, so phan tu, phan tu bat dau
	stage = (min(m, n) + 1) / 2;
    l[1] = m; w[1] = n;
    // (leng + width - 2) * 2
    for (int i = 1; i <= stage; ++i) {
    	ll res = max((l[i] + w[i] - 2) * 2, 1LL);
    	
    	st[i] = sum + 1; num[i] = res;
    	sum += res;
    	// cout << st[i] << " " << num[i] << endl;
    	l[i + 1] = l[i] - 2; w[i + 1] = w[i] - 2;
    }
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> m >> n;
    PreCal();
    
    // for (int i = 1; i <= m; ++i) {
    	// for (int j = 1; j <= n; ++j) {
    		// cout << Calc(i, j) << " ";
    	// }
    	// cout << endl;
    // }
    
    for (int i = 1; i <= m; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		ll type = Calc(i, j);
    		
    		if (j == type) {
    			// canh trai cua lop
    			cout << st[type] + (m - type + 1) - i << " ";
    		}
    		else if (i == type) {
    			// canh tren cua lop
    			cout << st[type] + l[type] - 1 + j - type << " ";
    		}
    		else if (n - j + 1 == type) {
    			// canh phai cua lop
    			cout << st[type] + l[type] + w[type] - 2 + i - type << " ";
    		}
    		else if (m - i + 1 == type) {
    			// canh duoi cua lop
    			cout << st[type] + 2 * l[type] + w[type]  - 3 + (n - type + 1) - j << " ";
    		}
    	}
    	cout << endl;
    }
    
    return 0;
}
