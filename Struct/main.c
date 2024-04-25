#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seat.h"
#include "Flightinfomation.h"
#include "Ticket.h"
#include "buyer.h"

int main() {
    int choice;
    int loop =1;
    #define MAX_SEATS 100
    #define MAX_LENGTH 50
    #define MAX_VES 100

    while(loop=1) {
        printf("\n1. Quan li cho ngoi\n");
        printf("2. Quan li chuyen bay\n");
        printf("3. Quan li ve\n");
        printf("4. Quan li khach hang\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                MenuSeat(); 
                break;
            case 2:
                MenuFlights(Flight flights[],int *currentFlightID); 
                break;
            case 3:
                ticketManagementMenu(); 
                break;
            case 4:
                BuyerMenu();
            case 5:
                printf("Dang thoat chuong trinh...\n");
                loop =0;
                break;
            default:
                printf("Khong hop le, vui long nhap so tu 1 den 4.\n");
        }
    }

    return 0;
}
