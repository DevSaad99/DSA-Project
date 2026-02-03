#include "buss.h"
#include <limits> 

int main() {
    const int maxBuses = 5;
    Bus buses[maxBuses];
    int choice;

    while (true) {
        cout << "\nSIMPLE BUS RESERVATION SYSTEM\n";
        cout << "1. Add new bus\n";
        cout << "2. Make reservation\n";
        cout << "3. View reservation\n";
        cout << "4. Show available buses\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number." << endl;
            continue;
        }

        switch (choice) {
            case 1: {
                int busIndex;
                cout << "Enter Bus Index (0 - " << maxBuses - 1 << "): ";
                cin >> busIndex;

                if (cin.fail() || busIndex < 0 || busIndex >= maxBuses) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid bus index. Try again." << endl;
                    continue;
                }

                buses[busIndex].addNewBus();
                break;
            }
            case 2: {
                int busIndex;
                cout << "Enter Bus Index (0 - " << maxBuses - 1 << "): ";
                cin >> busIndex;

                if (cin.fail() || busIndex < 0 || busIndex >= maxBuses) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid bus index. Try again." << endl;
                    continue;
                }

                buses[busIndex].makeReservation(buses, busIndex);
                break;
            }
            case 3: {
                int busIndex;
                cout << "Enter Bus Index (0 - " << maxBuses - 1 << "): ";
                cin >> busIndex;

                if (cin.fail() || busIndex < 0 || busIndex >= maxBuses) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid bus index. Try again." << endl;
                    continue;
                }

                buses[busIndex].viewBusDetails();
                break;
            }
            case 4:
                for (int i = 0; i < maxBuses; ++i) {
                    if (!buses[i].busNumber.empty()) {
                        buses[i].viewBusDetails();
                    }
                }
                break;
            case 5:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
