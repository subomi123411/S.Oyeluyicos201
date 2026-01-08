#include <iostream>
using namespace std;

inline void info_display(int year_of_adm, string name = "Steve") {
    cout << "Name: " << name << " is " << name.length();
    cout << "\nAdmitted in the year " << year_of_adm;
}

int main() {
    string name = "Jemimah"; int adm_year = 2009;
    info_display(adm_year);
    cout << endl;
    info_display(adm_year, name);
    return 0;
}
