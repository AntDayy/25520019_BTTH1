#include <iostream>
#include <limits>
#include <string>

using namespace std;

/*
Dinh nghia kieu du lieu Ngay gom co ngay thang nam
*/
struct Ngay
{
    int ngay;
    int thang;
    int nam;
};

/*
Kiem tra nguoi dung co nhap dung hay khong
Nhap ki tu dac biet, chuoi, chu cai khong hop le thi bat nhap lai
Nhap dung thi tra ve value
*/
int nhapSoNguyen(const string &loiNhac)
{
    int giaTri;
    while (true)
    {
        cout << loiNhac;
        if (cin >> giaTri)
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
    return giaTri;
}

/*
Ham kiem tra nam nhuan
Nam nhuan la nam chia het cho 400 hoac chia het cho 3 nhung khong chia het cho 100
*/
bool laNamNhuan(int nam)
{
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

/*
Ham tra ve so ngay toi da trong mot thang
Thang 2 se co 29 ngay neu la nam nhuan, khong thi co 28 ngay
*/
int soNgayTrongThang(int thang, int nam)
{
    switch (thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return laNamNhuan(nam) ? 29 : 28;
    default:
        return 0;
    }
}

/*
Ham kiem tra nguoi dung co nhap ngay thang nam dung hay khong
Ngay dung khi ngay > 1 va be hon so ngay toi da trong thang do
Thang dung khi thang >= 1 va <= 12
Nam dung khi nam > 0
*/
bool kiemTraNgayHopLe(Ngay n)
{
    if (n.nam <= 0 || n.thang < 1 || n.thang > 12)
        return false;
    if (n.ngay < 1 || n.ngay > soNgayTrongThang(n.thang, n.nam))
        return false;
    return true;
}

/*
Ham nhap ngay
Kiem tra xem nguoi dung co nhap dung ngay thang nam khong
Nhap sai thi bat nhap lai
*/
Ngay nhapNgay()
{
    Ngay n;
    cout << "Nhap ngay thang nam \n";
    while (true)
    {
        n.ngay = nhapSoNguyen("Nhap ngay: ");
        n.thang = nhapSoNguyen("Nhap thang: ");
        n.nam = nhapSoNguyen("Nhap nam: ");

        if (kiemTraNgayHopLe(n))
        {
            break;
        }
        else
        {
            cout << "Input khong hop le. Vui long nhap lai! \n";
        }
    }
    return n;
}

/*
Ham xuat ngay thang nam
*/
void xuatNgay(Ngay n)
{
    cout << n.ngay << "/" << n.thang << "/" << n.nam;
}

/*
Ham tim ngay ke tiep
Cong ngay do them 1 ngay va kiem tra xem sau khi cong co vuot qua so ngay toi da khong
Ngay vuot qua thi tro lai ngay 1 va sang thang tiep theo
Kiem tra xem thang co vuot qua nam moi hay khong
Vuot qua thi tro lai thang 1 va tang len nam moi
*/
Ngay timNgayKeTiep(Ngay n)
{
    Ngay keTiep = n;
    keTiep.ngay++;

    if (keTiep.ngay > soNgayTrongThang(keTiep.thang, keTiep.nam))
    {
        keTiep.ngay = 1;
        keTiep.thang++;

        if (keTiep.thang > 12)
        {
            keTiep.thang = 1;
            keTiep.nam++;
        }
    }
    return keTiep;
}

int main()
{
    Ngay n = nhapNgay();
    cout << "\nNgay ban vua nhap la: ";
    xuatNgay(n);
    Ngay keTiep = timNgayKeTiep(n);
    cout << "\nNgay ke tiep la:      ";
    xuatNgay(keTiep);
    cout << "\n";
    return 0;
}
