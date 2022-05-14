#include "SinhVien.h"
#pragma once

struct Node
{
    SinhVien detail;
    Node* next;
};

struct List
{
    Node* head;
    Node* tail;
};

class QLSinhVien : public SinhVien
{
private:
    List danhsach;
public:
    QLSinhVien();
    ~QLSinhVien();
    void input();
    void inputFromFile();
    void outputToFile();
    double getClsAvg();
    void getStdbelowClsAvg();
};