#pragma once

#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

class SinhVien {
    private:
        char* hoTen;
        char* ngaySinh;
        double* marks;

    public:
        SinhVien(); // Tao
        SinhVien(char* hoTen, char* ngaySinh, double marks[3]);
        SinhVien(SinhVien const &sinhvien); // Sao chep
        ~SinhVien(); // Huy

        char* getHoTen();
        void setHoTen(char* hoTen);
        char* getNgaySinh();
        void setNgaySinh(char* ngaySinh);
        double* getMarks();
        void setMarks(double* marks);

        SinhVien operator=(SinhVien const &sinhvien); // Gan bang
};