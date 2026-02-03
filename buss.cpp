#include "buss.h"

void Bus::addNewBus(){
    cout << "Enter Bus Number: ";
    cin>>busNumber;

    cout << "Enter Driver's name: ";
    cin>> busDriver;

    cout << "Arrival Time: ";
    cin>>busArrival;

    cout << "Departure Time: ";
    cin>>busDeparture;

    cout << "From: ";
    cin>>bForm;

    cout << "To: ";
    cin>>bTo;
    
    clearSeats();
    cout << "New bus added successfully. ";
}

void Bus::makeReservation(Bus buses[], int busIndex){
    showSeatAvailability(busIndex);

    cout << "Enter seat number for reservation: "<<endl;
    int seatNumber;
    cin>> seatNumber;

    if(seatNumber<1 || seatNumber > 32){
        cout << "Invalid seat number" <<endl;
        cout << "Please enter a number between 1 and 32" <<endl;
        return;
    }
    int row=(seatNumber-1)/4;
    int col=(seatNumber-1)%4;

    if(buses[busIndex].busSeat[row][col]=="Empty"){
        cout << "Enter passenger's name: ";
        cin>>buses[busIndex].busSeat[row][col];
        cout << "Reservation successful! " <<endl;
    }
    else{
        cout << "Oops! Seat is already reserved :( " << endl;
    }
}
void Bus::clearSeats(){
    for(int i=0;i<8;i++){
        for(int j=0;j<4;j++){
            busSeat[i][j]="Empty";
        }
    }
}
void Bus::viewBusDetails(){
    displayLine('*');
    cout << "Bus number: " << busNumber <<endl;
    cout << "Driver: " << busDriver<<endl;
    cout << "Arrival Time: " <<busArrival<<endl;
    cout << "Departure Time: " << busDeparture<<endl;
    cout << "From: " << bForm<<endl;
    cout << "To: " <<bTo<<endl;
    displayLine('*');

    showSeatAvailability(0);
}
void Bus::showAvailableBuses(Bus buses[]){
    displayLine('*');
    cout<<"Available buses: " ;
    for(int i=0;i<5;i++){
        if(!buses[i].busNumber.empty()){
            cout << "Bus number: " << buses[i].busNumber << "\tDriver" << buses[i].busDriver << "\tFrom: " <<buses[i].bForm<< "\tTo: " << buses[i].bTo<<endl;
        }
    } 
    displayLine('*');
}

void Bus::showSeatAvailability(int busIndex){
    cout << "Seat availability: " << endl;
    int seatNumber=1;
    for(int i=0;i<8;i++){
        for(int j=0;j<4;j++){
            cout << setw(5) << left << seatNumber << ".";
            cout << setw(10)<<left<<busSeat[i][j];
            seatNumber++;
        }
        cout << endl;
    } 
    cout << "There are " << (32-seatNumber+1)<<" seats available in Bus Number: " << busNumber <<endl;
}

void Bus::displayLine(char ch){
    for(int i=80;i>0;i--){
        cout << ch;
    }
    cout << endl;
}