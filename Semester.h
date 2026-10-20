#ifndef SEMESTER_h
#define SEMESTER_h
#include <string>
#include "Subject.h"
using namespace std;

//kqua cua 1 mon trong 1 ki
class Result {
private:
    Subject mon;
    double diem;
public:
    Result();
    Result(const Subject& mon, double diem);
    const Subject& getMon() const;
    double getDiem() const;
    void setDiem(double diem);
    void output() const;
};

// dsach mon va diem cua ki
class Semester {
private:
    string mahk;     // vd: 2025-1
    string tenhk;    // Hoc ky 1 nam 2025-2026
    Result* ds;
    int somon;

public:
    // Constructor & Destructor
    Semester();
    Semester(string mahk, string tenhk);
    Semester(const Semester& hk);
    Semester& operator=(const Semester& hk);
    ~Semester();
    // Getter
    string getMahk() const;
    string getTenhk() const;
    int getSoMon() const;
    Result getResult(int i) const;
    // Setter
    void setMahk(const string& mahk);
    void setTenhk(const string& tenhk);

    bool themMon(const Subject& mh, double diem);   // F neu trung ma mon
    bool xoaMon(const string& mamon);               // F neu khong tim thay
    bool capNhatDiem(const string& mamon, double diem);

    int tongTinChi() const;
    double tongDiemTinChi() const;   // sum(diem * tin chi)
    double tinhGpa() const;

    void input();           // chi nhap ma ky + ten ky
    void xuat() const;
};

#endif
