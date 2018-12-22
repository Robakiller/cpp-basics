#include <iostream>
#include <string>

using namespace std;

struct Aeroflot {
    string destination;
    string aircraft_type;
    int flight_number;
};

bool IsNumber(string);
Aeroflot* InputFlights(short);
void SortFlights(Aeroflot*, short);
void PrintFlights(Aeroflot*, short);
void SearchAircraftType(Aeroflot*, short, string);

int main() {
    short num_flights = 7;
    Aeroflot* flights = InputFlights(num_flights);
    SortFlights(flights, num_flights);

    cout << "Flights sorted by destination:\n";
    PrintFlights(flights, num_flights);

    string aircraft_type;
    while (true) {
        cout << "\nEnter the type of aircraft to search (or 0 to exit): ";
        cin >> aircraft_type;
        if (aircraft_type == "0") break;
        SearchAircraftType(flights, num_flights, aircraft_type);
    }

    delete[] flights;
    return 0;
}

bool IsNumber(string number) {
    for (size_t i = 0; i < number.length(); i++)
        if (!isdigit(number[i]))
            return 0;
    return 1;
}

Aeroflot* InputFlights(short num_flights) {
    Aeroflot* flights = new Aeroflot[num_flights];
    string buf;
    for (short i = 0; i < num_flights; i++) {
        cout << "Flight #" << i + 1 << "\ndestination: ";
        getline(cin, flights[i].destination);

    repeat_flight_number:
        cout << "flight number: ";
        getline(cin, buf);
        if (!IsNumber(buf)) {
            cout << "Error: digits only!\n";
            goto repeat_flight_number;
        }
        flights[i].flight_number = stoi(buf);

        cout << "aircraft type: ";
        getline(cin, flights[i].aircraft_type);
        cout << endl;
    }

    return flights;
}

void SortFlights(Aeroflot* flights, short num_flights) {
    for (short i = 0; i < num_flights - 1; i++)
        for (short j = 0; j < num_flights - i - 1; j++)
            if (flights[j].destination > flights[j + 1].destination)
                swap(flights[j], flights[j + 1]);
}

void PrintFlights(Aeroflot* flights, short num_flights) {
    for (short i = 0; i < num_flights; i++) {
        cout << "\ndestination: " << flights[i].destination;
        cout << "\nflight number: " << flights[i].flight_number;
        cout << "\naircraft type: " << flights[i].aircraft_type << endl;
    }
}

void SearchAircraftType(Aeroflot* flights, short num_flights, string aircraft_type) {
    bool flight_found = false;

    for (short i = 0; i < num_flights; i++)
        if (flights[i].aircraft_type == aircraft_type) {
            flight_found = true;
            cout << "\ndestination: " << flights[i].destination;
            cout << "\nflight number: " << flights[i].flight_number;
            cout << endl;
        }

    if (!flight_found)
        cout << "Such flights were not found.\n";
}