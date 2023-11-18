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

ll n, cnt[256];
string s;
unordered_set<ll> exist;

bool check() {
	for (auto it : exist) if (cnt[it] < 1) return true;
	return false;
}

bool check2() {
	for (auto it : exist) if (cnt[it] < 1) return false;
	return true;
}

int main() {
    nothing
    if (fopen("they_are_everywhere.inp", "r")) {
        freopen("they_are_everywhere.inp", "r", stdin);
        freopen("they_are_everywhere.out", "w", stdout);
    }
    cin >> n >> s;
    s = '#' + s;
    
    for (int i = 1; i < s.size(); ++i) exist.insert(s[i]);
    
    ll st = 1, en = 0, ans = n;
    for (st = 1; st < s.size(); ++st) {
    	while (check() == true && en < s.size() - 1) {
    		en++;
    		cnt[s[en]]++;
    		
    		// cout << st << " " << en << endl;
    		// for (auto it : exist) cout << it << " " << cnt[it] << endl;
    		// cout << "------" << endl;
    	}
    	
    	if (check2() == 1) ans = min(ans, en - st + 1);
    	
    	cnt[s[st]]--;
    }
    
    cout << ans << endl;
    
    return 0;
}

// abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ