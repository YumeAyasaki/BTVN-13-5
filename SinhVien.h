#pragma once

#include <iostream>
#include <cstring>
#include <string.h>
#include <stdlib.h> // Prevent segmentation fault

using namespace std;

class SinhVien {
    private:
        char* hoTen = new char[50];
        char* ngaySinh = new char[20];
        double* marks = new double[5];

    public:
        SinhVien(); // Tao
        SinhVien(char* const hoTen, char* const ngaySinh, double marks[3]);
        SinhVien(SinhVien const &sinhvien); // Sao chep
        ~SinhVien(); // Huy

        char* getHoTen();
        void setHoTen(char* hoTen);
        char* getNgaySinh();
        void setNgaySinh(char* ngaySinh);
        double* getMarks();
        void setMarks(double* marks);

        double getStdAvg();
        char* getHocLuc();

        SinhVien operator=(SinhVien const &sinhvien); // Gan bang
};