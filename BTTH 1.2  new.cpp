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
            cout << "Vui long nhap lai!\n";
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
        cout << "Mau so khong duoc bang 0. Vui long nhap lai!\n";
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
Ham tim phan so lon nhat
Quy dong de tim phan so lon nhat va dung long long de tranh tran so
Xuat phan so lon nhat
*/
void timPhanSoLonNhat(PhanSo ps1, PhanSo ps2)
{
    long long gtri1 = (long long)ps1.tuSo * ps2.mauSo;
    long long gtri2 = (long long)ps2.tuSo * ps1.mauSo;

    if (gtri1 > gtri2)
    {
        cout << "Phan so lon nhat la: ";
        xuatPhanSo(ps1);
    }
    else if (gtri1 < gtri2)
    {
        cout << "Phan so lon nhat la: ";
        xuatPhanSo(ps2);
    }
    else
        cout << "Hai phan so bang nhau";
    cout << endl;
}

int main()
{
    PhanSo ps1 = nhapPhanSo(1);
    PhanSo ps2 = nhapPhanSo(2);
    timPhanSoLonNhat(ps1, ps2);
    return 0;
}
