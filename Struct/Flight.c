#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char diemden[50];
	char diemdi[50];
	char thoigiankhoihanh[20];
	char thoigianhacanh[20];
	char hanghangkhong[30];
	int thoigianbay;
	char trangthai[30];

}Flight ; 


int calculateTravelTime(char departurePoint[], char destination[])
{
    int hour = (destination[0] - departurePoint[0]) * 10 + (destination[1] - departurePoint[1]);
    int minute = (destination[3] - departurePoint[3]) * 10 + (destination[4] - departurePoint[4]);
    return hour * 60 + minute;
}
  
  
  
void addFlight(Flight flights[],int* currentFlightID){
	printf("Enter the flight's departure point: ");
	scanf("%s",&flights[*currentFlightID].diemden);
	printf("Enter the flight's destination: ");
	scanf("%s",&flights[*currentFlightID].diemdi);
	printf("Enter the flight's departure time: ");
	scanf("%s",&flights[*currentFlightID].thoigiankhoihanh);
	printf("Enter the flight's landing time: ");
	scanf("%s",&flights[*currentFlightID].thoigianhacanh);
	printf("Enter the flight's airline brand: ");
	scanf("%s",&flights[*currentFlightID].hanghangkhong);
	printf("Enter the flight's status: ");
	scanf("%s",&flights[*currentFlightID].trangthai);
	
	flights[*currentFlightID].thoigianbay=calculateTravelTime(flights[*currentFlightID].thoigiankhoihanh,flights[*currentFlightID].thoigianhacanh);
	
	(*currentFlightID)++;
	
	
}


void changeFlight(Flight flights[]){
	int index;
    printf("Enter flight's ID to change: ");
    scanf("%d", &index);
	printf("Enter the flight's departure point: ");
	scanf("%s",&flights[index].diemden);
	printf("Enter the flight's destination: ");
	scanf("%s",&flights[index].diemdi);
	printf("Enter the flight's departure time: ");
	scanf("%s",&flights[index].thoigiankhoihanh);
	printf("Enter the flight's landing time: ");
	scanf("%s",&flights[index].thoigianhacanh);
	printf("Enter the flight's airline brand: ");
	scanf("%s",&flights[index].hanghangkhong);
	printf("Enter the flight's status: ");
	scanf("%s",&flights[index].trangthai);
	
}

void deleteFlight(Flight flights[],int *currentFlightID){
	int choice;
    printf("Enter flight's ID to delete: ");
    scanf("%d", &choice);
	int i;	
    for ( i = choice; i < *currentFlightID - 1; i++)
    {
        strcpy(flights[i].diemden, flights[i + 1].diemden);
        strcpy(flights[i].diemdi, flights[i + 1].diemdi);
        strcpy(flights[i].thoigiankhoihanh, flights[i + 1].thoigiankhoihanh);
        strcpy(flights[i].thoigianhacanh, flights[i + 1].thoigianhacanh);
        strcpy(flights[i].hanghangkhong, flights[i + 1].hanghangkhong);
        flights[i].thoigianbay = flights[i + 1].thoigianbay;
        strcpy(flights[i].trangthai, flights[i + 1].trangthai);
    }

    (*currentFlightID)--;
}

  
  void showflights(Flight flights[], int index){
  	printf("Diem den:%s\n",flights[index].diemden);
	printf("Diem di:%s\n",flights[index].diemdi);
	printf("Thoi gian khoi hanh:%s\n",flights[index].thoigiankhoihanh);
	printf("Thoi gian ha canh:%s\n",flights[index].thoigianhacanh);
	printf("Hang hang khong:%s\n",flights[index].hanghangkhong);
	printf("Thoi gian bay:%d\n",flights[index].thoigianbay);	
  	
}
  
  
  	
void MenuFlights(Flight flights[],int *currentFlightID){
	int loop=1;
	while(loop){
		 printf("ID Departure Destination Start Land Brand Total Time Status\n");
		int i;
        for ( i = 0; i < *currentFlightID; i++)
        {
            printf("%d %15s %15s %9s %9s %15s %d %10s \n",
                   i,
                   flights[i].diemden,
                   flights[i].diemdi,
                   flights[i].thoigiankhoihanh,
                   flights[i].thoigianhacanh,
                   flights[i].hanghangkhong,
                   flights[i].thoigianbay,
                   flights[i].trangthai);
		}
		
	int choice;

        printf("\n1. Add flight\n");
        printf("2. Delete flight\n");
        printf("3. Change flight\n");
        printf("4. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);
       

        switch (choice)
        {
        case 1:
            addFlight(flights, currentFlightID);
            system("Cls");
			break;
        case 2:
            deleteFlight(flights, currentFlightID);
            system("Cls");
			break;
        case 3:
            changeFlight(flights);
            system("Cls");
			break;
        case 4:
            loop = 0;
            break;		
		
		}
	}
}

int main(){
	Flight flights[100];
	int currentFlightID=0;
	MenuFlights(flights, &currentFlightID);
	return 0;
}
