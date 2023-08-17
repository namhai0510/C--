#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 5e3 + 5;

int n;
ll a[maxn], b[maxn], f[maxn][2];
signed main() {
    nothing
    if (fopen("boundary.inp", "r")) {
        freopen("boundary.inp", "r", stdin);
        freopen("boundary.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    
    f[1][0] = a[1];
    f[1][1] = b[1];
    
    for (int i = 2; i <= n; i++) {
        f[i][0] = max(f[i - 1][0] + abs(b[i] - b[i - 1]), f[i - 1][1] + abs(b[i] - a[i - 1])) + a[i];
        f[i][1] = max(f[i - 1][0] + abs(a[i] - b[i - 1]), f[i - 1][1] + abs(a[i] - a[i - 1])) + b[i];
    }
    cout << max(f[n][0], f[n][1]);
}

// Bờm nuôi một chú thằn lằn tham ăn và lười nhác nên muốn bày ra một trò chơi cho nó tập thể dục. Bộ đồ chơi
// của Bờm có 𝑛 viên gạch hình chữ nhật đánh số từ 1 đến 𝑛, hình chữ nhật thứ 𝑖 có hai cạnh là 𝑎𝑖
// , 𝑏𝑖
// . Bờm đặt 𝑛 viên
// gạch vào sát nhau theo đúng thứ tự từ 1 đến 𝑛 từ trái qua phải, đáy của các viên gạch nằm trên một đường thẳng
// nằm ngang tạo thành một mô hình, xung quanh mô hình đổ nước vì con thằn lằn này khá sợ nước.
// Tiếp theo Bờm đặt con thằn lằn vào góc trên trái của viên gạch đầu tiên và thức ăn vào góc trên phải của viên gạch
// cuối cùng. Con thằn lằn sẽ phải bò qua cạnh các viên gạch để đến nơi có đồ ăn.
// Ví dụ nếu Bờm dựng mô hình với 5 viên gạch kích thước 1 × 3, 2 × 4, 1 × 5, 1 × 4,
// 2 × 5 như hình bên, con thằn lằn sẽ phải bò qua quãng đường độ dài 11 để tới nơi có
// đồ ăn
// Các viên gạch của Bờm có màu sắc khác nhau và Bờm không muốn thay đổi thứ tự các viên gạch để giữ được
// tính hài hòa về màu sắc. Tuy nhiên Bờm nhận thấy rằng có thể xoay một số viên gạch đi 90 độ rồi dựng lại mô
// hình mới, giữ nguyên thứ tự các viên gạch mà con đường di chuyển của thằn lằn sẽ dài hơn, yêu cầu nó phải vận
// động nhiều hơn.
// Yêu cầu: Hãy chỉ cách cho Bờm dựng một mô hình mà quãng đường di chuyển của con thằn lằn là dài nhất có thể
// (chú ý là không được thay đổi thứ tự các viên gạch).
// Dữ liệu: Vào từ file văn bản BOUNDARY.INP
// Dòng 1 chứa số nguyên dương 𝑛 ≤ 105
// 𝑛 dòng tiếp theo, mỗi dòng chứa hai số nguyên dương 𝑎𝑖
// , 𝑏𝑖 ≤ 109
// cách nhau bởi dấu cách
// Kết quả: Ghi ra file văn bản BOUNDARY.OUT một số nguyên duy nhất là độ dài quãng đường con thằn lằn phải di
// chuyển trên mô hình tìm được

// goi f(i, 0) : do dai lon nhat neu o vi tri i chon a[i] la chieu ngang, b[i] la chieu doc 
// goi f(i, 1) : do dai lon nhat neu o vi tri i chon b[i] la chieu ngang, a[i] la chieu doc
// tu do co f[1][0] = a[i], f[1][1] = b[1]