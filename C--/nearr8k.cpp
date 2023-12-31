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

ll m, n, a[maxn + 2], dx[2] = {0, 1}, dy[2] = {1, 0};
ll cur, x = 1, y, u = 1, l = 1, pos = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> m >> n;
    
    for (int i = 1; i <=((m + 1) / 2) * ((n + 1) / 2); ++i) {
        if ((x + dx[pos] > (m + 1) / 2) || (y + dy[pos] > (n + 1) / 2)) {
            u += (pos == 0);
            l += (pos == 1);
            x = u; y = l;
            pos= (pos + 1) % 2;    
        }
        else {
            x += dx[pos];
            y += dy[pos];
        }
        
        for (int j = 1; j <= 4 /((int) (pow(2, ((x == (m + 1) / 2) && (m % 2 == 1)) + ((y == (n + 1) / 2) && (n % 2 == 1))))); ++j) {
            cur++;
            a[(x * ((j % 3) == 1) + (m - x + 1)*((j % 3) != 1) - 1) * n + (y * ((j % 2) == 1) + (n - y + 1) * (j % 2 == 0))] = cur;
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) cout << a[(i - 1) * n + j] << " ";
        cout << endl;
    }
    return 0;
}
