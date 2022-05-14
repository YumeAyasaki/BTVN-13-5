#include "QLSinhVien.h"

Node* createNode(SinhVien sv)
{
    Node* temp = new Node;
    temp->detail = sv;
    temp->next = nullptr;
    return temp;
}

void initList(List& danhsach)
{
    danhsach.head = danhsach.tail = nullptr;
}

bool isEmpty(List& danhsach)
{
    return danhsach.head == nullptr;
}

void insertTail(List& danhsach, SinhVien sv)
{
    Node* temp = createNode(sv);
    if (isEmpty(danhsach))
    {
        danhsach.head = danhsach.tail = temp;
        return;
    }
    else
    {
        danhsach.tail->next = temp;
        danhsach.tail = temp;
    }
}

void insertHead(List& danhsach, SinhVien sv)
{
	Node* temp = createNode(sv);
	if (isEmpty(danhsach))
    {
		danhsach.head = danhsach.tail = temp;
		return;
	}
    else
    {
        temp->next = danhsach.head;
	    danhsach.head = temp;
    }
}

void deleteList(List& danhsach)
{
	Node* current = danhsach.head;
	while (current)
    {
		Node* temp = current;
		current = current->next;
		delete temp;
		temp = nullptr;
	}
	danhsach.head = danhsach.tail = nullptr;
}

QLSinhVien::QLSinhVien()
{
    initList(danhsach);
}

QLSinhVien::~QLSinhVien()
{
    deleteList(danhsach);
}

void QLSinhVien::input()
{
    cout << "Nhap so luong sinh vien: ";
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin.ignore();
        cout << "Nhap sinh vien thu " << i + 1 << ":\n";
        SinhVien sv;
        // Can ham input sinh vien
        insertTail(danhsach, sv);
    }
    cout << "\n";
}

double QLSinhVien::getClsAvg()
{
    double sum = 0;
    Node* pointer = danhsach.head;
    int count = 0;
    while (pointer)
    {
        sum += pointer->detail.getStdAvg();
        ++count;
        pointer = pointer->next;
    }
    return sum/count;
}

List QLSinhVien::getStdbelowClsAvg()
{
    double clsAve = this->getClsAvg();
    List DuoiTB;
    initList(DuoiTB);    
    Node* temp = danhsach.head;
    while (temp)
    {
        if (temp->detail.getStdAvg() < clsAve)
        {
            insertTail(danhsach, temp->detail);
        }
        temp = temp->next;
    }
    return DuoiTB;
}