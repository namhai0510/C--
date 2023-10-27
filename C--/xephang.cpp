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
const int maxa = 2e3 + 5;

ll n, a[maxn + 2], psum[maxn + 4];
vector<ll> divisor;

int main() {
    nothing
    if (fopen("xephang.inp", "r")) {
        freopen("xephang.inp", "r", stdin);
        freopen("xephang.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	psum[i] = psum[i - 1] + a[i];
    }
    psum[n + 1] = +oo;
    
    ll sum;
    
    for(int i = 1; i <= n; ++i){
    	if (psum[i] > psum[n] / 2) break;
        sum = 0;
    	for (int j = 1; j <= n; ++j){
    		if (sum < psum[i]) sum += a[j];
    		if (sum == psum[i]) sum = 0;
    		if (sum > psum[i]) break;
    	}
    	if (sum == 0){
    		cout << psum[i];
    		return 0;
    	}
	}
    
    return 0;
}
