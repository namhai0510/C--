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

string n;
vector<ll> v;
int length = 0;
int sumN = 0, cnt0;

int main() {
    nothing
    if (fopen("MATMA.inp", "r")) {
        freopen("MATMA.inp", "r", stdin);
        freopen("MATMA.out", "w", stdout);
    }
    
    cin >> n;
    
    n = '#' + n;
    
    for (int i = 1; i < n.size(); ++i) v.pb(n[i] - '0'), sumN += n[i] - '0';
    sort(v.begin(), v.end(), greater<ll>());
    	
    // cout << sumN << " " << v[v.size() - 1] << endl;
    if (sumN % 3 != 0 || v[v.size() - 1] != 0) {
    	cout << -1;
    	return 0;
    }
    
    for (int i = 0; i < v.size(); ++i) cout << v[i];
    	
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
