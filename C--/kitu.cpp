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

int n, k;
string s;

ll cnt[256];

bool ok = false;

int main() {
    nothing
    if (fopen("kitu.inp", "r")) {
        freopen("kitu.inp", "r", stdin);
        freopen("kitu.out", "w", stdout);
    }
    cin >> n >> k;
    cin >> s;
    
    s = '#' + s;
    for (int i = 1; i < s.size(); ++i) {
    	cnt[s[i] - 'A']++;
    }
    for (int i = 'A' - 'A'; i <= 'Z' - 'A'; ++i) {
    	if (cnt[i] >= k) {
    		ok = true;
    		cout << char(i + 'A');
    	}
    }
    
    if (ok == false) cout << 0;
    return 0;
}