#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e19;
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

ll n, c1, c2, a[maxn + 2];
ll ret = 0, mx = 0, tmp[5];

void Input() {
	cin >> n >> c1 >> c2;
	
	for (int i = 1; i <= n; ++i) cin >> a[i], mx = max(mx, a[i]);
}

void Sub1() {
	for (int i = 1; i <= n; ++i) ret += mx - a[i];
	
	cout << ret * c1 << endl;
}

void Sub2() {
	priority_queue<ll> s;
	for (int i = 1; i <= n; ++i)
		if (mx - a[i] > 0) s.push(mx - a[i]);
		
	while (s.size() >= 2) {
		tmp[1] = s.top();
		s.pop();
		tmp[2] = s.top();
		s.pop();
		
		ret += tmp[2] * c2;
		
		if (tmp[1] - tmp[2] > 0)
			s.push(tmp[1] - tmp[2]);
	}
	
	while (s.size()) {
		ret += s.top() * c1;
		s.pop();
	}
	
	cout << ret << endl;
}

void Sub4() {
	ll l = mx, r = mx * 2;
	ll mn = 10000000;
	
	ret = +oo;
	
	for (int i = 1; i <= n; ++i) mn = min(mn, a[i]), tmp[1] += l - a[i];
	
	for (int i = l; i <= r; ++i) {
		tmp[2] = tmp[1];
		tmp[3] = 0;
		tmp[4] = i - mn;
		tmp[2] -= tmp[4];
		
		if (tmp[2] < tmp[4]) tmp[3] = c2 * tmp[2] + c1 * (tmp[4] - tmp[2]);
		else {
			tmp[3] = c2 * tmp[4];
			tmp[2] -= tmp[4];
			tmp[3] += c2 * (tmp[2] / 2);
			tmp[2] &= 1;
			
			if (tmp[2]) tmp[3] += c1;
		}
		
		ret = min(ret, tmp[3]);
		tmp[1] += n;
	}
	
	cout << ret << endl;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    Input();
    
    if (c1 * 2 <= c2) Sub1();
    else if (c1 <= c2) Sub2();
    else Sub4();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://oj.vnoi.info/problem/bedao_r20_c
