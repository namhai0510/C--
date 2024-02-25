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

ll n;
string s;
bool dp[maxn + 2][10];
int pr[maxn + 2][10];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> s;
    n = s.size();
    for (int i = 1; i <= n; ++i) {
    	for (int j = 0; j <= 7; ++j) pr[i][j] = -1;
    }
    
    s = '#' + s;
    dp[1][(s[1] - '0') % 8] = 1;
 
    for (int i = 2; i <= n; ++i) {
        dp[i][(s[i] - '0') % 8] = 1;
 
        for (int j = 0; j <= 7; ++j) {
            if (dp[i - 1][j]) {
                dp[i][(j * 10 + s[i] - '0') % 8] = 1;
                pr[i][(j * 10 + s[i] - '0') % 8] = j;
 
                dp[i][j] = 1;
                pr[i][j] = j;
            }
        }
    }
 
    for (int i = 1; i <= n; i++) {
        if (dp[i][0]) {
            string ans = "";
            int ci = i, cj = 0;
 
            while (1) {
                if (pr[ci][cj] == -1 || pr[ci][cj] != cj) {
                    ans = s[ci] + ans;
                }
 
                if (pr[ci][cj] == -1) break;
 
                cj = pr[ci][cj];
                ci--;
            }
 
            cout << "YES" << endl;
            cout << ans << endl;
            return 0;
        }
    }
 
    cout << "NO";
    return 0;
}

// https://codeforces.com/problemset/problem/550/C