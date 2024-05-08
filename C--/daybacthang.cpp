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
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, a[maxn + 2], ans = 0;
ll dp[maxn + 2], trace[maxn + 2], lst[maxn + 2];
vector<ll> seq;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	
    	dp[i] = dp[lst[a[i] + 1]] + 1;
    	trace[i] = lst[a[i] + 1];
    	
    	if (dp[lst[a[i]]] < dp[i]) {
            lst[a[i]] = i;
        }
    }
    
    for (int i = 1; i <= n; ++i) {
    	if (dp[i] > dp[ans]) ans = i;
    }
    
    cout << dp[ans] << endl;
    
    while (ans) {
    	seq.pb(ans);
    	ans = trace[ans];
    }
    
    for (int i = seq.size() - 1; i >= 0; --i) cout << seq[i] << " ";
    return 0;
}

// https://oj.vnoi.info/problem/bedao_r19_c
