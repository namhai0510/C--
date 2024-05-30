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
const int base = 31;

ll n;
vector<ll> ans;

bool Prime[maxn + 2];
void Eratos() {
	memset(Prime, 1, sizeof(Prime));
	Prime[0] = Prime[1] = 0;
	
	for (int i = 2; i * i <= maxn; ++i)
		if (Prime[i])
			for (int j = i * i; j <= maxn; j += i) Prime[j] = false;
}

int main() {
    nothing
    if (fopen("sd.inp", "r")) {
        freopen("sd.inp", "r", stdin);
        freopen("sd.out", "w", stdout);
    }
    Eratos();
    
	for (int i1 = 0; i1 <= 9; ++i1)
		for (int i2 = 0; i2 <= 9; ++i2)
			for (int i3 = 0; i3 <= 9; ++i3)
				for (int i4 = 0; i4 <= 9; ++i4)
					for (int i5 = 0; i5 <= 9; ++i5)
						for (int i6 = 0; i6 <= 9; ++i6)
							if (Prime[i1 * i1 + i2 * i2 + i3 * i3 + i4 * i4 + i5 * i5 + i6 * i6])
								ans.pb(i6 * 1 + i5 * 10 + i4 * 100 + i3 * 1000 + i2 * 10000 + i1 * 100000);
	
    cin >> n;
    cout << ans[n - 1];
    return 0;
}
