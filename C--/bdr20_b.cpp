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

int subs[5];
ll ans = 0, tasks = 0;
vector<ll> Time, Score, Pre;

void Input() {
	for (int i = 0; i < 3; ++i) {
		cin >> subs[i];
		
		for (int j = 0; j < subs[i]; ++j) {
			ll t, d, e, mask = 0;
            cin >> t >> d >> e;

            Time.pb(t);
            Score.pb((i > 0? 7 : 6) * d);

            while (e--) {
                ll x;
                cin >> x;
                --x;
                mask |= (1 << (tasks + x));
            }

            Pre.pb(mask);
		}
		
		tasks += subs[i];
	}	
}

void Process() {
	for (int mask = 0; mask < (1 << tasks); ++mask) {
        bool flag = 1;
        ll t = 0, d = 0;

        for(int i = 0; i < tasks; ++i) {
            if (mask & (1 << i)) {
                if ((mask & Pre[i]) != Pre[i]) {
                    flag = 0;
                    break;
                }

                t += Time[i];
                d += Score[i];
            }
        }

        if (!flag) continue;
        if (t <= 180) ans = max(ans, d);
    }

    cout << fixed << setprecision(2) << ans / 100.0;
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

// https://oj.vnoi.info/problem/bedao_r20_b