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

ll n, h[maxn + 2];
unordered_map<ll, ll> freq, cntCol;
ll mxleng, ways;

int main() {
    nothing
    if (fopen("HR.inp", "r")) {
        freopen("HR.inp", "r", stdin);
        freopen("HR.out", "w", stdout);
    }
    
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        freq[h[i]]++;
    }
	
	mxleng = ways = 0;

    for (auto& p1 : freq) {
        for (auto& p2 : freq) {
            if (p1.fi <= p2.fi) {
                ll S = p1.fi + p2.fi;
                ll col = 0;

                if (p1.fi == p2.fi) col = p1.se / 2;
                else col = min(p1.se, p2.se);

                cntCol[S] += col;
                mxleng = max(mxleng, cntCol[S]);
            }
        }
    }

    ways = 0;
    for (auto& p : cntCol) {
        if (p.se == mxleng) {
            ways++;
        }
    }

    cout << mxleng << " " << ways << endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
