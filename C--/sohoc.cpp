Số nguyên dương K được gọi là số nguyên tố đặc biệt nếu K là số nguyên tố và số K cộng với
các chữ số của K cũng là một số nguyên tố. Ví dụ với K=11 thì K là số nguyên tố đặc biệt vì K là số
nguyên tố và K cộng với các chữ số của K (11+1+1=13) cũng là số nguyên tố, với K=17 không được
gọi là số nguyên tố đặc biệt.
Yêu cầu: Cho số nguyên dương n và dãy số A gồm n số nguyên dương A1, A2, …, An. Em hãy đếm
các số trong dãy số A là số nguyên tố đặc biệt.
Dữ liệu: đọc vào từ file văn bản SOHOC.INP gồm:
- Dòng 1: ghi số nguyên dương n (n ≤ 106
);
- Dòng 2: ghi n số nguyên dương A1, A2, …, An (Ai ≤ 106
, i=1..n)
------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define hydrogen ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define ll long long
const int maxn = 1e7 + 5;
ll n,a[maxn],ans = 0;
bool PR[maxn];
void SangNT() {
    memset(PR, 1 , sizeof(PR));
    PR[0] = 0; PR[1] = 0;
    for (int i = 2; i <= sqrt(maxn); i++) {
        if (PR[i] == 1) {
            for (int j = i*i; j <= maxn; j += i) {
                PR[j] = 0;
            }
        }
    }
}
void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}
void Solve() {
    for (int i = 1; i <= n; i++) {
        if (PR[a[i]] == 1) {
            int k = a[i];
            int res = 0;
            while (k > 0) {
                res += k%10;
                k = k/10;
            }
            if(PR[res + a[i]] == 1) ans++;
            //cout << res << " " << a[i] << " " << PR[res + ans] << endl;
        }
    }
}
void Output() {
    cout << ans;
}
int main() {
    hydrogen;
    SangNT();
    Input();
    Solve();
    Output();
}
