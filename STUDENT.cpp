#include "STUDENT.h"
#include <iostream>
using namespace std;

// Constructor
Student::Student() : dshk(NULL), sohk(0) {}

Student::Student(string mssv, string hoten, string ngaysinh, string gioitinh, string tenlop, string khoa, string sdt)
    : Person(hoten, ngaysinh, sdt, gioitinh), mssv(mssv), tenlop(tenlop), khoa(khoa), dshk(NULL), sohk(0) {}

Student::Student(const Student& SV)
    : Person(SV), mssv(SV.mssv), tenlop(SV.tenlop), khoa(SV.khoa), dshk(NULL), sohk(SV.sohk) {
    if (sohk > 0) {
        dshk = new Semester[sohk];
        for (int i = 0; i < sohk; i++)
            dshk[i] = SV.dshk[i];
    }
}

Student& Student::operator=(const Student& SV) {
    if (this != &SV) {
        Person::operator=(SV);
        delete[] dshk;
        dshk = NULL;
        mssv = SV.mssv;
        tenlop = SV.tenlop;
        khoa = SV.khoa;
        sohk = SV.sohk;
        if (sohk > 0) {
            dshk = new Semester[sohk];
            for (int i = 0; i < sohk; i++)
                dshk[i] = SV.dshk[i];
        }
    }
    return *this;
}

Student::~Student() {
    delete[] dshk;
}

// Getter
string Student::getMssv() const { return mssv; }
string Student::getTenlop() const { return tenlop; }
string Student::getKhoa() const { return khoa; }
int Student::getSoKy() const { return sohk; }

Semester Student::getKy(int i) const {
    if (i >= 0 && i < sohk) return dshk[i];
    return Semester();
}

// Setter
void Student::setMssv(const string& mssv) { this->mssv = mssv; }
void Student::setTenlop(const string& tenlop) { this->tenlop = tenlop; }
void Student::setKhoa(const string& khoa) { this->khoa = khoa; }

bool Student::themKy(const Semester& hk) {
    for (int i = 0; i < sohk; i++) {
        if (dshk[i].getMahk() == hk.getMahk())
            return false;
    }
    Semester* temp = new Semester[sohk + 1];
    for (int i = 0; i < sohk; i++)
        temp[i] = dshk[i];
    temp[sohk] = hk;
    delete[] dshk;
    dshk = temp;
    sohk++;
    return true;
}

bool Student::xoaKy(const string& mahk) {
    int vitri = -1;
    for (int i = 0; i < sohk; i++) {
        if (dshk[i].getMahk() == mahk) {
            vitri = i;
            break;
        }
    }
    if (vitri == -1) return false;
    Semester* temp = NULL;
    if (sohk > 1) {
        temp = new Semester[sohk - 1];
        int k = 0;
        for (int i = 0; i < sohk; i++)
            if (i != vitri) temp[k++] = dshk[i];
    }
    delete[] dshk;
    dshk = temp;
    sohk--;
    return true;
}

Semester* Student::timKy(const string& mahk) {
    for (int i = 0; i < sohk; i++)
        if (dshk[i].getMahk() == mahk) return &dshk[i];
    return NULL;
}

int Student::tongTinChi() const {
    int tong = 0;
    for (int i = 0; i < sohk; i++)
        tong += dshk[i].tongTinChi();
    return tong;
}

double Student::tinhGpa() const {
    int tc = tongTinChi();
    if (tc == 0) return 0;
    double tongDiem = 0;
    for (int i = 0; i < sohk; i++)
        tongDiem += dshk[i].tongDiemTinChi();
    return tongDiem / tc;
}

string Student::xepLoai() const {
    if (tongTinChi() == 0) return "Chua co diem";
    double gpa = tinhGpa();
    if (gpa >= 8) return "Gioi";
    if (gpa >= 6.5) return "Kha";
    if (gpa >= 5) return "Trung binh";
    return "Yeu";
}

void Student::xuatBangDiem() const {
    cout << "\nBANG DIEM THEO HOC KY\n";
    if (sohk == 0) {
        cout << "(Chua co hoc ky nao)\n";
        return;
    }
    for (int i = 0; i < sohk; i++)
        dshk[i].xuat();
    cout << "\nTong tin chi: " << tongTinChi() << " | GPA tich luy: " << tinhGpa() << endl;
}

// IO
void Student::input() {
    Person::input();
    cout << "Nhap ma sinh vien: ";
    getline(cin, mssv);
    cout << "Nhap ten lop: ";
    getline(cin, tenlop);
    cout << "Nhap khoa: ";
    getline(cin, khoa);
}

void Student::output() const {
    Person::output();
    cout << " MSSV    : " << mssv << endl;
    cout << " Lop     : " << tenlop << endl;
    cout << " Khoa    : " << khoa << endl;
    cout << " So ky   : " << sohk << endl;
    cout << " Tin chi : " << tongTinChi() << endl;
    cout << " GPA     : " << tinhGpa() << endl;
    cout << " Xep loai: " << xepLoai() << endl;
}
