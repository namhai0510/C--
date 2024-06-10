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

string s[5];
ll cnt_x = 0, cnt_o = 0, cnt = 0;

bool Check(char c) {
	if (s[0][0] == c && s[0][1] == c && s[0][2] == c) return 1;
	if (s[1][0] == c && s[1][1] == c && s[1][2] == c) return 1;
	if (s[2][0] == c && s[2][1] == c && s[2][2] == c) return 1;
	
	if (s[0][0] == c && s[1][0] == c && s[2][0] == c) return 1;
	if (s[0][1] == c && s[1][1] == c && s[2][1] == c) return 1;
	if (s[0][2] == c && s[1][2] == c && s[2][2] == c) return 1;
	
	if (s[0][0] == c && s[1][1] == c && s[2][2] == c) return 1;
	if (s[0][2] == c && s[1][1] == c && s[2][0] == c) return 1;
	
	return 0;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    for (int i = 0; i <= 2; ++i) {
    	cin >> s[i];
    	
    	for (int j = 0; j <= 2; ++j) {
    		if (s[i][j] == 'X') cnt_x++;
    		else if (s[i][j] == '0') cnt_o++;
    		else cnt++;
    	}
    }
    
    bool x_win = Check('X'), o_win = Check('0');
    
    if (x_win && o_win) cout << "illegal" << endl, exit(0);
    
    if (cnt_x < cnt_o || cnt_x > cnt_o + 1) cout << "illegal" << endl, exit(0);
    if (x_win && cnt_x == cnt_o) cout << "illegal" << endl, exit(0);
    if (o_win && cnt_x == cnt_o + 1) cout << "illegal" << endl, exit(0);
    
    if (!x_win && !o_win && !cnt) cout << "draw" << endl, exit(0);
    
    if (x_win) cout << "the first player won" << endl, exit(0);
    if (o_win) cout << "the second player won" << endl, exit(0);
    
    if (cnt_x == cnt_o) cout << "first" << endl, exit(0);
    if (cnt_x == cnt_o + 1) cout << "second" << endl, exit(0);
    return 0;
}

// https://codeforces.com/problemset/problem/3/C