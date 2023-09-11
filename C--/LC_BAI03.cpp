#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 0x3f3f3f3f;
const ll mod = 1e9;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, a[maxn], cnt = 0;
map<ll, ll> mark;

void Sub3() {
	for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] % 2 - a[j] % 2 != 0) continue;
            ll it = lower_bound(a + 1, a + 1 + n, (a[i] + a[j]) / 2) - a;
            if (a[it] == (a[i] + a[j]) / 2 && mark[it] == 0) {
                mark[it] = 1;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    exit(0);
}
int main() {
    nothing
    if (fopen("LC_BAI03.inp", "r")) {
        freopen("LC_BAI03.inp", "r", stdin);
        freopen("LC_BAI03.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    
    if (n <= 3000) Sub3();
    
    return 0;
}