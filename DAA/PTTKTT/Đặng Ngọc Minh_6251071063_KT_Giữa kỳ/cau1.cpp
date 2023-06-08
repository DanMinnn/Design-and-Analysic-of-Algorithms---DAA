// ĐẶNG NGỌC MINH 
// 6251071063

#include <iostream>
using namespace std;

// câu 1a

/* Việc chuyển đổi thành một chương trình mới tương đương bằng
cách sử dụng tối thiểu cấu trúc lệnh lặp while và một số
biến phụ chỉ có thể thay thế cho các cấu trúc điều khiển là vòng lặp và rẽ nhánh chứ không thể thay thế cho các lệnh gán (di chuyển dữ liệu, truy nhập IO, ...).
Ví dụ: if(condition) ta có thể thay bằng while(condition) và sử dụng thêm điều kiện để thoát khỏi vòng lặp*/

// câu 1b và 1c
int F(int X[], int n, int m, int k){ 
    int s1 = 0, s0 = 0, dem1 = 0 , dem0 = 0;

    for(int i = 0; i < n; i++){
        if(X[i]){
            s1++;
            s0 = 0;
                if(s1 >= k)
                    dem1++;
        }

        else{
            s1 = 0;
            s0++;
            if(s0 >= m)
                dem0++;
        }
    }

    if(dem1 == 1 && dem0 == 0)
        return 1;
    return 0;
}

int Rewrite_F(int X[], int n, int m, int k){ 
    int s1 = 0, s0 = 0, dem1 = 0 , dem0 = 0;
    int i = 0;
    while(i < n){

        while(X[i] && i < n){
            s1++;
            s0 = 0;
            while(s1 >= k){
                dem1++;
                break;
            }
               
            i++;
        }

        while(!X[i] && i < n){
            s1 = 0;
            s0++;
            while(s0 >= m){
                dem0++;
                break;
            }
                
            i++;
        }
    }

    if(dem1 == 1 && dem0 == 0)
        return 1;
    return 0;
}

int main(){
    int X[] = {1, 0, 0, 0, 1, 1, 1};
    //int X[] = {1, 0, 0, 1, 1, 1, 1};
    //int X[] = {1, 0, 0, 1, 1, 1, 0};

    int p = F(X, 7, 2, 3);
    int x = Rewrite_F(X, 7, 2, 3);

    cout << "Result of F: " << p << endl;
    cout << "Result of Rewrite_F: " << x;
}

