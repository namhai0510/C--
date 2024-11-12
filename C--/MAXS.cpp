#include <bits/stdc++.h>

using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
const ll oo = 1e13;
const ll inf = 1e18 + 5;
const int maxn = 1e6;

ll m, n, a[maxn], st = 0;
string s, res = "0";

int cmp(string a, string b) {
    a.insert(0, max(0, (int)(b.length() - a.length())), '0');
    b.insert(0, max(0, (int)(a.length() - b.length())), '0');
    if (a > b) return 1;
    if (a == b) return 2;
    return 3;
}

void Input() {
    nothing
    if (fopen("MAXS.inp", "r")) {
        freopen("MAXS.inp", "r", stdin);
        freopen("MAXS.out", "w", stdout);
    }
    cin >> s;
}

void Solve() {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            string t;
            while (s[i] >= '0' && s[i] <= '9') {
                t += s[i];
                i++;
            }
            if (cmp(res, t) == 3) {
                res = t;
            }
        }
    }
}

void Output() {
    while (res[st] == '0') {
        st++;
    }
    for (int i = st; i < res.size(); i++) cout << res[i];
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}

int main() {
    Input();
    Solve();
    Output();
    return 0;
}
