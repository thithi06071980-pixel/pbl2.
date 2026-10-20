#ifndef LISTSV_h
#define LISTSV_h
#include "NODE.h"
#include <iostream>
#include <string>
using namespace std;

class LISTSV {
private:
    Node* head;
public:
    LISTSV();
    ~LISTSV();

    bool themDau(const Student& sv);
    bool themCuoi(const Student& sv);
    bool themTaiVitri(const Student& sv, int p);

    bool xoatheoMSSV(const string& mssv);
    bool xoatheoViTri(int p);

    Student* timtheomssv(const string& mssv);

    void xuat() const;
    int dem() const;
    void thongKe() const;

    void sapxeptheoMSSV();
    void sapxeptheoGPA();

    void docFile(const string& filename);
    bool ghiFile(const string& filename) const;

    bool kiemtratrungMSSV(const string& mssv) const;
};

#endif
