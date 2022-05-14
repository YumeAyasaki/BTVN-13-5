#include "SinhVien.h"
#include "QLSinhVien.h"

int main() {
    // double* marks = new double[5];
    // marks[0] = 7;
    // marks[1] = 8;
    // marks[2] = 9;
    // SinhVien temp((char*)"Ayasaki Yume", (char*)"19/11/2001", marks);
    // cout << temp.getHoTen() << '\n';
    // cout << temp.getHocLuc();

    QLSinhVien qlSinhVien;
    qlSinhVien.inputFromFile("input.txt");
    qlSinhVien.outputToFileB("output.txt");

    // List duoiTB = qlSinhVien.getStdbelowClsAvg();
    // qlSinhVien.outputToFileB("duoiTB.txt");

    return 0;
}