#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll oo = 0x3f3f3f3f;
const ll mod = 1e9;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

bool Prime[maxn];
void Sieve() {
    memset(Prime, true, sizeof(Prime));
    Prime[0] = false; Prime[1] = false;
    
    for (int i = 2; i * i < maxn; i++) {
        if (Prime[i]) {
            for (int j = i * i; j < maxn; j += i) {
                Prime[j] = false;
            }
        }
    }
}

ll n, cnt = 0;
string s;

int main() {
    nothing
    if (fopen("LC_BAI02.inp", "r")) {
        freopen("LC_BAI02.inp", "r", stdin);
        freopen("LC_BAI02.out", "w", stdout);
    }
    Sieve();
    
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        bool ok = true;
        while (s != "") {
            ll t = stoi(s);
            if (Prime[t] == false) {
                ok = false;
                break; 
            }
            s.pop_back();
        }
        if (ok) cnt++;
    }
    cout << cnt << endl;
    
    return 0;
}