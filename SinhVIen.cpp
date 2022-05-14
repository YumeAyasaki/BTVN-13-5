#include "SinhVien.h"

SinhVien::SinhVien() {
    
};

SinhVien::SinhVien(char* const hoTen, char* const maSo, char* const ngaySinh, double* marks) {
    strcpy(this->hoTen, hoTen);
    strcpy(this->maSo, maSo);
    strcpy(this->ngaySinh, ngaySinh);
    for (int i = 0; i < 3; ++i) {
        this->marks[i] = marks[i];
    }
};

SinhVien::SinhVien(SinhVien const &sinhvien) {
    strcpy(this->hoTen, sinhvien.hoTen);
    strcpy(this->maSo, sinhvien.maSo);
    strcpy(this->ngaySinh, sinhvien.ngaySinh);
    for (int i = 0; i < 3; ++i) {
        this->marks[i] = sinhvien.marks[i];
    }
};

SinhVien::~SinhVien() {
    delete[] hoTen;
    delete[] ngaySinh;
    delete[] marks;
};

SinhVien SinhVien::operator=(SinhVien const &sinhvien) {
    strcpy(this->hoTen, sinhvien.hoTen);
    strcpy(this->maSo, sinhvien.maSo);
    strcpy(this->ngaySinh, sinhvien.ngaySinh);
    for (int i = 0; i < 3; ++i) {
        this->marks[i] = sinhvien.marks[i];
    }
    return *this;
};


char* SinhVien::getHoTen() {
    return hoTen;
}

void SinhVien::setHoTen(char* const hoTen) {
    this->hoTen = hoTen;
}

char* SinhVien::getMaSo() {
    return maSo;
}

void SinhVien::setMaSo(char* const maSo) {
    this->maSo = maSo;
}

char* SinhVien::getNgaySinh() {
    return ngaySinh;
}

void SinhVien::setNgaySinh(char* const ngaySinh) {
    this->ngaySinh = ngaySinh;
}

double* SinhVien::getMarks() {
    return marks;
}

void SinhVien::setMarks(double* marks) {
    this->marks = marks;
}

double SinhVien::getStdAvg() {
    return marks[0] * 0.25 + marks[1] * 0.25 + marks[2] * 0.5;
}

char* SinhVien::getHocLuc() {
    double avg = getStdAvg();
    if (avg >= 8.0) {
        return (char*)"Gioi";
    }
    else if (avg >= 6.5) {
        return (char*)"Kha";
    }
    else if (avg >= 5.0) {
        return (char*)"Trung binh";
    }
    else if (avg >= 3.6) {
        return (char*)"Yeu";
    }
    return (char*)"Kem";
}

void SinhVien::setInput() {
    string st;
    cout << "Nhap ho ten: ";
    getline(cin, st);
    strcpy(hoTen, st.c_str());
    cout << "Nhap maSo: ";
    getline(cin, st);
    strcpy(maSo, st.c_str());
    cout << "Nhap ngaySinh: ";
    getline(cin, st);
    strcpy(ngaySinh, st.c_str());
    cout << "Nhap diem bai tap: ";
    cin >> marks[0];
    cout << "Nhap diem giua ki: ";
    cin >> marks[1];
    cout << "Nhap diem cuoi ki: ";
    cin >> marks[2];
}