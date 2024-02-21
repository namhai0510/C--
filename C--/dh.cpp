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

ll h, m, x;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> x;
    	
    h = (x / 60) % 12;
    m = x % 60;
    
    double angle = abs(30 * h - 5.5 * m);
    
    cout << fixed << setprecision(2) << min(abs(angle), abs(360 - angle)) << endl;
    return 0;
}

// Sau x phut, kim gio va kim phut se tao voi nhau 1 goc bao nhieu do (Chi tinh den 
// 180), Biet ban dau la 12h
