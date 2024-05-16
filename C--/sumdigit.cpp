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
const ll modd = 1e9;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

string n;
ll sumn = 0, length;
ll dp[305][2705][5];

ll dpdigit(ll d, ll s, ll smaller) {
	if (d > length) return (sumn == s);
	
	if (dp[d][s][smaller] != -1) return dp[d][s][smaller];
	
	ll maxC = 9, sum = 0;
	if (!smaller) maxC = n[d] - '0';
    
    for (int c = 0; c <= maxC; ++c) {
    	sum += dpdigit(d + 1, s + c, smaller | (c < maxC));
    	sum %= modd;
    }
    
    dp[d][s][smaller] = sum;
    
    return sum;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    length = n.size();
    
    if (n == "0") {
    	cout << 0;
    	return 0;
    }
    
    for (int i = 0; i < n.size(); ++i) sumn += (n[i] - '0');
    
    n = '#' + n;
    
    memset(dp, -1, sizeof(dp));
    
    cout << dpdigit(1, 0, 0) << endl;
    
    return 0;
}
