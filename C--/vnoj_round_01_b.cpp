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

ll test, n;
ll fibo[105], pos;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    fibo[1] = 0;
    fibo[2] = 1;
    fibo[3] = 2;
    for (int i = 4; i <= 100; ++i) fibo[i] = fibo[i - 2] + fibo[i - 1];
    
    cin >> test;
    
    while (test--) {
    	cin >> n;
    	
    	pos = upper_bound(fibo + 1, fibo + 101, n) - fibo;
    	
    	cout << pos - 3 << endl;
    }
    return 0;
}

// https://oj.vnoi.info/problem/vnoj_round_01_b
