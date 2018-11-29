#include <iostream>
#include <string>

using namespace std;

struct Aeroflot {
	string destination;
	string aircraft_type;
	unsigned short flight_number;
};

int main() {
	const short kFlightsNumber = 7;

	Aeroflot* flights = new Aeroflot[kFlightsNumber];
	string time_string = "";
	unsigned short time_number = 0;

	cout << "Enter the seven flights (destination of flight | flight number | aircraft type): "
			<< endl;

	for (short i = 0; i < kFlightsNumber; i++)
		cin >> flights[i].destination
			>> flights[i].flight_number
			>> flights[i].aircraft_type;

	for (short i = 0; i < kFlightsNumber; i++) {
		for (short j = 0; j < kFlightsNumber - 1; j++)
			if (flights[j].destination > flights[j + 1].destination) {
				time_string = flights[j].destination;
				flights[j].destination = flights[j + 1].destination;
				flights[j + 1].destination = time_string;

				time_string = flights[j].aircraft_type;
				flights[j].aircraft_type = flights[j + 1].aircraft_type;
				flights[j + 1].aircraft_type = time_string;

				time_number = flights[j].flight_number;
				flights[j].flight_number = flights[j + 1].flight_number;
				flights[j + 1].flight_number = time_number;
			}
	}

	cout << "\nEntered flights:\n";

	for (short i = 0; i < kFlightsNumber; i++)
		cout << flights[i].destination << " "
				<< flights[i].flight_number << " "
					<< flights[i].aircraft_type << ", ";

	while (true) {
		cout << "\n\nEnter the type of aircraft for getting list or 0 for exit: ";
		string entered_aircraft_type;
		cin >> entered_aircraft_type;

		if (entered_aircraft_type == "0")
			break;

		cout << "Such flights: " << endl;
		time_number = 0;

		for (short i = 0; i < kFlightsNumber; i++)
			if (flights[i].aircraft_type == entered_aircraft_type)
				cout << "Flight - " << flights[i].destination << " "
						<< flights[i].flight_number << endl;
			else
				time_number++;

		if (time_number == kFlightsNumber) {
			cout << "Such flights were not found";
		}
	}

	return 0;
}