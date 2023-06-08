#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

void dist(){
    int n;
    cout << "Nhap so luong thanh pho: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    for(int i = 1; i <= n; i++){
        cout << "Nhap khoang cach thanh pho: "<< i;
        for(int j = 1; j <= n; j++){
            cout << "voi thanh pho: " << j;
            cin >> dist[i][j];
        }
    }

    int start = 0;
    vector<int> path = {start};
    vector<bool> visited(n);

    while(path.size()){
        int next_city = -1;
        int dist_min = INF;

        for(int i = 1; i <= n; i++){
            if(!visited[i] && dist[start][i] < dist_min){
                dist_min = dist[start][i];
                next_city = i;
            }
        }

        start = next_city;
        path.push_back({next_city});
        visited[next_city] = true;
    }

    cout << "danh sach duong di: " << endl;
    for (int i = 1; i <= n; i++)
        cout << path[i] << ' ';
    cout << endl;
    
}