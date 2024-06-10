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

ll A, B, C, D;
ll num[maxn + 2], ans = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> A >> B >> C >> D;
    
    for (int i = A; i <= B; ++i) {
    	num[i + B]++;
    	num[i + C + 1]--;
    }
    
    for (int i = 1; i <= maxn; ++i) num[i] += num[i - 1];
	for (int i = 1; i <= maxn; ++i) num[i] += num[i - 1];
	
	for (int i = C; i <= D; ++i) ans += num[maxn] - num[i];
	
	cout << ans << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/1355/C
