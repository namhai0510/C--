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

ll n;
ll num[maxn + 2], ps[maxn + 2];
ll cur1, cur2, tmp;

void Init() {
	num[1] = ps[1] = 15;
	
	ll tmp;
	for (int i = 2; i <= 7; ++i) {
		tmp = 15;
		for (int j = 2; j <= i; ++j) tmp *= 16;
		
		ps[i] = ps[i - 1] + tmp;
		num[i] = num[i - 1] + (tmp * i);
	}
	
	// for (int i = 1; i <= 7; ++i) cout << ps[i] << " ";
	// cout << endl;
	// for (int i = 1; i <= 7; ++i) cout << num[i] << " ";
	// cout << endl;
}

string Get(ll n) {
	stack<string> s;
	string ret = "";
	
	while (n > 0) {
		tmp = n % 16;
		if (tmp < 10) s.push(to_string(tmp));
		else if (tmp == 10) s.push("A");
		else if (tmp == 11) s.push("B");
		else if (tmp == 12) s.push("C");
		else if (tmp == 13) s.push("D");
		else if (tmp == 14) s.push("E");
		else if (tmp == 16) s.push("F");
		
		n /= 16;
	} 
	
	while (!s.empty()) {
		ret += s.top();
		s.pop();
	}
	
	return ret;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    Init();
    
    cin >> n;
    
    if (n < num[1]) cout << Get(n) << endl;
    else if (n <= num[2]) {
        cur1 = (n - num[1] + 1) / 2;
        cur2 = cur1 + ps[1];
        tmp = (n - num[1]) % 2;
        if (tmp == 0) tmp = 2;
        
        string x = Get(cur2);
        cout << x[tmp - 1];
    }
    else if (n <= num[3]) {
        cur1 = (n - num[2] + 2) / 3;
		cur2 = cur1 + ps[2];
        tmp = (n - num[2]) % 3;
        if (tmp == 0) tmp = 3;
        
        string x = Get(cur2);
        cout << x[tmp - 1];
    }
    else if (n <= num[4]) {
        cur1 = (n - num[3] + 3) / 4;
        cur2 = cur1 + ps[3];
        tmp = (n - num[3]) % 4;
        if (tmp == 0) tmp = 4;
        
        string x = Get(cur2);
        cout << x[tmp - 1];
    }
    else if (n <= num[5]) {
        cur1 = (n - num[4] + 4) / 5;
        cur2 = cur1 + ps[4];
        tmp = (n - num[4]) % 5;
        if (tmp == 0) tmp = 5;
        
        string x = Get(cur2);
        cout << x[tmp - 1];
    }
    else if (n <= num[6]) {
        cur1 = (n - num[5] + 5) / 6;
        cur2 = cur1 + ps[5];
        tmp = (n - num[5]) % 6;
        if (tmp == 0) tmp = 6;
        
        string x = Get(cur2);
        cout << x[tmp - 1];
    }
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}