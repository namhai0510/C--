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

struct Data {
	ll val, st, en;
};

ll n, m, k;
ll a[maxn + 2], b[maxn + 2], L[maxn + 2], R[maxn + 2];
vector<Data> pos, ans;

bool valid = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    
    int it = 1;
    while (it <= n) {
        int j = it;
        while (j <= n && b[j] == b[j + 1]) ++j;
        pos.pb({b[j], it, j});
        it = j + 1;
    }
    
    it = 0;
    for (int i = 1; i <= n; ++i) {
        int l = pos[it].st, r = pos[it].en;
        if (a[i] == pos[it].val) {
            if (i >= r) L[i] = l;
            else if (i <= l) R[i] = r;
            else if (i >= l && i <= r) {
            	L[i] = l;
            	R[i] = r;
            }
            
            ++it;
        }
        if (it == pos.size()) {
            valid = 1;
            break;
        }
    }
    
    if (valid == 0) {
        cout << -1 << endl;;
        return 0;
    }
	
	for (int i = 1; i <= n; ++i) {
        if (!L[i] || L[i] == i) continue;
        ans.pb({2, L[i], i});
    }
    for (int i = n; i >= 1; --i) {
        if (!R[i] || R[i] == i) continue;
        ans.pb({1, i, R[i]});
    }
    
    cout << ans.size() << endl;
    for (auto it : ans) cout << it.val << " " << it.st << " " << it.en << endl;

    return 0;
}
