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

int count_beautiful_submatrices(int m, int n, int k, const vector<vector<int>>& A) {
    // Tạo mảng tổng tiền tố
    vector<vector<ll>> prefix_sum(m + 1, vector<ll>(n + 1, 0));

    // Điền giá trị vào mảng tổng tiền tố
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            prefix_sum[i][j] = A[i - 1][j - 1] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
        }
    }

    int count = 0;

    // Duyệt qua tất cả các bảng con
    for (int u = 1; u <= m; ++u) {
        for (int v = 1; v <= n; ++v) {
            for (int p = u; p <= m; ++p) {
                for (int q = v; q <= n; ++q) {
                    ll total = prefix_sum[p][q] 
                             - prefix_sum[u - 1][q] 
                             - prefix_sum[p][v - 1] 
                             + prefix_sum[u - 1][v - 1];
                    if (total % k == 0) {
                        ++count;
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    int m, n, k;
    cin >> m >> n >> k;
    
    vector<vector<int>> A(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    // Tính và in ra số lượng bảng số đẹp
    int result = count_beautiful_submatrices(m, n, k, A);
    cout << result << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
