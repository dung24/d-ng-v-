#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
 
struct SinhVien{
    char hovaten[30];
    int namsinh;
    float dT, dL, dH;
    float diemtong;
};
 
typedef SinhVien SV;
 
void nhap(SV &sv);
void nhapN(SV a[], int n);
void xuat(SV sv);
void xuatN(SV a[], int n);
void tinhTong(SV &sv);
//void xuatFile(SV a[], int n, char fileName[]);
 
int main(){
    int key;
    //char fileName[] = "DSSV.txt";
    int n;
    bool daNhap = false;
    do{
        printf("Nhap so luong SV: "); scanf("%d", &n);
        if(n < 1 || n > 40) printf("moi nhap lai !");
    }while(n < 1 || n > 40);
    SV a[n];
    while(true){
        system("cls");
        printf("******************************************\n");
        printf("**    CHUONG TRINH QUAN LY SINH VIEN    **\n");
        printf("**      1. Nhap du lieu                 **\n");
        printf("**      2. In danh sach sinh vien       **\n");
        printf("**      3. Xuat DS sinh vien            **\n");
        printf("**      0. Thoat                        **\n");
        printf("******************************************\n");
        printf("**       Nhap lua chon cua ban          **\n");
        scanf("%d",&key);
        switch(key){
            case 1:
                printf("\nBan da chon nhap DS sinh vien!");
                nhapN(a, n);
                printf("\nBan da nhap thanh cong!");
                daNhap = true;
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 2:
                if(daNhap){
                    printf("\nBan da chon xuat DS sinh vien!");
                    xuatN(a, n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
             /*case 3:
                if(daNhap){
                    printf("\nBan da chon xuat DS SV!");
                    xuatFile(a, n, fileName);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nXuat DSSV thanh cong vao file %s!", fileName);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break; */
            case 0:
                printf("\nBan da chon thoat chuong trinh!");
                getch();
                return 0;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
        }
    }
}
 
 void tinhTong(SV &sv){
 	sv.diemtong = sv.dT + sv.dL + sv.dH;
 }
 
void nhap(SV &sv){
    printf("\nNhap ho va ten : "); fflush(stdin); gets(sv.hovaten);
    printf("\nNhap nam sinh : "); scanf("%d", &sv.namsinh);
    printf("\nNhap diem toan : "); scanf("%f", &sv.dT);
    printf("\nNhap diem ly : "); scanf("%f", &sv.dL);
    printf("\nNhap diem hoa : "); scanf("%f", &sv.dH);
    tinhTong(sv);
}
 
void nhapN(SV a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0; i< n; ++i){
        printf("\nNhap SV thu %d:", i+1);
        nhap(a[i]);
    }
    printf("\n____________________________________\n");
}
 
void xuat(SV sv){
    printf("\nHo ten SV: %s", sv.hovaten);
    printf("\nNam sinh : %d", sv.namsinh);
    printf("\nDiem Toan : %.2f", sv.dT);
    printf("\nDiem Ly : %.2f", sv.dL);
    printf("\nDiem Hoa : %.2f", sv.dH);
    printf("\nDiem Tong : %.2f", sv.diemtong);
}
 
void xuatN(SV a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0;i < n;++i){
        printf("\nThong tin SV thu %d:", i+1);
        xuat(a[i]);
    }
    printf("\n____________________________________\n");
}
 
/*void sapxep(SV a[], int n){
    //Sap xep theo DTB tang dan
    SV tmp;
    for(int i = 0;i < n;++i){
        for(int j = i+1; j < n;++j){
            if(a[i].dtb > a[j].dtb){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
 
void xeploai(SV sv){
    if(sv.dtb >= 8) printf("Gioi");
    else if(sv.dtb >= 6.5) printf("Kha");
    else if(sv.dtb >= 4) printf("Trung binh");
    else printf("Yeu");
}
 
void xeploaiN(SV a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0;i < n;++i){
        printf("\nXep loai cua SV thu %d la: ", i+1);
        xeploai(a[i]);
    }
    printf("\n____________________________________\n");
}
 */
/*void xuatFile(SV a[], int n, char fileName[]){
    FILE * fp;
    fp = fopen (fileName,"w");
    fprintf(fp, "%20s%5s%10s%10s%10s%10s\n", "Ho Ten", "namsinh", "DT", "DL", "DH", "DiemTong");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%20s%5d%10f%10f%10f%10f\n", a[i].hovaten, a[i].namsinh , a[i].dT, a[i].dL, a[i].dH, a[i].diemtong);
    }
    fclose (fp);
} */
