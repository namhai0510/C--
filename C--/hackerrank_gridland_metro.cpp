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

ll m, n, k;
ll c[maxn + 2], l[maxn + 2], r[maxn + 2], del = 0;
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> m >> n >> k;
    
    if (k == 0) {
    	cout << m * n << endl;
    	return 0;
    }
    
    for (int i = 1; i <= k; ++i) {
    	cin >> c[i] >> l[i] >> r[i];
    }
    
    for (int i = 1; i <= k; ++i) {
    	for (int j = i + 1; j <= k; ++j) {
    		if (c[i] == c[j]) {
    			if (l[i] >= l[j] && r[i] <= r[j]) {
    				l[i] = 0; r[i] = -1;
    			}
    			
    			if (l[i] <= l[j] && r[i] >= l[j] && r[i] <= r[j]) {
    				l[j] = l[i];
    				l[i] = 0; r[i] = -1; 
    			}
    			
    			if (l[i] >= l[j] && l[i] <= r[j] && r[i] >= r[j]) {
    				r[j] = r[i];
    				l[i] = 0; r[i] = -1;
    			}
    			
    			if (l[i] <= l[j] && r[i] >= r[j]) {
    				l[j] = l[i]; r[j] = r[i];
    				l[i] = 0; r[i] = -1;
    			}
    			break;
    		}
    	}
    }
	
	for (int i = 1; i <= k; ++i) {
		del += (r[i] - l[i] + 1);
	}
    
    cout << m * n - del << endl;
    
    return 0;
}

// https://www.hackerrank.com/challenges/gridland-metro/problem?isFullScreen=true
