#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n;
struct Data {
	ll a, b, id;
} p[maxn + 2];

bool cmp (Data A, Data B) {
	return (min(A.a, B.b) < min(A.b, B.a));
}

int main() {
    nothing
    if (fopen("nk2mfs.inp", "r")) {
        freopen("nk2mfs.inp", "r", stdin);
        freopen("nk2mfs.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> p[i].a;
    }
    for (int i = 1; i <= n; ++i) {
    	cin >> p[i].b;
    	p[i].id = i;
    }
    
    sort(p + 1, p + 1 + n, cmp);
	// chon con co tgian lam ngan nhat de len trc
    
    ll stA, stB, enA, enB;
    stA = stB = enA = enB = 0;
    
    for (int i = 1; i <= n; ++i) {
    	stA = enA;
    	enA = stA + p[i].a;
    	stB = max(enA, enB);
    	enB = stB + p[i].b;
    }
    
    cout << enB << endl;
    for (int i = 1; i <= n; ++i) cout << p[i].id << " ";
    
    return 0;
}
