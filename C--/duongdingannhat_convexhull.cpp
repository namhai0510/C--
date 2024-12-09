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

struct Coordinate {
    int x, y, id;
};

Coordinate a[maxn + 2], b[maxn + 2];
int n, m, num, c;
double P;

bool Cmp (Coordinate p, Coordinate q) {
    return (p.x < q.x || (p.x == q.x && p.y < q.y));
}

pair<int,int> vctr (Coordinate p, Coordinate q) {
    return (make_pair(q.x - p.x, q.y - p.y));
}

ll CCW (Coordinate p, Coordinate q, Coordinate r) {
    pair<int,int> u = vctr(p,q);
    pair<int,int> v = vctr(q,r);
    return (1ll * u.fi * v.se - 1ll * u.se * v.fi);
}


bool Cmp2 (Coordinate p, Coordinate q) {
    ll CW = CCW(a[1], p, q);
    if (CW == 0) return (Cmp(p, q));
    return (CW > 0);
}

void Convex_Hull(Coordinate a[], int n, Coordinate b[], int &m) {
    sort (a + 1, a + n + 1, Cmp); // lấy phần tử thấp nhất
    sort (a + 2, a + n + 1, Cmp2); // sort theo góc quay
    b[m = 1] = a[1];
    for (int i = 2; i <= n; i++){
        while (m > 1 && CCW(b[m - 1], b[m], a[i]) <= 0) m--;
        b[++m] = a[i];
    }
}

double Distance (Coordinate p, Coordinate q) {
    ll hx = p.x - q.x;
    ll hy = p.y - q.y;
    return sqrt(hx * hx + hy * hy);
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n;
    
    cin >> a[1].x >> a[1].y;
    a[1].id = 1;
    cin >> a[2].x >> a[2].y;
    a[2].id = 2;
    
    c = 3;
    
    for (int i = 1; i <= n; ++i) {
    	ll x1, y1, x2, y2;
    	
    	a[c].x = x1;
    	a[c].y = y1;
    	a[c].id = c;
    	c++;
    	a[c].x = x2;
    	a[c].y = y2;
    	a[c].id = c;
    	c++;
    }
    
    Convex_Hull(a, n, b, m);
    
    P = 0.0;
    
    for (int i = 1; i <= m; i++) {
        P += Distance(b[i], b[i + 1]);
    }
    
    cout << setprecision(3) << fixed << P << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
