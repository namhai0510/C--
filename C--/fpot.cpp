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

ll n, d, ans = +oo;
pair<ll, ll> a[maxn + 2];
deque<ll> deq;

int main() {
    nothing
    if (fopen("fpot.inp", "r")) {
        freopen("fpot.inp", "r", stdin);
        freopen("fpot.out", "w", stdout);
    }
    cin >> n >> d;
    
    for (int i = 1; i <= n; ++i) cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + 1 + n);
    
    for (int i = 1; i <= n; ++i) {
        while (!deq.empty() && a[deq.back()].se >= a[i].se) deq.pop_back();
        deq.push_back(i);
        
        while (!deq.empty() && a[i].se - a[deq.front()].se >= d) {
            ans = min(ans, a[i].fi - a[deq.front()].fi);
            deq.pop_front();
        }
    }
    
    if (ans == +oo) cout << -1 << endl; 
	else cout << ans << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
