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

struct clb {
    ll a, b, c;
} x[maxn];

ll dp[maxn];

bool cmp1(clb a, clb b) {
    return a.c < b.c || (a.c == b.c && (a.a < b.a || (a.a == b.a && a.b < b.b)));
}

bool cmp2(clb a, clb b) {
    return a.c < b.c || (a.c == b.c && (a.b < b.b || (a.b == b.b && a.a < b.a)));
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }

    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i].a >> x[i].b >> x[i].c;
    }

    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + (i - 1);
    }

    sort(x + 1, x + 1 + n, cmp1);
    ll id = 1, cnt1 = 0, sum1 = 0;

    for (int i = 1; i <= n; i++) {
        if (x[i].c == 2) {
            id = i - 1;
            break;
        }
    }

    unordered_map<ll, ll> mp;
    x[0] = x[1];
    for (int i = 1; i <= id; i++) {
        if (x[i].a == x[i - 1].a) {
            cnt1++;
        } else {
            sum1 += dp[cnt1];
            for (auto it : mp) {
                sum1 -= dp[it.se];
            }
            if (sum1 < 0) sum1 = 0;
            cnt1 = 1;
            mp.clear();
        }
        mp[x[i].b]++;
    }

    sum1 += dp[cnt1];
    for (auto it : mp) {
        sum1 -= dp[it.se];
    }
    if (sum1 < 0) sum1 = 0;

    mp.clear();
    ll sum2 = 0, cnt2 = 1;

    for (int i = id + 1; i <= n; i++) {
        mp[x[i].b]++;
        if (x[i].a == x[i + 1].a) {
            cnt2++;
        } else {
            sum2 += dp[cnt2];
            for (auto it : mp) {
                sum2 -= dp[it.se];
            }
            if (sum2 < 0) sum2 = 0;
            cnt2 = 1;
            mp.clear();
        }
    }

    sum2 += dp[cnt2];
    for (auto it : mp) {
        sum2 -= dp[it.se];
    }
    if (sum2 < 0) sum2 = 0;

    mp.clear();
    sort(x + 1, x + 1 + n, cmp2);
    ll cnt3 = 0, sum3 = 0;
    x[0] = x[1];

    for (int i = 1; i <= id; i++) {
        if (x[i].b == x[i - 1].b) {
            cnt3++;
        } else {
            sum3 += dp[cnt3];
            for (auto it : mp) {
                sum3 -= dp[it.se];
            }
            cnt3 = 1;
            if (sum3 < 0) sum3 = 0;
            mp.clear();
        }
        mp[x[i].a]++;
    }

    sum3 += dp[cnt3];
    for (auto it : mp) {
        sum3 -= dp[it.se];
    }
    if (sum3 < 0) sum3 = 0;

    mp.clear();
    ll sum4 = 0, cnt4 = 1;

    for (int i = id + 1; i <= n; i++) {
        mp[x[i].a]++;
        if (x[i].b == x[i + 1].b) {
            cnt4++;
        } else {
            sum4 += dp[cnt4];
            for (auto it : mp) {
                sum4 -= dp[it.se];
            }
            cnt4 = 1;
            if (sum4 < 0) sum4 = 0;
            mp.clear();
        }
    }

    sum4 += dp[cnt4];
    for (auto it : mp) {
        sum4 -= dp[it.se];
    }
    if (sum4 < 0) sum4 = 0;

    cout << sum1 + sum2 + sum3 + sum4 << endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
