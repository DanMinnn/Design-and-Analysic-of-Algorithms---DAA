#include <iostream>
#include <string.h>
using namespace std;

string FindLCS(){
    string X, Y;
    cin >> X >> Y;
    int n = X.size();
    int m = Y.size();

    int F[n + 1][m + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0;j <= m; j++){
            if(i == 0 || j == 0)
                F[i][j] = 0;
            else{
                if(X[i - 1] == Y[j - 1])
                    F[i][j] = F[i - 1][j - 1] + 1;  
                else    
                    F[i][j] = max(F[i - 1][j], F[i][j - 1]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cout << F[i][j] << " ";
        cout << endl;
    }

    cout << F[n][m] << endl;

    int i = m, j = n;
    string lcs;
    while(i > 0 && j > 0){
        if(X[i - 1] == Y[j - 1]){
            lcs = X[i - 1] + lcs;
            --i;
            --j;
        }else if(F[i - 1][j] > F[i][j - 1]){
            --i;
        }else{
            --j;
        }
    }

    return lcs;

    
}

int main(){
    string lcs = FindLCS();
    cout << lcs << endl;
}