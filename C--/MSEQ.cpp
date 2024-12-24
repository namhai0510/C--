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

ll n, m, res = 0;
int main() {
    nothing
    if (fopen("MSEQ.inp", "r")) {
        freopen("MSEQ.inp", "r", stdin);
        freopen("MSEQ.out", "w", stdout);
    }
    cin >> n >> m;

    vector<int> cnt(m, 0);

    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        ll mod_val = ((a % m) + m) % m;
        cnt[mod_val]++;
    }
    if (cnt[0] > 0) res++;

    for (int i = 1; i <= m / 2; ++i) {
        if (i == m - i) {
            if (cnt[i] > 0) res++;
        } else {
            res += max(cnt[i], cnt[m - i]);
        }
    }

    cout << res << endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
