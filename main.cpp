#include <iostream>
#include <string>
#include "LISTSV.h"
#include "STUDENT.h"
#include "Subject.h"
#include "Semester.h"
#include "Lecturer.h"
#include "CourseSection.h"
using namespace std;
const int MAX = 100;
// Nhap 1 hoc ky (gom cac mon + diem) va them vao sinh vien
void nhapKyHoc(Student& sv) {
    Semester hk;
    hk.input();
    int n;
    cout << "Nhap so mon cua hoc ky: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        Subject mh;
        cout << "\nNhap mon thu " << i + 1 << ":\n";
        mh.input();
        double diem;
        cout << "Nhap diem: ";
        cin >> diem;
        cin.ignore();
        if (!hk.themMon(mh, diem)) {
            cout << "Ma mon trung trong hoc ky nay\n";
            i--;
        }
    }
    if (sv.themKy(hk))
        cout << "Them hoc ky thanh cong\n";
    else
        cout << "Ma hoc ky da ton tai, khong them\n";
}

int timGV(const Lecturer dsgv[], int sogv, const string& magv) {
    for (int i = 0; i < sogv; i++)
        if (dsgv[i].getMagv() == magv) return i;
    return -1;
}

int timHP(const CourseSection dshp[], int sohp, const string& mahp) {
    for (int i = 0; i < sohp; i++)
        if (dshp[i].getMahp() == mahp) return i;
    return -1;
}

int main()
{
    LISTSV ds;
    Lecturer dsgv[MAX];
    int sogv = 0;
    CourseSection dshp[MAX];
    int sohp = 0;
    int chon;
    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1.  Them sinh vien\n";
        cout << "2.  Xuat danh sach sinh vien\n";
        cout << "3.  Tim sinh vien theo MSSV\n";
        cout << "4.  Xoa sinh vien theo MSSV\n";
        cout << "5.  Sap xep theo MSSV\n";
        cout << "6.  Sap xep theo GPA\n";
        cout << "7.  Doc danh sach sinh vien tu file\n";
        cout << "8.  Ghi danh sach sinh vien ra file\n";
        cout << "9.  Thong ke xep loai sinh vien\n";
        cout << "10. Them hoc ky (mon + diem) cho sinh vien\n";
        cout << "11. Them giang vien\n";
        cout << "12. Tao lop hoc phan\n";
        cout << "13. Them sinh vien vao lop hoc phan\n";
        cout << "14. Xem lop hoc phan\n";
        cout << "0.  Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();
        switch (chon) {
        case 1: {
            Student sv;
            cout << "\n===== NHAP THONG TIN SINH VIEN =====\n";
            sv.input();
            int k;
            cout << "Nhap so hoc ky: ";
            cin >> k;
            cin.ignore();
            for (int i = 0; i < k; i++) {
                cout << "\n--- Hoc ky thu " << i + 1 << " ---\n";
                nhapKyHoc(sv);
            }
            if (ds.themCuoi(sv))
                cout << "\nThem sinh vien thanh cong\n";
            else
                cout << "\nMSSV da ton tai\n";
            break;
        }
        case 2: {
            cout << "\n===== DANH SACH SINH VIEN =====\n";
            ds.xuat();
            break;
        }
        case 3: {
            string mssv;
            cout << "Nhap MSSV can tim: ";
            getline(cin, mssv);
            Student* p = ds.timtheomssv(mssv);
            if (p != NULL) {
                cout << "\n===== TIM THAY SINH VIEN =====\n";
                p->output();
                p->xuatBangDiem();
            }
            else {
                cout << "Khong tim thay sinh vien\n";
            }
            break;
        }
        case 4: {
            string mssv;
            cout << "Nhap MSSV can xoa: ";
            getline(cin, mssv);
            if (ds.xoatheoMSSV(mssv))
                cout << "Xoa thanh cong\n";
            else
                cout << "Khong tim thay MSSV\n";
            break;
        }
        case 5: {
            ds.sapxeptheoMSSV();
            cout << "Da sap xep theo MSSV thanh cong\n";
            break;
        }
        case 6: {
            ds.sapxeptheoGPA();
            cout << "Da sap xep theo GPA thanh cong\n";
            break;
        }
        case 7: {
            string filename;
            cout << "Nhap ten file (vd: sinhvien.dat): ";
            getline(cin, filename);
            ds.docFile(filename);
            break;
        }
        case 8: {
            string filename;
            cout << "Nhap ten file can ghi: ";
            getline(cin, filename);
            if (ds.ghiFile(filename))
                cout << "Ghi file thanh cong\n";
            else
                cout << "Ghi file that bai\n";
            break;
        }
        case 9: {
            ds.thongKe();
            break;
        }
        case 10: {
            string mssv;
            cout << "Nhap MSSV: ";
            getline(cin, mssv);
            Student* p = ds.timtheomssv(mssv);
            if (p != NULL)
                nhapKyHoc(*p);
            else
                cout << "Khong tim thay sinh vien\n";
            break;
        }
        case 11: {
            if (sogv >= MAX) {
                cout << "Danh sach giang vien da day\n";
                break;
            }
            Lecturer gv;
            cout << "\n===== NHAP THONG TIN GIANG VIEN =====\n";
            gv.input();
            if (timGV(dsgv, sogv, gv.getMagv()) != -1)
                cout << "Ma giang vien da ton tai\n";
            else {
                dsgv[sogv++] = gv;
                cout << "Them giang vien thanh cong\n";
            }
            break;
        }
        case 12: {
            if (sohp >= MAX) {
                cout << "Danh sach lop hoc phan da day\n";
                break;
            }
            CourseSection hp;
            cout << "\n===== TAO LOP HOC PHAN =====\n";
            hp.input();
            if (timHP(dshp, sohp, hp.getMahp()) != -1) {
                cout << "Ma lop hoc phan da ton tai\n";
                break;
            }
            string magv;
            cout << "Nhap ma giang vien phu trach: ";
            getline(cin, magv);
            int vt = timGV(dsgv, sogv, magv);
            if (vt == -1) {
                cout << "Khong tim thay giang vien (hay them giang vien truoc)\n";
                break;
            }
            hp.setGiangVien(dsgv[vt]);
            dshp[sohp++] = hp;
            cout << "Tao lop hoc phan thanh cong\n";
            break;
        }
        case 13: {
            string mahp, mssv;
            cout << "Nhap ma lop hoc phan: ";
            getline(cin, mahp);
            int vt = timHP(dshp, sohp, mahp);
            if (vt == -1) {
                cout << "Khong tim thay lop hoc phan\n";
                break;
            }
            cout << "Nhap MSSV: ";
            getline(cin, mssv);
            if (!ds.kiemtratrungMSSV(mssv)) {
                cout << "Khong tim thay sinh vien\n";
                break;
            }
            if (dshp[vt].themSV(mssv))
                cout << "Them sinh vien vao lop hoc phan thanh cong\n";
            else
                cout << "Khong them duoc (da co trong lop hoac lop da day)\n";
            break;
        }
        case 14: {
            string mahp;
            cout << "Nhap ma lop hoc phan: ";
            getline(cin, mahp);
            int vt = timHP(dshp, sohp, mahp);
            if (vt == -1) {
                cout << "Khong tim thay lop hoc phan\n";
                break;
            }
            cout << "\n===== LOP HOC PHAN =====\n";
            dshp[vt].xuatThongTin();
            cout << "Danh sach sinh vien:\n";
            for (int i = 0; i < dshp[vt].getSoSV(); i++) {
                string mssv = dshp[vt].getSV(i);
                Student* sv = ds.timtheomssv(mssv);
                cout << " " << i + 1 << ". " << mssv << " - "
                     << (sv != NULL ? sv->getHoten() : "(khong con trong danh sach)") << endl;
            }
            break;
        }
        case 0: {
            cout << "Ket thuc chuong trinh\n";
            break;
        }
        default: {
            cout << "Lua chon khong hop le\n";
        }
        }
    } while (chon != 0);
    return 0;
}
