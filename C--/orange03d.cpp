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

ll n, a[maxn + 2], ans = 0, max_a = maxn + 2;
bool check = 1;

bool cmp(ll a, ll b) {
	return a > b;
}

int main() {
    nothing
    if (fopen("orange03d.inp", "r")) {
        freopen("orange03d.inp", "r", stdin);
        freopen("orange03d.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    sort(a + 1, a + 1 + n, cmp);
	
	for (int i = 1; i <= n; ++i) {
		check = 1;
		for (int j = 3; j >= 1; --j) {
			if (a[i] + j == max_a + 2) {
				check = 0;
				break;
			}
		}
		
		if (check) {
			ans++;
			max_a = a[i] - 1;
		}
	}
	
	cout << ans << " ";
	
	ans = 0; max_a = maxa + 2;
	
	for (int i = 1; i <= n; ++i) {
        for (int j = 3; j >= 1; --j) {
            if (a[i] + j < max_a + 2) {
                ans++;
                max_a = a[i] + j - 2;
                break;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
