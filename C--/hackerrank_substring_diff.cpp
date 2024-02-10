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

ll t, k, length, dp[maxa + 2][maxa + 2];
string s1, s2;

bool Check(int pos) {
	for (int i = pos; i <= length; ++i) {
		for (int j = pos; j <= length; ++j) {
			if (dp[i][j] - dp[i - pos][j - pos] <= k) return true;
		}
	}
	
	return false;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    
    while (t--) {
    	cin >> k >> s1 >> s2;
    	
    	s1 = '#' + s1;
    	s2 = '#' + s2;
    	
    	length = s1.size() - 1;
    	
    	for (int i = 1; i <= length; ++i) {
    		for (int j = 1; j <= length; ++j) {
    			if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1];
    			else dp[i][j] = dp[i - 1][j - 1] + 1;
    		}
    	}
    
    	int l = 1, r = length, mid;
    	
    	while (l <= r) {
    		mid = (l + r) / 2;
    		
    		// cout << l << " " << r << " " << mid << endl;
    		
    		if (Check(mid)) l = mid + 1;
    		else r = mid - 1;
    	}
    	
    	cout << l - 1<< endl;
    }
    return 0;
}

// https://www.hackerrank.com/challenges/substring-diff/problem?isFullScreen=true