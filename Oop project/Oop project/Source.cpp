#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Admin {
	//First 2 strings are used for login
	string UserName;
	string Password;
	//strings for destinations and Times
	string StartPoint;
	string Destination;
	string EndPoint;
	string Arrival_Time;
	string Departure_Time;

public:

	int login();
	void setSchedule(int);
	void setSeats(int i, int j, Admin seats[][]) {
		
		cout << "How many trains?" << endl;
		cin >> i;
		for (int t = 0;t < i;t++) {
			cout << "Enter number of seats for train " << i << endl;
			for (int k = 0; k < j; k++)
			{
				cin>>seats[i][j];
			}
		}
		for (int t = 0;t < i;t++) {
			cout << "Enter number of seats for train " << i << endl;
			for (int k = 0; k < j; k++)
			{
				cout<<seats[i*j]<<endl;
			}
		}
	}
};

void Admin::setSchedule(int a) {
	fstream Trains;
	Trains.open("Train Secdual.txt", ios::out);
	int b = 0;
	if (Trains.is_open()) {
		cout << "\nTime Formate: HH:MM am/pm\n" << endl;
		Trains << "-----------------Train " << 1 << " ---------------------------" << endl;
		cout << "\n-----------------Train " << 1 << " ---------------------------\n" << endl;
		cout << "\nStarting point : ";
		cin.ignore();
		getline(cin, StartPoint);
		cout << "Departure Time: ";
		cin.ignore();
		getline(cin, Departure_Time);
		cout << endl;
		Trains << "\nStarting point : " << StartPoint << endl;
		Trains << "Departure Time: " << Departure_Time << endl;

		cout << "Enter the Number of destinaions : ";
		cin >> b;
		cout << endl;
		for (int i = 0; i < b; i++) {
			cout << "Destinaion NO." << i + 1 << " : ";
			getline(cin, Destination);
			cout << "Arrival Time: ";
			cin.ignore();
			getline(cin, Arrival_Time);
			cout << "Departure Time: ";
			cin.ignore();
			getline(cin, Departure_Time);
			Trains << "\nDestinaion NO." << i + 1 << " : " << Destination << endl;
			Trains << "Arrival Time: " << Arrival_Time << endl;
			Trains << "Departure Time: " << Departure_Time << endl;
		}
		cout << "\nEndPoint : ";
		cin.ignore();
		getline(cin, EndPoint);
		cout << "Arrival Time: ";
		cin.ignore();
		getline(cin, Arrival_Time);
		cout << endl;
		Trains << "\nEndPoint : " << EndPoint << endl;
		Trains << "Arrival Time: " << Arrival_Time << endl;
		Trains.close();
	}

	for (int i = 1; i < a; i++) {
		Trains.open("Train Secdual.txt", ios::app);
		if (Trains.is_open()) {
			Trains << "\n-----------------Train " << i + 1 << " ---------------------------\n" << endl;
			cout << "\n-----------------Train " << i + 1 << " ---------------------------\n" << endl;
			cout << "\nStarting point : ";
			cin.ignore();
			getline(cin, StartPoint);
			cout << "Departure Time: ";
			cin.ignore();
			getline(cin, Departure_Time);
			cout << endl;
			Trains << "\nStarting point : " << StartPoint << endl;
			Trains << "Departure Time: " << Departure_Time << endl;

			cout << "Enter the Number of destinaions : ";
			cin >> b;
			for (int j = 0; j < b; j++) {
				cout << "\nDestinaion NO." << j + 1 << " : ";
				cin.ignore();
				getline(cin, Destination);
				cout << "Arrival Time: ";
				cin.ignore();
				getline(cin, Arrival_Time);
				cout << "Departure Time: ";
				cin.ignore();
				getline(cin, Departure_Time);
				Trains << "\nDestinaion NO." << j + 1 << " : " << Destination << endl;
				Trains << "Arrival Time: " << Arrival_Time << endl;
				Trains << "Departure Time: " << Departure_Time << endl;
			}
			cout << "\nEndPoint : ";
			cin.ignore();
			getline(cin, EndPoint);
			cout << "Arrival Time: ";
			cin.ignore();
			getline(cin, Arrival_Time);
			cout << endl;
			Trains << "\nEndPoint : " << EndPoint << endl;
			Trains << "Arrival Time: " << Arrival_Time << endl;

			Trains.close();

		}
	}

}

int main(){
	int choice;
	Admin Train;
	int i, j;
	Admin *seats = new Admin[i][j];
	do
	{
		cout << "Press 1 for Admin\nPress 2 for Custumor\nPress 3 to Quit" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				cout << "Press 1 to set Seats for the train" << endl;
				switch (choice)
				{
				case 1: {
					seats->setSeats(i, j, seats);


					Train.setSeats();
					break;
				}
				default:
					break;
				}

				break;
		}
			case 2:
			{

				break;
			}
			default:
			break;
		}

	} while (choice != 3);
}