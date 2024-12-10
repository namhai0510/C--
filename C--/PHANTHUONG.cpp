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

ll n, cnt = 0, tmp = 0;
string a;

int main() {
    nothing
    if (fopen("PHANTHUONG.inp", "r")) {
        freopen("PHANTHUONG.inp", "r", stdin);
        freopen("PHANTHUONG.out", "w", stdout);
    }
    
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a;
    	
    	tmp = 0;
    	for (int j = 0; j < a.size(); ++j) tmp += (a[j] - '0');
    	
    	if (tmp % 9 == 0 && a[a.size() - 1] == '0') cnt++;
    }
    
    cout << cnt << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
