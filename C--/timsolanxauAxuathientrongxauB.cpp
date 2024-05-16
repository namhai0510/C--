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

ll POW[maxn + 2], hashB[maxn + 2];
string A, B;
ll lenA, lenB;

vector<ll> ans;

ll getHash (int i, int j) {
    return (hashB[j] - hashB[i - 1] * POW[j - i + 1] + modd * modd) % modd;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> A >> B;
    
    lenA = A.size();
    lenB = B.size();
    
	A = '#' + A;
	B = '#' + B;
	
	POW[0] = 1;
	for (int i = 1; i <= lenB; ++i) {
		POW[i] = (POW[i - 1] * base) % modd;
	}
	
	for (int i = 1; i <= lenB; ++i) {
		hashB[i] = (hashB[i - 1] * base + B[i] - 'a' + 1) % modd;
    }
    
    ll hashA = 0;
    for (int i = 1; i <= lenA; ++i) {
    	hashA = (hashA * base + A[i] - 'a' + 1) % modd;
    }
    
    for (int i = 1; i <= lenB - lenA + 1; ++i) {
    	if (hashA == getHash(i, i + lenA - 1)) ans.pb(i);
    }
    
    cout << ans.size() << endl;
    for (auto it : ans) cout << it << " ";
    
    return 0;
}
