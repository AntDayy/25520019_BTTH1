#include <iostream>
#include <numeric>
#include <limits>
#include <string>

using namespace std;

/*
Dinh nghia kieu du lieu phan so gom co tu so va mau so
*/
struct PhanSo
{
    int tuSo;
    int mauSo;
};

/*
Kiem tra nguoi dung co nhap dung hay khong
Nhap ki tu dac biet, chuoi, chu cai khong hop le thi bat nhap lai
Nhap dung thi tra ve value
*/
int nhapSoNguyen(const string &error)
{
    int value;
    while (true)
    {
        cout << error;
        if (cin >> value)
        {
            break;
        }
        else
        {
            cout << " [Loi] Vui long chi nhap so nguyen!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return value;
}

/*
Ham rut gon phan so truoc khi xuat
Doi dau cua phan so khi mau so be hon 0
*/
void rutGon(PhanSo &ps)
{
    int ucln = gcd(ps.tuSo, ps.mauSo);
    ps.tuSo /= ucln;
    ps.mauSo /= ucln;
    if (ps.mauSo < 0)
    {
        ps.tuSo = -ps.tuSo;
        ps.mauSo = -ps.mauSo;
    }
}

/*
Ham nhap tu so va mau so
Neu nguoi dung nhap mau so bang 0 thi bat nhap lai
Rut gon phan so ngay sau khi nhap
*/
PhanSo nhapPhanSo(int stt)
{
    PhanSo ps;
    cout << "Nhap Phan So thu " << stt << endl;
    ps.tuSo = nhapSoNguyen("Nhap tu so: ");
    while (true)
    {
        ps.mauSo = nhapSoNguyen("Nhap mau so: ");
        if (ps.mauSo != 0)
            break;
        cout << " [Loi] Mau so khong duoc bang 0!\n";
    }
    rutGon(ps);
    return ps;
}

/*
Ham xuat phan so
Neu tu so = 0 thi cout 0
Neu mau so = 1 thi cout ra tu so
*/
void xuatPhanSo(PhanSo ps)
{
    if (ps.tuSo == 0)
        cout << "0";
    else if (ps.mauSo == 1)
        cout << ps.tuSo;
    else
        cout << ps.tuSo << "/" << ps.mauSo;
}

/*
Ham tinh tong giua hai phan so
Quy dong hai phan so roi thuc hien phep cong
Rut gon phan so truoc khi xuat
*/
PhanSo tinhTong(PhanSo ps1, PhanSo ps2)
{
    PhanSo kq;
    kq.tuSo = (ps1.tuSo * ps2.mauSo) + (ps2.tuSo * ps1.mauSo);
    kq.mauSo = ps1.mauSo * ps2.mauSo;
    rutGon(kq);
    return kq;
}

/*
Ham tinh hieu giua hai phan so
Quy dong hai phan so roi thuc hien phep tru
Rut gon phan so truoc khi xuat
*/
PhanSo tinhHieu(PhanSo ps1, PhanSo ps2)
{
    PhanSo kq;
    kq.tuSo = (ps1.tuSo * ps2.mauSo) - (ps2.tuSo * ps1.mauSo);
    kq.mauSo = ps1.mauSo * ps2.mauSo;
    rutGon(kq);
    return kq;
}

/*
Ham tinh tich giua hai phan so
Tich cua hai phan so la tu so nhan voi tu so va mau so nhan voi mau so
Rut gon phan so truoc khi xuat
*/
PhanSo tinhTich(PhanSo ps1, PhanSo ps2)
{
    PhanSo kq;
    kq.tuSo = ps1.tuSo * ps2.tuSo;
    kq.mauSo = ps1.mauSo * ps2.mauSo;
    rutGon(kq);
    return kq;
}

/*
Ham tinh thuong giua hai phan so
Thuong cua hai phan so la tich nghich dao cua hai phan so
Truong hop khong the thuc hien phep chia vi phan so thu 2 = 0 thi thoat
Rut gon phan so truoc khi xuat
*/
void tinhThuong(PhanSo ps1, PhanSo ps2)
{
    if (ps2.tuSo == 0)
    {
        return;
    }
    PhanSo kq;
    kq.tuSo = ps1.tuSo * ps2.mauSo;
    kq.mauSo = ps1.mauSo * ps2.tuSo;
    rutGon(kq);
    xuatPhanSo(kq);
    cout << "\n";
}

int main()
{
    PhanSo ps1 = nhapPhanSo(1);
    PhanSo ps2 = nhapPhanSo(2);
    cout << "Tong: ";
    xuatPhanSo(tinhTong(ps1, ps2));
    cout << endl;
    cout << "Hieu: ";
    xuatPhanSo(tinhHieu(ps1, ps2));
    cout << endl;
    cout << "Tich: ";
    xuatPhanSo(tinhTich(ps1, ps2));
    cout << endl;
    cout << "Thuong: ";
    tinhThuong(ps1, ps2);
    return 0;
}
