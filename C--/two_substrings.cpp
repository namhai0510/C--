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

string s;
ll posAB[3] = {0, +oo, 0}, posBA[3] = {0, +oo, 0};

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> s;
    s = '#' + s + '#';
    
    for (int i = 1; i < s.size() - 1; ++i) {
    	if (s[i] == 'A' && s[i + 1] == 'B') {
    		posAB[1] = min(posAB[1], i * 1LL);
    		posAB[2] = max(posAB[2], i * 1LL);
    	}
    	else if (s[i] == 'B' && s[i + 1] == 'A') {
    		posBA[1] = min(posBA[1], i * 1LL);
    		posBA[2] = max(posBA[2], i * 1LL);
    	}
    }
    
    if (posAB[1] < +oo && posBA[2] > 0 && abs(posBA[2] - posAB[1]) > 1) cout << "YES";
	else if(posAB[1] < +oo && posBA[2] > 0 && abs(posAB[2] - posBA[1]) > 1) cout << "YES";
	else cout << "NO";
    return 0;
}
// https://codeforces.com/problemset/problem/550/A