#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 1e17 + 2;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, S, a[maxn + 2], sum, res = 0;

ll Check(ll mid){
  vector<ll> b;
  for (int i = 1; i <= n; ++i) 
  	b.push_back(a[i] + i * mid);
  	
  sort(b.begin(), b.end());
  sum = 0;
  
  for (int i = 0; i < mid; ++i) sum += b[i];
  return sum <= S;
}

ll Bs() {
	ll l = 1, r = n, mid, ans = 0;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (Check(mid) == 1) {
			l = mid + 1;
			ans = mid;
			res = sum;
		}
		else r = mid - 1;
	}
	
	return ans;
}
int main() {
    nothing
    if (fopen("Sagheer_and_NubianMarket.inp", "r")) {
        freopen("Sagheer_and_NubianMarket.inp", "r", stdin);
        freopen("Sagheer_and_NubianMarket.out", "w", stdout);
    }
    cin >> n >> S;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    ll time = Bs();
    cout << time << " ";
    cout << res << endl;
    return 0;
}