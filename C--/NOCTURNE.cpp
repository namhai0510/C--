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

ll n, q;
vector<ll> a, dp, minL, minR, queries;
stack<ll> st;

ll Cnt(ll start, ll n) {
    if (dp[start] != -1) return dp[start];
    
    int L = minL[start];
    int R = minR[start];
    if (L == -1 and R == -1) {
        dp[start] = 1;
    } 
    else if (L == -1) {
        dp[start] = Cnt(R, n);
    } 
    else if (R == -1) {
        dp[start] = Cnt(L, n);
    } 
    else {
        dp[start] = (Cnt(L, n) + Cnt(R, n)) % modd;
    }
    return dp[start];
}

int main() {
    nothing
    if (fopen("NOCTURNE.inp", "r")) {
        freopen("NOCTURNE.inp", "r", stdin);
        freopen("NOCTURNE.out", "w", stdout);
    }
    cin >> n >> q;
    
    a.resize(n);
    minL.resize(n, -1);
    minR.resize(n, -1);
    dp.resize(n, -1);
    queries.resize(q);
    
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        if (!st.empty()) minL[i] = st.top();
        st.push(i);
    }
    
    while (!st.empty()) st.pop();
    
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        if (!st.empty()) minR[i] = st.top();
        st.push(i);}
        
   
    for (int i = 0; i < q; ++i) cin >> queries[i], --queries[i];
    for (int i = 0; i < n; ++i) Cnt(i, n);
    for (int i = 0; i < q; ++i) cout << dp[queries[i]] << endl;

    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
