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
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, m, C[maxa][maxa], dp[maxa][maxa], pre[maxa][maxa];


void TruyVet(int i, int j) {
    if (j == 1) {
        cout << i << endl;
        return;
    }
    int k = pre[i][j];
    TruyVet(k, j - 1);
    cout << i - k << endl;
}

int main() {
    nothing
    // if (fopen("messages.inp", "r")) {
        freopen("messages.inp", "r", stdin);
        freopen("messages.out", "w", stdout);
    // }
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> C[i][j];
            dp[i][j] = +oo;
        }
        dp[i][1] = C[i][1];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            for(int k = 0; k <= i; k++) {
                if (dp[i][j] > C[i - k][j] + dp[k][j - 1]) {
                    dp[i][j] = C[i - k][j] + dp[k][j - 1];
                    pre[i][j] = k; 
                    // Khi truyen i goi tin tren j kenh truyen thi cac kenh truyen tu 1..j - 1 se truyen 
                    // tong so k goi tin
                }
            }
        }
    }
    
    ll ans = +oo;
    for (int j = 1; j <= m; j++) {
        ans = min(ans, dp[n][j]);
    }
    cout << ans << endl;
    TruyVet(n, m);
}