#include<bits/stdc++.h>
using namespace std;

#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n";
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll modd = 1e9 + 7;
const ll maxn = 1e6 + 2;
const ll maxa = 2e3 + 2;

string p[] = {"0", "ABC", "ACB", "BAC", "BCA", "CAB", "CBA"};
ll test, n;
string s;

bool Solve(ll x1, ll x2, ll x3, ll x4, ll x5, ll x6) {
	int now = 1, it = 0;
	
	for (int i = 1; i <= n; ++i) {
		if (now == 1) it = x1;
		if (now == 2) it = x2;
		if (now == 3) it = x3;
		if (now == 4) it = x4;
		if (now == 5) it = x5;
		if (now == 6) it = x6;
		
		if (now >= 7) return 1;
		
		if (s[i] == p[it][0]) {
			if (s[i + 1] == p[it][1] && s[i + 2] == p[it][2]) now++, i += 2;
		}
	}
	
	// cout << now << endl;
	if (now >= 7) return 1;
	else return 0;
}

bool ok = 0;

int main() {
	nothing
	if (fopen("ss.inp", "r")) {
		freopen("ss.inp", "r", stdin);
		freopen("ss.out", "w", stdout);
	}
	cin >> test;
	
	while (test--) {
		cin >> s;
		
		n = s.size();
		s = '#' + s + "##";
		ok = 0;
		
		if (s.size() < 19) {
			cout << "NO" << endl;
			continue;
		}
		
		for (int p1 = 1; p1 <= 6; ++p1) {
			for (int p2 = 1; p2 <= 6; ++p2) {
				if (ok) break;
				
				if (p2 == p1) continue;
				
				for (int p3 = 1; p3 <= 6; ++p3) {
					if (ok) break;
					
					if (p3 == p1) continue;
					if (p3 == p2) continue;
					
					for (int p4 = 1; p4 <= 6; ++p4) {
						if (ok) break;
						
						if (p4 == p1) continue;
						if (p4 == p2) continue;
						if (p4 == p3) continue;
						
						for (int p5 = 1; p5 <= 6; ++p5) {
							if (ok) break;
							
							if (p5 == p1) continue;
							if (p5 == p2) continue;
							if (p5 == p3) continue;
							if (p5 == p4) continue;
							
							for (int p6 = 1; p6 <= 6; ++p6) {
								if (ok) break;
								
								if (p6 == p1) continue;
								if (p6 == p2) continue;
								if (p6 == p3) continue;
								if (p6 == p4) continue;
								if (p6 == p5) continue;
								
								if (Solve(p1, p2, p3, p4, p5, p6)) {
									ok = 1;
									break;
								}
							}
						}
					}
				}
			}
		}
		
		if (ok) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}

