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

int n, a[maxn + 2], b[maxn + 2];
vector<int> c;
ll sum = 0;

int main() {
    nothing
    if (fopen("acm.inp", "r")) {
        freopen("acm.inp", "r", stdin);
        freopen("acm.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= 2 * n; ++i) {
    	cin >> a[i] >> b[i];
    	c.pb(b[i] - a[i]);
    	
    	sum += a[i];
    }
    sort(c.begin(), c.end());
    
    for (int i = 0; i < n; ++i) sum += c[i];
    cout << sum;
    
    return 0;
}

// https://oj.vnoi.info/problem/acmnb