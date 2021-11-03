#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <sstream>
using namespace std;

int user = 0;
int total = 1;
time_t timeArrived;
unsigned int size = 26;
char str[80];
bool valid;

struct Patient {
	string id;
	string firstname;
	string lastname;
	int age;
	string gender;
	string contact;
	string address;
	Patient* next;
	Patient* previous;
} *patientHead, * patientTail, * patientCurrent, * patientNewNode, * patientSortHead, * patientTempCurrent;

struct Waiting {
	int order;
	Patient* patient;
	string doctor;
	time_t timeArrived;
	string sickness;
	bool disability;
	string medicine;
	string sortItem;
	Waiting* next;
} *waitingHead, * waitingCurrent, * waitingNewNode, * waitingSortHead, * waitingTempCurrent;

struct History {
	string id;
	Patient* patient;
	string doctor;
	time_t timeVisited;
	string sickness;
	bool disability;
	string medicine;
	string sortItem;
	History* next;
	History* previous;
} *historyHead, * historyTail, * historyCurrent, * historyNewNode, * historySortHead, * historyTempCurrent;

void addtoPatient()
{
	if (patientHead == NULL)
	{
		patientHead = patientTail = patientNewNode;
	}
	else
	{
		patientNewNode->previous = patientTail;
		patientTail->next = patientNewNode;
		patientTail = patientNewNode;
		patientCurrent = patientHead;
	}

	cout << "Patient registered!" << endl;

	cout << "ID\t\t\t: " << patientNewNode->id << endl;
	cout << "Firstname\t\t: " << patientNewNode->firstname << endl;
	cout << "Lastname\t\t: " << patientNewNode->lastname << endl;
	cout << "Age\t\t\t: " << patientNewNode->age << endl;
	cout << "Gender\t\t\t: " << patientNewNode->gender << endl;
	cout << "Contact\t\t\t: " << patientNewNode->contact << endl;
	cout << "Address\t\t\t: " << patientNewNode->address << endl;
	cout << endl << endl;

	//id generation
	total++;
}

void addtoHistory() {
	if (historyHead == NULL)
	{
		historyHead = historyTail = historyNewNode;
	}
	else
	{
		historyCurrent = historyHead;
		historyTail->next = historyNewNode;
		historyNewNode->previous = historyTail;
		historyTail = historyNewNode;
	}

	cout << "Patient added to History List!" << endl;
}

void addtoWaiting()
{
	if (waitingHead == NULL)
	{
		waitingHead = waitingNewNode;
	}
	else
	{
		waitingCurrent = waitingHead;
		while (waitingCurrent->next != NULL)
		{
			waitingCurrent = waitingCurrent->next;
		}
		waitingCurrent->next = waitingNewNode;
	}

	cout << "Patient added to Waiting List!" << endl;
}

//void matchtoPatient(string PatientID) {
//	if (patientHead->id != PatientID) {
//		patientCurrent = patientHead;
//		while (patientCurrent != NULL) {
//			if (patientCurrent->id == PatientID) {
//				waitingNewNode->patient = patientCurrent;
//				return;
//			}
//			patientCurrent = patientCurrent->next;
//		}
//	}
//	else {
//		waitingNewNode->patient = patientHead;
//	}
//}

void HardCode() {
	//Hard Code of Patient Record
	patientHead = patientCurrent = NULL;

	patientNewNode = new Patient;
	patientNewNode->id = "P0001";
	patientNewNode->firstname = "Vivian";
	patientNewNode->lastname = "Fong";
	patientNewNode->age = 24;
	patientNewNode->gender = "F";
	patientNewNode->contact = "0123456789";
	patientNewNode->address = "4, Jalan Bunga, Taman Bunga, 48793 Malaysia";
	patientNewNode->next = NULL;
	patientNewNode->previous = NULL;
	addtoPatient();

	patientNewNode = new Patient;
	patientNewNode->id = "P0002";
	patientNewNode->firstname = "James";
	patientNewNode->lastname = "Pang";
	patientNewNode->age = 34;
	patientNewNode->gender = "M";
	patientNewNode->contact = "0123464789";
	patientNewNode->address = "54, Jalan Bunga, Taman Bunga, 48793 Malaysia";
	patientNewNode->next = NULL;
	patientNewNode->previous = NULL;
	addtoPatient();

	patientNewNode = new Patient;
	patientNewNode->id = "P0003";
	patientNewNode->firstname = "Isabella";
	patientNewNode->lastname = "Ng";
	patientNewNode->age = 65;
	patientNewNode->gender = "F";
	patientNewNode->contact = "0123376789";
	patientNewNode->address = "24, Jalan Bunga, Taman Bunga, 48793 Malaysia";
	patientNewNode->next = NULL;
	patientNewNode->previous = NULL;
	addtoPatient();

	patientNewNode = new Patient;
	patientNewNode->id = "P0004";
	patientNewNode->firstname = "Charlotte";
	patientNewNode->lastname = "Ng";
	patientNewNode->age = 14;
	patientNewNode->gender = "F";
	patientNewNode->contact = "0123153789";
	patientNewNode->address = "16, Jalan Bunga, Taman Bunga, 48793 Malaysia";
	patientNewNode->next = NULL;
	patientNewNode->previous = NULL;
	addtoPatient();

	patientNewNode = new Patient;
	patientNewNode->id = "P0005";
	patientNewNode->firstname = "Emily";
	patientNewNode->lastname = "Kong";
	patientNewNode->age = 63;
	patientNewNode->gender = "F";
	patientNewNode->contact = "012373290";
	patientNewNode->address = "54, Jalan Lily, Taman Bunga, 48793 Malaysia";
	patientNewNode->next = NULL;
	patientNewNode->previous = NULL;
	addtoPatient();

	patientNewNode = new Patient;
	patientNewNode->id = "P0006";
	patientNewNode->firstname = "Ahmad";
	patientNewNode->lastname = "Abdullah";
	patientNewNode->age = 38;
	patientNewNode->gender = "M";
	patientNewNode->contact = "0123456789";
	patientNewNode->address = "4, Jalan Bunga, Taman Bunga, 48793 Malaysia";
	patientNewNode->next = NULL;
	patientNewNode->previous = NULL;
	addtoPatient();

	patientNewNode = new Patient;
	patientNewNode->id = "P0007";
	patientNewNode->firstname = "Boey";
	patientNewNode->lastname = "Choo";
	patientNewNode->age = 72;
	patientNewNode->gender = "M";
	patientNewNode->contact = "0195678923";
	patientNewNode->address = "2-4-1, Jalil Condo, Taman Bangsa, 48329 Malaysia";
	patientNewNode->next = NULL;
	patientNewNode->previous = NULL;
	addtoPatient();

	patientNewNode = new Patient;
	patientNewNode->id = "P0008";
	patientNewNode->firstname = "Muthu";
	patientNewNode->lastname = "Sivanathan";
	patientNewNode->age = 29;
	patientNewNode->gender = "M";
	patientNewNode->contact = "0167834988";
	patientNewNode->address = "N-7-5, Damai Apartments, Taman Bangsa, 48340 Malaysia";
	patientNewNode->next = NULL;
	patientNewNode->previous = NULL;
	addtoPatient();

	patientNewNode = new Patient;
	patientNewNode->id = "P0009";
	patientNewNode->firstname = "Jaemin";
	patientNewNode->lastname = "Kim";
	patientNewNode->age = 20;
	patientNewNode->gender = "M";
	patientNewNode->contact = "0154793216";
	patientNewNode->address = "54, Jalan Oversea, Taman Endah, 53700 Malaysia";
	patientNewNode->next = NULL;
	patientNewNode->previous = NULL;
	addtoPatient();

	patientNewNode = new Patient;
	patientNewNode->id = "P0010";
	patientNewNode->firstname = "Jenny";
	patientNewNode->lastname = "Lee";
	patientNewNode->age = 28;
	patientNewNode->gender = "F";
	patientNewNode->contact = "0123456789";
	patientNewNode->address = "24, Jalan Jalil, Taman Puncak, 49450 Malaysia";
	patientNewNode->next = NULL;
	patientNewNode->previous = NULL;
	addtoPatient();

	//Hard Code of History List Record
	historyHead = historyCurrent = NULL;
	historyNewNode = new History;
	historyNewNode->id = "P0001";
	historyNewNode->patient;
	historyNewNode->doctor = "Dr. Tan";
	historyNewNode->timeVisited = 1620021717;
	historyNewNode->sickness = "Vomit";
	historyNewNode->disability = false;
	historyNewNode->medicine = "Kaopectate";
	historyNewNode->sortItem = "";
	historyNewNode->next = NULL;
	//matchtoPatient("P0001");
	addtoHistory();

	historyNewNode = new History;
	historyNewNode->id = "P0002";
	historyNewNode->patient;
	historyNewNode->doctor = "Dr. Wong";
	historyNewNode->timeVisited = 1620022347;
	historyNewNode->sickness = "Head Pain";
	historyNewNode->disability = false;
	historyNewNode->medicine = "Kaopectate";
	historyNewNode->sortItem = "";
	historyNewNode->next = NULL;
	//matchtoPatient("P0002");
	addtoHistory();

	historyNewNode = new History;
	historyNewNode->id = "P0003";
	historyNewNode->patient;
	historyNewNode->doctor = "Dr. Tan";
	historyNewNode->timeVisited = 1620026537;
	historyNewNode->sickness = "Stomach Pain";
	historyNewNode->disability = false;
	historyNewNode->medicine = "3";
	historyNewNode->sortItem = "";
	historyNewNode->next = NULL;
	//matchtoPatient("P0003");
	addtoHistory();

	historyNewNode = new History;
	historyNewNode->id = "P0004";
	historyNewNode->patient;
	historyNewNode->doctor = "Dr. Wong";
	historyNewNode->timeVisited = 1620027527;
	historyNewNode->sickness = "Cough";
	historyNewNode->disability = false;
	historyNewNode->medicine = "4";
	historyNewNode->sortItem = "";
	historyNewNode->next = NULL;
	//matchtoPatient("P0004");
	addtoHistory();

	historyNewNode = new History;
	historyNewNode->id = "P0002";
	historyNewNode->patient;
	historyNewNode->doctor = "Dr. Tan";
	historyNewNode->timeVisited = 1620108117;
	historyNewNode->sickness = "Vomit";
	historyNewNode->disability = false;
	historyNewNode->medicine = "5";
	historyNewNode->sortItem = "";
	historyNewNode->next = NULL;
	//matchtoPatient("P0002");
	addtoHistory();
}

void validate(string input) {
	while (!::all_of(begin(input), end(input), std::isalpha))
	{
		cout << "Invalid input! Enter input again : ";
		getline(cin, input);
		::all_of(begin(input), end(input), std::isalpha);
	}
}

void InsertintoWaitingList()
{
	system("cls");
	bool add = 1;
	int order;
	string id;
	string firstname;
	string lastname;
	int age;
	char gender;
	string contact;
	string address;
	string sickness;
	bool disability;
	char validGender[2] = { 'F', 'M' };

	cout << "1 - Register New Patient \n 0- Choose Existing Patient" << endl;
	cout << "Enter option ('1' or '0') : ";
	cin >> add;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid input! Enter option again : ";
		cin >> add;
	}
	cin.ignore();

	if (add)
	{
		::stringstream oss;
		oss << ::setw(4) << ::setfill('0') << total;
		::string s = oss.str();
		id = "P" + s;
		cout << "ID : " << id << endl;
		cout << "First Name : ";
		getline(cin, firstname);
		validate(firstname);
		cout << "Last Name : ";
		getline(cin, lastname);
		validate(lastname);
		cout << "Age : ";
		cin >> age;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid input! Enter age again : ";
			cin >> age;
		}
		cin.ignore();
		cout << "Gender ('F' / 'M') : ";
		cin >> gender;
		valid = ::find(::begin(validGender), ::end(validGender), gender) != ::end(validGender);
		while (!valid)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid input! Enter gender again : ";
			cin >> gender;
			cin.ignore();
			valid = ::find(::begin(validGender), ::end(validGender), gender) != ::end(validGender);
		}
		cin.ignore();
		cout << "Contact : ";
		getline(cin, contact);
		while (!::all_of(begin(contact), end(contact), std::isdigit))
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid input! Enter input again : ";
			getline(cin, contact);
			cin.ignore();
			::all_of(begin(contact), end(contact), std::isdigit);
		}
		cout << contact;
		cout << "Address : ";
		getline(cin, address);
		cout << "Time : ";
		timeArrived = time(0);
		ctime_s(str, ::size, &timeArrived);
		cout << str;
		cout << "Sickness : ";
		getline(cin, sickness);
		validate(sickness);
		cout << "Disability ('1' - Yes / '0' - No) : ";
		cin >> disability;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid input! Enter disability again ('1' - Yes / '0' - No) : ";
			cin >> disability;
		}
		cin.ignore();

		//creating new patient node
		patientNewNode = new Patient;
		patientNewNode->id = id;
		patientNewNode->firstname = firstname;
		patientNewNode->lastname = lastname;
		patientNewNode->age = age;
		patientNewNode->gender = gender;
		patientNewNode->contact = contact;
		patientNewNode->address = address;
		patientNewNode->previous = NULL;
		patientNewNode->next = NULL;
		addtoPatient();

		//creating new waiting node
		waitingNewNode = new Waiting;
		waitingNewNode->order = total;
		waitingNewNode->patient = patientNewNode;
		waitingNewNode->doctor = "";
		waitingNewNode->timeArrived = timeArrived;
		waitingNewNode->sickness = sickness;
		waitingNewNode->disability = disability;
		waitingNewNode->medicine = "";
		waitingNewNode->sortItem = "";
		waitingNewNode->next = NULL;
		addtoWaiting();

	}
	else
	{
		patientCurrent = patientHead;
		int select = 1;
		while (select != 0)
		{
			system("cls");
			cout << "Patient List : " << endl;
			cout << "ID\t\t\t: " << patientCurrent->id << endl;
			cout << "Firstname\t\t: " << patientCurrent->firstname << endl;
			cout << "Lastname\t\t: " << patientCurrent->lastname << endl;
			cout << "Age\t\t\t: " << patientCurrent->age << endl;
			cout << "Gender\t\t\t: " << patientCurrent->gender << endl;
			cout << "Contact\t\t\t: " << patientCurrent->contact << endl;
			cout << "Address\t\t\t: " << patientCurrent->address << endl;
			cout << endl << endl;
			cout << "1. Next Patient\t 2. Previous Patient \t 0. Select Patient" << endl;

			cout << "Enter selection : ";
			cin >> select;
			cin.ignore();

			if (select == 1 && patientCurrent->next != NULL)
			{
				patientCurrent = patientCurrent->next;
			}
			else if (select == 2 && patientCurrent->previous != NULL)
			{
				patientCurrent = patientCurrent->previous;
			}
			else if (select == 0)
			{
				cout << "Time : ";
				timeArrived = time(0);
				ctime_s(str, ::size, &timeArrived);
				cout << str;
				cout << "Sickness : ";
				getline(cin, sickness);
				validate(sickness);
				cout << "Disability ('1' - Yes / '0' - No) : ";
				cin >> disability;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Invalid input! Enter disability again ('1' - Yes / '0' - No) : ";
					cin >> disability;
				}
				cin.ignore();

				waitingNewNode = new Waiting;
				waitingNewNode->order = total;
				waitingNewNode->patient = patientCurrent;
				waitingNewNode->doctor = "";
				waitingNewNode->timeArrived = timeArrived;
				waitingNewNode->sickness = sickness;
				waitingNewNode->disability = disability;
				waitingNewNode->medicine = "";
				waitingNewNode->sortItem = "";
				waitingNewNode->next = NULL;
				cout << waitingNewNode->sickness;
				addtoWaiting();
			}
			else if (select != 1 && select != 2 && select != 0)
			{
				cout << "Invalid option!" << endl;
				system("pause");
			}
			else if (select == 2 && patientCurrent->previous == NULL)
			{
				cout << "This is the first patient in the list!" << endl;
			}
			else
			{
				cout << "This is the last patient in the list!" << endl;
				system("pause");
			}
		}
	}

	system("pause");
	system("cls");
}

void InsertintoPatientList()
{
	string doctor;
	string medicine;

	system("cls");
	cout << "Enter doctor name : ";
	getline(cin, doctor);
	validate(doctor);
	cout << "Enter medicine name : ";
	getline(cin, medicine);
	timeArrived = time(0);

	historyNewNode = new History;
	historyNewNode->id = waitingHead->patient->id;
	historyNewNode->patient = waitingHead->patient;
	historyNewNode->doctor = doctor;
	historyNewNode->timeVisited = timeArrived;
	historyNewNode->sickness = waitingHead->sickness;
	historyNewNode->disability = waitingHead->disability;
	historyNewNode->medicine = medicine;
	historyNewNode->sortItem = waitingHead->sortItem;
	historyNewNode->next = NULL;
	historyNewNode->previous = NULL;

	//history linked list
	if (historyHead == NULL)
	{
		historyHead = historyTail = historyNewNode;
	}
	else
	{
		historyTail->next = historyNewNode;
		historyNewNode->previous = historyTail;
		historyTail = historyNewNode;
	}

	//removing waiting list head
	waitingCurrent = waitingHead;
	waitingHead = waitingHead->next;
	delete waitingCurrent;

	cout << "Patient history updated!" << endl;
	system("pause");
}

void login(int decision)
{
	string username = "";
	string password = "";

	if (decision == 0)
	{
		cout << "Welcome !" << endl;
		cout << "Enter username : ";
		getline(cin, username);
		cout << "Enter password : ";
		getline(cin, password);

		if (username == "nurse" && password == "nurse123")
		{
			cout << "You are logged in as nurse." << endl;
			user = 1;
		}
		else if (username == "doctor" && password == "doctor123")
		{
			cout << "You are logged in as doctor." << endl;
			user = 2;
		}
		else
		{
			cout << "Invalid login details. Exiting system....." << endl;
		}
	}
	else
	{
		username = "";
		password = "";
		user = 0;
		cout << "You are logged out. Exiting system.....";
	}
}

void MainPage(int user)
{
	int choice = 1;
	system("cls");
	int nurseChoices[7] = { 1, 2, 3, 4, 5, 6, 0 };
	int doctorChoices[5] = { 1, 2, 3, 4, 0 };

	while (choice != 0)
	{
		if (user == 1)
		{
			cout << "Currently logged in as : Nurse " << endl;
			cout << "1. Add new patient to waiting list" << endl;
			cout << "2. Change patient order in waiting list according to priority" << endl;
			cout << "3. View all patients on original waiting list" << endl;
			cout << "4. Call patient to be treated" << endl;
			cout << "5. Search for patient on waiting list based on Patient ID or First Name" << endl;
			cout << "6. View waiting list in ascending order of visit time" << endl;
			cout << "0. Logout" << endl;
			cout << "Enter option (0-6) : ";
			cin >> choice;
			cin.ignore();

			valid = ::find(::begin(nurseChoices), ::end(nurseChoices), choice) != ::end(nurseChoices);

			while (!valid)
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Enter option (0-6) : ";
				cin >> choice;
				cin.ignore();
				valid = ::find(::begin(nurseChoices), ::end(nurseChoices), choice) != ::end(nurseChoices);
			}

			switch (choice)
			{
			case 1:
				InsertintoWaitingList();
				break;
				/*case 2:
					sorting_waiting();
					break;
				case 3:
					display_waiting();
					break; */
			case 4:
				InsertintoPatientList();
				break;
				/*	case 5:
						search_waiting();
						break;
					case 6:
						sorting_waiting();
						break; */
			case 0:
				login(1);
			}
		}
		else if (user == 2)
		{
			cout << "Currently logged in as : Doctor " << endl;
			cout << "1. View all patients on original waiting list" << endl;
			cout << "2. Search for patient based on visit history and modify records" << endl;
			cout << "3. View patient history list in descending order" << endl;
			cout << "4. Search for patient based on Sickness or First Name" << endl;
			cout << "0. Logout" << endl;
			cout << "Enter option (0-4) : ";
			cin >> choice;
			cin.ignore();

			valid = ::find(::begin(doctorChoices), ::end(doctorChoices), choice) != ::end(doctorChoices);

			while (!valid)
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Enter option (0-4) : ";
				cin >> choice;
				cin.ignore();
				valid = ::find(::begin(doctorChoices), ::end(doctorChoices), choice) != ::end(doctorChoices);
			}

			/*switch(choice)
			{
			case 1:
				display_waiting();
				break;
			case 2:
				update_history();
				break;
			case 3:
				sorting_history();
				break;
			case 4:
				search_history();
				break;
			case 0:
				login(1);
			}*/
		}
	}

}

int main()
{
	HardCode();
	login(0);
	if (user != 0)
		MainPage(user);
	return 0;
}
