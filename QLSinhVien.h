#include "SinhVien.h"
#pragma once

class QLSinhVien : public SinhVien
{
private:
    int size;
    SinhVien** Danhsach;
public:
    QLSinhVien();
    ~QLSinhVien();
    void input();
    void inputFromFile();
    void outputToFile();
};

