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

ll q, n, p[maxn + 2], ans[maxn + 2];
vector<ll> now;
bool visited[maxn + 2];

int main() {
    nothing
    if (fopen("books_exchange.inp", "r")) {
        freopen("books_exchange.inp", "r", stdin);
        freopen("books_exchange.out", "w", stdout);
    }
    cin >> q;
    while (q--) {
    	cin >> n;
    	memset(visited, 0, sizeof(visited));
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> p[i];
    	}
    	
    	for (int i = 1; i <= n; ++i) {
    		if (visited[i] == 0) {
    			now.clear();
    			
    			while (visited[i] == 0) {
    				now.pb(i);
    				visited[i] = 1;
    				i = p[i];
    			}
    			
    			for (auto it : now) ans[it] = now.size();
    		}
    	}
    	
    	for (int i = 1; i <= n; ++i) {
    		cout << ans[i] << " ";
	    }
	    cout << endl;
	}
    return 0;
}
