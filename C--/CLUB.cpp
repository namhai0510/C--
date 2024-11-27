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
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

string m1, m2;
map<char, ll> c1, c2;
ll q;

int main() {
    nothing
    if (fopen("CLUB.inp", "r")) {
        freopen("CLUB.inp", "r", stdin);
        freopen("CLUB.out", "w", stdout);
    }
    
    cin >> m1 >> m2;
    
    for (int i = 0; i < m1.size(); ++i) c1[m1[i]]++;
    for (int i = 0; i < m2.size(); ++i) c2[m2[i]]++;
    
    cin >> q;
    
    while (q--) {
    	char c;
    	cin >> c;
    	
    	if (c1[c] > c2[c]) cout << 1 << endl;
    	else if (c1[c] < c2[c]) cout << 2 << endl;
    	else cout << 3 << endl;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
