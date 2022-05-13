#include "SinhVien.h"

SinhVien::SinhVien() {
    
};

SinhVien::SinhVien(char* const hoTen, char* const ngaySinh, double* marks) {
    strcpy(this->hoTen, hoTen);
    strcpy(this->ngaySinh, ngaySinh);
    for (int i = 0; i < 3; ++i) {
        this->marks[i] = marks[i];
    }
};

SinhVien::SinhVien(SinhVien const &sinhvien) {
    *this = sinhvien;
};

SinhVien::~SinhVien() {
    delete[] hoTen;
    delete[] ngaySinh;
    delete[] marks;
};

SinhVien SinhVien::operator=(SinhVien const &sinhvien) {
    return SinhVien(sinhvien);
};


char* SinhVien::getHoTen() {
    return hoTen;
}

void SinhVien::setHoTen(char* hoTen) {
    this->hoTen = hoTen;
}

char* SinhVien::getNgaySinh() {
    return ngaySinh;
}

void SinhVien::setNgaySinh(char* ngaySinh) {
    this->ngaySinh = ngaySinh;
}

double* SinhVien::getMarks() {
    return marks;
}

void SinhVien::setMarks(double* marks) {
    this->marks = marks;
}
