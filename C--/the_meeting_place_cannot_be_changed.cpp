#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const double oo = 1e12 + 1;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const double epsilon = 0.000001;
struct Data {
	ll x, v;
} a[maxn + 2];

pair<double, double> pos[maxn + 2];
double ans = 0.0;
ll n;

bool Check(double t) {
	double lmax = -oo, rmin = +oo;
	for (int i = 1; i <= n; ++i) {
		pos[i].fi = (a[i].x - a[i].v * t);
		pos[i].se = (a[i].x + a[i].v * t);
	}
	
	for (int i = 1; i <= n; ++i) {
		lmax = max(lmax, pos[i].fi);
		rmin = min(rmin, pos[i].se);
	}
	
	if (lmax <= rmin) return 1;
	return 0;
}

void Bs() {
	double l = 0.00, r = +oo, mid;
	
	while (abs(r - l) > epsilon) {
		mid = (l + r) / 2;
		
		// cout << setprecision(6) << fixed << r - l << " ";
		// cout << mid << " " << Check(mid) << endl;
		if (Check(mid) == 1) {
			r = mid;
			ans = mid;
		}
		else l = mid;
	}
}
int main() {
    nothing
    if (fopen("the_meeting_place_cannot_be_changed.inp", "r")) {
        freopen("the_meeting_place_cannot_be_changed.inp", "r", stdin);
        freopen("the_meeting_place_cannot_be_changed.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i].x;

    }
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i].v;
    }
    Bs();
    
    // for (int i = 1; i <= n; ++i) {
    	// cout << a[i].x << " " << a[i].v << endl;
    // }
    cout << setprecision(10) << fixed << ans << endl;
    return 0;
}