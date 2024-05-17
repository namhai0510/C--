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
const int base = 311;

const ll modx = 1e9 + 3;
ll n;
string A, B;
ll POW[maxn + 2], POWX[maxn + 2];
ll hashA[maxn + 2], hashB[maxn + 2];
ll hashAX[maxn + 2], hashBX[maxn + 2];

int getA (int l, int r) {
	return (hashA[r] - hashA[l - 1] * POW[r - l + 1] + modd * modd) % modd;
}
int getB (int l, int r) {
	return (hashB[r] - hashB[l - 1] * POW[r - l + 1] + modd * modd) % modd;
}
int getAX (int l, int r) {
	return (hashAX[r] - hashAX[l - 1] * POWX[r - l + 1] + modx * modx) % modx;
}
int getBX (int l, int r) {
	return (hashBX[r] - hashBX[l - 1] * POWX[r - l + 1] + modx * modx) % modx;
}

unordered_map<ll, ll> m, mX;

bool Check(ll val) {
	m.clear();
	for (int i = 1; i <= 2 * n; ++i) {
		if (i + val > 2 * n) break;
		
		m[getA(i, i + val - 1)] = 1;
		mX[getAX(i, i + val - 1)] = 1;
	}
	
	for (int i = 1; i <= 2 * n; ++i) {
		if (i + val > 2 * n) break;
		if (m[getB(i, i + val - 1)] == 1 && mX[getBX(i, i + val - 1)] == 1) return 1;
	}
	
	return 0;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> A >> B;
    
    n = A.size();
    
    A = '#' + A + A;
    B = '#' + B + B;
    
    POW[0] = POWX[0] = 1;
    for (int i = 1; i <= 2 * n; ++i) {
    	POW[i] = (POW[i - 1] * base) % modd;
    	POWX[i] = (POWX[i - 1] * base) % modx;
    	
    	hashA[i] = (hashA[i - 1] * base + A[i]) % modd;
		hashB[i] = (hashB[i - 1] * base + B[i]) % modd;
		
		hashAX[i] = (hashAX[i - 1] * base + A[i]) % modx;
		hashBX[i] = (hashBX[i - 1] * base + B[i]) % modx;
    }
	ll l = 1, r = n, mid, ans = 0;
    
    while (l <= r) {
		mid = (l + r) / 2;
		if (Check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	
	cout << ans << endl;
	
    return 0;
}
