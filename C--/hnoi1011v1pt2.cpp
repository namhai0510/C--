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

struct Data {
	ll c1;
	ll ca;
	ll cA;
};

Data ps[maxn + 2];
string s;
ll n, cnt = 0;
ll l, r, mid, pos;

bool Check(int begin, int end) {
    ll num1 = ps[end].c1 - ps[begin - 1].c1;
    ll numa = ps[end].ca - ps[begin - 1].ca;
    ll numA = ps[end].cA - ps[begin - 1].cA;
    return (num1 > 0 && numa > 0 && numA > 0 && end - begin + 1 >= 6);
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
	
	cin >> s;
	
	n = s.size();
	s = '#' + s; 
	
	ps[0] = {0, 0, 0};
	for (int i = 1; i <= n; ++i) {
		ps[i] = ps[i - 1];
		
		if (s[i] >= '0' && s[i] <= '9') ps[i].c1++;
		if (s[i] >= 'a' && s[i] <= 'z') ps[i].ca++;
		if (s[i] >= 'A' && s[i] <= 'Z') ps[i].cA++;
	}   
	
	for (int i = 1; i <= n - 6 + 1; ++i) {
		pos = -1;
		
		l = i;
		r = n;
		
		while (l <= r && r - i + 1 >= 6) {
	        mid = (l + r) / 2;
	        if (Check(i, mid)) {
	            pos = mid;
	            r = mid - 1;
	        } 
	        else l = mid + 1;
	    }
	    
	    if (pos != -1) cnt += n - pos + 1;
	    else break;
	}
	
	cout << cnt << endl;
	
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
