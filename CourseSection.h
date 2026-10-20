#ifndef COURSESECTION_h
#define COURSESECTION_h
#include <string>
#include "Subject.h"
#include "Lecturer.h"
using namespace std;
// Lop hoc phan: 1 mon + 1 giang vien + danh sach sinh vien (luu MSSV)
// Luu MSSV thay vi con tro Student de khong bi sai khi LISTSV sap xep/xoa.
class CourseSection {
private:
    string mahp;
    Subject mon;
    Lecturer gv;
    string* dssv;     // danh sach MSSV
    int sosv;
    int sisotoida;
public:
    // Constructor & Destructor
    CourseSection();
    CourseSection(string mahp, const Subject& mon, const Lecturer& gv, int sisotoida);
    CourseSection(const CourseSection& hp);
    CourseSection& operator=(const CourseSection& hp);
    ~CourseSection();
    // Getter
    string getMahp() const;
    Subject getMon() const;
    Lecturer getGiangVien() const;
    int getSoSV() const;
    int getSiSoToiDa() const;
    string getSV(int i) const;     // tra ve MSSV thu i
    // Setter
    void setMahp(const string& mahp);
    void setMon(const Subject& mon);
    void setGiangVien(const Lecturer& gv);
    void setSiSoToiDa(int sisotoida);

    bool themSV(const string& mssv);   // F neu trung hoac day lop
    bool xoaSV(const string& mssv);    // F neu khong tim thay
    bool coSV(const string& mssv) const;
    // IO
    void input();                       // nhap ma HP, mon, si so toi da (giang vien gan rieng)
    void xuatThongTin() const;          // khong in danh sach SV
};

#endif
