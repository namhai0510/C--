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

int n, res;
int a[maxn], dp[maxn], f[maxn], mp[maxn], vt[maxn];

int main() {
    nothing

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i] = f[i] = -oo;
    }
    
    for (int i = 1; i <= n; ++i) {
        int pos = mp[a[i] - 1];
        dp[i] = max(dp[i], dp[pos] + 1);
        mp[a[i]] = i;
        res = max(res, dp[i]);
    }
    
    res++;
    memset(mp, 0, sizeof mp);
    
    for (int i = n; i >= 1; --i) {
        int pos = mp[a[i] + 1];
        f[i] = max(f[i], f[pos] + 1);
        mp[a[i]] = i;
    }
    
    for (int i = 1; i <= n; ++i) {
        vt[a[i]] = i;
        int de = vt[a[i] - 2];
        if (de == 0) continue;
        res = max(res, dp[de] + f[i] + 1);
    }
    
    cout << res << endl;
    
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    
    return 0;
}
