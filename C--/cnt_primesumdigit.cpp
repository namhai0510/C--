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
#define MAX_DIGIT 18

vector<int> primes;
bool is_prime[200];

// Kiểm tra số nguyên tố
void sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < 200; i++) {
        if (is_prime[i]) {
            primes.pb(i);
            for (int j = i * i; j < 200; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

// Hàm DP
ll dp[MAX_DIGIT][200][2];
vector<int> digits;

// DP đếm số lượng p thỏa mãn điều kiện
ll digit_dp(int pos, int sum, bool tight) {
    if (pos == digits.size()) {
        // Nếu đã duyệt hết chữ số, kiểm tra xem tổng có phải số nguyên tố không
        return is_prime[sum];
    }

    if (dp[pos][sum][tight] != -1) {
        return dp[pos][sum][tight];
    }

    ll res = 0;
    int limit = tight ? digits[pos] : 9;

    for (int digit = 0; digit <= limit; ++digit) {
        res += digit_dp(pos + 1, sum + digit, tight && (digit == limit));
    }

    return dp[pos][sum][tight] = res;
}

// Hàm khởi tạo DP với một số n
ll solve(ll n) {
    digits.clear();
    while (n > 0) {
        digits.pb(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());
    memset(dp, -1, sizeof(dp));
    return digit_dp(0, 0, 1);
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }

    sieve(); // Khởi tạo danh sách các số nguyên tố
    ll L, R;
    cin >> L >> R;
    cout << solve(R) - solve(L - 1) << endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
