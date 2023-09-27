#include<bits/stdc++.h>
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL);
using ll = long long;
using ull = unsigned long long;
#define in insert
#define fi first
#define se second
#define pb push_back
#define el "\n"
const ll mod = 998244353;
const int maxn = 1e6 + 5;
const int maxa = 3e4 + 5;
ll n, a[maxn];

int main() {
    nothing
    if (fopen("xs.inp","r")) {
        freopen("xs.inp","r",stdin);
        freopen("xs.out","w",stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);

    ll cnt = 0, res = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == res + 1) {
            while (a[i] == a[i + 1]) {
                cnt++;
                i++;
            }
        }
        else {
            if (cnt >= 2){
				cnt-=2;
			}
			else if (cnt == 1 && n - 1 >= res){
				cnt -= 1;
				n -= 1;
			}
			else if (cnt == 0 && n - 2 >= res){
				n -= 2;
			}
			else {
				break;
			}
			i--;
        }
        res++;
    }

    res += (cnt / 2);
    cout << res;
    return 0;
}

