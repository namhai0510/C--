Để tạo niềm vui cho mọi người, chính quyền quyết định lắp đặt một thiết bị ở nơi công cộng. Thiết
bị này giao tiếp với mọi người thông qua bàn phím và màn hình và có một số nguyên lưu bên trong
bộ nhớ của nó. Ban đầu số nguyên này khởi đầu bằng 1.
Thiết bị hoạt động như sau:
 Một người gõ một số nguyên từ bàn phím
 Thiết bị sẽ nhân số trong bộ nhớ của nó với số nguyên vừa gõ và kết quả được lưu lại vào
chính bộ nhớ này.
 Thiết bị sẽ hiển thị lời chào lên màn hình nếu như số trong bộ nhớ là số chính phương. Khi
đó người gõ số sẽ được nhiều may mắn.
Viết chương trình, cho biết dãy số nguyên mà những người chơi lần lượt gõ, xác định xem người
chơi nào sẽ là người may mắn.
Dữ liệu: vào từ file SQRNUM.INP
 Dòng đầu tiên chứa số nguyên N (1≤N≤500000) là số lượng người tham gia giao tiếp với
thiết bị.
 Tiếp theo là N dòng, mỗi dòng ghi một số nguyên được gõ bởi một người theo thứ tự
giao tiếp với thiết bị. Các số nguyên này nằm giữa 1 và 106
.
Chú ý rằng kết quả số trong bộ nhớ có thể vượt quá kiểu số nguyên 64 bit
-----------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define atami ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define ll long long
#define pb push_back
const int maxn = 1e6 + 5;
double epsilon = 0.000000001;
ll n,cnt = 0;
bool check[maxn];
vector<ll> luu;
void SangNT() {
    memset(check,true,sizeof(check));
    check[0]=false;
    check[1]=false;
    for (int i = 2;i <= sqrt(maxn); i++) {
        if (check[i]) {
            luu.pb(i);
            for (int j = i * i; j <= maxn;j += i) {
                check[j]=false;
            }
        }
    }
}
void Input() {
    cin >> n;
}
void Solve() {
    vector<ll> kq(maxn, 0);
    for (int i = 1; i <= n; i++) {
        ll k; cin >> k;
        bool ok = true;
        ll t = k;
        vector<ll> save;
        for (int i = 0; t > 1;) {
            if (t % luu[i] == 0) {
                save.pb(luu[i]);
                t /= luu[i];
            }
            else i++;
        }
        for (auto it : save) {
            if (kq[it] % 2) {
                cnt++;
            }
            else cnt--;
            kq[it]++;
        }
        if (cnt == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
int main(){
    freopen("SS.INP","r",stdin);
    atami;
    SangNT();
    Input();
    Solve();
}
