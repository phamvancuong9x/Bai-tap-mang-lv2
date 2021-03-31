//3. có 2 mảng a, b đã được sắp xếp TĂNG DẦN.Trộng mảng a, b vào c sao cho mảng c tăng dần.
//VD: a: 1 2 7
//b : 0 2 6 9
//= > c: 0 1 2 2 6 7 9﻿
#include<iostream>
#define MAX 100
using namespace std;
void nhapSoLuong(int& n);
void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
void gop_vao_c(int b[], int c[], int nb, int& nc);
void gop_vao_c2(int a[], int c[], int na, int& nc);
int main() {
	int na;
	int nb;
	int nc = 0;
	int a[MAX];
	int b[MAX];
	int c[MAX];
	cout << "\t\t===============Mang a ================\n\n";
	nhapSoLuong(na);
	nhapMang(a, na);
	cout << "\t\t===============Mang b =================\n\n ";
	nhapSoLuong(nb);
	nhapMang(b, nb);
	cout << "\t\t===============mang c =================\n\n ";
	gop_vao_c(b, c, nb, nc);
	gop_vao_c2(a, c, na, nc);
	xuatMang(c, nc);
	system("pause");
	return 0;
}
void nhapSoLuong(int& n) {
	do {
		cout << "Nhap so luong phan t cua mang : ";
		cin >> n;
	} while (n<1 || n>MAX);
}
void nhapMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i << " : ";
		cin >> a[i];
	}
}
void xuatMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "phan tu thu " << i << " : " << a[i] << endl;
	}
}
void themMang(int a[], int& n, int vt, int x) {
	for (int i = n; i > vt; i--) {
		a[i] = a[i - 1];
	}
	a[vt] = x;
	n++;
}
void xoaMang(int a[], int &n, int vt) {
	for (int i = vt; i < n - 1; i++) {
		a[i] = a[i + i];
	}
	n--;
}
void gop_vao_c(int b[], int c[],int nb,int &nc) {
	for (int i = 0; i < nb; i++) {
		c[i]=b[i];
		nc++;
	}
}
void gop_vao_c2(int a[], int c[], int na, int& nc) {
	/*a= 1 2 7 8  9
	*    0 1 2 3 4 
	* c=6;
	* 1 2 6  
	  0 1 2
	
	*/
	for (int i = 0; i < na; i++) {
		for (int j = 0; j < nc; j++) {
			if (a[i] <= c[j]) { themMang(c, nc, j, a[i]); break; }
			else if (a[i] > c[nc - 1]) { themMang(c, nc, nc, a[i]); break; }
			
		}
	}
}
