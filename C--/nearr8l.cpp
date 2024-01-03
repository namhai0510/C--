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

ll a[maxn + 2], n, res = 1;

int main() {
    nothing
    if (fopen("nearr8l.inp", "r")) {
        freopen("nearr8l.inp", "r", stdin);
        freopen("nearr8l.out", "w", stdout);
    }
    memset(a, 0, sizeof(a));
    cin >> n;
    
    for (int i = 1; i <= (n - (n + 1) / 2); ++i) {
    	for (int j = 1; j <= (n - (n + 1) / 2); ++j) {
    		a[(i - 1) * n + j] = res;
    		res++;
	        a[(i - 1) * n + j + (n + 1) / 2] = res;
	        res++;
	        a[(i + (n + 1) / 2 - 1) * n + j] = res;
	        res++;
	        a[(i + (n + 1) / 2 - 1) * n + j + (n + 1) / 2] = res;
	        res++;
    	}
    }
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		cout << a[(i - 1) * n + j] << " ";
    	}
    	cout << endl;
    }
    return 0;
}
