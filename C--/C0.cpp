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

ll test;
ll a[5];
bool exist = 0;

int main() {
    nothing
    if (fopen("C0.inp", "r")) {
        freopen("C0.inp", "r", stdin);
        freopen("C0.out", "w", stdout);
    }
    
    test = 2;
    
    while (test--) {
    	cin >> a[1] >> a[2] >> a[3];
    	
    	exist = 0;
    	sort(a + 1, a + 1 + 3);
    	do {
    		if (a[1] + a[2] - a[3] == 0) {
    			cout << "yes" << endl;
    			exist = 1;
    			break;
    		}
    	}
    	while (next_permutation(a + 1, a + 1 + 3));
    	
    	if (!exist)
    		cout << "no" << endl;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
