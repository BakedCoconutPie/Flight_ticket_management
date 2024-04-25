#ifndef BUYER_H
#define BUYER_H

#define MAX_LENGTH 50
#define BUYER_FILE_PATH "C:\\Users\\ACER\\Documents\\buyer\\buyer.txt"

typedef struct {
    char CCCD[MAX_LENGTH];
    char name[MAX_LENGTH];
    char sdt[MAX_LENGTH];
    char mail[MAX_LENGTH];
} buyer_detail;

void addBuyer(buyer_detail *AnewBuyer);
void displayBuyer(buyer_detail AnewBuyer);
void changeBuyer(buyer_detail *AnewBuyer);
void writeBuyerFile(buyer_detail Buyer[], int n);
void readBuyerFile(buyer_detail Buyer[], int *n);

#endif