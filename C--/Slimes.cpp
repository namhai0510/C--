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
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        vector<int> res(n, n);
        for (int z = 0; z < 2; ++z) {
            vector<ll> s(n + 1);
            for (int i = 0; i < n; ++i) s[i + 1] = s[i] + a[i];

            vector<int> p(n, -1);
            for (int i = 1; i < n; ++i) {
                int j = (z ? n - i - 1 : i);
                int l = 1, r = i;
                
                while (l <= r) {
                    int m = (l + r) / 2;
                    if (s[i] - s[i - m] > a[i] && p[i - 1] >= i - m) {
                        res[j] = min(res[j], m);
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
                
                if (a[i - 1] > a[i]) res[j] = 1;
                p[i] = (a[i] == a[i - 1] ? p[i - 1] : i - 1);
            }
            reverse(a.begin(), a.end());
        }

        for (int i = 0; i < n; ++i) 
            cout << (res[i] == n ? -1 : res[i]) << ' ';
        
        cout << endl;
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
