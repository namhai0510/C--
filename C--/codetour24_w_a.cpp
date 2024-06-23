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
const int maxn = 1e5 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll n, color[3][maxn + 2][4], delta[maxn + 2][4];
double ans = 0.0;
map<pair<ll, pair<ll, ll>>, ll> mp;
string s;

map<char, ll> HEX;
void Init() {
	HEX['0'] = 0;
	HEX['1'] = 1;
	HEX['2'] = 2;
	HEX['3'] = 3;
	HEX['4'] = 4;
	HEX['5'] = 5;
	HEX['6'] = 6;
	HEX['7'] = 7;
	HEX['8'] = 8;
	HEX['9'] = 9;
	HEX['A'] = 10;
	HEX['B'] = 11;
	HEX['C'] = 12;
	HEX['D'] = 13;
	HEX['E'] = 14;
	HEX['F'] = 15;
}

void Convert(int i, int t) {
	color[t][i][1] = 16 * HEX[s[1]] + HEX[s[2]];
	color[t][i][2] = 16 * HEX[s[3]] + HEX[s[4]];
	color[t][i][3] = 16 * HEX[s[5]] + HEX[s[6]];
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    Init();
    cin >> n;
    
    for (int x = 1; x <= 2; ++x) {
	    for (int i = 1; i <= n; ++i) {
	    	cin >> s;
	    	
	    	Convert(i, x);
	    	// cout << color[x][i][1] << " " << color[x][i][2] << " " << color[x][i][3] << endl;
    	}
    }
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= 3; ++j) {
    		if (color[1][i][j] == color[2][i][j]) delta[i][j] = 0;
    		else if (color[1][i][j] < color[2][i][j]) delta[i][j] = color[2][i][j] - color[1][i][j];
    		else delta[i][j] = 256 - (color[1][i][j] - color[2][i][j]);
    	}
    }
    
    for (int i = 1; i <= n; ++i)
    	mp[{delta[i][1], {delta[i][2], delta[i][3]}}]++;
    	
    for (auto it : mp) {
    	ans = max(ans, it.se * 100.00 / (double)n);
    }
    
    cout << fixed << setprecision(2) << ans;
    cout << "%";
    	
    
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/codetour24_w_a
