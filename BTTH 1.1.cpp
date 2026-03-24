#include <iostream>
#include <numeric>
#include <limits>
#include <string>

using namespace std;

// ham nhap so nguyen, neu nguoi dung nhap ktdb hoac chuoi thi bat nhap lai
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

// ham nhap phan so (kiem tra mau khac 0)
void nhapPhanSo(int &tuSo, int &mauSo)
{
    tuSo = nhapSoNguyen("Nhap tu so: ");
    while (true)
    {
        mauSo = nhapSoNguyen("Nhap mau so: ");
        if (mauSo != 0)
        {
            break;
        }
        else
        {
            cout << "Mau so khong duoc phep bang 0, vui long nhap lai \n";
        }
    }
}

// ham rut gon phan so
void rutGonPhanSo(int &tuSo, int &mauSo)
{
    int ucln = gcd(tuSo, mauSo);
    tuSo /= ucln;
    mauSo /= ucln;
    if (mauSo < 0)
    {
        tuSo = -tuSo;
        mauSo = -mauSo;
    }
}

// ham in ket qua
void xuatPhanSo(int tuSo, int mauSo)
{
    if (tuSo == 0)
    {
        cout << "Ket qua: 0\n";
    }
    else if (mauSo == 1)
    {
        cout << "Ket qua: " << tuSo << "\n";
    }
    else
    {
        cout << "Ket qua: " << tuSo << "/" << mauSo << "\n";
    }
}

int main()
{
    int tu, mau;
    nhapPhanSo(tu, mau);
    rutGonPhanSo(tu, mau);
    xuatPhanSo(tu, mau);

    return 0;
}