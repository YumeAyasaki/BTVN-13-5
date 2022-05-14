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
        if (danhsach.tail == nullptr) {
            danhsach.tail = temp;
        }
        else {
            danhsach.tail->next = temp;
            danhsach.tail = temp;
        }
        
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

void insertMid(Node* node, SinhVien sv)
{
	Node* q = createNode(sv);
	q->next = node->next;
	node->next = q;
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

void QLSinhVien::inputFromFile(string fileName) {
    Node* temp = new Node;
    // List l;
    // initList(l);
    ifstream fs("input.txt", ios_base::in);
    if (fs.is_open()){
        string* st;
        while (!fs.eof())
        {
            st = new string;
            getline(fs,*st);
            temp->detail.setHoTen((char*)(*st).c_str());
            st = new string;
            getline(fs,*st);
            temp->detail.setMaSo((char*)(*st).c_str());
            st = new string;
            getline(fs,*st);
            temp->detail.setNgaySinh((char*)(*st).c_str());
            double* tmp = new double[3];
            fs>>tmp[0];
            fs>>tmp[1];
            fs>>tmp[2];
            temp->detail.setMarks(tmp);
            getline(fs,*st);
            insertTail(danhsach,temp->detail);
        }
    }
    fs.close();
}

void QLSinhVien::outputToFile(string fileName) {
    int i = 0;
    Node* temp = danhsach.head;

    ofstream fo;
    fo.open(fileName);
    
    while (temp != NULL) {
        if (i == 0) { // header
            fo << setw(10) << "STT";
            fo << setw(30) << "Ho va ten";
            fo << setw(10) << "MSSV" ;
            fo << setw(20) << "Ngay sinh";
            fo << setw(10) << "Bai tap";
            fo << setw(10) << "Giua ki";
            fo << setw(10) << "Cuoi ki";
            fo << setw(10) << "TB";
        }
        else {
            fo << setw(10) << i;
            fo << setw(30) << temp->detail.getHoTen();
            fo << setw(10) << temp->detail.getMaSo();
            fo << setw(20) << temp->detail.getNgaySinh();
            fo << setw(10) << temp->detail.getMarks()[0];
            fo << setw(10) << temp->detail.getMarks()[1];
            fo << setw(10) << temp->detail.getMarks()[2];
            fo << setw(10) << temp->detail.getStdAvg();
            temp = temp->next;
        }
        fo << '\n';
        i++;
    }
    fo.close();
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
            insertTail(DuoiTB, temp->detail);
        }
        temp = temp->next;
    }
    return DuoiTB;
}

void QLSinhVien::addSVtoList(SinhVien& sv)
{
    if (atoi(danhsach.head->detail.getMaSo()) > atoi(sv.getMaSo())) {
		insertHead(danhsach, sv);
		return;
	}
    else if (atoi(danhsach.tail->detail.getMaSo()) < atoi(sv.getMaSo())) {
		insertTail(danhsach, sv);
		return;
	}
    
    Node* temp = danhsach.head;
	while (temp->next) {
		if (atoi(temp->detail.getMaSo()) < atoi(sv.getMaSo()) && atoi(temp->next->detail.getMaSo()) > atoi(sv.getMaSo())) {
			insertMid(temp, sv);
		}
		temp = temp->next;
	}
}

void QLSinhVien::outputToFileB(string fileName) {
    int i = 0;
    Node* temp = danhsach.head;

    ofstream fo;
    fo.open(fileName);
    
    while (temp != NULL) {
        if (i == 0) { // header
            fo << setw(10) << "STT";
            fo << setw(30) << "Ho va ten";
            fo << setw(10) << "MSSV" ;
            fo << setw(20) << "Ngay sinh";
            fo << setw(10) << "Bai tap";
            fo << setw(10) << "Giua ki";
            fo << setw(10) << "Cuoi ki";
            fo << setw(10) << "TB";
            fo << setw(20) << "Xep loai";
        }
        else {
            fo << setw(10) << i;
            fo << setw(30) << temp->detail.getHoTen();
            fo << setw(10) << temp->detail.getMaSo();
            fo << setw(20) << temp->detail.getNgaySinh();
            fo << setw(10) << temp->detail.getMarks()[0];
            fo << setw(10) << temp->detail.getMarks()[1];
            fo << setw(10) << temp->detail.getMarks()[2];
            fo << setw(10) << temp->detail.getStdAvg();
            fo << setw(20) << temp->detail.getHocLuc();
            temp = temp->next;
        }
        fo << '\n';
        i++;
    }
    fo.close();
}