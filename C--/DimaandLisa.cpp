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
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll n;

unordered_set<int> Eratos;
bool Prime(int x) {
	if (Eratos.count(x)) return true;
	if (x == 1) return false;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) return false;
	}
	
	Eratos.insert(x);
	return true;
}

int main() {
    nothing
    // if (fopen("ss.inp", "r")) {
        // freopen("ss.inp", "r", stdin);
        // freopen("ss.out", "w", stdout);
    // }
    cin >> n;
    
    if (Prime(n)) {
    	cout << 1 << endl << n << endl;
    	return 0;
    }
    
    for (int i = n - 2; i >= 0; --i) {
    	if (Prime(i)) {
    		if (Prime(n - i)) {
				cout << 2 << endl;
				cout << i << " " << n - i << endl;
				return 0;
			}
    		for (int j = 2; j + i <= n - 1; ++j) {
    			if (Prime(j) && Prime(n - i - j)) {
    				cout << 3 << endl;
    				cout << i << " " << j << " " << (n - i - j) << endl;
    				return 0;
    			}
    		}
    	}
    }
    
    
    return 0;
}

// https://codeforces.com/problemset/problem/584/D
