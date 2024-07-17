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

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

template<class X, class Y>
bool maximize(X &x, const Y &y) {
    if (x < y) {
        x = y; 
        return true;
    } else return false;
}

template<class X, class Y>
bool minimize(X &x, const Y &y) {
    if (x > y) {
        x = y; 
        return true;
    } else return false;
}

const int MAX = 10001000;
const int MOD = (int)1e9 + 7;

int add(int x, int y) {
    return x + y >= MOD ? x + y - MOD : x + y;
}

int sub(int x, int y) {
    return x - y < 0 ? x - y + MOD : x - y;
}

int n, k, delta, best[MAX], cnt[MAX], sum[MAX], limit[MAX];
bool removed[MAX];

void init() {
    cin >> n >> k >> delta;
    REP(ahihi, k) {
        int x; cin >> x;
        removed[x] = true;
    }
}

void process() {
    int maxBest = 0, j = 0;
    FOR(i, 1, n) {
        if (removed[i]) {
            best[i] = -1;
            continue;
        }
        while (j < i - delta - 1) maximize(maxBest, best[++j]);
        best[i] = maxBest + 1;
        maximize(limit[best[i]], i);
    }
    FOR(i, 1, n) maximize(maxBest, best[i]);

    FOR(i, 1, n) {
        if (removed[i]) cnt[i] = 0;
        else {
            if (best[i] == 1) cnt[i] = 1;
            else {
                int L = limit[best[i] - 2] + 1, R = limit[best[i] - 1];
                minimize(R, i - delta - 1);
                cnt[i] = sub(sum[R], sum[L - 1]);
            }
        }
        sum[i] = add(sum[i - 1], cnt[i]);
    }

    int res = 0;
    FOR(i, 1, n) if (best[i] == maxBest) res = add(res, cnt[i]);
    cout << maxBest << "\n" << res << "\n";
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    init();
    process();

    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
