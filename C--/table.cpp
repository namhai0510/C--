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
const int maxa = 5e3 + 5;

ll n, m, k;
ll a[maxa][maxa], S[maxa][maxa];

ll GetSum(int x1, int y1, int x2, int y2) {
    return S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1]; 
}

int main() {
    nothing
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + a[i][j];
        }
    }
    
    ll ans = 1;
    int lx, ly, rx, ry;
    
    for (int i = 1; i <= n + m - 1; ++i) {
        if (i <= n) {
            lx = n - i + 1; ly = 1;
        }
        else {
            lx = 1; ly = i - n + 1;
        }

        if (i > m) {
            rx = n + m - i; ry = m;
        }
        else {
            rx = n; ry = i;
        }
        
        ll Sum = 0;
        int rxx = lx, ryy = ly, lxx = lx, lyy = ly;
        while (rxx <= rx) {
            Sum += GetSum(lxx, ryy, rxx, ryy) + GetSum(rxx, lyy, rxx, ryy - 1);
            while (Sum > k) {
                Sum -= GetSum(lxx, lyy, rxx, lyy);
                Sum -= GetSum(lxx, lyy + 1, lxx, ryy);
                lxx++; lyy++;
            }
            ans = max(ans, 1LL * (rxx - lxx + 1));
            rxx++; ryy++;
        }
    }
    
    cout << ans << endl;
    exit(0);
}

// tinh tong cac ptu nam trong hinh chu nhat co goc tren trai la (x1, y1) va goc duoi phai la (x2, y2)
// = S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1]