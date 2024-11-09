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

struct MinMaxQueue {
    deque<vector<ll>> mn, mx;
    int len = 0;

    void push(int v) {
        len++;
        int c = 1;
        while(!mn.empty() && v < mn.back()[0]) {
            c += mn.back()[1];
            mn.pop_back();
        }
        
        mn.push_back({v,c});
        
        c = 1;
        while(!mx.empty() && v > mx.back()[0]) {
            c += mx.back()[1];
            mx.pop_back();
        }
        
        mx.push_back({v,c});
    }
    
    void pop() {
        len--;
        if(--mn.front()[1] <=0) mn.pop_front();
        if(--mx.front()[1] <=0) mx.pop_front();
    }
    
    ll min() {
        return mn.empty() ? 0 : mn.front()[0];
    }
    
    ll max() {
        return mx.empty() ? 0 : mx.front()[0];
    }
};

ll n, m, k, x;
vector<MinMaxQueue> q;
vector<ll> res;
ll l, r, best, length;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n >> m >> k;
    
    q.resize(m);
    res.resize(m);
    
    auto MaxSum = [&] {
    	ll S = 0;
    	for (int i = 0; i < m; ++i) S += q[i].max();
    	
    	return S;
    };
	
	l = r = 0;
	best = 0;
	
	while (r++ < n) {
		for (int i = 0; i < m; ++i) {
			cin >> x;
			
			q[i].push(x);
		}
		
		while (MaxSum() > k) {
            l++;
            for (int i = 0; i < m; ++i) q[i].pop();
        }
        
        length = r - l;
        if (length >  best) {
            best = length;
            for (int i = 0; i < m; ++i) res[i] = q[i].max();
        }
	}
	
	for (int i = 0; i < m; ++i) cout << res[i] << " ";
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/514/D
		