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
const ll modd = 1e9 + 7;
const int maxn = 1e7 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll n;
vector<ll> a;

vector<ll> prime;
bool Check[maxn + 2];

void Sieve() {
	memset(Check, 1, sizeof(Check));
	Check[0] = Check[1] = false;
	
	for (int i = 2; i * i <= maxn; ++i)
		if (Check[i])
			for (int j = i * i; j <= maxn; j += i) Check[j] = 0;
			
	for (int i = 3; i <= maxn; ++i) 
		if (Check[i]) prime.pb(i);
}


void BruteForce(int id, int num, ll val) {
	if (num == n) {
		if (val % n == 0 && Check[val / n]) {
            cout << n << endl;
            for (auto i: a) cout << i << " ";
            exit(0);
        }
        
        return;
	}
	
	if (id == prime.size()) return;
	
	a.push_back(prime[id]);
	BruteForce(id + 1, num + 1, val + prime[id]);
	a.pop_back();
	BruteForce(id + 1, num, val);
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    Sieve();
    
    n = 600000;
    shuffle(prime.begin(), prime.end(), mt19937(0));
    
    BruteForce(0, 0, 0);
    
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/vnoj_round_01_c
