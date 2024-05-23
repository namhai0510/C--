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
const int maxn = 5e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll test, a, b;
ll p[maxn + 2], factors[maxn + 2];

void Init() {
	for (int i = 2; i <= maxn; ++i) {
		if (!p[i])
			for (int j = i * 2; j <= maxn; j += i) p[j] = i;
	}
	
	for (int i = 2; i <= maxn; ++i) {
		if (!p[i]) factors[i] = 1;
		else factors[i] = factors[i / p[i]] + 1;
	}
	
	for (int i = 2; i <= maxn; ++i) factors[i] += factors[i - 1];
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    Init();
    cin >> test;
    
    while (test--) {
    	cin >> a >> b;
    	
    	cout << factors[a] - factors[b] << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/546/D
