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

ll n, m, a[maxn], res = -oo, cnt[maxn];

// Function to count divisors of x
ll Analyze(ll x) {
    ll cnt = 0;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) cnt += 2;
        if (i == sqrt(x)) cnt--;
    }
    return cnt;
}

// Function to read input data
void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[i] = Analyze(a[i]);
    }
}

// Function to find the maximum count of divisors
void Solve() {
    for (int i = 1; i <= n; i++) {
        if (res < cnt[i]) {
            res = cnt[i];
            m = i;
        }
    }
}

// Function to print the result
void Output() {
    cout << a[m] << endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}

int main() {
	nothing
    if (fopen("Uocso.inp", "r")) {
        freopen("Uocso.inp", "r", stdin);
        freopen("Uocso.out", "w", stdout);
    }
    
    Input();
    Solve();
    Output();
    return 0;
}