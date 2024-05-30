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
const int base = 31;

ll n, a[maxn + 2], res = 0;
vector<ll> v;

bool Prime[maxn + 2];
void Eratos() {
    memset(Prime, 1, sizeof(Prime));

    Prime[0] = Prime[1] = 0;

    for(int i = 2; i * i <= maxn; ++i) {
        if (Prime[i])
            for (int j = i * i; j <= maxn; j += i) Prime[j] = 0;
    }

    for(int i = 2; i <= maxn; ++i)
        if (Prime[i]) v.pb(i);
}

ll Count (ll x) {
    if (x == 1) return 0;
    
    ll cnt = 0;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            while (x % i == 0) {
                cnt++;
                x /= i;
            }
        }
    }
    
    if (x != 1) cnt++;
    return cnt;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    Eratos();
    
    cout << v.size() << endl;
    
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (Count(a[i]) % 2 == 0) cout << "2 ";
        else cout << "1 ";
    }
    
    return 0;
}
