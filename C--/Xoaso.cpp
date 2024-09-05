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
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll test;
ll n, st[4 * maxn + 2], s[maxn + 2], e[maxn + 2], a[maxn + 2], cnt[maxn + 2], ans = 0, tmp = 0; 
vector<ll> b;

void Update(int id, int l, int r, int i, int v) {
    if (i < l || r < i) return;
    if (l == r) {
        st[id] += v;
        return;
    }
    int mid = (l + r) / 2;
    Update(id * 2, l, mid, i, v);
    Update(id * 2 + 1, mid + 1, r, i, v);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int Get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return max(Get(id * 2, l, mid, u, v), Get(id * 2 + 1, mid + 1, r, u, v));
}

void Clear() {
	b.clear();
	for (int i = 1; i <= 4 * n; ++i) st[i] = 0;
    for (int i = 1; i <= n; ++i) cnt[i] = e[i] = s[i] = 0;
}

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
    	cin >> a[i], b.pb(a[i]);
    
    b.pb(-oo);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        cnt[a[i]]++;
        e[a[i]] = max(e[a[i]], i * 1LL);
        if (s[a[i]] == 0) s[a[i]] = i;
    }
}

void Process() {
    ans = 0;
    for (int i = 1; i < b.size(); i++) {
        tmp = Get(1, 1, n, 1, s[i] - 1) + cnt[i];
        ans = max(ans, tmp);
        Update(1, 1, n, e[i], tmp);
    }
    cout << ans << endl;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }

    cin >> test;
    
    while (test--) {
        Input();
        Process();
        Clear();
    }
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
