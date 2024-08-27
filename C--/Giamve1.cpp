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
const int maxn = 2e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

int n, q, a[maxn + 2], res, nt[maxn + 2], mp[maxn + 2], v[20];

void Sieve() {
    for (int i = 2; i <= maxn; ++i) nt[i] = i;
    for (int i = 2; i * i <= maxn; ++i) 
        if (nt[i] == i) 
            for (int j = i * i; j <= maxn; j += i) 
                if (nt[j] == j) nt[j] = i;    
}

int u(int x) {
    if (x == 0) return 0;
    int c = 0;
    while (x != 1) {
        ++c; 
        x /= nt[x];
    }
    
    return c;
}

int uc(int x, int y) {
    if (x == 0 || y == 0) return 0;
    
    int ans = 0;
    int id = 0;
    
    while (x > 1) {
        if (!mp[nt[x]]) v[id++] = nt[x];
        ++mp[nt[x]];
        x /= nt[x];
    }
    
    while (y > 1) {
        int gan = nt[y], c = 0;
        while (y % gan == 0) {
            y /= gan;
            ++c;
        }
        ans += min(c, mp[gan]);
    }
    
    for (int i = 0; i < id; ++i) mp[v[i]] = 0;
    
    return ans;
}


int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    Sieve();
    
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        res += u(a[i]) - uc(a[i], a[i - 1]);
    }
    
    cout << res << endl;
    while (q--) {
        int i, v;
        cin >> i >> v;
        res -= u(a[i]) - uc(a[i], a[i - 1]) - uc(a[i + 1], a[i]);
        a[i] = v;
        res += u(a[i]) - uc(a[i], a[i - 1]) - uc(a[i + 1], a[i]);
        cout << res << endl;
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://nguyenhue2024.contest.codeforces.com/group/8Tw3vQnae2/contest/545662/problem/A