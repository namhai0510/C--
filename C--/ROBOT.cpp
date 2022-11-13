#include<bits/stdc++.h>

using namespace std;

int main () {
    //freopen("ROBOT.INP","r",stdin);
    //freopen("ROBOT.OUT","w",stdout);
    int N,M;
    cin >> N >> M;
    int R[N],V[M],S[N];
    memset(S, 0 , sizeof(S));
    for (int i=0;i<N;i++) cin >> R[i];
    for (int i=0;i<M;i++) {
        cin >> V[i];
        for (int j=0;j<N;j++) {
            S[j]=S[j]+abs(R[j]-V[i]);
            cout << R[j] << " " << V[i] << " " << S[j] << endl;
        }
    }
    sort(S,S+N);
    cout << S[N-1];
}
