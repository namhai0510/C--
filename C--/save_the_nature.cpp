#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 1e17 + 2;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll q, n, k, p[maxn + 2], pct[3], od[3];
bool can = 0;

bool cmp(ll a, ll b) {
	return a > b;
}

void Input() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	sort(p + 1, p + 1 + n, cmp);
	
	cin >> pct[1] >> od[1];
	cin >> pct[2] >> od[2];
	cin >> k;
	
	if (pct[1] < pct[2]) {
		swap(pct[1], pct[2]);
		swap(od[1], od[2]);
	}
}

bool Check(ll val) {
	ll x = 0, y = 0, xy = 0;
	ll res = 0;
	
	for (int i = 1; i <= val; ++i) {
		if (i % od[1] == 0 && i % od[2] == 0) xy++;
		else if (i % od[1] == 0) x++;
		else if (i % od[2] == 0) y++;
	}
	
	for (int i = 1; i <= val; ++i) {
		if (xy > 0) {
			res += p[i] * (pct[1] + pct[2]) / 100;
			xy--;
		}
		else if (x > 0) {
			res += p[i] * pct[1] / 100;
			x--;
		}
		else if (y > 0){
			res += p[i] * pct[2] / 100;
			y--;
		}
		else break;
	}
	
	return (res >= k);
}

ll Bs() {
	ll l = 0, r = n + 1, mid, ans = -1;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (Check(mid) == 1) {
			// cout << l << " " << r << " " << mid << endl;
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	
	return ans;
}
void Solve() {
	// cout << n << endl;
	// for (int i = 1; i <= n; ++i) cout << p[i] << " ";
	// cout << endl << k << endl;
	cout << Bs() << endl;
}

int main() {
    nothing
    if (fopen("save_the_nature.inp", "r")) {
        freopen("save_the_nature.inp", "r", stdin);
        freopen("sssave_the_natureout", "w", stdout);
    }
    cin >> q;
    while (q--) {
    	Input();
    	Solve();
    }
    return 0;
}
