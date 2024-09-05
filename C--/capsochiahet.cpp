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

ll n, k, a[maxn + 2], cnt, ans, x, y;

void Input() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        a[__gcd(x, y)]++;
    }
}

void Process() {
    ans = 0;
    
    for (int i = 1; i <= maxn; ++i) {
        cnt = 0;
        x = i;
        
        while (x <= maxn) {
            cnt += a[x];
            if (cnt >= k) {
                ans++;
                break;
            }
            
            x += i;
        }
    }
    
    cout << ans;
}


int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }

    Input();
    Process();

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
