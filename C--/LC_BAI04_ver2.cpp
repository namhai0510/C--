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
const ll mod = 1e9;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, k, a[maxn], dp[maxn], minRange[maxn];
deque<ll> dq;

int main() {
    nothing
    if (fopen("LC_BAI04.inp", "r")) {
        freopen("LC_BAI04.inp", "r", stdin);
        freopen("LC_BAI04.out", "w", stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

	while (dq.empty() == false) dq.pop_back();
	
	a[n+1] = 0;
	
	dq.push_back(0);
	
    for(int i = 1; i <= n + 1; i++) {
		if (dq.size() && dq.front() + k < i) dq.pop_front(); 
		   
		dp[i] = dp[dq.front()] + a[i]; 	
		
		while (dq.size() && dp[dq.back()] >= dp[i]) dq.pop_back();
		    
		dq.push_back(i); 
    }
    
    
    cout << dp[n + 1];
    
    return 0;
}

// code xu ly tim min trong doan i - k toi i
// while (dq.size()) dq.pop_front();
// for (int i = 1; i <= n; ++i) { 
    // while (dq.size() && a[dq.back()] >= a[i]) dq.pop_back();
//     
    // dq.push_back(i); 
//     
    // if (dq.front() + k <= i) dq.pop_front(); 
//     
    // if (i >= k) minRange[i] = a[dq.front()]; 
// }