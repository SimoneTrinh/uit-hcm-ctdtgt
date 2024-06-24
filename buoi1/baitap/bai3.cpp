#include <stdio.h>
#include <iostream>

using namespace std;

struct NhanVien
{
    int _maNV;
    string _hoTen;
    int _luongCoBan;
    int _soNgayLam;
    int _luongHangThang = getLuongThang();

    // NhanVien(int maNV, string hoTen, int luongCoBan, int soNgayLam)
    // {
    //     _maNV = maNV;
    //     _hoTen = hoTen;
    //     _luongCoBan = luongCoBan;
    //     _soNgayLam = soNgayLam;
    //     _luongHangThang = getLuongThang();
    // }

    int getLuongThang()
    {
        int luong = _luongCoBan + (_soNgayLam * 180000);
        if (luong > 8000000)
        {
            luong = luong * (1 + 0.05);
        }
        else if (luong < 5000000)
        {
            luong = luong * (1 + 0.1);
        }
        return luong;
    }

    void printInfoNhanVien()
    {
        cout << "Nhan vien: " << _hoTen << " | ID: " << _maNV << " | Luong co ban: " << _luongCoBan << " | Ngay cong: " << _soNgayLam << " | Thuc lanh: " << _luongHangThang << endl;
    }
};

void initNhanVien(NhanVien *nv, int &length)
{
    length = 10;
    *(nv + 0) = {1, "Nguyen Van An", 5000000, 22};
    *(nv + 1) = {2, "Tran Thi Bao", 6000000, 20};
    *(nv + 2) = {3, "Le Van Cuc", 3500000, 25};
    *(nv + 3) = {4, "Pham Thi Dung", 4200000, 18};
    *(nv + 4) = {5, "Hoang Van Quang", 4800000, 24};
    *(nv + 5) = {6, "Vo Thi Trang", 4300000, 21};
    *(nv + 6) = {7, "Bui Van Cong", 5700000, 19};
    *(nv + 7) = {8, "Do Thi Hong", 5900000, 23};
    *(nv + 8) = {9, "Pham Van Bach", 6100000, 20};
    *(nv + 9) = {10, "Nguyen Thi Ngoc", 6100000, 22};
}

void showListNhanVien(NhanVien *nv, int &length)
{
    for (int i = 0; i < length; i++)
    {
        (nv + i)->printInfoNhanVien();
    }
}

void showTotalSalaryCost(NhanVien *nv, int &length)
{
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        total += (nv + i)->_luongHangThang;
    }
    cout << "Tong so tien luong cong ty can tra: " << total << " VND.";
}

void showTotalSalaryCostOfLess5MillEmployee(NhanVien *nv, int &length)
{
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        if ((nv + i)->_luongCoBan < 5000000)
        {
            total += (nv + i)->_luongHangThang;
        }
    }
    cout << "Tong so tien luong cong ty can tra cho NV co luong CB < 5M: " << total << " VND.";
}

void findNVByID(NhanVien *nv, int &length, int IDNhanVien)
{
    int found = 0;
    for (int i = 0; i < length; i++)
    {
        if ((nv + i)->_maNV == IDNhanVien)
        {
            cout << "Tim thay nhan vien co ma NV " << IDNhanVien << ". Ho ten: " << (nv + i)->_hoTen << endl;
            found = 1;
        }
    }
    if (found == 0)
    {
        cout << "Khong tim thay nhan vien co ma NV " << IDNhanVien << endl;
    }
}

void findEmployeeHaveLowestSalary(NhanVien *nv, int &length)
{
    int lowestSalary = 50000000;
    int employeeID = 100;
    for (int i = 0; i < length; i++)
    {
        if ((nv + i)->_luongHangThang < lowestSalary)
        {
            lowestSalary = (nv + i)->_luongHangThang;
            employeeID = (nv + i)->_maNV;
        }
    }
    cout << "Nhan vien co luong thap nhat la: " << lowestSalary << endl;
    findNVByID(nv, length, employeeID);
}

void findAllEmployeeHaveBaseSalary(NhanVien *nv, int &length, int baseSalary)
{
    for (int i = 0; i < length; i++)
    {
        if ((nv + i)->_luongCoBan == baseSalary)
        {
            findNVByID(nv, length, (nv + i)->_maNV);
        }
    }
}

void findEmployeeHaveHighestBaseSalary(NhanVien *nv, int &length)
{
    int highestSalary = 0;
    for (int i = 0; i < length; i++)
    {
        if ((nv + i)->_luongCoBan >= highestSalary)
        {
            highestSalary = (nv + i)->_luongCoBan;
        }
    }
    cout << "Nhan vien co luong co ban cao nhat la: " << highestSalary << endl;
    findAllEmployeeHaveBaseSalary(nv, length, highestSalary);
}

int main()
{
    // 1. Tao du lieu nhan vien cho cong ty
    NhanVien *listNV = new NhanVien[100];
    int length = 0;
    initNhanVien(listNV, length);
    // 2. Xuat danh sach nhan vien cong ty
    // 3. Cap nhat tien luong cho tung nhan vien
    showListNhanVien(listNV, length);
    // 4. Tong luong thang cong ty phai tra cho nhan vien
    showTotalSalaryCost(listNV, length);
    // 5. Tong luong thang cua cac nhan vien co luong co ban < 5 trieu
    showTotalSalaryCostOfLess5MillEmployee(listNV, length);
    // 6. Tim nhan vien theo ma nhan vien
    findNVByID(listNV, length, 3);
    // 7. Tim nhan vien co luong hang thang thap nhat
    findEmployeeHaveLowestSalary(listNV, length);
    // 8. Tim nhan vien co luong co ban cao nhat
    findEmployeeHaveHighestBaseSalary(listNV, length);
    return 0;
}