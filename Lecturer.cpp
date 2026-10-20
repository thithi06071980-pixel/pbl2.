#include "Lecturer.h"
#include <iostream>
using namespace std;

Lecturer::Lecturer() {}

Lecturer::Lecturer(string magv, string hoten, string ngaysinh, string gioitinh, string sdt, string khoa, string hocvi)
    : Person(hoten, ngaysinh, sdt, gioitinh), magv(magv), khoa(khoa), hocvi(hocvi) {}

string Lecturer::getMagv() const { return magv; }
string Lecturer::getKhoa() const { return khoa; }
string Lecturer::getHocvi() const { return hocvi; }

void Lecturer::setMagv(const string& magv) { this->magv = magv; }
void Lecturer::setKhoa(const string& khoa) { this->khoa = khoa; }
void Lecturer::setHocvi(const string& hocvi) { this->hocvi = hocvi; }

void Lecturer::input() {
    Person::input();
    cout << "Nhap ma giang vien: ";
    getline(cin, magv);
    cout << "Nhap khoa: ";
    getline(cin, khoa);
    cout << "Nhap hoc vi: ";
    getline(cin, hocvi);
}

void Lecturer::output() const {
    Person::output();
    cout << " MaGV  : " << magv << endl;
    cout << " Khoa  : " << khoa << endl;
    cout << " Hoc vi: " << hocvi << endl;
}
