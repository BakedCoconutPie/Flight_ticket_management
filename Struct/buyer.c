#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50
#define BUYER_FILE_PATH "buyer.txt"

typedef struct {
    char CCCD[MAX_LENGTH];
    char name[MAX_LENGTH];
    char sdt[MAX_LENGTH];
    char mail[MAX_LENGTH];
} buyer_detail;

void addBuyer(buyer_detail *AnewBuyer) {
    printf("Nhap so CCCD: ");
    scanf("%d", &AnewBuyer->CCCD);
    printf("Nhap ten nguoi mua ve: ");
    scanf("%*c%19[^\n]", AnewBuyer->name);          //đọc vào cả chuỗi (bao gồm dấu cách), chỉ dừng khi gặp \n
    printf("Nhap so sdt: ");
    scanf("%d", &AnewBuyer->sdt);
    printf("Nhap dai chi mail (neu can): ");
    scanf("%*c%19[^\n]", AnewBuyer->mail);
}

void displayBuyer(buyer_detail AnewBuyer) {
    printf("     Thong tin cua nguoi mua ve     \n");
    printf("So CCCD: %s\n", AnewBuyer.CCCD);
    printf("Nguoi mua ve: %s\n", AnewBuyer.name);
    printf("So sdt: %s\n", AnewBuyer.sdt);
    printf("Dia chi mail cua nguoi mua ve: %s\n", AnewBuyer.mail);
}

void changeBuyer(buyer_detail *AnewBuyer) {
    printf("Nhap so CCCD: ");
    scanf("%d", &AnewBuyer->CCCD);
    printf("Nhap ten nguoi mua ve: ");
    scanf("%*c%19[^\n]", AnewBuyer->name);          //đọc vào cả chuỗi (bao gồm dấu cách), chỉ dừng khi gặp \n
    printf("Nhap so sdt: ");
    scanf("%d", &AnewBuyer->sdt);
    printf("Nhap dia chi mail (neu can): ");
    scanf("%*c%19[^\n]", AnewBuyer->mail);
}

void writeBuyerFile(buyer_detail Buyer[], int n) {
    FILE *fp;
    fp = fopen(BUYER_FILE_PATH, "wb");
    if (fp == NULL) {
        printf("Cannot open file %s\n", BUYER_FILE_PATH);
        return;
    }

    fwrite(Buyer, sizeof(buyer_detail), n, fp);
    puts("Nhap thong tin nguoi mua ve thanh cong !");
    fclose(fp);
}

void readBuyerFile(buyer_detail Buyer[], int *n) {
    FILE *fp;
    fp = fopen(BUYER_FILE_PATH, "rb");
    if (fp == NULL) {
        printf("Cannot open file %s\n", BUYER_FILE_PATH);
        return;
    }

    *n = fread(Buyer, sizeof(buyer_detail), MAX_LENGTH, fp);
    fclose(fp);
}

int main () {
    buyer_detail Buyer[MAX_LENGTH];
    int n = 0;
    int option = 0;
    do {
        printf("\n=====Thong tin nguoi mua ve=====\n");
        printf("1. Nhap thong tin nguoi mua ve\n");
        printf("2. In ra thong tin nguoi mua ve\n");
        printf("3. Cap nhat/chinh sua thong tin nguoi mua ve\n");
        printf("4. Ghi thong tin nguoi mua ve\n");
        printf("5. Doc thong tin nguoi mua ve\n");
        printf("6. Thoat\n");
        printf("Choose your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addBuyer(&Buyer[n]);
                n++;
                break;
            case 2:
                for (int i = 0; i < n; i++) {
                    displayBuyer(Buyer[i]);
                }
                break;
            case 3:
                printf("Nhap vi tri can cap nhat: ");
                int pos;
                scanf("%d", &pos);
                if (pos >= 0 && pos < n) {
                    changeBuyer(&Buyer[pos]);
                } else {
                    printf("Vi tri khong hop le.\n");
                }
                break;
            case 4:
                writeBuyerFile(Buyer, n);
                break;
            case 5:
                readBuyerFile(Buyer, &n);
                for (int i = 0; i < n; i++) {
                    displayBuyer(Buyer[i]);
                }
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Chon khong hop le, vui long chon lai.\n");
        }
    } while (option != 6);

    return 0;
}