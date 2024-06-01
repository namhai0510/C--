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
ll test, n, cnt[7];
string s;

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
		
		for (int i = 1; i <= 6; ++i) cnt[i] = 0;
		
		if (s.size() < 19) {
			cout << "NO" << endl;
			continue;
		}
		
		for (int i = 1; i <= n; ++i) {
			if (s[i] == 'A') {
				if (s[i + 1] == 'B' && s[i + 2] == 'C') cnt[1]++, i += 2;
				else if (s[i + 1] == 'C' && s[i + 2] == 'B') cnt[2]++, i += 2;
			}
			else if (s[i] == 'B') {
				if (s[i + 1] == 'A' && s[i + 2] == 'C') cnt[3]++, i += 2;
				else if (s[i + 1] == 'C' && s[i + 2] == 'A') cnt[4]++, i += 2;
			}
			else if (s[i] == 'C') {
				if (s[i + 1] == 'A' && s[i + 2] == 'B') cnt[5]++, i += 2;
				else if (s[i + 1] == 'B' && s[i + 2] == 'A') cnt[6]++, i += 2;
			}
		}
		
		bool check = 1;
		for (int i = 1; i <= 6; ++i) {
			if (cnt[i] == 0)  {
				check = false;
			 	break;
			}
		}
			
		if (check) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}

