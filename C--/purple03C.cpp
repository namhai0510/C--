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
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll n, res = 0;
string s, t, x;

void Init() {
	n = s.size();
    t = s;
    x = s;
    
    sort(t.begin(), t.end());
    if (t[0] == '0')
        for (int i = 1; i < n; ++i)
        	if (t[i] != '0') {
        		swap(t[i], t[0]); 
        		break;
        	}
}

int main() {
    nothing
    cin >> s;
    
    Init();
    
    for (int i = 0; i < n; ++i) {
        if (x[i] != t[i]) {
            int better = i;
            for (int k = i + 1; k < n; ++k)
                if (x[k] == t[i]) {
                    better = k; 
                    break;
                }
            
            res += abs((t[i] - x[i]) * (better - i));
            swap(x[better], x[i]);
        }
    }
    
    cout << res << endl;
    
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
