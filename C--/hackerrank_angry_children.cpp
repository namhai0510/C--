#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define se second
#define pb push_back
const ll oo = 1e13;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll n, k, a[maxn + 2], ans, sum, tmp;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> k;
    
    for (int i = 0; i <= n - 1; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    tmp = sum = 0;
    
    sum += a[0];
    for (int i = 1; i <= k - 1; ++i) {
        tmp += a[i] * i - sum;
        sum += a[i];
    }
    ans = tmp;
    
    for (int i = k; i <= n - 1; ++i) {
        tmp -= (sum - a[i - k] * k);
        sum -= a[i - k];
        tmp += (a[i] * (k - 1) - sum);
        sum += a[i];
        
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}

// https://www.hackerrank.com/challenges/angry-children-2/problem?isFullScreen=true