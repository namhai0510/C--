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

ll n, k, a[maxn], dp[maxn];

int main() {
    nothing
    if (fopen("LC_BAI03.inp", "r")) {
        freopen("LC_BAI03.inp", "r", stdin);
        freopen("LC_BAI03.out", "w", stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 0; i <= n + 5; i++) dp[i] = +oo;
    dp[0] = 0; dp[1] = a[1];
    for(int i = 2; i <= n + 1; i++) {
        for(int j = 1; j <= k; j++) {
            if(i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + a[i]);
            }
        }
    }
    
    cout << dp[n + 1];
    
    return 0;
}