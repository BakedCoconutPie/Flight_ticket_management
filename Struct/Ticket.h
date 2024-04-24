#ifndef TICKET_H
#define TICKET_H

#define MAX_SEATS 100

struct Seat {
    int seatNumber;
    int flightNumber;
    int booked;
};

void saveToFile();
void loadFromFile();
void displayMenu();
void addSeat();
void deleteSeat();
void editSeat();
void displaySeats();

#endif /* TICKET_H */