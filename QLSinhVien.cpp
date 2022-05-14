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
        cout << "Nhap sinh vien thu " << i + 1 << ":\n";
        SinhVien sv;
        cin.ignore();
        sv.setInput();
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

void QLSinhVien::outputToFileB(string fileName) {
    int i = 0;
    Node* temp = danhsach.head;

    ofstream fo;
    fo.open(fileName);
    
    while (temp != NULL) {
        if (i == 0) { // header
            fo << "STT" << setw(10);
            fo << "Ho va ten" << setw(30);
            fo << "MSSV" << setw(10);
            fo << "Ngay sinh" << setw(20);
            fo << "Bai tap" << setw(10);
            fo << "Giua ki" << setw(10);
            fo << "Cuoi ki" << setw(10);
            fo << "Trung binh" << setw(10);
            fo << "Xep loai" << setw(10);
        }
        else {
            fo << i << setw(10);
            fo << temp->detail.getHoTen() << setw(30);
            fo << temp->detail.getMaSo() << setw(10);
            fo << temp->detail.getNgaySinh() << setw(20);
            fo << temp->detail.getMarks()[0] << setw(10);
            fo << temp->detail.getMarks()[1] << setw(10);
            fo << temp->detail.getMarks()[2] << setw(10);
            fo << temp->detail.getStdAvg() << setw(10);
            fo << temp->detail.getHocLuc() << setw(10);
            temp = temp->next;
        }
        fo << '\n';
        i++;
    }
    fo.close();
}