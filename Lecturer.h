#ifndef LECTURER_h
#define LECTURER_h
#include <string>
#include "Person.h"
using namespace std;

class Lecturer : public Person {
private:
    string magv;
    string khoa;
    string hocvi;   // Thac si / Tien si / PGS / GS

public:
    Lecturer();
    Lecturer(string magv, string hoten, string ngaysinh, string gioitinh, string sdt, string khoa, string hocvi);
    // Getter
    string getMagv() const;
    string getKhoa() const;
    string getHocvi() const;
    // Setter
    void setMagv(const string& magv);
    void setKhoa(const string& khoa);
    void setHocvi(const string& hocvi);
    // IO
    void input();
    void output() const;
};

#endif
