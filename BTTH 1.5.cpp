#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

/*
Dinh nghia kieu du lieu HocSinh gom co ho ten, diem toan, diem van va diem trung binh
*/
struct HocSinh
{
    string hoTen;
    float diemToan;
    float diemVan;
    float diemTrungBinh;
};

/*
Ham kiem tra xem nguoi dung co nhap loi hay khong
Nhap loi khi diem < 0 va > 10, ten thi nhap sai
Nhap dung thi tra ve diem
*/
float nhapDiem(const string &error)
{
    float diem;
    while (true)
    {
        cout << error;
        if (cin >> diem && diem >= 0 && diem <= 10)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        else
        {
            cout << "Diem khong hop le! Vui long nhap so thuc tu 0 den 10.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return diem;
}

/*
Ham nhap thong tin
*/
void nhapThongTin(HocSinh &hs)
{
    cout << "Nhap thon tin hoc sinh \n";
    cout << "Nhap ho va ten: ";
    getline(cin, hs.hoTen);
    hs.diemToan = nhapDiem("Nhap diem Toan (0-10): ");
    hs.diemVan = nhapDiem("Nhap diem Van (0-10): ");
}

/*
Ham tinh diem trung binh
Tra ve kieu du lieu so thuc
*/
void tinhDiemTrungBinh(HocSinh &hs)
{
    hs.diemTrungBinh = (hs.diemToan + hs.diemVan) / 2.0f;
}

/*
Ham xuat thong tin cua hoc sinh
Dung fixed va setprecision de lam tron hai chu so thap phan
*/
void xuatThongTin(HocSinh hs)
{
    cout << "\nKET QUA HO SO HOC SINH\n";
    cout << "Ho va ten       : " << hs.hoTen << "\n";
    cout << "Diem Toan       : " << hs.diemToan << "\n";
    cout << "Diem Van        : " << hs.diemVan << "\n";

    cout << fixed << setprecision(2);
    cout << "Diem Trung Binh : " << hs.diemTrungBinh << "\n";
}

int main()
{
    HocSinh hs;
    nhapThongTin(hs);
    tinhDiemTrungBinh(hs);
    xuatThongTin(hs);
    return 0;
}
