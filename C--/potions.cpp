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

ll n, a[maxn + 2], S = 0;
priority_queue<ll, vector<ll>, greater<ll>> q;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    
    for (int i = 1; i <= n; ++i) {
    	S += a[i];
    	q.push(a[i]);
    	
    	while (S < 0) {
    		S -= q.top();
    		q.pop();
    	}
    }
    
    cout << q.size() << endl;
    return 0;
}
