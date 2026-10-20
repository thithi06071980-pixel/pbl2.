#ifndef SUBJECT_h
#define SUBJECT_h
#include <string>
#include <iostream>
using namespace std;

class Subject {
private:
    string mamon;
    string tenmon;
    int sotinchi;

public:
    // Constructor
    Subject();
    Subject(string mamon, string tenmon, int sotinchi); 

    // Getter
    string getMamon() const;
    string getTenmon() const;
    int getSotinchi() const;    

    // Setter
    void setMamon(const string& mamon);
    void setTenmon(const string& tenmon);
    void setSotinchi(int sotinchi);


    // IO
    void input();
    void output() const;
};

#endif
