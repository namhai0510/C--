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
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll t, n, a[maxn + 2], cnt = 0;
bool ev[maxn + 2];

int main() {
    nothing
    if (fopen("good_subarrays_easy_ver.inp", "r")) {
        freopen("good_subarrays_easy_ver.inp", "r", stdin);
        freopen("good_subarrays_easy_ver.out", "w", stdout);
    }
    cin >> t;
    while (t--) {
    	cnt = 0;
    	cin >> n;
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    	}
    	
    	int l = 1;
    	for (int r = 1; r <= n; ++r) {
    		while (a[r] < r - l + 1) l++;
    		
    		cnt += 1LL * (r - l + 1);
    	}
    	
    	cout << cnt << endl;
    }
    return 0;
}