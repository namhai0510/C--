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
ll n, a[maxn + 2];

set<ll> s;
bool exist = 0;

void Input() {
	cin >> n;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
}

void Process() {
	exist = 1;
	s.clear();
	s.insert(a[1]);
	
	for (int i = 2; i <= n; ++i) {
		ll prev = a[i - 1];
		
		if (prev < a[i]) {
			auto it = s.upper_bound(prev);
			
			if (it != s.end() && (*it < a[i])) {
				exist = 0;
				break;
			}
		}
		if (prev > a[i]) {
			auto it = s.lower_bound(prev);
			
            if (it != s.begin() && (*(--it) > a[i])) {
                exist = 0;
                break;
            }
		}
		
		s.insert(a[i]);
	}
	
	if (exist) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> test;
    
    while (test--) {
    	Input();
    	Process();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1536/D
