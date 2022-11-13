#include<bits/stdc++.h>

using namespace std;
pair <int,int> A,B,C,D;
long long Area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
int main () {
    cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second >> D.first >> D.second;
    long long S=Area(A.first,A.second,B.first,B.second,C.first,C.second);
    long long S1=Area(A.first,A.second,B.first,B.second,D.first,D.second);
    long long S2=Area(A.first,A.second,C.first,C.second,D.first,D.second);
    long long S3=Area(B.first,B.second,C.first,C.second,D.first,D.second);
    if (abs(S1+S2+S3)<=S) cout << "1";
        else cout << "0";
}
