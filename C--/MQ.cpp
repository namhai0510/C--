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

ll n, S, total = 0;
ll a[maxn + 2], cost[maxn + 2];;
ll mxG = 0, mnC = 0;

bool CanBuy(ll num) {    
    for (int i = 1; i <= n; ++i) {
        cost[i] = a[i] * num + i;
    }
	sort(cost + 1, cost + 1 + n);
	
	total = 0;
	for (int i = 1; i <= num; ++i) total += cost[i];
	
	return total <= S;
}

void Input() {
	cin >> n >> S;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
}

void Process() {
	ll l = 0, r = n, mid;
	
	while (l <= r) {
        mid = (l + r) / 2;
     	
     	if (CanBuy(mid)) {
     		mxG = mid;
     		mnC = total;
     		
     		l = mid + 1;
     	}  
     	else r = mid - 1;
    }

    cout << mxG << " " << mnC << endl;
}

int main() {
    nothing
    if (fopen("MQ.inp", "r")) {
        freopen("MQ.inp", "r", stdin);
        freopen("MQ.out", "w", stdout);
    }
    
    Input();
    Process();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
