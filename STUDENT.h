#ifndef STUDENT_h
#define STUDENT_h
#include <string>
#include "Person.h"
#include "Semester.h"
using namespace std;

class Student : public Person {
private:
    string mssv;
    string tenlop;
    string khoa;
    Semester* dshk;   // danh sach hoc ky 
    int sohk;
   // string tinhtrang; //(dang hoc / bao luu / dinh chi / thoi hoc)

public:
    // Constructor & Destructor
    Student();
    Student(string mssv, string hoten, string ngaysinh, string gioitinh, string tenlop, string khoa, string sdt);
    Student(const Student& SV);
    Student& operator=(const Student& SV);
    ~Student();

    // Getter
    string getMssv() const;
    string getTenlop() const;
    string getKhoa() const;
    int getSoKy() const;
    Semester getKy(int i) const;

    // Setter
    void setMssv(const string& mssv);
    void setTenlop(const string& tenlop);
    void setKhoa(const string& khoa);

    bool themKy(const Semester& hk);          // F neu trung ma ky
    bool xoaKy(const string& mahk);           // F neu khong tim thay
    Semester* timKy(const string& mahk);      // NULL neu khong co (con tro mat hieu luc sau themKy/xoaKy)

    int tongTinChi() const;
    double tinhGpa() const;                   // GPA tich luy tat ca cac ky
    string xepLoai() const;
    void xuatBangDiem() const;

    // IO
    void input();
    void output() const;
};

#endif
