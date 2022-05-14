#pragma once

#include <fstream>
#include "SinhVien.h"
#include <iomanip>

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

class QLSinhVien
{
private:
    List danhsach;
public:
    QLSinhVien();
    ~QLSinhVien();
    void input();
    void output();
    void inputFromFile(string fileName);
    void outputToFile(string fileName);
    double getClsAvg();
    List getStdbelowClsAvg();

    void addSVtoList(SinhVien& sv);
    void outputToFileB(string fileName);
};