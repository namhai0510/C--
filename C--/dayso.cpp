#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll modd = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxa = 2e3 + 5;

ll n, k, a[maxn + 2], ps[maxn + 2];

ll cnt = 0, ans = +oo;
bool dp[maxn + 2], f[maxn + 2];

bool Check[maxn + 2];
void Sieve() {
	memset(Check, true, sizeof(Check));
	
	Check[0] = false;
	Check[1] = false;
	
	for (int i = 2; i * i <= maxn; ++i) {
		if (Check[i]) {
			for (int j = i * i; j <= maxn; j += i) Check[j] = false;
		}
	}
}

void Sub_nondel() {
	cnt = 0;
	dp[0] = 1;
	
	for (int i = 1; i <= n; ++i) {
		
		for (int j = 0; j <= ps[n]; ++j) f[j] = dp[j];
		
		for (int j = a[i]; j <= ps[n]; ++j) {
			if (f[j - a[i]] == 1) dp[j] = 1;
		}
	}
	
	for (int i = 1; i <= ps[n]; ++i) {
		cnt += dp[i] * Check[i];
		// cout << i << " " << dp[i] << " " << Check[i] << " " << cnt << endl;
	}
	
	cout << cnt << endl;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    Sieve();
    ps[0] = 0;
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	ps[i] = ps[i - 1] + a[i];
    }
    
    if (k == 0) {
    	Sub_nondel();
    	return 0;
    }
    
    for (int del = 1; del <= n; ++del) {
    	cnt = 0;
    	
    	for (int i = 1; i <= maxn; ++i) dp[i] = 0;
    	dp[0] = 1;
    	// Khoi tao lai gia tri
    	
    	for (int i = 1; i <= n; ++i) {
    		if (i == del) continue;
    		
    		for (int j = 0; j <= ps[i]; ++j) f[j] = dp[j];
    		
    		for (int j = a[i]; j <= ps[i]; ++j) {
    			if (f[j - a[i]] == 1) dp[j] = 1;
    		}
    	}
    	
    	for (int i = 1; i <= ps[n]; ++i) {
    		cnt += dp[i] * Check[i];
    		// cout << i << " " << dp[i] << " " << Check[i] << " " << cnt << endl;
    	}
    	
    	ans = min(ans, cnt);
    	
    	// cout << endl << "-----" << endl;
    } 
    
    cout << ans << endl;
    return 0;
}

// cho N (<= 100) và K, cùng N số a[i] (<= 1000)
// 
// ta bỏ đi K số, sao cho số dãy con (ko liên tiếp) có tổng là số nguyên tố ít nhất
// 
// lưu ý, nếu có 10 dãy cùng tổng cũng chỉ tính 1 lần (ví dụ 1 2 3 thì 1 2 và 3 tổng cùng là 3 chỉ tính 1 lần)
// 
// INPUT
// 3 0
// 2 5 6
// 
// OUTPUT
// 5
// 
// INPUT
// 3 1
// 2 5 6
// 
// OUTPUT
// 1