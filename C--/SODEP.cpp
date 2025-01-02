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

const ll INF = 1e18 + 5;
const int SMALL = 1e3 + 5;
const int MAX_DIGITS = 18;

ll T, n, a[maxn], res, dp[MAX_DIGITS][2][1024];

void initialize() {
    nothing
    if (fopen("SODEP.inp", "r")) {
        freopen("SODEP.inp", "r", stdin);
        freopen("SODEP.out", "w", stdout);
    }
    cin >> T;
}

void extractDigits(ll num, int digits[], int &len) {
    len = 0;
    while (num > 0) {
        digits[len++] = num % 10;
        num /= 10;
    }
    reverse(digits, digits + len);
}

ll calculate(int pos, bool tight, int prevMask, int digits[], int len) {
    if (pos == len) {
        return prevMask != 0;
    }
    if (dp[pos][tight][prevMask] != -1) {
        return dp[pos][tight][prevMask];
    }

    ll res = 0;
    int limit = tight ? digits[pos] : 9;
    for (int digit = 0; digit <= limit; ++digit) {
        if (digit == 0 && prevMask == 0) {
            res += calculate(pos + 1, tight && (digit == limit), 0, digits, len);
        } else if ((prevMask & (1 << digit)) == 0) {
            res += calculate(pos + 1, tight && (digit == limit), prevMask | (1 << digit), digits, len);
        }
    }
    return dp[pos][tight][prevMask] = res;
}

ll countNumbers(ll num) {
    if (num == 0) return 0;
    int digits[MAX_DIGITS], len;
    extractDigits(num, digits, len);
    memset(dp, -1, sizeof(dp));
    return calculate(0, true, 0, digits, len);
}

ll findAnswer(ll A, ll B) {
    return countNumbers(B) - countNumbers(A - 1);
}

void solve() {
    while (T--) {
        ll A, B;
        cin >> A >> B;
        cout << findAnswer(A, B) << endl;
    }
}

int main() {
    initialize();
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
