#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
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

ll n, k, p, a[maxn + 2], c[maxn + 2];

map<ll, vector<ll>> pos;

ll st[30][maxn + 2];
void Preprocess() {
    for (int i = 1; i <= n; ++i) st[0][i] = c[i];
    for (int j = 1; j <= 25; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}

ll queryMin(int l, int r) {
    int k = __lg(r - l + 1);
    return min(st[k][l], st[k][r - (1 << k) + 1]);
}

int main() {
    nothing
    if (fopen("dc.inp", "r")) {
        freopen("dc.inp", "r", stdin);
        freopen("dc.out", "w", stdout);
    }
    cin >> n >> k >> p;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i] >> c[i];
    	pos[a[i]].pb(i);
    }
    
    Preprocess();
    
    ll res = 0;
    for (auto it : pos) {
    	if (it.se.size() <= 1) continue;
    	
    	int length = it.se.size() - 1;
    	
    	// cout << length << endl;
    	
    	int y = 1;
    	for (int x = 0; x <= length - 1; ++x) {
    		if (y <= x) y = x + 1;
    		
    		ll minn = queryMin(it.se[x], it.se[y]);

    		while (y + 1 <= length && minn > p) {
    			y++;
    			minn = queryMin(it.se[x], it.se[y]);
    		}
			
			if (minn <= p) res += length - y + 1;
			
			// cout << x << " " << y << endl;
    	}
    	
    	// cout << it.fi << " " << cnt << endl;
    	// res += cnt;
    }
    
    cout << res << endl;
    
    return 0;
}

// https://cdn.discordapp.com/attachments/1195563097549721723/1208775756457582672/image.png?ex=65e48326&is=65d20e26&hm=9a34ecb950d365d4fccdd399983f7d5d38dd54b2c371caf750b32782aa8b3cc1&