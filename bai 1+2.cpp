//cho 2 mang:
//a: 1 2 3 4
//b : 5 6 7
//1. Viết chương trình gộp mảng a vào đầu mảng b
//= > b: 1 2 3 4 5 6 7
//2. Viết chương trình gộp mảng a vào cuối mảng b
//= > b: 5 6 8 1 2 3 4
#include<iostream>
#define MAX 100
using namespace std;
void nhapSoLuong(int& n);
void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
void gopTruoc(int a[], int b[], int na, int& nb);
void gopSau(int a[], int b[], int na, int& nb);
int main() {
	int na;
	int nb;
	int a[MAX];
	int b[MAX];
	cout << "\t\t===============Mang a ================\n\n";
	nhapSoLuong(na);
	nhapMang(a, na);
	cout << "\t\t===============Mang b =================\n\n ";
	nhapSoLuong(nb);
	nhapMang(b, nb);
//Them vao phia truoc
	cout << "\t\t===========mang b sau khi gop mang a vao phia truoc=========\n\n";
	gopTruoc(a, b, na, nb);
	xuatMang(b, nb);
	//Them vao phia sau
	/*cout << "\t\t===========mang b sau khi gop mang a vao phia sau=========\n\n";
	gopSau(a, b, na, nb);
	xuatMang(b, nb);*/
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
		cout << "phan tu thu " << i << " : " << a[i]<<endl;
	}
}
void themMang(int a[], int& n,int vt,int x) {
	for (int i = n; i > vt; i--) {
		a[i] = a[i - 1];
	}
	a[vt] = x;
	n++;
}
void gopTruoc(int a[], int b[],int na,int &nb) {
	for (int i = na - 1; i >= 0; i--) {
		themMang(b, nb, 0, a[i]);
	}
}
void gopSau(int a[], int b[], int na, int& nb) {
	for (int i = 0; i < na; i++) {
		themMang(b, nb, nb , a[i]);
	}
}