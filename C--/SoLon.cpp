#include<bits/stdc++.h>

using namespace std;

string Cong(string a, string b) {
    while (a.size() < b.size()) a = "0" + a;
    while (b.size() < a.size()) b = "0" + b;

    int nho = 0;
    int tong;
    string ketqua = "";
    for (int i = a.size() - 1; i >= 0; i--) {
        tong = (a[i] - 48) + (b[i] - 48) + nho;
        nho = tong/10;
        ketqua = char(tong%10 + 48) + ketqua;
    }

    if (nho > 0) ketqua = "1" + ketqua;
    return ketqua;

}
string Tru(string a, string b) {
    while (a.size() < b.size()) a = "0" + a;
    while (b.size() < a.size()) b = "0" + b;

    int nho = 0;
    int hieu=0;
    string ketqua = "";
    for (int i = a.size() - 1; i >= 0; i--) {
        hieu=(a[i]-48)-(b[i]-48)-nho;
        if (hieu<0) {
            hieu+=10;
            nho=1;
        }
        else {
            nho=0;
        }
        ketqua=(char)(hieu+'0')+ketqua;
    }
    if (ketqua.size()>1&&ketqua[0]=='0') {
        string T=ketqua.substr(1,ketqua.size()-1);
        return T;
    }
    return ketqua;

}

string Multi (string solon1,string solon2) {

    string ketqua = "";
    //string dem_0 = "0";
    for (int i=solon1.size()-1;i>=0;i--) {           ///Số chữ số của số A

        for (int j=1;j<=(solon1[i]-48);j++) {
            ketqua=Cong(ketqua,solon2);

        }
        solon2=solon2+"0";
    }
    //ketqua=ketqua.substr(0,ketqua.size()-2);
    return ketqua;
}
long long TongChuSo (string solon) {
    long long ketqua=0;
    for (int i=0;i+1<solon.size();i++) ketqua+=(solon[i]-48);
    return ketqua;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string A,B,P="",M="",S="";
    cin >> A >> B;

    if (A.size() == 1)
    {
        if (stoi(A)  == 0)
        {
          P=B;
          M="-"+B;
          S="0";
          cout << P << endl << M << endl << S;
          return 0;
        }
    }

    if (B.size() == 1)
    {
        if (stoi(B)  == 0)
        {
          P=A;
          M=A;
          S="0";
          cout << P << endl << M << endl << S;
          return 0;
        }
    }

    P=Cong(A,B);
    if (TongChuSo(A)>=TongChuSo(B)) S=Multi(B,A);
    else S=Multi(A,B);
    while (A.size() < B.size()) A = "0" + A;
    while (B.size() < A.size()) B = "0" + B;
    if (A>=B) M=Tru(A,B);
        else {
            M=Tru(B,A);
            M="-"+M;
        }
    cout << P << endl << M << endl << S;
    return 0;
}
