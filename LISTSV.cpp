#include "LISTSV.h"
#include <fstream>
#include <iostream>
using namespace std;

LISTSV::LISTSV() {
    head = NULL;
}

LISTSV::~LISTSV() {
    while (head != NULL) {
        Node* p = head;
        head = head->next;
        delete p;
    }
}

bool LISTSV::themDau(const Student& sv) {
    if (kiemtratrungMSSV(sv.getMssv())) return false;
    Node* p = new Node(sv);
    p->next = head;
    head = p;
    return true;
}

bool LISTSV::themCuoi(const Student& sv) {
    if (kiemtratrungMSSV(sv.getMssv())) return false;
    Node* p = new Node(sv);
    if (head == NULL) {
        head = p;
        return true;
    }
    Node* q = head;
    while (q->next != NULL)
        q = q->next;
    q->next = p;
    return true;
}

bool LISTSV::themTaiVitri(const Student& sv, int p) {
    if (p < 1) return false;
    if (kiemtratrungMSSV(sv.getMssv())) return false;
    if (p == 1) return themDau(sv);

    Node* q = head;
    int d = 1;
    while (q != NULL && d < p - 1) {
        q = q->next;
        d++;
    }
    if (q == NULL) return false;
    Node* t = new Node(sv);
    t->next = q->next;
    q->next = t;
    return true;
}

bool LISTSV::xoatheoMSSV(const string& mssv) {
    Node* p = head;
    Node* truoc = NULL;
    while (p != NULL) {
        if (p->data.getMssv() == mssv) {
            if (truoc == NULL)
                head = p->next;
            else
                truoc->next = p->next;
            delete p;
            return true;
        }
        truoc = p;
        p = p->next;
    }
    return false;
}

bool LISTSV::xoatheoViTri(int vitri) {
    if (head == NULL || vitri < 1) return false;
    if (vitri == 1) {
        Node* t = head;
        head = head->next;
        delete t;
        return true;
    }
    Node* b = head;
    Node* truoc = NULL;
    int d = 1;
    while (b != NULL && d < vitri) {
        truoc = b;
        b = b->next;
        d++;
    }
    if (b == NULL) return false;
    truoc->next = b->next;
    delete b;
    return true;
}

Student* LISTSV::timtheomssv(const string& mssv) {
    Node* p = head;
    while (p != NULL) {
        if (p->data.getMssv() == mssv) return &p->data;
        p = p->next;
    }
    return NULL;
}

void LISTSV::xuat() const {
    if (head == NULL) {
        cout << "Danh sach sinh vien rong\n";
        return;
    }
    cout << "\n--- DANH SACH SINH VIEN ---\n";
    for (Node* p = head; p != NULL; p = p->next) {
        p->data.output();
        cout << "---------------------------\n";
    }
}

int LISTSV::dem() const {
    int d = 0;
    for (Node* p = head; p != NULL; p = p->next)
        d++;
    return d;
}

void LISTSV::thongKe() const {
    int gioi = 0, kha = 0, tb = 0, yeu = 0, chuaCo = 0, tong = 0;
    for (Node* p = head; p != NULL; p = p->next) {
        string loai = p->data.xepLoai();
        if (loai == "Gioi") gioi++;
        else if (loai == "Kha") kha++;
        else if (loai == "Trung binh") tb++;
        else if (loai == "Yeu") yeu++;
        else chuaCo++;
        tong++;
    }
    cout << "\n===== THONG KE XEP LOAI =====\n";
    cout << "Tong so sinh vien: " << tong << endl;
    cout << "Gioi        : " << gioi << endl;
    cout << "Kha         : " << kha << endl;
    cout << "Trung binh  : " << tb << endl;
    cout << "Yeu         : " << yeu << endl;
    cout << "Chua co diem: " << chuaCo << endl;
}

void LISTSV::sapxeptheoMSSV() {
    for (Node* p = head; p != NULL; p = p->next) {
        for (Node* q = p->next; q != NULL; q = q->next) {
            if (p->data.getMssv() > q->data.getMssv()) {
                Student temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

void LISTSV::sapxeptheoGPA() {
    for (Node* p = head; p != NULL; p = p->next) {
        for (Node* q = p->next; q != NULL; q = q->next) {
            if (p->data.tinhGpa() < q->data.tinhGpa()) {
                Student temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

// Dinh dang file:
// so sinh vien
// moi sinh vien: hoten, ngaysinh, gioitinh, sdt, mssv, lop, khoa, so ky
//   moi ky: mahk, tenhk, so mon
//     moi mon: mamon, tenmon, "tinchi diem"
void LISTSV::docFile(const string& filename) {
    ifstream file(filename.c_str());
    if (!file.is_open()) {
        cout << "Khong the mo file: " << filename << endl;
        return;
    }
    int soluong;
    file >> soluong;
    file.ignore();
    for (int i = 0; i < soluong; i++) {
        string hoten, ngaysinh, gioitinh, sdt;
        string mssv, tenlop, khoa;
        getline(file, hoten);
        getline(file, ngaysinh);
        getline(file, gioitinh);
        getline(file, sdt);
        getline(file, mssv);
        getline(file, tenlop);
        getline(file, khoa);
        Student sv(mssv, hoten, ngaysinh, gioitinh, tenlop, khoa, sdt);

        int sohk;
        file >> sohk;
        file.ignore();
        for (int j = 0; j < sohk; j++) {
            string mahk, tenhk;
            getline(file, mahk);
            getline(file, tenhk);
            Semester hk(mahk, tenhk);

            int somon;
            file >> somon;
            file.ignore();
            for (int k = 0; k < somon; k++) {
                string mamon, tenmon;
                int sotinchi;
                double diem;
                getline(file, mamon);
                getline(file, tenmon);
                file >> sotinchi >> diem;
                file.ignore();
                hk.themMon(Subject(mamon, tenmon, sotinchi), diem);
            }
            sv.themKy(hk);
        }
        if (!themCuoi(sv))
            cout << "Trung MSSV: " << sv.getMssv() << endl;
    }
    file.close();
    cout << "\nDoc du lieu tu file thanh cong\n";
}

bool LISTSV::ghiFile(const string& filename) const {
    ofstream file(filename.c_str());
    if (!file.is_open())
        return false;
    file << dem() << endl;
    for (Node* p = head; p != NULL; p = p->next) {
        const Student& sv = p->data;
        file << sv.getHoten() << endl;
        file << sv.getNgaysinh() << endl;
        file << sv.getGioitinh() << endl;
        file << sv.getSdt() << endl;
        file << sv.getMssv() << endl;
        file << sv.getTenlop() << endl;
        file << sv.getKhoa() << endl;
        file << sv.getSoKy() << endl;
        for (int j = 0; j < sv.getSoKy(); j++) {
            Semester hk = sv.getKy(j);
            file << hk.getMahk() << endl;
            file << hk.getTenhk() << endl;
            file << hk.getSoMon() << endl;
            for (int k = 0; k < hk.getSoMon(); k++) {
                Result r = hk.getResult(k);
                file << r.getMon().getMamon() << endl;
                file << r.getMon().getTenmon() << endl;
                file << r.getMon().getSotinchi() << " " << r.getDiem() << endl;
            }
        }
    }
    file.close();
    return true;
}

bool LISTSV::kiemtratrungMSSV(const string& mssv) const {
    for (Node* p = head; p != NULL; p = p->next)
        if (p->data.getMssv() == mssv) return true;
    return false;
}
