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
const int maxn = 2e5 + 150;
const int maxa = 2e3 + 5;
const int base = 31;

template<class X, class Y> 
	bool maximize(X &x, Y &y) {
		if (x < y) {
			x = y;
			return true;
		}
		else return false;
	}
template<class X, class Y> 
	bool minimize(X &x, Y &y) {
		if (x > y) {
			x = y;
			return true;
		}
		else return false;
	}
	
struct DisjointSet {
	vector<int> lab;
	
	DisjointSet(int n = 0) {
		lab.assign(n + 3, -1);
	}
	
	int find(int x) {
		return (lab[x] < 0 ? x : lab[x] = find(lab[x]));
	}
	
	bool join (int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		
		if (lab[x] > lab[y]) swap(x, y);
		lab[x] += lab[y];
		lab[y] = x;
		return true;
	}
};	

struct Edge {
	int u, v, c;
	
	Edge() {
		u = v = c = 0;
	}
	
	void Input(void) {
		cin >> u >> v >> c;
	}
	
	bool operator < (const Edge &e) const {
		return c > e.c;
	}
};

ll n, m, numComp = 0;
Edge edges[maxn + 2];
bool inTree[maxn + 2];

void loadGraph() {
	cin >> n >> m;
	
	for (int i = 1; i <= m; ++i) edges[i].Input();
	
	sort(edges + 1, edges + 1 + m);
}

void process() {
	DisjointSet dsu(n);
	for (int i = 1; i <= m; ++i) {
		inTree[i] = dsu.join(edges[i].u, edges[i].v);
	}
	
	for (int i = 1; i <= n; ++i) {
		if (dsu.find(i) == i) numComp++;
	}
	
	int used = 0;
	ll res = 0;
	for (int i = m; i >= 1; --i) {
		if (!inTree[i] && used < numComp - 1) res += edges[i].c;
		used++;
	}
	
	cout << res << endl;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    loadGraph();
    process();
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
