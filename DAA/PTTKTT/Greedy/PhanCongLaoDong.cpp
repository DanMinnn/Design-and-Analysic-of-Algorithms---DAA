
#include <iostream>
#include <vector>
const int INT_MAX = 10000;
using namespace std;

// Struct lưu thông tin về công nhân và công việc
struct PhanCong {
    int congNhan;
    int congViec;
    int thoiGian;
};

// Hàm thực hiện giải thuật "tham ăn" để phân công công việc
vector<PhanCong> phanCongThamAn(vector<vector<int>>& thoiGian) {
    int n = thoiGian.size(); // Số lượng công nhân và công việc
    vector<bool> daPhanCong(n, false); // Mảng đánh dấu các công việc đã được phân công
    vector<PhanCong> phanCongs; // Mảng lưu phân công công việc
    
    // Duyệt qua từng công việc
    for (int congViec = 0; congViec < n; congViec++) {
        int thoiGianNhoNhat = INT_MAX; // Thời gian nhỏ nhất để thực hiện công việc
        int congNhanThichHopNhat = -1; // Công nhân thích hợp nhất để thực hiện công việc
        
        // Tìm công nhân có thời gian thực hiện công việc nhỏ nhất và chưa được phân công
        for (int congNhan = 0; congNhan < n; congNhan++) {
            if (!daPhanCong[congNhan] && thoiGian[congNhan][congViec] < thoiGianNhoNhat) {
                thoiGianNhoNhat = thoiGian[congNhan][congViec];
                congNhanThichHopNhat = congNhan;
            }
        }
        
        // Gán công việc cho công nhân và đánh dấu công việc đã được phân công
        phanCongs.push_back({congNhanThichHopNhat, congViec, thoiGianNhoNhat});
        daPhanCong[congNhanThichHopNhat] = true;
    }
    
    return phanCongs;
}
/* 5 6 4 7 2
5 2 4 5 1      
4 5 4 6 3
5 5 3 4 2
3 3 5 2 5 */
int main() {
    // Khởi tạo ma trận thời gian công việc
    vector<vector<int>> thoiGian = {{5, 6, 4, 7, 2},  
                                    {5, 2, 4, 5, 1},
                                    {4, 5, 4, 6, 3},
                                    {5, 5, 3, 4, 2},
                                    {3, 3, 5, 2, 5}};
    
    // Thực hiện phân công công việc
    vector<PhanCong> phanCongs = phanCongThamAn(thoiGian);
    
    // In kết quả phân công công việc và tổng thời gian
    int tongThoiGian = 0;
    for (const PhanCong& phanCong : phanCongs) {
        cout << "Công nhân " << phanCong.congNhan + 1 << " thực hiện công việc " << phanCong.congViec + 1 << " trong " << phanCong.thoiGian << " đơn vị thời gian.\n";
        tongThoiGian += phanCong.thoiGian;
    }
    cout << "Tổng thời gian: " << tongThoiGian << endl;
    
    return 0;
}