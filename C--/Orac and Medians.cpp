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
const int maxn = 1e5;
const int maxa = 2e3;
const int base = 31;

ll test;
ll n, k, a[maxn + 2];
bool exist = 0;

void Process() {
	exist = 0;
	
	for (int i = 1; i <= n; ++i) {
		if (a[i] < k) a[i] = 0;
		if (a[i] == k) a[i] = 1, exist = 1;
		if (a[i] > k) a[i] = 2;
	}
	
	if (exist == 0) {
		cout << "no" << endl;
		return;
	}
	
	if (n == 1) {
		cout << "yes" << endl;
		return;
	}
	
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n && j <= i + 2; ++j)
			if (a[i] && a[j]) {
				cout << "yes" << endl;
				return;
			}
			
	cout << "no" << endl;
	return;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> test;
    
    while (test--) {
    	cin >> n >> k;
    	
    	for (int i = 1; i <= n; ++i) cin >> a[i];
    	Process();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1349/B