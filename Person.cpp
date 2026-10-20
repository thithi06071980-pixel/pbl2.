#include "Person.h"
#include <iostream>
using namespace std;

Person::Person() : hoten(""), ngaysinh(""), sdt(""), gioitinh("") {}

Person::Person(string hoten, string ngaysinh, string sdt, string gioitinh)
    : hoten(hoten), ngaysinh(ngaysinh), sdt(sdt), gioitinh(gioitinh) {}

Person::~Person() {}

void Person::input() {
    cout << "Ho ten: ";
    getline(cin, hoten);
    cout << "Ngay sinh: ";
    getline(cin, ngaysinh);
    cout << "Gioi tinh: ";
    getline(cin, gioitinh);
    cout << "So dien thoai: ";
    getline(cin, sdt);
}

void Person::output() const {
    cout << "Ho ten       : " << hoten << endl;
    cout << "Ngay sinh    : " << ngaysinh << endl;
    cout << "Gioi tinh    : " << gioitinh << endl;
    cout << "So dien thoai: " << sdt << endl;
}

string Person::getHoten() const { return hoten; }
string Person::getNgaysinh() const { return ngaysinh; }
string Person::getSdt() const { return sdt; }
string Person::getGioitinh() const { return gioitinh; }

void Person::setHoten(const string& hoten) { this->hoten = hoten; }
void Person::setNgaysinh(const string& ngaysinh) { this->ngaysinh = ngaysinh; }
void Person::setSdt(const string& sdt) { this->sdt = sdt; }
void Person::setGioitinh(const string& gioitinh) { this->gioitinh = gioitinh; }
