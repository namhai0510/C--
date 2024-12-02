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
const int maxn = 1e5;
const int maxa = 2e3;
const int base = 31;

ll n, res = 0;
string s[maxn + 2];
ll dp[30][30][30];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> s[i];
    	s[i] = '#' + s[i];
    	
    	int p[4] = {'#', s[i][1] - 'a', s[i][2] - 'a', s[i][3] - 'a'};
    	
    	for (int j = 0; j < 26; j++){
            for (int k = 0; k < 26; k++){
                if (j != p[2] && k != p[3]) res += dp[p[1]][j][k];
                if (j != p[1] && k != p[3]) res += dp[j][p[2]][k];
                if (j != p[1] && k != p[2]) res += dp[j][k][p[3]];
            }
        } 
        
        dp[p[1]][p[2]][p[3]]++;
    }
    
    cout << res << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
