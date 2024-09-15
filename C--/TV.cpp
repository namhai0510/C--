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

ll n, q, l, r, k, st, x, a[maxn + 2];
bool allbin = 1;

void Input() {
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        
        if (a[i] != 0 && a[i] != 1) allbin = 0;
    }
}

void Sub3() {
    while (q--) {
        ll zero_blocks = 0;
        
        cin >> l >> r >> k;
        
        bool exist_zero = 0, exist_one = 0;
        for (int i = l; i <= r; i++) {
            if (a[i] == 1) exist_one = 1;
            if (a[i] == 0) {
                zero_blocks++;
                
                if (zero_blocks > 1) break;
                
                while (a[i] == 0) {
                    if (i == r) break;
                    i++;
                }
                
                exist_zero = 1;
            }
        }
        
        if (zero_blocks == 1) cout << k << endl;
        else if (!exist_zero) cout << k - 1 << endl;
        else if (zero_blocks > 1) cout << k + 1 << endl;
    }
}

void Process() {
    while (q--) {
        cin >> l >> r >> k;
        if (k == 0) {
            bool non_zero = 0;
            
            for (int i = l; i <= r; ++i) {
                if (a[i] != 0) {
                    cout << "1\n";
                    non_zero = 1;
                    break;
                }
            }
            
            
            if (!non_zero) cout << 0 << endl;
        }
        else {
            bool res = 0;
            st = a[l];
            x = 0;
            
            if (st > k) {
                cout << k + 1 << endl;
                res = 1;
            }
            
            if (st < k) ++x;
            
            if (!res) {
                for (int i = l + 1; i <= r; i++) {
                    if (a[i] > k) {
                        cout << k + 1 << endl;
                        res = 1;
                        break;
                    }
                    if (a[i] != k && a[i] != a[i - 1]) {
                        x++;
                    }
                }
                
                if (!res) cout << x << endl;
            }
        }
    }
}

int main() {
	nothing
    if (fopen("TV.inp", "r")) {
        freopen("TV.inp", "r", stdin);
        freopen("TV.out", "w", stdout);
    }
    Input();
    
    if (allbin) Sub3();
    else Process();
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
