#include <iostream>
#include <math.h>
using namespace std;

// đổi tiền
/* int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n;
        cin >> n;
        int a[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        int cnt = 0;
        for (int i = 0; i < 10; i++)
        {
            cnt += n/a[i];
            n %= a[i];
        }

        cout << cnt << "\t";
    }
} */

// mua sách

int main(){
    int n, a[1005], ans = 0;
    cout << "n: ";
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <=n; j++){
            if(a[i] < a[j])
                swap(a[i], a[j]);
        }
    }

    for(int i = 1; i <= n; i++)
        cout << a[i] << "\t";

    for(int i = 1; i <= n; i++){
        if(i % 3 == 0)
            continue;
        
        ans += a[i];
    }

    cout << endl;  
    cout << ans;
}