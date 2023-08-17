#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll ans = 0, f[maxn];
bool check (int x, int y) {
    // if (y > x) swap(x, y);
    string a = to_string(x), b = to_string(y);
    if (a.size() != b.size()) return false;
    
	for (int i = 0; i < a.length(); i++)
		for (int j = i + 1; j < a.length(); j++)
			if (a[i] == a[j])
				if (b[i] != b[j]) return false;
				
	return true;
}

int main() {
    nothing
    if (fopen("dangcau.inp", "r")) {
        freopen("dangcau.inp", "r", stdin);
        freopen("dangcau.out", "w", stdout);
    }
    
    for (int i = 1; i <= maxa; i++) f[i] = -1;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        int st = 1, en = 9;
        
        for (int j = 1; j < s.size(); j++) {
            st *= 10;
            en *= 10 + 9;
        }
        
        for (int j = st; j <= en; j++) {
            if (f[j] == -1) {
                if (check(i, j) && check(j, i)) f[max(i, j)] = min(i, j);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (f[i] == -1) f[i] = i;
    }
    // for (int i = 1; i <= n; i++) cout << f[i] << endl;
    // cout << f[213] << " " << f[102] << endl;
    // cout << check(213, 102) << " " << check(102, 100) << endl;
    for (int i = 1; i <= n; i++) {
        ans += f[i];
    }
    
    cout << ans;
    return 0;
}