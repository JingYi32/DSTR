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
int typedetail = 0;

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
} *waitHead, * waitCurrent, * waitNewNode, * waitSorted, * waitTemp;

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
} *historyHead, * historyTail, * historyCurrent, * historyNewNode, * historySortHead, * historySortTail, * historyTemp;

//Insert Hard Code Function
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

	//id generation
	total++;
}

void matchtoPatient(string PatientID) {
	if (patientHead->id != PatientID) {
		patientCurrent = patientHead;
		while (patientCurrent != NULL) {
			if (patientCurrent->id == PatientID) {
				if (::typedetail == 1) {
					waitNewNode->patient = patientCurrent;
				}
				else {
					historyNewNode->patient = patientCurrent;
				}
				return;
			}
			patientCurrent = patientCurrent->next;
		}
	}
	else {
		if (::typedetail == 1) {
			waitNewNode->patient = patientHead;
		}
		else {
			historyNewNode->patient = patientHead;
		}

	}
}

void addtoWaiting()
{
	if (waitHead == NULL)
	{
		waitHead = waitNewNode;
	}
	else
	{
		waitCurrent = waitHead;
		while (waitCurrent->next != NULL)
		{
			waitCurrent = waitCurrent->next;
		}
		waitCurrent->next = waitNewNode;
	}
}

void addtoHistory() {
	if (historyHead == NULL)
	{
		historyHead = historyTail = historyNewNode;
	}
	else
	{
		historyNewNode->previous = historyTail;
		historyTail->next = historyNewNode;
		historyTail = historyNewNode;
		historyCurrent = historyHead;
	}
}

void HardCode() {
	//Hard Code of Patient Record
	patientHead = patientCurrent = NULL;

	patientNewNode = new Patient;
	patientNewNode->id = "P0001";
	patientNewNode->firstname = "Vivian";
	patientNewNode->lastname = "Fong";
	patientNewNode->age = 24;
	patientNewNode->gender = "Female";
	patientNewNode->contact = "060123456789";
	patientNewNode->address = "4, Jalan Bunga, Taman Bunga, 48793 Malaysia";
	patientNewNode->next = NULL;
	patientNewNode->previous = NULL;
	addtoPatient();

	patientNewNode = new Patient;
	patientNewNode->id = "P0002";
	patientNewNode->firstname = "James";
	patientNewNode->lastname = "Pang";
	patientNewNode->age = 34;
	patientNewNode->gender = "Male";
	patientNewNode->contact = "060123464789";
	patientNewNode->address = "54, Jalan Bunga, Taman Bunga, 48793 Malaysia";
	patientNewNode->next = NULL;
	patientNewNode->previous = NULL;
	addtoPatient();

	patientNewNode = new Patient;
	patientNewNode->id = "P0003";
	patientNewNode->firstname = "Isabella";
	patientNewNode->lastname = "Ng";
	patientNewNode->age = 65;
	patientNewNode->gender = "Female";
	patientNewNode->contact = "060123376789";
	patientNewNode->address = "24, Jalan Bunga, Taman Bunga, 48793 Malaysia";
	patientNewNode->next = NULL;
	patientNewNode->previous = NULL;
	addtoPatient();

	patientNewNode = new Patient;
	patientNewNode->id = "P0004";
	patientNewNode->firstname = "Charlotte";
	patientNewNode->lastname = "Ng";
	patientNewNode->age = 14;
	patientNewNode->gender = "Female";
	patientNewNode->contact = "060123153789";
	patientNewNode->address = "27, Jalan Bunga, Taman Bunga, 48793 Malaysia";
	patientNewNode->next = NULL;
	patientNewNode->previous = NULL;
	addtoPatient();

	patientNewNode = new Patient;
	patientNewNode->id = "P0005";
	patientNewNode->firstname = "Shia";
	patientNewNode->lastname = "Lim";
	patientNewNode->age = 28;
	patientNewNode->gender = "Male";
	patientNewNode->contact = "060123145789";
	patientNewNode->address = "36, Jalan Bunga, Taman Bunga, 48793 Malaysia";
	patientNewNode->next = NULL;
	patientNewNode->previous = NULL;
	addtoPatient();

	//Hard Code of Waiting List Record
	::typedetail = 1;
	waitHead = waitCurrent = NULL;
	waitNewNode = new Waiting;
	waitNewNode->order = 1;
	waitNewNode->doctor = "";
	waitNewNode->timeArrived = 1636446600;
	waitNewNode->sickness = "Head Pain";
	waitNewNode->disability = false;
	waitNewNode->medicine = "";
	waitNewNode->sortItem = "";
	waitNewNode->next = NULL;
	matchtoPatient("P0001");
	addtoWaiting();

	waitNewNode = new Waiting;
	waitNewNode->order = 2;
	waitNewNode->doctor = "";
	waitNewNode->timeArrived = 1636446900;
	waitNewNode->sickness = "Vomit";
	waitNewNode->disability = false;
	waitNewNode->medicine = "";
	waitNewNode->sortItem = "";
	waitNewNode->next = NULL;
	matchtoPatient("P0002");
	addtoWaiting();

	waitNewNode = new Waiting;
	waitNewNode->order = 3;
	waitNewNode->doctor = "";
	waitNewNode->timeArrived = 1636447320;
	waitNewNode->sickness = "Head Pain";
	waitNewNode->disability = true;
	waitNewNode->medicine = "";
	waitNewNode->sortItem = "";
	waitNewNode->next = NULL;
	matchtoPatient("P0003");
	addtoWaiting();

	waitNewNode = new Waiting;
	waitNewNode->order = 4;
	waitNewNode->doctor = "";
	waitNewNode->timeArrived = 1636447800;
	waitNewNode->sickness = "Fever";
	waitNewNode->disability = false;
	waitNewNode->medicine = "";
	waitNewNode->sortItem = "";
	waitNewNode->next = NULL;
	matchtoPatient("P0004");
	addtoWaiting();

	waitNewNode = new Waiting;
	waitNewNode->order = 5;
	waitNewNode->doctor = "";
	waitNewNode->timeArrived = 1636448280;
	waitNewNode->sickness = "Fever";
	waitNewNode->disability = false;
	waitNewNode->medicine = "";
	waitNewNode->sortItem = "";
	waitNewNode->next = NULL;
	matchtoPatient("P0002");
	addtoWaiting();


	//Hard Code of History List Record
	::typedetail = 2;
	historyHead = historyCurrent = NULL;
	historyNewNode = new History;
	historyNewNode->id = "H0001";
	historyNewNode->doctor = "Dr. Tan";
	historyNewNode->timeVisited = 1636156982;
	historyNewNode->sickness = "Vomit";
	historyNewNode->disability = false;
	historyNewNode->medicine = "Kaopectate";
	historyNewNode->sortItem = "";
	historyNewNode->next = NULL;
	historyNewNode->previous = NULL;
	matchtoPatient("P0004");
	addtoHistory();

	historyNewNode = new History;
	historyNewNode->id = "H0002";
	historyNewNode->doctor = "Dr. Wong";
	historyNewNode->timeVisited = 1636159524;
	historyNewNode->sickness = "Head Pain";
	historyNewNode->disability = false;
	historyNewNode->medicine = "Panadol";
	historyNewNode->sortItem = "";
	historyNewNode->next = NULL;
	historyNewNode->previous = NULL;
	matchtoPatient("P0002");
	addtoHistory();

	historyNewNode = new History;
	historyNewNode->id = "H0003";
	historyNewNode->doctor = "Dr. Tan";
	historyNewNode->timeVisited = 1636164754;
	historyNewNode->sickness = "Stomach Pain";
	historyNewNode->disability = false;
	historyNewNode->medicine = "Pepto-Bismol";
	historyNewNode->sortItem = "";
	historyNewNode->next = NULL;
	historyNewNode->previous = NULL;
	matchtoPatient("P0003");
	addtoHistory();

	historyNewNode = new History;
	historyNewNode->id = "H0004";
	historyNewNode->doctor = "Dr. Wong";
	historyNewNode->timeVisited = 1636172926;
	historyNewNode->sickness = "Cough";
	historyNewNode->disability = false;
	historyNewNode->medicine = "Cough Syrup";
	historyNewNode->sortItem = "";
	historyNewNode->next = NULL;
	historyNewNode->previous = NULL;
	matchtoPatient("P0005");
	addtoHistory();

	historyNewNode = new History;
	historyNewNode->id = "H0005";
	historyNewNode->doctor = "Dr. Tan";
	historyNewNode->timeVisited = 1636191824;
	historyNewNode->sickness = "Vomit";
	historyNewNode->disability = false;
	historyNewNode->medicine = "Kaopectate";
	historyNewNode->sortItem = "";
	historyNewNode->next = NULL;
	historyNewNode->previous = NULL;
	matchtoPatient("P0001");
	addtoHistory();

	historyNewNode = new History;
	historyNewNode->id = "H0006";
	historyNewNode->doctor = "Dr. Ahmad";
	historyNewNode->timeVisited = 1636417424;
	historyNewNode->sickness = "Cough";
	historyNewNode->disability = true;
	historyNewNode->medicine = "Cough Syrup";
	historyNewNode->sortItem = "";
	historyNewNode->next = NULL;
	historyNewNode->previous = NULL;
	matchtoPatient("P0002");
	addtoHistory();

	historyNewNode = new History;
	historyNewNode->id = "H0007";
	historyNewNode->doctor = "Dr. Tan";
	historyNewNode->timeVisited = 1636433012;
	historyNewNode->sickness = "Fever";
	historyNewNode->disability = false;
	historyNewNode->medicine = "Panadol with Optizorb";
	historyNewNode->sortItem = "";
	historyNewNode->next = NULL;
	historyNewNode->previous = NULL;
	matchtoPatient("P0005");
	addtoHistory();

	historyNewNode = new History;
	historyNewNode->id = "H0008";
	historyNewNode->doctor = "Dr. Ahmad";
	historyNewNode->timeVisited = 1636443803;
	historyNewNode->sickness = "Vomit";
	historyNewNode->disability = false;
	historyNewNode->medicine = "Kaopectate";
	historyNewNode->sortItem = "";
	historyNewNode->next = NULL;
	historyNewNode->previous = NULL;
	matchtoPatient("P0003");
	addtoHistory();
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
	string gender;
	string contact;
	string address;
	string sickness;
	bool disability;
	string validGender[2] = { "Female", "Male" };

	//choose add new patient or select existing patient from hardcode
	cout << "1 - Register New Patient \n0 - Choose Existing Patient" << endl;
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

	//register new patient
	if (add)
	{
		//regulate id generation (4 digits)
		::stringstream oss;
		oss << ::setw(4) << ::setfill('0') << total;
		::string s = oss.str();
		id = "P" + s;
		cout << "ID : " << id << endl;
		cout << "First Name : ";
		getline(cin, firstname);
		cout << "Last Name : ";
		getline(cin, lastname);
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
		cout << "Gender ('Female' / 'Male') : ";
		getline(cin, gender);
		valid = ::find(::begin(validGender), ::end(validGender), gender) != ::end(validGender);
		while (!valid)
		{
			cout << "Invalid input! Enter gender again : ";
			getline(cin, gender);
			valid = ::find(::begin(validGender), ::end(validGender), gender) != ::end(validGender);
		}
		cout << "Contact : ";
		getline(cin, contact);
		while (!::all_of(begin(contact), end(contact), std::isdigit))
		{
			cout << "Invalid input! Enter input again : ";
			getline(cin, contact);
		}
		cout << "Address : ";
		getline(cin, address);
		cout << "Time : ";
		timeArrived = time(0);
		ctime_s(str, ::size, &timeArrived);
		cout << str;
		cout << "Sickness : ";
		getline(cin, sickness);
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
		waitNewNode = new Waiting;
		waitNewNode->order = total;
		waitNewNode->patient = patientNewNode;
		waitNewNode->doctor = "";
		waitNewNode->timeArrived = timeArrived;
		waitNewNode->sickness = sickness;
		waitNewNode->disability = disability;
		waitNewNode->medicine = "";
		waitNewNode->sortItem = "";
		waitNewNode->next = NULL;
		addtoWaiting();

	}
	else
	{
		//select existing patient
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

				waitNewNode = new Waiting;
				waitNewNode->order = total;
				waitNewNode->patient = patientCurrent;
				waitNewNode->doctor = "";
				waitNewNode->timeArrived = timeArrived;
				waitNewNode->sickness = sickness;
				waitNewNode->disability = disability;
				waitNewNode->medicine = "";
				waitNewNode->sortItem = "";
				waitNewNode->next = NULL;
				addtoWaiting();
			}
			else if (select != 1 && select != 2 && select != 0 || cin.fail())
			{
				cout << "Invalid option!" << endl;
				system("pause");
			}
			else if (select == 2 && patientCurrent->previous == NULL)
			{
				cout << "This is the first patient in the list!" << endl;
				system("pause");
			}
			else
			{
				cout << "This is the last patient in the list!" << endl;
				system("pause");
			}
		}
	}

	system("cls");
}

//adding patient history after appointment
void InsertintoPatientList()
{
	string doctor;
	string medicine;

	system("cls");
	cout << "Patient name : " << waitHead->patient->firstname << " " << waitHead->patient->lastname << endl;
	cout << "Enter doctor name : ";
	getline(cin, doctor);
	cout << "Enter medicine name : ";
	getline(cin, medicine);
	timeArrived = time(0);

	historyNewNode = new History;
	historyNewNode->id = waitHead->patient->id;
	historyNewNode->patient = waitHead->patient;
	historyNewNode->doctor = doctor;
	historyNewNode->timeVisited = timeArrived;
	historyNewNode->sickness = waitHead->sickness;
	historyNewNode->disability = waitHead->disability;
	historyNewNode->medicine = medicine;
	historyNewNode->sortItem = waitHead->sortItem;
	historyNewNode->next = NULL;
	historyNewNode->previous = NULL;
	addtoHistory();

	//removing waiting list head
	waitCurrent = waitHead;
	waitHead = waitHead->next;
	delete waitCurrent;

	cout << "Patient history updated!" << endl;
	system("pause");
	system("cls");
}

void tabbing(string text, string text2) {
	if (text2 == "") {
		if (text.size() <= 5) {
			cout << "\t\t|";
		}
		else if (text.size() < 15) {
			cout << "\t|";
		}
		else {
			cout << "|";
		}
	} else {
		string test = text + text2;
		if (test.size() <= 5) {
			cout << "\t\t\t|";
		}
		else if (test.size() < 15) {
			cout << "\t\t|";
		}
		else {
			cout << "\t|";
		}
	}
}

void displayWaiting() {
	system("cls");
	waitCurrent = waitHead;
	int i = 1;
	if (waitCurrent != NULL) {
		cout << "=========================================================[ Patient waiting list ]========================================================" << endl;
		cout << "|  No. \t|Patient ID \t|Name \t\t\t|Age \t|Gender |Contact \t|Time Arrived\t\t|Sickness \t|Disability\t|" << endl;
		cout << "=========================================================================================================================================" << endl;
		while (waitCurrent != NULL) {
			cout << "|  " << i << ".\t|";
			cout << waitCurrent->patient->id << "\t\t|";
			cout << waitCurrent->patient->firstname << " " << waitCurrent->patient->lastname;
			tabbing(waitCurrent->patient->firstname, waitCurrent->patient->lastname);
			cout << waitCurrent->patient->age << "\t|";
			cout << waitCurrent->patient->gender << "\t|";
			cout << waitCurrent->patient->contact << "\t|";
			time_t now = waitCurrent->timeArrived;
			tm ltmm;
			localtime_s(&ltmm, &now);
			tm* ltm = &ltmm;
			string month;
			switch (ltm->tm_mon) {
				case 0: month = "Jan"; break;
				case 1: month = "Feb"; break;
				case 2: month = "Mar"; break;
				case 3: month = "Apr"; break;
				case 4: month = "May"; break;
				case 5: month = "Jun"; break;
				case 6: month = "Jul"; break;
				case 7: month = "Aug"; break;
				case 8: month = "Sept"; break;
				case 9: month = "Oct"; break;
				case 10: month = "Nov"; break;
				case 11: month = "Dec"; break;
			}
			string datetime = to_string(ltm->tm_mday) + "-" +
				month + "-" +
				to_string(1900 + ltm->tm_year) + " " +
				to_string(ltm->tm_hour) + ":" +
				to_string(ltm->tm_min) ;
			cout << datetime << "\t|";
			cout << waitCurrent->sickness;
			tabbing(waitCurrent->sickness, "");
			if (waitCurrent->disability == 1) {
				cout << "Yes" << "      \t|" << endl;
			}
			else {
				cout << "No" << "      \t|" << endl;
			}
			waitCurrent = waitCurrent->next;
			i++;
		}
		cout << "=========================================================================================================================================" << endl;
	} else {
		cout << "+-----List is currently empty-----+" << endl << endl;
	}
	system("pause");
	system("cls");
}

void display(int list, int num) {
	//Display waiting list
	if (list == 1) {
		system("cls");
		cout << "---------------------- [ ";
		cout << waitCurrent->patient->firstname << " " << waitCurrent->patient->lastname;
		cout << "'s Info ] ----------------------" << endl << endl;
		cout << "Entry Number\t: " << num << endl;
		cout << "Patient ID \t: " << waitCurrent->patient->id << endl;
		cout << "Name \t\t: " << waitCurrent->patient->firstname << " " << waitCurrent->patient->lastname << endl;
		cout << "Age \t\t: " << waitCurrent->patient->age << endl;
		cout << "Gender \t\t: " << waitCurrent->patient->gender << endl;
		cout << "Contact \t: " << waitCurrent->patient->contact << endl;
		cout << "Address \t: " << waitCurrent->patient->address << endl;
		time_t now = waitCurrent->timeArrived;
		tm ltmm;
		localtime_s(&ltmm, &now);
		tm* ltm = &ltmm;
		string month;
		switch (ltm->tm_mon) {
		case 0: month = "Jan"; break;
		case 1: month = "Feb"; break;
		case 2: month = "Mar"; break;
		case 3: month = "Apr"; break;
		case 4: month = "May"; break;
		case 5: month = "Jun"; break;
		case 6: month = "Jul"; break;
		case 7: month = "Aug"; break;
		case 8: month = "Sept"; break;
		case 9: month = "Oct"; break;
		case 10: month = "Nov"; break;
		case 11: month = "Dec"; break;
		}
		string datetime = to_string(ltm->tm_mday) + "-" +
			month + "-" +
			to_string(1900 + ltm->tm_year) + " " +
			to_string(ltm->tm_hour) + ":" +
			to_string(ltm->tm_min);
		cout << "Time Arrived \t: " << datetime << endl;
		cout << "Sickness \t: " << waitCurrent->sickness << endl;
		if (waitCurrent->disability == 1) {
			cout << "Disability \t: Yes" << endl << endl;
		}
		else {
			cout << "Disability \t: No" << endl << endl;
		}
	}
	//Display history list
	else if (list == 2) {
		system("cls");
		cout << "---------------------- [ ";
		cout << historyCurrent->patient->firstname << " " << historyCurrent->patient->lastname;
		cout << "'s Info ] ----------------------" << endl << endl;
		cout << "Entry Number\t: " << num << endl;
		cout << "Patient ID \t: " << historyCurrent->patient->id << endl;
		cout << "Name \t\t: " << historyCurrent->patient->firstname << " " << historyCurrent->patient->lastname << endl;
		cout << "Age \t\t: " << historyCurrent->patient->age << endl;
		cout << "Gender \t\t: " << historyCurrent->patient->gender << endl;
		cout << "Contact \t: " << historyCurrent->patient->contact << endl;
		cout << "Address \t: " << historyCurrent->patient->address << endl;
		time_t now = historyCurrent->timeVisited;
		tm ltmm;
		localtime_s(&ltmm, &now);
		tm* ltm = &ltmm;
		string month;
		switch (ltm->tm_mon) {
		case 0: month = "Jan"; break;
		case 1: month = "Feb"; break;
		case 2: month = "Mar"; break;
		case 3: month = "Apr"; break;
		case 4: month = "May"; break;
		case 5: month = "Jun"; break;
		case 6: month = "Jul"; break;
		case 7: month = "Aug"; break;
		case 8: month = "Sept"; break;
		case 9: month = "Oct"; break;
		case 10: month = "Nov"; break;
		case 11: month = "Dec"; break;
		}
		string datetime = to_string(ltm->tm_mday) + "-" +
			month + "-" +
			to_string(1900 + ltm->tm_year) + " " +
			to_string(ltm->tm_hour) + ":" +
			to_string(ltm->tm_min);
		cout << "Time Visited \t: " << datetime << endl;
		cout << "Sickness \t: " << historyCurrent->sickness << endl;
		if (historyCurrent->disability == 1) {
			cout << "Disability \t: Yes" << endl;
		}
		else {
			cout << "Disability \t: No" << endl;
		}
		cout << "Doctor \t\t: " << historyCurrent->doctor << endl;
		cout << "Medicine \t: " << historyCurrent->medicine << endl << endl;
	}
}

void searchWaiting() {
	int decision = 1;
	string id, name;
	waitCurrent = waitHead;
	while (decision != 0) {
		system("cls");
		int num = 1;
		int found = 0;
		cout << "Search options: " << endl;
		cout << "1. Patient ID " << endl;
		cout << "2. Patient Name " << endl;
		cout << "0. Exit Search " << endl;
		cout << "Please enter your decision: ";
		cin >> decision;
		cin.ignore();
		if (decision == 1) {
			cout << "\nPlease enter patient ID: ";
			cin >> id;
			cin.ignore();
			while (waitCurrent != NULL) {
				if (id == waitCurrent->patient->id) {
					//Display waiting list
					display(1, num);
					found ++;
					num++;
					system("pause");
				}
				waitCurrent = waitCurrent->next;
			}
			if (found == 0) {
				cout << "\nPatient does not exist in waiting list" << endl << endl;
				system("pause");
			}
			waitCurrent = waitHead;
		}
		else if (decision == 2){
			cout << "\nPlease enter patient name: ";
			getline(cin, name);
			while (waitCurrent != NULL) {
				string fn = waitCurrent->patient->firstname;
				string ln = waitCurrent->patient->lastname;
				string fullName = waitCurrent->patient->firstname + " " + waitCurrent->patient->lastname;
				if ((name == fn) || (name == ln) || (name == fullName)) {
					//Display waiting list
					display(1, num);
					found++;
					num++;
					system("pause");
				}
				waitCurrent = waitCurrent->next;
			}
			if (found == 0) {
				cout << "\nPatient does not exist in waiting list" << endl << endl;
				system("pause");
			}
			waitCurrent = waitHead;
		}
		else if (decision == 0) {
			system("cls");
			return;
		}
		else if ((decision != 0) || (decision != 1) || (decision != 2)) {
			cout << "\nPlease enter given options!" << endl;
			system("pause");
		}
	}
	system("cls");
}

void searchHistory() {
	int decision = 1;
	string name, sick;
	historyCurrent = historyHead;
	while (decision != 0) {
		system("cls");
		int num = 1;
		int found = 0;
		cout << "Search options: " << endl;
		cout << "1. Patient Name " << endl;
		cout << "2. Patient Sickness " << endl;
		cout << "0. Exit Search " << endl;
		cout << "Please enter your decision: ";
		cin >> decision;
		cin.ignore();
		if (decision == 1) {
			cout << "\nPlease enter patient name: ";
			getline(cin, name);
			while (historyCurrent != NULL) {
				string fn = historyCurrent->patient->firstname;
				string ln = historyCurrent->patient->lastname;
				string fullName = historyCurrent->patient->firstname + " " + historyCurrent->patient->lastname;
				if ((name == fn) || (name == ln) || (name == fullName)) {
					display(2, num);
					found++;
					num++;
					found++;
					system("pause");
				}
				historyCurrent = historyCurrent->next;
			}
			if (found == 0) {
				cout << "Patient does not exist in history list" << endl << endl;
				system("pause");
			}
			historyCurrent = historyHead;
		}
		else if (decision == 2) {
			cout << "\nPlease enter patient sickness: ";
			getline(cin, sick);
			cout << sick << endl << endl;
			while (historyCurrent != NULL) {
				string sickness = historyCurrent->sickness;
				if (sick == sickness) {
					display(2, num);
					found++;
					num++;
					found++;
					system("pause");
				}
				historyCurrent = historyCurrent->next;
			}
			if (found == 0) {
				cout << "Patient does not exist in history list" << endl << endl;
				system("pause");
			}
			historyCurrent = historyHead;
		}
		else if (decision == 0) {
			system("cls");
			return;
		}
		else {
			cout << "\nPlease enter given options!" << endl;
			system("pause");
		}
	}
	system("cls");
}

void updateHistory() {
	if (historyHead == NULL) {
		system("cls");
		cout << "\n+--------History list is currently empty--------+" << endl;
		system("pause");
		return;
	}
	int decision = 1;
	string id;
	while (decision != 0) {
		int num = 1;
		int found = 0;
		system("cls");
		historyCurrent = historyHead;
		cout << "1. Update patient info" << endl;
		cout << "0. Exit update" << endl;
		cout << "Enter your decision: ";
		cin >> decision;
		cin.ignore();
		if (decision == 1) {
			cout << "\nPlease enter patient ID: ";
			cin >> id;
			cin.ignore();
			while (historyCurrent != NULL) {
				if (id == historyCurrent->patient->id) {
					int option = 1;
					while (option != 0) {
						display(2, num);
						found++;
						cout << "\n\n==========================[ Update options ]==========================" << endl;
						cout << "1. Patient Sickness " << endl;
						cout << "2. Patient Doctor " << endl;
						cout << "3. Patient Medicine " << endl;
						cout << "0. Exit Update " << endl;
						cout << "======================================================================" << endl;
						cout << "Please enter your decision: ";
						cin >> option;
						cin.ignore();
						if (option == 1) {
							cout << "\nPlease enter new sickness: ";
							getline(cin, historyCurrent->sickness);
							cout << "Update was successful!" << endl;
							system("pause");
						}
						else if (option == 2) {
							cout << "\nPlease enter new doctor name: ";
							getline(cin, historyCurrent->doctor);
							cout << "Update was successful!" << endl;
							system("pause");
						}
						else if (option == 3) {
							cout << "\nPlease enter new medicine: ";
							getline(cin, historyCurrent->medicine);
							cout << "Update was successful!" << endl;
							system("pause");
						}
						else if ((option < 0) || (option >3)) {
							cout << "\nPlease enter given options!" << endl;
							system("pause");
						}
					}
					num++;
				}
				historyCurrent = historyCurrent->next;
			}
			if (found == 0) {
				cout << "Patient does not exist in history list" << endl;
				system("pause");
			}
			historyCurrent = historyHead;
		}
		else if (decision == 0) {
			system("cls");
			return;
		}
		else if ((decision != 0) || (decision != 1)) {
			cout << "\nPlease enter given options!" << endl;
			system("pause");
		}
	}
	system("cls");
}

void changePriority() {
	//Check if the waiting list is empty
	if (waitHead != NULL)
	{
		waitCurrent = waitHead;
		waitSorted = NULL;

		while (waitCurrent != NULL)
		{
			waitNewNode = new Waiting;
			waitNewNode->order = waitCurrent->order;
			waitNewNode->patient = waitCurrent->patient;
			waitNewNode->doctor = waitCurrent->doctor;
			waitNewNode->timeArrived = waitCurrent->timeArrived;
			waitNewNode->sickness = waitCurrent->sickness;
			waitNewNode->disability = waitCurrent->disability;
			waitNewNode->medicine = waitCurrent->medicine;
			waitNewNode->sortItem = waitCurrent->sortItem;
			waitNewNode->next = NULL;

			if (waitSorted == NULL)
			{
				waitSorted = waitNewNode;
			}
			else if (!waitNewNode->disability)
			{
				waitTemp = waitSorted;
				while (waitTemp->next != NULL)
				{
					waitTemp = waitTemp->next;
				}
				waitTemp->next = waitNewNode;
			}
			else if (!waitSorted->disability)
			{
				waitNewNode->next = waitSorted;
				waitSorted = waitNewNode;
			}
			else {
				Waiting* previous = NULL;
				waitTemp = waitSorted;
				while (waitTemp->disability)
				{
					previous = waitTemp;
					waitTemp = waitTemp->next;
				}
				previous->next = waitNewNode;
				waitNewNode->next = waitTemp;
			}
			waitCurrent = waitCurrent->next;
		}
		waitHead = waitSorted;
		cout << "\nChange sucessfully!" << endl << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Waiting List is empty!";
		system("pause");
		system("cls");
	}
}

//Sorting Function
void setSortingItem(int sortdecision1) {
	//Waiting List
	if (user == 1) {
		waitNewNode->sortItem.clear();

		//User select sort by Patient ID
		if (sortdecision1 == 1) {
			waitNewNode->sortItem = waitNewNode->patient->id;
		}
		//User select sort by Patient Name
		else if (sortdecision1 == 2) {
			waitNewNode->sortItem = waitNewNode->patient->firstname + " " + waitNewNode->patient->lastname;
		}
		//User select sort by Time Visited
		else if (sortdecision1 == 3) {
			waitNewNode->sortItem = waitNewNode->timeArrived;
		}
	}
	//History List
	else {
		historyNewNode->sortItem.clear();

		//User select sort by Patient ID
		if (sortdecision1 == 1) {
			historyNewNode->sortItem = historyNewNode->patient->id;
		}
		//User select sort by Patient Name
		else if (sortdecision1 == 2) {
			historyNewNode->sortItem = historyNewNode->patient->firstname + " " + historyNewNode->patient->lastname;
		}
		//User select sort by Time Visited
		else if (sortdecision1 == 3) {
			historyNewNode->sortItem = historyNewNode->timeVisited;
		}
		//Sickness
		else if (sortdecision1 == 4) {
			historyNewNode->sortItem = historyNewNode->sickness;
		}
		//Doctor
		else if (sortdecision1 == 5) {
			historyNewNode->sortItem = historyNewNode->doctor;
		}
	}
}

void pastingData(int sortdecision2) {
	//Waiting List
	if (user == 1) {
		//Ascending order
		if (sortdecision2 == 1) {
			if (waitSorted == NULL) {
				waitSorted = waitNewNode;
				return;
			}
			else if (waitNewNode->sortItem < waitSorted->sortItem) {
				waitNewNode->next = waitSorted;
				waitSorted = waitNewNode;
				return;
			}
			else {
				Waiting* previous = waitSorted;
				waitTemp = waitSorted->next;

				while (waitTemp != NULL && waitNewNode->sortItem > waitTemp->sortItem) {
					previous = waitTemp;
					waitTemp = waitTemp->next;
				}
				previous->next = waitNewNode;
				waitNewNode->next = waitTemp;
				return;
			}
			return;
		}
		//User select sort in descending order
		else {
			if (waitSorted == NULL) {
				waitSorted = waitNewNode;
			}
			else if (waitNewNode->sortItem > waitSorted->sortItem) {
				waitNewNode->next = waitSorted;
				waitSorted = waitNewNode;
				return;
			}
			else {
				Waiting* previous = waitSorted;
				waitTemp = waitSorted->next;

				while (waitTemp != NULL && waitNewNode->sortItem < waitTemp->sortItem) {
					previous = waitTemp;
					waitTemp = waitTemp->next;
				}

				previous->next = waitNewNode;
				waitNewNode->next = waitTemp;
				return;
			}
			return;
		}
	}

	//History List
	else {
		//Ascending
		if (sortdecision2 == 1) {
			if (historySortHead == NULL) {
				historySortHead = historySortTail = historyNewNode;
				return;
			}
			else if (historyNewNode->sortItem < historySortHead->sortItem) {
				historyNewNode->next = historySortHead;
				historySortHead->previous = historyNewNode;
				historySortHead = historyNewNode;
			}
			else if (historyNewNode->sortItem > historySortTail->sortItem) {
				historySortTail->next = historyNewNode;
				historyNewNode->previous = historySortTail;
				historySortTail = historyNewNode;
			}
			else {
				historyTemp = historySortHead->next;
				while (historyNewNode->sortItem > historyTemp->sortItem) {
					historyTemp = historyTemp->next;
				}
				historyTemp->previous->next = historyNewNode;
				historyNewNode->previous = historyTemp->previous;
				historyTemp->previous = historyNewNode;
				historyNewNode->next = historyTemp;
			}
		}
		//Decending
		else {
			if (historySortHead == NULL) {
				historySortHead = historySortTail = historyNewNode;
				return;
			}
			else if (historyNewNode->sortItem > historySortHead->sortItem) {
				historyNewNode->next = historySortHead;
				historySortHead = historyNewNode;
			}
			else if (historyNewNode->sortItem < historySortTail->sortItem) {
				historySortTail->next = historyNewNode;
				historyNewNode->previous = historySortTail;
				historySortTail = historyNewNode;
			}
			else {
				historyTemp = historySortHead->next;

				while (historyNewNode->sortItem < historyTemp->sortItem) {
					historyTemp = historyTemp->next;
				}

				historyTemp->previous->next = historyNewNode;
				historyNewNode->previous = historyTemp->previous;
				historyTemp->previous = historyNewNode;
				historyNewNode->next = historyTemp;
			}
		}
	}
	return;
}

void CreateSortedList(int sortdecision1, int sortdecision2) {
	//Waiting List
	if (user == 1) {
		waitNewNode = new Waiting;
		waitNewNode->order = waitCurrent->order;
		waitNewNode->patient = waitCurrent->patient;
		waitNewNode->doctor = waitCurrent->doctor;
		waitNewNode->timeArrived = waitCurrent->timeArrived;
		waitNewNode->sickness = waitCurrent->sickness;
		waitNewNode->disability = waitCurrent->disability;
		waitNewNode->medicine = waitCurrent->medicine;
		waitNewNode->sortItem = waitCurrent->sortItem;
		waitNewNode->next = NULL;
	}
	//History List
	else {
		historyNewNode = new History;
		historyNewNode->id = historyCurrent->id;
		historyNewNode->patient = historyCurrent->patient;
		historyNewNode->doctor = historyCurrent->doctor;
		historyNewNode->timeVisited = historyCurrent->timeVisited;
		historyNewNode->sickness = historyCurrent->sickness;
		historyNewNode->disability = historyCurrent->disability;
		historyNewNode->medicine = historyCurrent->medicine;
		historyNewNode->sortItem = historyCurrent->sortItem;
		historyNewNode->next = NULL;
		historyNewNode->previous = NULL;
	}
	setSortingItem(sortdecision1);
	pastingData(sortdecision2);
}

void MoveForward() //original printing with page by page
{
	if (user == 1) {
		if (waitCurrent->next != NULL)
		{
			waitCurrent = waitCurrent->next;
		}
		else
		{
			cout << "End of list!" << endl;
			system("Pause");
		}
	}
	else {
		if (historyCurrent->next != NULL) {
			historyCurrent = historyCurrent->next;
		}
		else {
			cout << "End of list!" << endl;
			system("Pause");
		}
	}
}

void MoveBackward() //reverse printing with page by page
{
	if (user == 1) {
		if (waitCurrent != waitSorted)
		{
			waitTemp = waitSorted;
			while (waitTemp->next != waitCurrent) {
				waitTemp = waitTemp->next;
			}
			waitCurrent = waitTemp;
		}
		else
		{
			cout << "End of list!" << endl;
			system("Pause");
		}
	}
	else {
		if (historyCurrent->previous != NULL) {
			historyCurrent = historyCurrent->previous;
		}
		else {
			cout << "End of list!" << endl;
			system("Pause");
		}
	}
}

void DisplayByPage() {
	if (user == 1) {
		waitCurrent = waitSorted;
		int decision = 1;

		while (decision != 3) {
			system("CLS");
			cout << "Order\t\t\t: " << waitCurrent->order << endl;
			time_t now = waitCurrent->timeArrived;
			tm ltmm;
			localtime_s(&ltmm, &now);
			tm* ltm = &ltmm;

			string datetime = to_string(1900 + ltm->tm_year) + "-" +
				to_string(1 + ltm->tm_mon) + "-" +
				to_string(ltm->tm_mday) + " " +
				to_string(ltm->tm_hour) + ":" +
				to_string(ltm->tm_min) + ":" +
				to_string(ltm->tm_sec);
			cout << "Time Arrived\t\t: " << datetime << endl;
			cout << "Patient ID\t\t: " << waitCurrent->patient->id << endl;
			cout << "Patient Firstname\t: " << waitCurrent->patient->firstname << endl;
			cout << "Patient Lastname\t: " << waitCurrent->patient->lastname << endl;
			cout << "Sickness\t\t: " << waitCurrent->sickness << endl;
			cout << "Disability\t\t: ";
			if (waitCurrent->disability) {
				cout << "True";
			}
			else {
				cout << "False";
			}
			cout << endl << endl;

			cout << "1. Next Patient\n2. Previous Patient\n3. Exit Display" << endl;
			cout << "Enter the selection\t:";
			cin >> decision;
			while (cin.fail() || (decision < 1 && decision > 3)) 
			{
				cout << "Wrong Input! Kindly insert again!";
				cout << "1. Next Patient\n2. Previous Patient\n3. Exit Display";
				cout << "Enter the selection\t:";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> decision;
			}

			switch (decision)
			{
			case 1: MoveForward(); break;
			case 2: MoveBackward(); break;
			case 3: cout << "Goodbye!" << endl << endl; system("cls");
			}
		}
	}
	else 
	{
		historyCurrent = historySortHead;
		int decision = 1;

		while (decision != 3) 
		{
			system("CLS");
			cout << "History ID\t\t: " << historyCurrent->id << endl;
			cout << "Patient ID\t\t: " << historyCurrent->patient->id << endl;
			cout << "Patient Firstname\t: " << historyCurrent->patient->firstname << endl;
			cout << "Patient Lastname\t: " << historyCurrent->patient->lastname << endl;
			time_t now = historyCurrent->timeVisited;
			tm ltmm;
			localtime_s(&ltmm, &now);
			tm* ltm = &ltmm;
			string datetime = to_string(1900 + ltm->tm_year) + "-" +
				to_string(1 + ltm->tm_mon) + "-" +
				to_string(ltm->tm_mday) + " " +
				to_string(ltm->tm_hour) + ":" +
				to_string(ltm->tm_min) + ":" +
				to_string(ltm->tm_sec);
			cout << "Time Visited\t\t: " << datetime << endl;
			cout << "Doctor\t\t\t: " << historyCurrent->doctor << endl;
			cout << "Sickness\t\t: " << historyCurrent->sickness << endl;
			cout << "Disability\t\t: ";
			if (waitCurrent->disability) {
				cout << "True";
			}
			else {
				cout << "False";
			}
			cout << endl;
			cout << "Medicine\t\t: " << historyCurrent->medicine << endl << endl;
			cout << "1. Next Patient\n2. Previous Patient\n3. Exit Display" << endl;
			cout << "Enter the selection\t:";
			cin >> decision;
			while (cin.fail() || (decision < 1 && decision > 3)) 
			{
				cout << "Wrong Input! Kindly insert again!";
				cout << "1. Next Patient\n2. Previous Patient\n3. Exit Display";
				cout << "Enter the selection\t:";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> decision;
			}

			switch (decision)
			{
			case 1: MoveForward(); break;
			case 2: MoveBackward(); break;
			case 3: cout << "Goodbye!" << endl << endl;
			}
		}
	}

}

void sortFunction() {
	int sortdecision1, sortdecision2;
	system("cls");
	if (user == 1) {
		//Nurse

		//Ask user what they want to sort as
		cout << "Kindly select one item to sort by: \n1. Patient ID\n2. Patient Name\n3. Time Visited\n4. Exit" << endl;
		cout << "Enter the selection\t: ";
		cin >> sortdecision1;
		while (cin.fail() || (sortdecision1 < 1 && sortdecision1 > 4)) {
			cout << "Wrong Input! Kindly insert again!" << endl;
			cout << "Kindly select one item to sort by: \n1. Patient ID\n2. Patient Name\n3. Time Visited\n4. Exit" << endl;
			cout << "Enter the selection\t:";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> sortdecision1;
		}

		//Exit sort fucntion if user select 4
		if (sortdecision1 == 4) {
			cout << "Exit Sort Function!" << endl;
			return;
		}

		cout << endl;

		cout << "Kindly select one item to sort by:\n1. Ascending\n2. Descending" << endl;
		cout << "Enter the selection\t: ";
		cin >> sortdecision2;
		while (cin.fail() || (sortdecision1 < 1 && sortdecision1 > 4)) {
			cout << "Wrong Input! Kindly insert again!" << endl;
			cout << "Kindly select one item to sort by: \n1. Patient ID\n2. Patient Name\n3. Time Visited\n4. Exit" << endl;
			cout << "Enter the selection\t:";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> sortdecision1;
		}

		//Create the temporarily sort list
		waitCurrent = waitHead;
		waitSorted = NULL;
		while (waitCurrent != NULL) {
			CreateSortedList(sortdecision1, sortdecision2);
			waitCurrent = waitCurrent->next;
		}

		//Display the sort list by page
		DisplayByPage();
	}
	else {
		//Doctor
		cout << "Kindly select one item to sort by: \n1. Patient ID\n2. Patient Name\n3. Time Visited\n4. Sickness\n5. Doctor\n6. Exit" << endl;
		cout << "Enter the selection\t: ";
		cin >> sortdecision1;
		while (cin.fail() || (sortdecision1 < 1 && sortdecision1 > 6)) {
			cout << "Wrong Input! Kindly insert again!" << endl;
			cout << "Kindly select one item to sort by: \n1. Patient ID\n2. Patient Name\n3. Time Visited\n4. Sickness\n5. Doctor\n6. Exit" << endl;
			cout << "Enter the selection\t:";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> sortdecision1;
		}

		//Exit sort fucntion if user select 7
		if (sortdecision1 == 6) {
			cout << "Exit Sort Function!" << endl;
			return;
		}

		cout << endl;

		cout << "Kindly select one item to sort by:\n1. Ascending\n2. Descending" << endl;
		cout << "Enter the selection\t: ";
		cin >> sortdecision2;
		while (cin.fail() || (sortdecision1 < 1 && sortdecision1 > 6)) {
			cout << "Wrong Input! Kindly insert again!" << endl;
			cout << "Kindly select one item to sort by: \n1. Patient ID\n2. Patient Name\n3. Time Visited\n4. Exit" << endl;
			cout << "Enter the selection\t:";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> sortdecision1;
		}

		//Create the temporarily sort list
		historyCurrent = historyHead;
		historySortHead = NULL;
		while (historyCurrent != NULL) {
			CreateSortedList(sortdecision1, sortdecision2);
			historyCurrent = historyCurrent->next;
		}

		//Display the sort list by page
		DisplayByPage();
	}

	//Delete sort list
	while (waitSorted != NULL) {
		waitTemp = waitSorted;
		waitSorted = waitSorted->next;
		delete waitTemp;
	}
}

void login() {
	string username = "";
	string password = "";
	bool enter = true;

	if (user != 0) {
		username = "";
		password = "";
		user = 0;
		cout << "You are logged out." << endl;
		system("pause");
	}

	system("cls");
	cout << "Welcome to Klinik Sulaiman! Do you wish to log in? (Enter '1' - Yes / '0' - Exit system) : ";
	cin >> enter;
	cin.ignore();

	if (!enter) {
		cout << "Exiting system.....";
		system("exit");
	}
	else {
		cout << "Enter username : ";
		getline(cin, username);
		cout << "Enter password : ";
		getline(cin, password);

		if (username == "nurse" && password == "nurse123") {
			cout << "You are logged in as nurse." << endl;
			user = 1;
		}
		else if (username == "doctor" && password == "doctor123") {
			cout << "You are logged in as doctor." << endl;
			user = 2;
		}
		else {
			cout << "Invalid login details. Exiting system....." << endl;
		}
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
			cout << "5. Search for patient on waiting list based on Patient ID or Name" << endl;
			cout << "6. Sort waiting list" << endl;
			cout << "0. Logout" << endl;
			cout << "Enter option (0-6) : ";
			cin >> choice;
			cin.ignore();

			valid = ::find(::begin(nurseChoices), ::end(nurseChoices), choice) != ::end(nurseChoices);

			while (!valid || cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Enter option (0-6) : ";
				cin >> choice;
				valid = ::find(::begin(nurseChoices), ::end(nurseChoices), choice) != ::end(nurseChoices);
			}

			switch (choice)
			{
			case 1:
				InsertintoWaitingList();
				break;
			case 2:
				changePriority();
				break; 
			case 3:
				displayWaiting();
				break; 
			case 4:
				InsertintoPatientList();
				break;
			case 5:
				searchWaiting();
				break;
			case 6:
				sortFunction();
				break;
			case 0:
				login();
				break;
			}
		}
		else if (user == 2)
		{
			cout << "Currently logged in as : Doctor " << endl;
			cout << "1. View all patients on original waiting list" << endl;
			cout << "2. Search for patient in history list and modify records" << endl;
			cout << "3. Sort history list" << endl;
			cout << "4. Search for patient based on Sickness or Name" << endl;
			cout << "0. Logout" << endl;
			cout << "Enter option (0-4) : ";
			cin >> choice;
			cin.ignore();

			valid = ::find(::begin(doctorChoices), ::end(doctorChoices), choice) != ::end(doctorChoices);

			while (!valid || cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Enter option (0-4) : ";
				cin >> choice;
				valid = ::find(::begin(doctorChoices), ::end(doctorChoices), choice) != ::end(doctorChoices);
			}

			switch (choice)
			{
			case 1:
				displayWaiting();
				break;
				case 2:
				updateHistory();
				break;
			case 3:
				sortFunction();
				break;
			case 4:
				searchHistory();
				break;
			case 0:
				login();
				break;
			}
		}
	}

}

int main()
{
	HardCode();
	login();
	while (user != 0)
		MainPage(user);
	return 0;
}
