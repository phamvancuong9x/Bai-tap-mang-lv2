//4. Cho 1 mảng các số nguyên a.Viết chương trình tách các số âm ra mảng b và xóa khỏi a
//VD : mảng a : 1 - 2   3   4 - 6   0
//Xuất :
//	mảng a : 1   3    4   0
//	mảng b : -2 - 6
#include<iostream>
#define MAX 100
using namespace std;
void nhapSoLuong(int& n);
void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
void tachMang(int a[], int b[], int& na, int& nb);
void xoaMang2(int a[], int& na);
int main() {
	int na;
	int nb=0;
	int a[MAX];
	int b[MAX];
	nhapSoLuong(na);
	nhapMang(a, na);
	tachMang(a, b, na, nb);
	xoaMang2(a, na);
	cout << "\t\t===============Mang a  sau xoa================\n\n";
	if (na == 0) { cout << "Mang a la mang rong \n"; }
	else { xuatMang(a, na); }
	cout << "\t\t===============Mang b sau tach=================\n\n ";
	if (nb == 0) { cout << "Mang b la mang rong \n"; }
	else { xuatMang(b, nb); }
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
void xoaMang(int a[], int& n, int vt) {
	for (int i = vt; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
	n--;
}
void tachMang(int a[], int b[], int& na, int& nb) {	
	for (int i = 0; i < na; i++) {
		if (a[i] < 0) {
			b[nb] = a[i];
			nb++;
		}
	}
	
}
void xoaMang2(int a[], int& na) {
	for (int i = 0; i < na; i++) {
		if (a[i] < 0) { xoaMang(a, na, i); i--; }
	}
}