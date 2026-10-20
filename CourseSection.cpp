#include "CourseSection.h"
#include <iostream>
using namespace std;

CourseSection::CourseSection() : dssv(NULL), sosv(0), sisotoida(0) {}

CourseSection::CourseSection(string mahp, const Subject& mon, const Lecturer& gv, int sisotoida)
    : mahp(mahp), mon(mon), gv(gv), dssv(NULL), sosv(0), sisotoida(sisotoida) {}

CourseSection::CourseSection(const CourseSection& hp)
    : mahp(hp.mahp), mon(hp.mon), gv(hp.gv), dssv(NULL), sosv(hp.sosv), sisotoida(hp.sisotoida) {
    if (sosv > 0) {
        dssv = new string[sosv];
        for (int i = 0; i < sosv; i++)
            dssv[i] = hp.dssv[i];
    }
}

CourseSection& CourseSection::operator=(const CourseSection& hp) {
    if (this != &hp) {
        delete[] dssv;
        dssv = NULL;
        mahp = hp.mahp;
        mon = hp.mon;
        gv = hp.gv;
        sosv = hp.sosv;
        sisotoida = hp.sisotoida;
        if (sosv > 0) {
            dssv = new string[sosv];
            for (int i = 0; i < sosv; i++)
                dssv[i] = hp.dssv[i];
        }
    }
    return *this;
}

CourseSection::~CourseSection() {
    delete[] dssv;
}

string CourseSection::getMahp() const { return mahp; }
Subject CourseSection::getMon() const { return mon; }
Lecturer CourseSection::getGiangVien() const { return gv; }
int CourseSection::getSoSV() const { return sosv; }
int CourseSection::getSiSoToiDa() const { return sisotoida; }

string CourseSection::getSV(int i) const {
    if (i >= 0 && i < sosv) return dssv[i];
    return "";
}

void CourseSection::setMahp(const string& mahp) { this->mahp = mahp; }
void CourseSection::setMon(const Subject& mon) { this->mon = mon; }
void CourseSection::setGiangVien(const Lecturer& gv) { this->gv = gv; }
void CourseSection::setSiSoToiDa(int sisotoida) { this->sisotoida = sisotoida; }

bool CourseSection::coSV(const string& mssv) const {
    for (int i = 0; i < sosv; i++)
        if (dssv[i] == mssv) return true;
    return false;
}

bool CourseSection::themSV(const string& mssv) {
    if (coSV(mssv)) return false;
    if (sosv >= sisotoida) return false;
    string* temp = new string[sosv + 1];
    for (int i = 0; i < sosv; i++)
        temp[i] = dssv[i];
    temp[sosv] = mssv;
    delete[] dssv;
    dssv = temp;
    sosv++;
    return true;
}

bool CourseSection::xoaSV(const string& mssv) {
    int vitri = -1;
    for (int i = 0; i < sosv; i++) {
        if (dssv[i] == mssv) {
            vitri = i;
            break;
        }
    }
    if (vitri == -1) return false;
    string* temp = NULL;
    if (sosv > 1) {
        temp = new string[sosv - 1];
        int k = 0;
        for (int i = 0; i < sosv; i++)
            if (i != vitri) temp[k++] = dssv[i];
    }
    delete[] dssv;
    dssv = temp;
    sosv--;
    return true;
}

void CourseSection::input() {
    cout << "Nhap ma lop hoc phan: ";
    getline(cin, mahp);
    mon.input();
    cout << "Nhap si so toi da: ";
    cin >> sisotoida;
    cin.ignore();
}

void CourseSection::xuatThongTin() const {
    cout << "Ma lop hoc phan: " << mahp << endl;
    cout << "Mon hoc        : " << mon.getMamon() << " - " << mon.getTenmon()
         << " (" << mon.getSotinchi() << " tin chi)" << endl;
    cout << "Giang vien     : " << gv.getMagv() << " - " << gv.getHoten() << endl;
    cout << "Si so          : " << sosv << "/" << sisotoida << endl;
}
