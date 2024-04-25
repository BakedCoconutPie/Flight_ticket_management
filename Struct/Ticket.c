#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VES 100

struct VeMayBay {
    char ten_nguoi_dat[50];
    char thoi_gian_dat[20];
    char gia_ve[20];
    char hang_ve[20];
    char so_may_bay[10];
    char so_ghe[10];
};

struct QuanLyVeMayBay {
    struct VeMayBay danh_sach_ve[MAX_VES];
    int so_luong_ve;
};

void hien_thi_thong_tin_ve(struct VeMayBay ve) {
    printf("Thong tin ve may bay:\n");
    printf("Thong tin nguoi dat: %s\n", ve.ten_nguoi_dat);
    printf("Thoi gian dat: %s\n", ve.thoi_gian_dat);
    printf("Gia ve: %s\n", ve.gia_ve);
    printf("Hang ve: %s\n", ve.hang_ve);
    printf("So may bay: %s\n", ve.so_may_bay);
    printf("So ghe: %s\n", ve.so_ghe);
}

void them_ve(struct QuanLyVeMayBay *quan_ly_ve, struct VeMayBay ve) {
    if (quan_ly_ve->so_luong_ve < MAX_VES) {
        quan_ly_ve->danh_sach_ve[quan_ly_ve->so_luong_ve++] = ve;
        printf("Da them ve thanh cong.\n");
    } else {
        printf("Danh sach ve da day, khong the them moi.\n");
    }
}

void xoa_ve(struct QuanLyVeMayBay *quan_ly_ve, char* ten_nguoi_dat) {
    int i, found = 0;
    for (i = 0; i < quan_ly_ve->so_luong_ve; i++) {
        if (strcmp(quan_ly_ve->danh_sach_ve[i].ten_nguoi_dat, ten_nguoi_dat) == 0) {
            found = 1;
            int j;
            for (j = i; j < quan_ly_ve->so_luong_ve - 1; j++) {
                quan_ly_ve->danh_sach_ve[j] = quan_ly_ve->danh_sach_ve[j + 1];
            }
            quan_ly_ve->so_luong_ve--;
            printf("Da xoa ve cua %s.\n", ten_nguoi_dat);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay ve cua %s.\n", ten_nguoi_dat);
    }
}

void hien_thi_danh_sach_ve(struct QuanLyVeMayBay quan_ly_ve) {
    printf("Danh sach ve may bay:\n");
    int i;
    for (i = 0; i < quan_ly_ve.so_luong_ve; i++) {
        printf("Ve so %d:\n", i + 1);
        hien_thi_thong_tin_ve(quan_ly_ve.danh_sach_ve[i]);
    }
}

void TicketsMenu() {
    struct QuanLyVeMayBay quan_ly_ve = {{}, 0};
    int choice;
    do {
        printf("\nQuan ly ve may bay\n");
        printf("1. Them ve may bay\n");
        printf("2. Xoa ve may bay\n");
        printf("3. Hien thi danh sach ve may bay\n");
        printf("4. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        getchar(); // Loại bỏ ký tự newline từ bước trước
        switch(choice) {
            case 1: {
                struct VeMayBay ve;
                printf("Nhap thong tin ve may bay:\n");
                printf("Ten nguoi dat: ");
                fgets(ve.ten_nguoi_dat, sizeof(ve.ten_nguoi_dat), stdin);
                ve.ten_nguoi_dat[strcspn(ve.ten_nguoi_dat, "\n")] = '\0'; // Loại bỏ ký tự newline
                printf("Thoi gian dat: ");
                fgets(ve.thoi_gian_dat, sizeof(ve.thoi_gian_dat), stdin);
                ve.thoi_gian_dat[strcspn(ve.thoi_gian_dat, "\n")] = '\0';
                printf("Gia ve: ");
                fgets(ve.gia_ve, sizeof(ve.gia_ve), stdin);
                ve.gia_ve[strcspn(ve.gia_ve, "\n")] = '\0';
                printf("Hang ve: ");
                fgets(ve.hang_ve, sizeof(ve.hang_ve), stdin);
                ve.hang_ve[strcspn(ve.hang_ve, "\n")] = '\0';
                printf("So ve may bay: ");
                fgets(ve.so_may_bay, sizeof(ve.so_may_bay), stdin);
                ve.so_may_bay[strcspn(ve.so_may_bay, "\n")] = '\0';
                printf("So ghe: ");
                fgets(ve.so_ghe, sizeof(ve.so_ghe), stdin);
                ve.so_ghe[strcspn(ve.so_ghe, "\n")] = '\0';
                them_ve(&quan_ly_ve, ve);
                break;
            }
            case 2: {
                char ten_nguoi_dat[50];
                printf("Nhap ten nguoi can xoa: ");
                fgets(ten_nguoi_dat, sizeof(ten_nguoi_dat), stdin);
                ten_nguoi_dat[strcspn(ten_nguoi_dat, "\n")] = '\0';
                xoa_ve(&quan_ly_ve, ten_nguoi_dat);
                break;
            }
            case 3:
                hien_thi_danh_sach_ve(quan_ly_ve);
                break;
            case 4:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Chon khong hop le, vui long chon lai.\n");
        }
    } while(choice != 4);
}

int main() {
    TicketsMenu();
    return 0;
}
