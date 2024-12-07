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

const int X = 900;

struct Data {
	ll x1, x2, y1, y2;
};

struct Comp : vector<ll> {
    void build() { 
    	sort(begin(), end()); 
    	erase(unique(begin(), end()), end()); 
    }
    
    int prod(int val) { 
    	return lower_bound(begin(), end(), val) - begin(); 
    }
};

ll n, l, r, res = 0, S = 0, L, R;
Data rct[maxn + 2];
ll xsz, ysz, sz;

Comp cx, cy; 

void Init() {
	ll mx = rct[1].x1, my = rct[1].y1;
	
    for (int i = 1; i <= n; ++i) {
        mx = min(mx, rct[i].x1);
        my = min(my, rct[i].y1);
    }
    for (int i = 1; i <= n; ++i) {
        cx.push_back(rct[i].x1);
        cx.push_back(rct[i].x2);
        
        cy.push_back(rct[i].y1);
        cy.push_back(rct[i].y2);
        
        cx.push_back(rct[i].y1 + 1);
        cy.push_back(rct[i].y2 + 1);
    }
    
    cx.build(); cy.build();
    
    for (int i = 1; i <= n; ++i) {
        rct[i].x1 = cx.prod(rct[i].x1);
        rct[i].x2 = cx.prod(rct[i].x2);
        rct[i].y1 = cy.prod(rct[i].y1);
        rct[i].y2 = cy.prod(rct[i].y2);
    }
}

vector<vector<pair<ll ,ll>>> Full;
vector<vector<vector<tuple<ll, ll, ll>>>> Half;
vector<pair<ll, ll>> Pos;

void UpdateHalfRct(int id, ll l, ll r, ll a, ll b) {
	l = max(l, Pos[id].fi);
    r = min(r, Pos[id].se);
    Half[id][a].push_back({l, r, 1});
    Half[id][b].push_back({l, r, -1});
}

void UpdateFullRct(int id, ll a, ll b) {
	Full[id][a].fi++;
    Full[id][b].se++;
}

void Update() {
	for (int i = 1; i <= n; ++i) {
        int l = rct[i].x1, r = rct[i].x2;
        int idleft = l / X, idright = r / X;
        
        if (idleft == idright) {
            UpdateHalfRct(idleft, l, r, rct[i].y1, rct[i].y2);
        } 
        else {
            for(int j = idleft + 1; j < idright; ++j) {
                UpdateFullRct(j, rct[i].y1, rct[i].y2);
            }
            
            UpdateHalfRct(idleft, l, r, rct[i].y1, rct[i].y2);
            UpdateHalfRct(idright, l, r, rct[i].y1, rct[i].y2);
        }
    }
}

vector<ll> cnt, freq;

void Add(int type, int i) {
	if (type == 1) {
		if (i < 0 || i > n) return;
		S += cnt[i];
	}
	
	if (type == 2) {
		ll tmp = cx[i + 1] - cx[i];
		
        cnt[freq[i]] -= tmp;
        if(L <= freq[i] && freq[i] <= R) S -= tmp;
        ++freq[i];
        if(L <= freq[i] && freq[i] <= R) S += tmp;
        cnt[freq[i]] += tmp;
	}
}

void Remove(int type, int i) {
	if (type == 1) {
		if (i < 0 || i > n) return;
		S -= cnt[i];
	}
	
	if (type == 2) {
		ll tmp = cx[i + 1] - cx[i];
		
        cnt[freq[i]] -= tmp;
        if(L <= freq[i] && freq[i] <= R) S -= tmp;
        --freq[i];
        if(L <= freq[i] && freq[i] <= R) S += tmp;
        cnt[freq[i]] += tmp;
	}
}

void GetResult() {
    for (int a = 0; a <= sz; ++a) {
        S = 0;
        L = l, R = r;
        cnt.resize(n + 1, 0);
        freq.resize(n + 1, 0);

        cnt[0] = cx[Pos[a].se + 1] - cx[Pos[a].fi];

        for (int i = 0; i < ysz; ++i) {
            for (auto[lx, rx, t] : Half[a][i]) {
                if (t == 1) {
                    for(int g = lx; g <= rx; ++g) Add(2, g);
                }
            }
            
            for (int g = 0; g < Full[a][i].fi; ++g) Add(1, --L), Remove(1, R--);
            if (i + 1 < ysz) {
                assert(cy[i + 1] > cy[i]);
                res += S * (cy[i + 1] - cy[i]);
            }
            
            for (auto[lx, rx, t] : Half[a][i]) {
                if (t == -1) {
                    for(int g = lx; g <= rx; ++g) Remove(2, g);
                }
            }
            
            for (int g = 0; g < Full[a][i].se; ++g) Add(1, ++R), Remove(1, L++);
        }
    }
    
    cout << res << endl;
}

int main() {
    nothing
    if (fopen("rect.inp", "r")) {
        freopen("rect.inp", "r", stdin);
        freopen("rect.out", "w", stdout);
    }
	
	cin >> n >> l >> r;
	
	for (int i = 1; i <= n; ++i) {
		cin >> rct[i].x1 >> rct[i].y1 >> rct[i].x2 >> rct[i].y2;
	}    
	
    Init();
    
    xsz = cx.size();
    ysz = cy.size();
    
    cx.push_back(cx.back());
    cy.push_back(cy.back());
    
    sz = xsz / X;
    
    Full.resize(sz + 2, vector<pair<ll, ll>>(ysz + 2));
    Half.resize(sz + 2, vector<vector<tuple<ll, ll, ll>>>(ysz + 2));
    
    Pos.resize(sz + 2, pair<ll, ll>(xsz + 2, 0));
    
    Update();
    GetResult();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
