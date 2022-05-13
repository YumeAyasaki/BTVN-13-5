#include "SinhVien.h"

int main() {
    double* marks = new double[5];
    marks[0] = 7;
    marks[1] = 8;
    marks[2] = 9;
    SinhVien temp("Ayasaki Yume", "19/11/2001", marks);
    cout << temp.getHoTen();
    return 0;
}