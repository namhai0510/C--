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
const int base = 31;

ll n, a[maxn + 2];
ll mina = 1000000005, sum = 0;
bool pos, neg;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	pos |= (a[i] >= 0);
    	neg |= (a[i] <= 0);
    	
    	mina = min(mina, abs(a[i]));
    	sum += abs(a[i]);
    }
    
    if (n == 1) cout << a[n] << endl, exit(0);
    
    if (pos && neg) cout << sum;
    else cout << sum - 2 * mina;
    return 0;
}

// https://codeforces.com/problemset/problem/1038/D
