#include<bits/stdc++.h>

using namespace std;

int main () {
    int m,n;
    cin >> m >> n;
    vector<int> l,r,x;
    pair <int,int> p[m];
    int a,b,c;
    for (int i=0;i<m;i++) {
        cin >> p[i].second;
        p[i].first=0;
    }
    for (int i=0;i<n;i++) {
        cin >> a >> b >> c;
        l.push_back(a);
        r.push_back(b);
        x.push_back(c);
    }
    for (int i=i;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (p[j].second>=l[i] && p[j].second<=r[i] && (p[j].second-l[i])%2==0) p[j].first+=x[i];
                else if (p[j].second>=l[i] && p[j].second<=r[i] && (p[j].second-l[i])%2==1) p[j].first=p[j].first-x[i];
        }
    }
    for (int i=0;i<m;i++) {
        cout << p[i].first << endl;
    }

}
/*weath.cpp
Để nghiên cứu về tác động của biến đổi khí hậu, An tiến hành một thí nghiệm với kịch bản như sau: An chọn một số vị trí trên bản đồ và đánh số từ 1 cho đến hết. Ban đầu, độ cao so với mực nước biển của tất cả các vị trí là 0. An sẽ thực hiện n tác động biến đổi khí hậu được đánh số từ 1 đến n. Tác động thứ i (1 ≤ i ≤ n) sẽ làm thay đổi độ cao của các vị trí có số hiệu từ li đến ri lần lượt theo quy tắc: vị trí li sẽ tăng độ cao thêm xi, vị trí li + 1 sẽ giảm bớt độ cao xi, vị trí li + 2 sẽ tăng độ cao thêm xi và tiếp tục cho đến vị trí ri.
Yêu cầu: Hãy giúp An xác định độ cao của m vị trí p1, p2, …, pm sau khi thực hiện n tác động.
Dữ liệu vào:
- Dòng thứ nhất chứa hai số nguyên dương m và n (m ≤ 103, n ≤ 103);
- Trong m dòng tiếp theo, dòng thứ i chứa số nguyên dương pi (pi ≤ 109, 1 ≤ i ≤ m);
- Trong n dòng tiếp theo, dòng thứ i chứa 3 số nguyên dương li, ri và xi ( li ≤ ri ≤ 109, xi ≤ 103, 1 ≤ i ≤ n).
Kết quả ra màn hình: gồm m dòng, dòng thứ i ghi độ cao của vị trí pi (1 ≤ i ≤ m) tìm được.
Ví dụ
Input:
5  2
1
3
6
7
8
1  6  7
3  7  2
Output:
7
9
-9
2
0
Giải thích:
- Sau tác động thứ 1: các vị trí 1 và 3 có độ cao là 7, vị trí 6 có độ cao -7, các vị trí 7 và 8 giữ nguyên độ cao 0.
- Sau tác động thứ 2: vị trí 1 giữ nguyên độ cao 7, vị trí 3 có độ cao 9, vị trí 6 có độ cao -9; vị trí 7 có độ cao là 2, vị trí 8 giữ nguyên độ cao 0.
*/

