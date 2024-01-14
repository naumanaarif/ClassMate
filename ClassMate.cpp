// Object-Oriented Programming (Theory)
// Final Project

// ClassMate - Timetable Management Software

// Developed by
// 1. Muhammad Nauman Arif (2514-2022)
// 1. Ismail Dad Khan (2927-2022)

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int TOTAL_WORKING_DAYS = 4;
const int TOTAL_SLOTS = 8;
map<int, string> DAYS = {
	{0, "Monday"},
	{1, "Tuesday"},
	{2, "Wednesday"},
	{3, "Thursday"},
	{4, "Friday"},
};

class Slot {
public:
	int slotId;
	string time;
	string instructor;
	string courseTitle;
	string room;

	// Constructor
	Slot(int s, string t, string i, string c, string r) :
		slotId(s), time(t), instructor(i), courseTitle(c), room(r) { }

	void print() const {
		cout << "| " << slotId << " | " << time << " | ";
		cout << setw(8) << left << courseTitle << " | ";
		cout << setw(12) << left << instructor << " | ";
		cout << setw(4) << room << " |" << endl;
	}
};

class Timetable {
public:
	string className;
	map<string, vector<Slot>> days;

	// Constructor
	Timetable() {}
	Timetable(string c, map<string, vector<Slot>> t) : className(c), days(t) {}

	bool isSlotAvailable(string day, int slot) {
		if (days[day][slot - 1].courseTitle == "") {
			return true;
		}
		return false;
	}

	bool isRoomAvailable(string day, int slot, string room) {
		if (days[day][slot - 1].room == room) {
			return false;
		}
		return true;
	}

	bool isInstructorAvailable(string day, int slot, string instructor) {
		if (days[day][slot - 1].instructor == instructor) {
			return false;
		}
		return true;
	}

	bool canArrangeExtraClass(string day, int slot, string instructor, string room) {
		if (this->isSlotAvailable(day, slot) &&
			this->isInstructorAvailable(day, slot, instructor) &&
			this->isRoomAvailable(day, slot, room))
		{
			return true;
		}
		return false;
	}

	void display() {
		cout << "+----------------------------------------------------+\n";
		cout << "|                  " << className << " TIMETABLE                 |\n";
		cout << "+----------------------------------------------------+\n\n";

		for (int i = 0; i < DAYS.size(); i++)
		{
			string day = DAYS[i];
			cout << day << endl;

			cout << "+---+---------------+----------+--------------+------+\n";
			cout << "| # |    Timing     |  Course  |  Instructor  | Room |\n";
			cout << "+---+---------------+----------+--------------+------+\n";

			for (int slot = 0; slot < TOTAL_SLOTS; slot++)
			{
				days[day][slot].print();
			}

			cout << "+---+---------------+----------+--------------+------+\n\n";
		}
	}
};

map<string, vector<Slot>> TIMETABLE_BSCS_3B =
{
	{
		"Monday",
		{
			Slot(1, "08:25 - 09:20", "M. Uzair", "OOP-L", "CL-2"),
			Slot(2, "09:20 - 10:15", "M. Uzair", "OOP-L", "CL-2"),
			Slot(3, "10:15 - 11:10", "M. Uzair", "OOP-L", "CL-2"),
			Slot(4, "11:10 - 12:05", "", "", ""),
			Slot(5, "12:05 - 13:00", "Mr. Jibran", "OOP", "R"),
			Slot(6, "13:15 - 14:10", "Mr. Jibran", "OOP", "K"),
			Slot(7, "14:10 - 15:05", "", "", ""),
			Slot(8, "15:05 - 16:00", "", "", "")
		}
	},
	{
		"Tuesday",
		{
			Slot(1, "08:25 - 09:20", "Arisha.E", "LA", "V"),
			Slot(2, "09:20 - 10:15", "Arisha.E", "LA", "V"),
			Slot(3, "10:15 - 11:10", "Sumaira.MQ", "DLD", "S"),
			Slot(4, "11:10 - 12:05", "Sumaira.MQ", "DLD", "S"),
			Slot(5, "12:05 - 13:00", "", "", ""),
			Slot(6, "13:15 - 14:10", "M.Waqar", "DCCN-L", "AI-L"),
			Slot(7, "14:10 - 15:05", "M.Waqar", "DCCN-L", "AI-L"),
			Slot(8, "15:05 - 16:00", "M.Waqar", "DCCN-L", "AI-L")
		}
	},
	{
		"Wednesday",
		{
			Slot(1, "08:25 - 09:20", "", "", ""),
			Slot(2, "09:20 - 10:15", "Mr. Jibran", "OOP", "F"),
			Slot(3, "10:15 - 11:10", "", "", ""),
			Slot(4, "11:10 - 12:05", "Sadia.A", "PnS", "S"),
			Slot(5, "12:05 - 13:00", "Sadia.A", "PnS", "S"),
			Slot(6, "13:15 - 14:10", "M.Waqar", "DCCN", "G"),
			Slot(7, "14:10 - 15:05", "M.Waqar", "DCCN", "G"),
			Slot(8, "15:05 - 16:00", "", "", "")
		}
	},
	{
		"Thursday",
		{
			Slot(1, "08:25 - 09:20", "Maria.B", "DLD-L", "BE-L"),
			Slot(2, "09:20 - 10:15", "Maria.B", "DLD-L", "BE-L"),
			Slot(3, "10:15 - 11:10", "Maria.B", "DLD-L", "BE-L"),
			Slot(4, "11:10 - 12:05", "", "", ""),
			Slot(5, "12:05 - 13:00", "Arisha.E", "LA", "C"),
			Slot(6, "13:15 - 14:10", "M.Waqar", "DCCN", "C"),
			Slot(7, "14:10 - 15:05", "Sumaira.MQ", "DLD", "E"),
			Slot(8, "15:05 - 16:00", "Sadia.A", "PnS", "M"),
		}
	},
	{
		"Friday",
		{
			Slot(1, "08:25 - 09:20", "", "", ""),
			Slot(2, "09:20 - 10:15", "", "", ""),
			Slot(3, "10:15 - 11:10", "", "", ""),
			Slot(4, "11:10 - 12:05", "", "", ""),
			Slot(5, "12:05 - 13:00", "", "", ""),
			Slot(6, "13:15 - 14:10", "", "", ""),
			Slot(7, "14:10 - 15:05", "", "", ""),
			Slot(8, "15:05 - 16:00", "", "", "")
		}
	}
};

void displayHomepage() {
	cout << """\
+----------------------------------------------------+\n\
|     ClassMate - Timetable Management Software      |\n\
+----------------------------------------------------+\n\
| Developed by:                                      |\n\
| 1. Muhammad Nauman Arif (2514-2022)                |\n\
| 2. Ismail Dad Khan (2927-2022)                     |\n\
+----------------------------------------------------+\n\n""";

	cout << """\
+----------------------------------------------------+\n\
|         Which feature do you want to use?          |\n\
+----------------------------------------------------+\n\
| 1: Slot Availability Check                         |\n\
| 2: Room Availability Check                         |\n\
| 3: Instructor Availability Check                   |\n\
| 4: Arrange Extra Class                             |\n\
| 5: Display Timetable                               |\n\
+----------------------------------------------------+\n\n""";
}

void slotAvailabilityCheck(Timetable timetable) {
	cout << """\
+----------------------------------------------------+\n\
|              Slot Availability Checker             |\n\
+----------------------------------------------------+\n\n""";
	
	string day;
	int slot;

	cout << " Please enter the required information" << endl;
	cout << " Day: ";
	cin >> day;
	cout << " Slot: ";
	cin >> slot;
	cout << endl;

	if (timetable.isSlotAvailable(day, slot)) {
		cout << " AVAILABLE!" << endl<< endl;
	}
	else
	{
		cout << " NOT AVAILABLE!" << endl << endl;
	}
}

void roomAvailabilityCheck(Timetable timetable) {
	cout << """\
+----------------------------------------------------+\n\
|              Room Availability Checker             |\n\
+----------------------------------------------------+\n\n""";

	string day, room;
	int slot;

	cout << " Please enter the required information" << endl;
	
	cout << " Day: ";
	cin >> day;
	
	cout << " Slot: ";
	cin >> slot;

	cout << " Room: ";
	cin >> room;
	cout << endl;

	if (timetable.isRoomAvailable(day, slot, room)) {
		cout << " AVAILABLE!" << endl << endl;
	}
	else
	{
		cout << " NOT AVAILABLE!" << endl << endl;
	}
}

void instructorAvailabilityCheck(Timetable timetable) {
	cout << """\
+----------------------------------------------------+\n\
|          Instructor Availability Checker           |\n\
+----------------------------------------------------+\n\n""";

	string day, instructor;
	int slot;

	cout << " Please enter the required information" << endl;

	cout << " Day: ";
	cin >> day;

	cout << " Slot: ";
	cin >> slot;

	cout << " Instructor: ";
	cin >> instructor;
	cout << endl;

	if (timetable.isInstructorAvailable(day, slot, instructor)) {
		cout << " AVAILABLE!" << endl << endl;
	}
	else
	{
		cout << " NOT AVAILABLE!" << endl << endl;
	}
}

void classAdjustmentTool(Timetable timetable) {
	cout << """\
+----------------------------------------------------+\n\
|                Class Adjustment Tool               |\n\
+----------------------------------------------------+\n\n""";

	string day, instructor, room;
	int slot;

	cout << " Please enter the required information" << endl;

	cout << " Day: ";
	cin >> day;

	cout << " Slot: ";
	cin >> slot;

	cout << " Instructor: ";
	cin >> instructor;

	cout << " Room: ";
	cin >> room;

	cout << endl;

	if (timetable.canArrangeExtraClass(day, slot, instructor, room)) {
		cout << " YES! Extra class can be arranged in Slot #" << slot << " at Room " << room << endl << endl;
	}
	else
	{
		cout << " NOT POSSIBLE!" << endl << endl;
	}
}

void displayNavigation() {
	cout << """\n\
+----------------------------------------------------+\n\
| Press 'B' to go back to the main menu              |\n\
| Press 'X' to exit the program                      |\n\
+----------------------------------------------------+\n\n""";
}

void displayEndScreen() {
	cout << """\
+----------------------------------------------------+\n\
|          Thank you for using ClassMate!            |\n\
+----------------------------------------------------+\n\n""";
}

int main() {
	Timetable timetable("BSCS-3B", TIMETABLE_BSCS_3B);

	do {
		displayHomepage();

		int choice;
		cout << " Select an option: ";
		cin >> choice;

		system("CLS");

		switch (choice) {
		case 1:
			slotAvailabilityCheck(timetable);
			displayNavigation();
			break;
		case 2:
			roomAvailabilityCheck(timetable);
			displayNavigation();
			break;
		case 3:
			instructorAvailabilityCheck(timetable);
			displayNavigation();
			break;
		case 4:
			classAdjustmentTool(timetable);
			displayNavigation();
			break;
		case 5:
			timetable.display();
			displayNavigation();
			break;
		default:
			cout << "Invalid option";
			break;
		}

		char navigationOption;
		cout << " Choose a navigation option: ";
		cin >> navigationOption;

		if (toupper(navigationOption) == 'X') {
			system("CLS");
			displayEndScreen();
			break;  // Exit the program
		}

		system("CLS");

	} while (true);

	return 0;
}
