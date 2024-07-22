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

ll test, n, cnt, ans;
string s;

void Input() {
	cin >> n;
	cin >> s;
}

void Process() {
	cnt = ans = 0;
	
    while(s.size() && s[0] == s.back()) {
        cnt++;
        s.pop_back();
    }
    
    if (s.empty()) {
        if (cnt <= 2) {
            cout << "0" << endl;
            return;
        }
        if (cnt == 3) {
            cout << "1" << endl;
            return;
        }
        
        cout << (cnt + 2) / 3 << endl;
        return;
    }
    
    s.push_back('$');
    for (int i = 0; i + 1 < s.size(); ++i) {
        cnt++;
        
        if(s[i] != s[i + 1]) {
            ans += cnt / 3;
            cnt = 0;
        }
    }
    
    cout << ans << endl;
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

// https://codeforces.com/problemset/problem/1392/D
