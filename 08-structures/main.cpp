#include <iostream>
#include <string>

using namespace std;

struct AEROFLOT
{
	string vsDestination;
	string vsAircraftType;
	unsigned short vusiFlightNumber;
};

int main()
{
	AEROFLOT * pascFlights = new AEROFLOT[7];
	string TimeString = "";
	unsigned short TimeNumber = 0;

	cout << "Enter the destination of flight, flight number and aircraft type: "
			<< endl;

	for (short i = 0; i < 7; i++)
		cin >> pascFlights[i].vsDestination
			>> pascFlights[i].vusiFlightNumber 
			>> pascFlights[i].vsAircraftType;

	for (short i = 0; i < 7; i++)
	{
		for (short j = 0; j < 6; j++)
			if (pascFlights[j].vsDestination > pascFlights[j + 1].vsDestination)
			{
				TimeString = pascFlights[j].vsDestination;
				pascFlights[j].vsDestination = pascFlights[j + 1].vsDestination;
				pascFlights[j + 1].vsDestination = TimeString;

				TimeString = pascFlights[j].vsAircraftType;
				pascFlights[j].vsAircraftType = pascFlights[j + 1].vsAircraftType;
				pascFlights[j + 1].vsAircraftType = TimeString;

				TimeNumber = pascFlights[j].vusiFlightNumber;
				pascFlights[j].vusiFlightNumber = pascFlights[j + 1].vusiFlightNumber;
				pascFlights[j + 1].vusiFlightNumber = TimeNumber;
			}
	}

	cout << "\nEntered flights:\n";

	for (short i = 0; i < 7; i++)
		cout << pascFlights[i].vsDestination << " "
				<< pascFlights[i].vusiFlightNumber << ", ";

	while (true)
	{
		cout << "\nEnter the type of aircraft for getting list or 0 for exit: ";
		string vsEnteredAircraftType;
		cin >> vsEnteredAircraftType;

		if (vsEnteredAircraftType == "0")
			break;

		cout << "Such flights: " << endl;
		TimeNumber = 0;

		for (short i = 0; i < 7; i++)
			if (pascFlights[i].vsAircraftType == vsEnteredAircraftType)
				cout << "Flight - " << pascFlights[i].vsDestination << " "
						<< pascFlights[i].vusiFlightNumber << endl;
			else
				TimeNumber++;

		if (TimeNumber == 7)
		{
			cout << "Such flights were not found";
		}
	}

	return 0;
}