#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
const int MOD = 1e9 + 7;
int dp[MAX];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }
    cout << dp[n];
    return 0;
}
