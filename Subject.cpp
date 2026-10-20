#include "Subject.h"
#include <iostream>
#include <iomanip>
using namespace std;

Subject::Subject() : sotinchi(0) {}

Subject::Subject(string mamon, string tenmon, int sotinchi)
    : mamon(mamon), tenmon(tenmon), sotinchi(sotinchi) {}

string Subject::getMamon() const { return mamon; }
string Subject::getTenmon() const { return tenmon; }
int Subject::getSotinchi() const { return sotinchi; }

void Subject::setMamon(const string& mamon) { this->mamon = mamon; }
void Subject::setTenmon(const string& tenmon) { this->tenmon = tenmon; }
void Subject::setSotinchi(int sotinchi) { this->sotinchi = sotinchi; }

void Subject::input() {
    cout << "Nhap ma mon: ";
    getline(cin, mamon);
    cout << "Nhap ten mon: ";
    getline(cin, tenmon);
    cout << "Nhap so tin chi: ";
    cin >> sotinchi;
    cin.ignore();
}

void Subject::output() const {
    cout << left
         << setw(10) << mamon
         << setw(30) << tenmon
         << setw(10) << sotinchi
         << endl;
}
