// ĐẶNG NGỌC MINH 
// 6251071063

#include <iostream>
#include<fstream>
using namespace std;

long KT_ThuanNghich(long s1){
   long s2 = 0; 
   long tmp = s1;
   while (tmp > 0){
      s2 = s2 * 10 + tmp % 10;
      tmp = tmp / 10;
   }

   return (s2 == s1);
}

int TongCacSoChiaHetCho10(long s){
	int tong = 0;
	while(s > 0){
		tong = tong + s % 10;
		s /= 10;
	}

 	if(tong % 10 == 0 ) 
        return 1;
 	return 0;
}

int KiemTraPT_0(long pt){
	int s;
	while(pt > 0){
		s = pt % 10;
		
		if(s == 0) return 0;
		pt /= 10;
	}
	return 1;
}


int main(){
	ofstream F1,F2,F3;
	F1.open("Loai1.out", ios_base::out);
	F2.open("Loai2.out", ios_base::out);
	F3.open("Loai3.out", ios_base::out);
	for(long k = 100000;k <= 999999; k++){
		
		if(KT_ThuanNghich(k) && TongCacSoChiaHetCho10(k) == 0){
			F1 << "\n";
			for(int i = 2; i <= 8; i++)
			F1 << "091" << i << k <<"  ";
		}
		if(TongCacSoChiaHetCho10(k) && KiemTraPT_0(k) == 0){
			F2 << "\n";
			for(int i = 2; i <= 8; i++)
			F2 << "091" << i << k <<"  ";
		}
		if(KiemTraPT_0(k)){
			F3 << "\n";
			for(int i = 2; i <= 8; i++)
			F3 << "091" << i << k <<"  ";
		}
	}
    
	F1.close();F2.close();F3.close();
	system("pause");
	return 0;
}