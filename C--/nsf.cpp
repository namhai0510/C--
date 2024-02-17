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

ll n, Mob[maxn + 2];

void Make_Mobius() {
	Mob[1] = 1;
	for (int i = 1; i <= maxn; i++)
		for (int j = 2 * i; j <= maxn; j += i) Mob[j] -= Mob[i];
}

ll Check(ll x) {
	ll cnt = 0;
	for (int i = 1; i <= sqrt(x); ++i) {
    	if (Mob[i] == -1) {
    		cnt -= x / (i * i);
    	}
    	else if (Mob[i] == 1) {
    		cnt += x / (i * i);
    	}
    }
    // Calculate the number of square-free integers
    
    return x - cnt; // Number of non square-free integers
}

int main() {
    nothing
    if (fopen("nsf.inp", "r")) {
        freopen("nsf.inp", "r", stdin);
        freopen("nsf.out", "w", stdout);
    }
    Make_Mobius();
    
    cin >> n;
    ll l = 1, r = 1e12, mid;
    while (l <= r) {
    	mid = (l + r) / 2;
    	
    	ll c = Check(mid);
    	if (c >= n) r = mid - 1;
    	else l = mid + 1;
    }
    
    cout << l << endl;
    return 0;
}

// Output require : Non square-free integers at n-th