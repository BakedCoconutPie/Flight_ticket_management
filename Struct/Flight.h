#ifndef FLIGHT_H
#define FLIGHT_H

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
} Flight;

int calculateTravelTime(char departurePoint[], char destination[]);

void addFlight(Flight flights[], int *currentFlightID);

void changeFlight(Flight flights[]);

void deleteFlight(Flight flights[], int *currentFlightID);

void showflights(Flight flights[], int index);

void MenuFlights(Flight flights[], int *currentFlightID);

#endif
