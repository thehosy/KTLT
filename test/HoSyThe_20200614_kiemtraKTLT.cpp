#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct List {
    T *head, *tail;

    List(): head(NULL), tail(NULL) {}
};

struct NhanVien {
    string maNV;
    string hoten;
    int namsinh;
    double hsluong;
    double luong, tongluong, PCCV, congdoanphi;
    string chucdanh;
    NhanVien *next;

    NhanVien(): next(NULL) {}
};

struct PhongBan {
    string tenPhongBan;
    string diachi;
    int soluongnv;
    double luongTT, tongluongPB, tongCDP;
    List<NhanVien> dsNhanvien;
    PhongBan *next;

    PhongBan(): 
    dsNhanvien(List<NhanVien> ()), next(NULL), tongluongPB(0), tongCDP(0) {}
};

unordered_map<string, double> PCCV = {{"GVCC", 2000}, {"GVC", 1500}, 
{"GV", 1000}, {"CBKT", 750}, {"CBHC", 500}};

template<typename T>
void add_back_toList(List<T> &ls, T *node) {
    if(ls.head == NULL) {
        ls.head = node;
        ls.tail = node;
        return;
    }
    ls.tail->next = node;
    ls.tail = node;
}

void freeDsNhanVien(List<NhanVien> &ls) {
    while(ls.head != NULL) {
        NhanVien *temp = ls.head->next;
        delete ls.head;
        ls.head = temp;
    }
    ls.tail = NULL;
}

void freeList(List<PhongBan> &ls) {
    while(ls.head != NULL) {
        PhongBan *temp = ls.head->next;
        freeDsNhanVien(ls.head->dsNhanvien);
        delete ls.head;
        ls.head = temp;
    }
    ls.tail = NULL;
}

NhanVien* nhap_nhanvien() {
    NhanVien *nv = new NhanVien();
    cout << "\n       Ma NV: ";
    cin >> nv->maNV;
    cin.ignore();
    cout << "\n       Ho ten Nhan vien: ";
    getline(cin, nv->hoten);
    cout << "\n       Nhap nam sinh: ";
    cin >> nv->namsinh;
    cout << "\n       Nhap HS luong: ";
    cin >> nv->hsluong;
    cin.ignore();
    cout << "\n       Nhap chuc danh: ";
    cin >> nv->chucdanh;

    return nv;
}

void nhap_phongban(List<PhongBan> &dsPhongban) {
    int n;
    cout << "Nhap so phong ban: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        PhongBan* pb = new PhongBan();
        add_back_toList(dsPhongban, pb);
        cin.ignore();
        cout << "   Ten Phong Ban: ";
        getline(cin, pb->tenPhongBan);
        cout << "\n   Dia chi: ";
        getline(cin, pb->diachi);
        cout << "\n   Luong toi thieu: ";
        cin >> pb->luongTT;
        cout << "\n   So nhan vien: ";
        cin >> pb->soluongnv;
        cout << "\n   Nhap ds Nhan vien:";
        for(int j = 1; j <= pb->soluongnv; j++) {
            cout << "\n   Nhan vien thu: " << j << '\n';
            cin.ignore();
            NhanVien *nv = nhap_nhanvien();
            nv->luong = nv->hsluong * pb->luongTT;
            nv->PCCV = PCCV[nv->chucdanh];
            nv->tongluong = nv->luong + nv->PCCV;
            nv->congdoanphi = nv->tongluong / 100;
            
            pb->tongluongPB += nv->tongluong;
            pb->tongCDP += nv->congdoanphi;

            add_back_toList(dsPhongban.tail->dsNhanvien, nv);
        }
    }
    cout << "\nBan da nhap thanh cong!\n";
    system("pause");
}

void in_dsNhanvien(List<NhanVien> &dsNhanvien) {
    NhanVien *nv = dsNhanvien.head;
    while(nv != NULL) {
        cout << setw(8) << right << nv->maNV
            << "       " << setw(25) << left << nv->hoten << "      " 
            << setw(8) << left << nv->chucdanh << "      " << setw(8) << left << nv->PCCV << "  "
            << setw(8) << left <<nv->hsluong << "  " << setw(12) << left << nv->tongluong << "  "
            << setw(10) << left << nv->congdoanphi << "  " << (nv->tongluong -  nv->congdoanphi) << '\n';

        nv = nv->next;
    }
}

void in_dsPhongban(List<PhongBan> &dsPhongban) {
    PhongBan *pb = dsPhongban.head;
    while(pb != NULL) {
        cout << "   Ten phong ban: " << pb->tenPhongBan << '\n';
        cout << "   Dia chi: " << pb->diachi << '\n';
        cout << "   Luong TT: " << pb->luongTT << '\n';
        cout << "   Tong luong PB: " << pb->tongluongPB << '\n';
        cout << "   Tong CD phi: " << pb->tongCDP << '\n';
        cout << "   Bang luong Nhan vien:\n";
        cout << "   MaNV        Ho ten NV                     Chuc danh         PCCV     HesoL      Luong         CDP        Con nhan\n";
        in_dsNhanvien(pb->dsNhanvien);
        pb = pb->next;
        cout << '\n';
    }

    cout << '\n';
    system("pause");
}

int main() {
    cout << "Ho Sy The - 20200614\n";

    List<PhongBan> dsPhongban = List<PhongBan>();
    int choice;

    while(true) {
        cout << "\n\n**************************************************\n"
                "**  CHUONG TRINH QUAN LY Phong ban - Nhan vien  **\n"
                "**1. Nhap cac Phong ban                         **\n"
                "**2. In ket qua ds Phong ban va Nhan vien       **\n"
                "**0. Thoat                                      **\n"
                "**************************************************\n"
                "**  Nhap lua chon cua ban                       **\n\n";
        
        cin >> choice;

        if(choice == 0) {
            cout << "\nBan da chon thoat chuong trinh!\n";
            freeList(dsPhongban);
            break;
        }
        switch(choice) {
            case 1: {
                cout << "Ban da chon nhap ds phong ban - nhan vien!\n";
                nhap_phongban(dsPhongban);
                break;
            }
            case 2: {
                cout << "Ban da chon xuat DS phong ban!\n";
                in_dsPhongban(dsPhongban);
                break;
            }
            default: {
                cout << "\nBan da chon sai chuc nang. Moi nhap lai!\n";
                break;
            }
        }
    }

    return 0;
}