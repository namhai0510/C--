#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = LLONG_MAX / 2;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n;
ull a[maxn + 2], psum[maxn + 4];
map<ull, ll> pos;

int main() {
    nothing
    if (fopen("xephang.inp", "r")) {
        freopen("xephang.inp", "r", stdin);
        freopen("xephang.out", "w", stdout);
    }
    cin >> n;
    psum[0] = 0;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	psum[i] = psum[i - 1] + a[i];
    	pos[psum[i]] = 1;
    }
    
    bool check = true;
    for (int i = 1; i <= n; ++i) {
    	if (psum[n] % psum[i] != 0) continue;
    	
    	check = true;
    	for (ull val = psum[i] * 2; val <= psum[n]; val += psum[i]) {
    		if (pos[val] == 0) {
    			check = false;
    			break;
    		}
    	}
    	
    	if (check) {
    		cout << psum[i] << endl;
    		return 0;
    	}
    }
    
    return 0;
}
