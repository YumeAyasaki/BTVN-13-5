#pragma once

#include <iostream>
#include <cstring>
#include <string.h>
#include <stdlib.h> // Prevent segmentation fault
#include <string>

using namespace std;

class SinhVien {
    private:
        char* hoTen = new char[30];
        char* maSo = new char[20];
        char* ngaySinh = new char[20];
        double* marks = new double[5];

    public:
        SinhVien(); // Tao
        SinhVien(char* const hoTen, char* const maSo, char* const ngaySinh, double marks[3]);
        SinhVien(SinhVien const &sinhvien); // Sao chep
        ~SinhVien(); // Huy

        char* getHoTen();
        void setHoTen(char* const hoTen);
        char* getMaSo();
        void setMaSo(char* const maSo);
        char* getNgaySinh();
        void setNgaySinh(char* const ngaySinh);
        double* getMarks();
        void setMarks(double* marks);

        double getStdAvg();
        char* getHocLuc();

        SinhVien operator=(SinhVien const &sinhvien); // Gan bang

        void setInput();       
};