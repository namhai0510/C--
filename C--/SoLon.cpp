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
int main () {
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
    for (int i=1;i<=stoi(A);i++) S=Cong(S,B);
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
