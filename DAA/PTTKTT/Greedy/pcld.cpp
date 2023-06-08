#include <iostream>
#include <vector>
using namespace std;

const int INT_MAX = 100001;

struct PhanCong{
    int congViec;
    int congNhan;
    int thoiGian;
};

vector<PhanCong>phanCongLD(vector<vector<int>> &thoiGian){
    int n = thoiGian.size();
    vector<bool>daPhanCong(n, false);
    vector<PhanCong> phanCongs;

    for(int congViec = 0; congViec < n; congViec++){
        int thoiGianNhoNhat = INT_MAX;
        int congNhanThichHop = -1;

        for(int congNhan = 0; congNhan < n; congNhan++){
            if(!daPhanCong[congNhan] && thoiGian[congNhan][congViec] < thoiGianNhoNhat){
                thoiGianNhoNhat = thoiGian[congNhan][congViec];
                congNhanThichHop = congNhan;
            }
        }
        phanCongs.push_back({congNhanThichHop, congViec, thoiGianNhoNhat});
        daPhanCong[congNhanThichHop] = true;
    }

    return phanCongs;
}

int main(){
    vector<vector<int>>thoiGian ={};

    vector<PhanCong> phanCongs = phanCongLD(thoiGian);

    int tongThoiGian = 0;
    for(PhanCong &phanCong : phanCongs){
        //.....
        tongThoiGian += phanCong.thoiGian;
    }

    cout << "Tong thoi gian: " << tongThoiGian << endl;
}