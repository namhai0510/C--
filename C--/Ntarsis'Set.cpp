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

ll test, n, k, a[maxn + 2];
ll it, num;

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
    	a[n + 1] = +oo;
    	
    	it = 1;
    	num = 1;
    	
    	while (k--) {
            while (it <= n && a[it] <= num + it - 1) it++;
            
            num += it - 1;
        }

        cout << num << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1852/A