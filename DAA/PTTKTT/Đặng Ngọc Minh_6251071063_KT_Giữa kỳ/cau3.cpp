// ĐẶNG NGỌC MINH 
// 6251071063

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

ifstream datain("DATA.IN");
ofstream dataout("DATA.OUT");

int a[100][100], n, dem = 0, aa[100], bb[100], x[100], dem1;

void NhapDL(int &n)
{
    datain >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            datain >> a[i][j];
    for (int i = 1; i <= n; i++)
    {
        int k = 0;
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 1)
            {
                if (j > i)
                {
                    dem++;
                    aa[dem] = i;
                    bb[dem] = j;
                }
            }
    }
}

void DFS(int i)
{
    cout << i << " " << endl;
    x[i] = 1;
    for (int j = 1; j <= n; j++)
        if (x[j] == 0 && a[i][j] == 1){
            DFS(j);
            cout << j << " ";
        }
}

int LienThong()
{
    for (int i = 1; i <= n; i++)
        x[i] = 0;
    DFS(1);
    for (int i = 1; i <= n; i++)
        if (x[i] == 0)
            return 0;
    return 1;
}

void DFS(int i, int j, int ax[][100])
{
    x[i] = 1;
    for (int k = 1; k <= n; k++)
        if (ax[i][k] == 1 && x[k] == 0)
        {
            if (k == j)
            {
                dem1 = 1;
                return;
            }
            DFS(j, k, a);
        }
}

int KT(int ax[][100], int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
            {
                dem1 = 0;
                for (int k = 1; k <= n; k++)
                    x[k] = 0;
                DFS(i, j, ax);
                if (dem1 == 0)
                    return 0;
            }
    return 1;
}

int ThucHien(int i, int ax[][100])
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == dem)
        {

            for (int k = 1; k <= n; k++)
                for (int h = 1; h <= n; h++)
                    ax[k][h] = 0;
            for (int k = 1; k <= dem; k++)
                if (x[k] == 0)
                    ax[aa[k]][bb[k]] = 1;
                else
                    ax[bb[k]][aa[k]] = 1;
            if (KT(ax, n) == 1)
                return 1;
        }
        else
            ThucHien(i + 1, ax);
    }
}

main()
{
    NhapDL(n);
    cout << dem << endl;
    if (LienThong() == 0)
        dataout << "Vo Nghiem" << endl;
    else
    {
        int ax[100][100];
        ThucHien(1, ax);
        if (KT(ax, n) == 1)
        {
            dataout << dem << endl;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (ax[i][j] == 1){
                        dataout << i << " " << j << endl;
                        cout << i << " " << j << endl;
                    }
        }
        else
            dataout << "Vo Nghiem" << endl;
    }
}

