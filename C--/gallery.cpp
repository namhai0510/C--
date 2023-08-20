#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 5e3 + 5;

int m, n;
struct Data {
    ll st, en, c;
};

bool cmp(Data A, Data B) {
    return (A.st < B.st || (A.st == B.st && A.en < B.en) || (A.st == B.st && A.en == B.en && A.c < B.c));
}
Data a[maxn + 5];

ll f[maxn + 5];

signed main() {
    nothing
    if (fopen("gallery.inp", "r")) {
        freopen("gallery.inp", "r", stdin);
        freopen("gallery.out", "w", stdout);
    }
    cin >> n >> m;
    
    for (int i = 1; i <= n + 1; ++i) f[i] = +oo;
    f[0] = 0;
    
    for (int i = 1; i <= m; ++i) {
        cin >> a[i].st >> a[i].en >> a[i].c;
    }
    sort(a + 1, a + 1 + m, cmp);
    
    for (int i = 1; i <= m; i++) {
        for (int j = a[i].st + 1; j <= a[i].en; ++j) {
            f[j] = min(f[j], f[a[i].st] + a[i].c);
        }
    }
    
    cout << f[n];
}
