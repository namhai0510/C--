/*Trong một chuyến thám hiểm mạo hiểm, một đoàn thám hiểm không may lọt vào mê cung với rất nhiều cạm bẫy. 
Trong mê cung đó chỉ có một lối ra duy nhất, lối ra bao gồm các ô hình vuông, được xếp thành một hàng dài. 
Muốn đi được ra ngoài, mọi người phải bước qua một hang các ô hình vuông đó và phải bước theo quy tắc sau:
-Quy tắc 1: Mỗi bước đi chỉ có thể bước một ô, hai ô hoặc ba ô.
-Quy tắc 2: Người thứ 2 trở đi bước theo quy tắc 1, và không trùng với các bước của những người đi trước đó.
Hỏi đoàn thám hiểm đó còn lại tối thiểu bao nhiêu người có thể thoát ra khỏi mê cung.

Dữ liệu vào:
-Dòng đầu tiên chứa số M (M<= 10^250) là số người trong mê cung đó.
-Dòng thứ 2 chứa số N (N<=1000) là tổng số ô vuông.

Dữ liệu ra:
-Một dòng duy nhất là kết quả của bài toán.
----------------------------------------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;
#define hydrogen ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 3;
const int maxa = 1e3 + 3;
ll m; ll n;
ll f[maxn];

void Input() {
    cin >> m >> n;
}

void Solve() {
    f[1] = 1; f[2] = 2; f[3] = 4;
    for (int i = 4; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    }
}

void Truyvet() {
    
}

void Output() {
    if (m >= f[n]) cout << m - f[n] << endl;
    else cout << "0" << endl;
}

int main() {
    hydrogen;
    Input();
    Solve();
    Output();
    return 0;
}
