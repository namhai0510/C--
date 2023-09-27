#include<bits/stdc++.h>
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL);
using ll = long long;
using ull = unsigned long long;
#define in insert
#define fi first
#define se second
#define pb push_back
#define el "\n"
const ll oo = 1e9;
const ll mod = 998244353;
const int maxn = 1e6 + 5;
const int maxa = 5e3 + 8;
ll n, a[maxn][30];
ll dif = -oo, ans = -oo;
string s;
int main() {
    nothing
    if (fopen("clm.inp","r")) {
        freopen("clm.inp","r",stdin);
        freopen("clm.out","w",stdout);
    }
    cin >> n;
    cin >> s;
    s = '#' + s;
    for (int i = 1; i <= n; ++i) {
        for (int j = 'a' - 'a'; j <= 'z' - 'a'; ++j) {
            a[i][j] = a[i - 1][j];
        }
        a[i][s[i] - 'a']++;
    }

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 'a' - 'a'; j <= 'z' - 'a'; ++j) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; ++j) {
            ll c_max = -oo, c_min = +oo;
            for (int k = 'a' - 'a'; k <= 'z' - 'a'; ++k) {
                if (a[j][k] == 0) continue;
                if (c_max < a[j][k] - a[i - 1][k]) c_max = a[j][k] - a[i - 1][k];
                if (c_min > a[j][k] - a[i - 1][k]) c_min = a[j][k] - a[i - 1][k];
            }
            if (dif < c_max - c_min) {
                dif = c_max - c_min;
                ans = j - i;
            }
            // cout << c_max << " " << c_min << " " << dif << endl;
        }
    }

    cout << dif;
}

