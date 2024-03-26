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

const int ox[4] = {-1, 0, 0, 1};
const int oy[4] = {0, -1, 1, 0};

ll m, n, a[maxa + 2][maxa + 2];
ll ans = +oo, D[maxa + 2][maxa + 2];

struct Grp {
	ll f, s, t;
};

struct cmp {
    bool operator () (Grp A, Grp B){
        return A.f > B.f;
    }
};

void Pre() {
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			D[i][j] = +oo;
		}
	}
}

bool inside(int r, int c) {
	if (r < 1 || c < 1 || r > m || c > n) return false;
	
	return true;
}

void Dijkstra() {
	priority_queue<Grp, vector<Grp>, cmp> h;
	
	for (int i = 1; i <= m; i ++) {
        D[i][1] = 1;
        h.push({D[i][1], i, 1});
    }
	
	while (!h.empty()) {
		ll c = h.top().f, u[2] = {h.top().s, h.top().t};
		h.pop();
		
		if (c > D[u[0]][u[1]]) continue;
		
		for (int o = 0; o < 4; ++o) {
			if (inside(u[0] + ox[o], u[1] + oy[o]) == false) continue;
			
			if (D[u[0] + ox[o]][u[1] + oy[o]] > 
				D[u[0]][u[1]] + (a[u[0]][u[1]] != a[u[0] + ox[o]][u[1] + oy[o]])) {
                D[u[0] + ox[o]][u[1] + oy[o]] 
                	= D[u[0]][u[1]] + (a[u[0]][u[1]] != a[u[0] + ox[o]][u[1] + oy[o]]);
                
                h.push({D[u[0] + ox[o]][u[1] + oy[o]], u[0] + ox[o], u[1] + oy[o]});
            }
		}
	}
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> m >> n;
    
    Pre();
    
    for (int i = 1; i <= m; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		cin >> a[i][j];
    	}
    }
    
    Dijkstra();
    
    for (int i = 1; i <= m; ++i) {
    	ans = min(ans, D[i][n]);
    }
    
    cout << ans << endl;
    return 0;
}
