#ifndef PERSON_h
#define PERSON_h
#include <string>
using namespace std;

class Person {
protected:
    string hoten;
    string ngaysinh;
    string sdt;
    string gioitinh;
public:
    // Constructor & Destructor
    Person();
    Person(string hoten, string ngaysinh, string sdt, string gioitinh);
    virtual ~Person();
    // I/O
    virtual void input();
    virtual void output() const;
    // Getter
    string getHoten() const;
    string getNgaysinh() const;
    string getGioitinh() const;
    string getSdt() const;
    // Setter
    void setHoten(const string& hoten);
    void setNgaysinh(const string& ngaysinh);
    void setGioitinh(const string& gioitinh);
    void setSdt(const string& sdt);
};

#endif
