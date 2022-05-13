#include "QLSinhVien.h"

QLSinhVien::QLSinhVien()
{
    this->size = 0;
    this->Danhsach = nullptr;
}

QLSinhVien::~QLSinhVien()
{
    this->size = 0;
    delete[]this->Danhsach;
}

void QLSinhVien::input()
{
    cout << "Nhap so luong sinh vien: ";
    cin >> this->size;
    this->Danhsach = new SinhVien*[size];
    for (int i = 0; i < this->size; i++)
    {
        this->Danhsach[i] = new SinhVien;
        // Can ham input sinh vien
    }
    
}