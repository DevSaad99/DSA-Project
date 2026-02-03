#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Bus{

    string busDriver;
    string busArrival;
    string busDeparture;
    string bForm;
    string bTo;
    string busSeat[8][4];

    public:
    
    string busNumber;

    void addNewBus();
    void makeReservation(Bus busses[], int busIndex);
    void clearSeats();
    void viewBusDetails();
    void showAvailableBuses(Bus buses[]);
    void showSeatAvailability(int busIndex);
    void displayLine(char ch);
};
