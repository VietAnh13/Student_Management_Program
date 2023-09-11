#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;
bool programExit;

constexpr char INPUT_STUDENT_LIST_FILE_NAME[] = "LIST_STUDENT_INPUT.TXT";
constexpr char ADDITIONAL_INPUT_STUDENT_LIST_FILE_NAME[] = "LIST_STUDENT_INPUT_ADDITIONAL.TXT";


// Define struct student
typedef struct dateOfBirth {
	unsigned int day, month, year;
} dOB;
typedef struct testScore {
	float math, physics, chemistry, literature, english;
	float CPA;
} tS;
struct grade {
	string Major;
	string Class;
};
typedef struct student {
	string ID;
	string name;
	string gender;
	dOB DateOfBirth;
	grade Grade;
	tS score;
} stud;

// Create Linked List and Function
struct Node {
	stud info;
	Node* next;
};
struct List {
	Node* head;
	Node* tail;
};
void Init(List& s)
{
	s.head = s.tail = NULL;
}
bool IsEmpty(List& s) {
	if (s.head == NULL) return true;
	else return false;
}
Node* CreateNode(stud x) {
	Node* p = new Node;
	if (p == NULL) {
		cout << "Not enough memory to allocate !!";
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}
void AddFirst(List& s, Node* p)
{
	if (IsEmpty(s)) {
		s.head = s.tail = p;
	}
	else {
		p->next = s.head;
		s.head = p;
	}
}
void AddLast(List& s, Node* p)
{
	if (IsEmpty(s)) {
		s.head = s.tail = p;
	}
	else {
		s.tail->next = p;
		s.tail = p;
	}
}
void RemoveList(List& s)
{
	Node* p = NULL;
	while (!IsEmpty(s)) {
		p = s.head;
		s.head = s.head->next;
		delete p;
	}
	if (IsEmpty(s)) {
		cout << "|   |------------------------------------------------------------------- " << endl;
		cout << "|   | List is empty";
	}
}


// Format name and check ID input
string FormatName(string a)
{
	bool s = true;
	unsigned int i = 0, j = 0;
	for (i; i < a.length(); i++)
	{
		if (s)
		{
			if (a[i] == ' ') continue;
			if ((a[i] >= 'a') && (a[i] <= 'z'))
				a[i] -= 32;
			s = false;
		}
		else
		{
			if (a[i] == ' ') s = true;
			if ((a[i] >= 'A') && (a[i] <= 'Z'))
				a[i] += 32;
		}
		a[j++] = a[i];
	}
	if (s) {
		j = j - 1;
	}
	a.erase(j);
	return a;
}
bool CheckID(List s, stud x)
{
	Node* p = s.head;
	while (p != NULL) {
		if (x.ID == p->info.ID) {
			return false;
		}
		else p = p->next;
	}
	return true;
}

// Input and Output 
void Input(List& s, stud& x)
{
	do {
		cout << "|   | Enter the student ID:              "; cin.ignore(); cin >> x.ID;
		if (CheckID(s, x));
		else cout << "|   | ID already exists, please check the ID again !" << endl;
	} while (!CheckID(s, x));
	cout << "|   | Enter student name:                "; cin.ignore(); getline(cin, x.name, '\n');
	x.name = FormatName(x.name);
	cout << "|   | Enter Gender (Male/Female):        "; cin >> x.gender;
	cout << "|   | Enter student's date of birth:     "; cin >> x.DateOfBirth.day >> x.DateOfBirth.month >> x.DateOfBirth.year;
	cout << "|   | Enter the major of the student:    "; cin.ignore(); getline(cin, x.Grade.Major, '\n');
	cout << "|   | Enter the class of the student:    "; cin >> x.Grade.Class;
	cout << "|   | Enter Math test scores:            "; cin >> x.score.math;
	cout << "|   | Enter Physics test scores:         "; cin >> x.score.physics;
	cout << "|   | Enter Chemistry test scores:       "; cin >> x.score.chemistry;
	cout << "|   | Enter Literature test scores:      "; cin >> x.score.literature;
	cout << "|   | Enter English test scores:         "; cin >> x.score.english;
	cout << "|---|-------------------------------------------------------------------|" << endl;
}
void InputNew(List& s, stud& x)
{
	do {
		cout << "\t\t\t\t\t\t\t" << "|   | Enter the student ID:              "; cin.ignore(); cin >> x.ID;
		if (CheckID(s, x));
		else cout << "\t\t\t\t\t\t\t" << "|   | ID already exists, please check the ID again !" << endl;
	} while (!CheckID(s, x));
	cout << "\t\t\t\t\t\t\t" << "|   | Enter student name:                "; cin.ignore(); getline(cin, x.name, '\n');
	x.name = FormatName(x.name);
	cout << "\t\t\t\t\t\t\t" << "|   | Enter Gender (Male/Female):        "; cin >> x.gender;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter student's date of birth:     "; cin >> x.DateOfBirth.day >> x.DateOfBirth.month >> x.DateOfBirth.year;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter the major of the student:    "; cin.ignore(); getline(cin, x.Grade.Major, '\n');
	cout << "\t\t\t\t\t\t\t" << "|   | Enter the class of the student:    "; cin >> x.Grade.Class;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter Math test scores:            "; cin >> x.score.math;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter Physics test scores:         "; cin >> x.score.physics;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter Chemistry test scores:       "; cin >> x.score.chemistry;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter Literature test scores:      "; cin >> x.score.literature;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter English test scores:         "; cin >> x.score.english;
	cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
}
float ChangexTenToxFour(float s)
{
	if (s >= 0 && s < 3.995) return 0;
	if (s >= 3.995 && s < 4.995) return 1;
	if (s >= 4.995 && s < 5.495) return 1.5;
	if (s >= 5.495 && s < 6.495) return 2;
	if (s >= 6.495 && s < 6.995) return 2.5;
	if (s >= 6.995 && s < 7.995) return 3;
	if (s >= 7.995 && s < 8.495) return 3.5;
	if (s >= 8.495 && s <= 10) return 4;
	else return -1;
}
float CPA(stud& x)
{
	x.score.CPA = (ChangexTenToxFour(x.score.math) * 4 + ChangexTenToxFour(x.score.physics) * 4 + ChangexTenToxFour(x.score.chemistry) * 2 + ChangexTenToxFour(x.score.literature) * 3 + ChangexTenToxFour(x.score.english) * 3) / 16;
	return x.score.CPA;
}
void OutputFull(stud x)
{
	cout << "|  " << setw(28) << left << x.name;
	cout << "| " << setw(9) << left << x.ID;
	cout << "|  " << setw(3) << left << x.gender;
	cout << "|  " << setw(2) << right << x.DateOfBirth.day << "/" << setw(2) << right << x.DateOfBirth.month << "/" << setw(7) << left << x.DateOfBirth.year;
	cout << "|   " << setw(7) << left << setprecision(2) << fixed << x.score.math;
	cout << "|   " << setw(7) << left << setprecision(2) << fixed << x.score.physics;
	cout << "|   " << setw(7) << left << setprecision(2) << fixed << x.score.chemistry;
	cout << "|   " << setw(7) << left << setprecision(2) << fixed << x.score.literature;
	cout << "|   " << setw(7) << left << setprecision(2) << fixed << x.score.english;
	cout << "|   " << setw(7) << left << setprecision(2) << fixed << CPA(x);
	cout << "|  " << setw(7) << left << x.Grade.Class;
	cout << "|  " << setw(27) << left << x.Grade.Major << "|" << endl;
	cout << "|______|" << "______________________________|" << "__________|" << "_____|" << "_______________|" << "__________|" << "__________|" << "__________|" << "__________|" << "__________|" << "__________|" << "_________|" << "_____________________________|" << endl;
}
int CountStudent(List& s)
{
	Node* p = s.head;
	int i = 0;
	while (p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}
void EnterStudentInfo(List& s, stud& x)
{
	Init(s);
	int n;
	cout << "|   |" << endl;
	cout << "|   | Enter the number of students: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int k = i % 10;
		int q = i % 100;
		string od;
		switch (k)
		{
		case 1:
			if (q == 11) { od = "th"; }
			else od = "st";
			break;
		case 2:
			if (q == 12) { od = "th"; }
			else od = "nd";
			break;
		case 3:
			if (q == 13) { od = "th"; }
			else od = "rd";
			break;
		default:
			od = "th";
			break;
		}
		cout << "|   |" << endl;
		cout << "|   | Enter the information of the " << i << od << " student" << endl;
		Input(s, x);
		Node* p = CreateNode(x);
		AddLast(s, p);
	}
}
void ExportFullInfoOfStudent(List s, stud x)
{
	Node* p = s.head;
	int i = 1;
	cout << " ______" << "_______________________________" << "___________" << "______" << "________________" << "___________" << "___________" << "___________" << "___________" << "___________" << "___________" << "__________" << "______________________________" << endl;
	cout << "|  NO  |" << "             NAME             |" << "    ID    |" << " GEN |" << " DATE OF BIRTH |" << "   MATH   |" << "   PHYS   |" << "   CHEM   |" << "   LITE   |" << "   ENGL   |" << "   *CPA   |" << "  CLASS  |" << "            MAJOR            |" << endl;
	cout << "|______|" << "______________________________|" << "__________|" << "_____|" << "_______________|" << "__________|" << "__________|" << "__________|" << "__________|" << "__________|" << "__________|" << "_________|" << "_____________________________|" << endl;
	while (p != NULL)
	{
		if (p == NULL) break;
		else {
			x = p->info;
			cout << "|      |" << "                              |" << "          |" << "     |" << "               |" << "          |" << "          |" << "          |" << "          |" << "          |" << "          |" << "         |" << "                             |" << endl;
			if (i < 10) {
				cout << "| 000" << setw(2) << left << i;
			}
			if (9 < i && i < 100) {
				cout << "| 00" << setw(3) << left << i;
			}
			if (99 < i && i < 1000) {
				cout << "| 0" << setw(4) << left << i;
			}
			if (999 < i && i < 10000) {
				cout << "| " << setw(5) << left << i;
			}
			OutputFull(x);
			p = p->next;
			i++;
		}
	}
}
void OutputCPA(stud x)
{
	cout << "|  " << setw(28) << left << x.name;
	cout << "| " << setw(9) << left << x.ID;
	cout << "|   " << setw(7) << left << setprecision(2) << fixed << CPA(x);
	cout << "|  " << setw(7) << left << x.Grade.Class;
	cout << "|  " << setw(27) << left << x.Grade.Major << "|" << endl;
	cout << "\t\t\t\t\t" << "|______|" << "______________________________|" << "__________|" << "__________|" << "_________|" << "_____________________________|" << endl;
}
void ExportCPAInfoOfStudent(List s, stud x)
{
	Node* p = s.head;
	int i = 1;
	cout << "\t\t\t\t\t" << " ______" << "_______________________________" << "___________" << "___________" << "__________" << "______________________________" << endl;
	cout << "\t\t\t\t\t" << "|  NO  |" << "             NAME             |" << "    ID    |" << "   *CPA   |" << "  CLASS  |" << "            MAJOR            |" << endl;
	cout << "\t\t\t\t\t" << "|______|" << "______________________________|" << "__________|" << "__________|" << "_________|" << "_____________________________|" << endl;
	while (p != NULL)
	{
		if (p == NULL) break;
		else {
			x = p->info;
			cout << "\t\t\t\t\t" << "|      |" << "                              |" << "          |" << "          |" << "         |" << "                             |" << endl;
			if (i < 10) {
				cout << "\t\t\t\t\t" << "| 000" << setw(2) << left << i;
			}
			if (9 < i && i < 100) {
				cout << "\t\t\t\t\t" << "| 00" << setw(3) << left << i;
			}
			if (99 < i && i < 1000) {
				cout << "\t\t\t\t\t" << "| 0" << setw(4) << left << i;
			}
			if (999 < i && i < 10000) {
				cout << "\t\t\t\t\t" << "| " << setw(5) << left << i;
			}
			OutputCPA(x);
			p = p->next;
			i++;
		}
	}
}

// Load data from file .txt
void ReadDateOfBirth(ifstream& filein, dOB& DOB)
{
	filein >> DOB.day;
	filein.seekg(1, 1);
	filein >> DOB.month;
	filein.seekg(1, 1);
	filein >> DOB.year;
	filein.seekg(2, 1);
}
void ReadGrade(ifstream& filein, grade& GRADE)
{
	getline(filein, GRADE.Class, ',');
	filein.seekg(1, 1);
	getline(filein, GRADE.Major, ',');
	filein.seekg(1, 1);
}
void ReadScore(ifstream& filein, tS& SCORE)
{
	filein >> SCORE.math;
	filein.seekg(1, 1);
	filein >> SCORE.physics;
	filein.seekg(1, 1);
	filein >> SCORE.chemistry;
	filein.seekg(1, 1);
	filein >> SCORE.literature;
	filein.seekg(1, 1);
	filein >> SCORE.english;
}
void InputDataFromFileTXT(ifstream& filein, stud& x)
{
	getline(filein, x.name, ',');
	x.name = FormatName(x.name);
	filein.seekg(1, 1);
	getline(filein, x.ID, ',');
	filein.seekg(1, 1);
	getline(filein, x.gender, ',');
	filein.seekg(1, 1);
	ReadDateOfBirth(filein, x.DateOfBirth);
	ReadGrade(filein, x.Grade);
	ReadScore(filein, x.score);
}
void LoadDataFromFileTXT(List& s, stud& x)
{
	ifstream filein;
	filein.open(INPUT_STUDENT_LIST_FILE_NAME, ios::in);
	Init(s);
	int line;
	filein >> line;
	string firstSpace;
	getline(filein, firstSpace);
	int i = 1;
	while (!filein.eof())
	{
		int percent = (100 * i) / line;
		InputDataFromFileTXT(filein, x);
		Node* p = CreateNode(x);
		AddLast(s, p);
		string space;
		getline(filein, space);
		cout << "\n\n\n";
		cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
		cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|>>>|    (2)  Load data from file .txt                             |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|---|--------------------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   |    Loading data...(" << setw(3) << right << percent << "%)                                     |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|___|______________________________________________________________|" << endl;
		i += 1;
		system("cls");
	}
	filein.close();
}

// Out put data to file .txt
void OutputCPAToFileTXT(ofstream& fileout, stud x)
{
	fileout << setw(26) << left << x.name << ", ";
	fileout << x.ID << ", ";
	fileout << x.Grade.Class << ", ";
	fileout << x.Grade.Major << ", ";
	fileout << setprecision(2) << fixed << CPA(x);
}
void OutputFullToFileTXT(ofstream& fileout, stud x)
{
	fileout << setw(26) << left << x.name << ", ";
	fileout << x.ID << ", ";
	fileout << x.gender << ", ";
	fileout << setw(2) << right << x.DateOfBirth.day << "/" << setw(2) << right << x.DateOfBirth.month << "/" << x.DateOfBirth.year << ", ";
	fileout << x.Grade.Class << ", ";
	fileout << x.Grade.Major << ", ";
	fileout << setprecision(2) << fixed << x.score.math << ", ";
	fileout << setprecision(2) << fixed << x.score.physics << ", ";
	fileout << setprecision(2) << fixed << x.score.chemistry << ", ";
	fileout << setprecision(2) << fixed << x.score.literature << ", ";
	fileout << setprecision(2) << fixed << x.score.english << ", ";
	fileout << setprecision(2) << fixed << CPA(x);
}
void ExportCPAToFileTXT(List s, stud x)
{
	ofstream fileout;
	fileout.open("LIST_CPA_OUTPUT.TXT", ios::out);
	Node* p = s.head;
	while (p != NULL)
	{
		x = p->info;
		OutputCPAToFileTXT(fileout, x);
		fileout << endl;
		p = p->next;
	}
	fileout.close();
}
void ExportFullToFileTXT(List s, stud x)
{
	ofstream fileout;
	fileout.open("LIST_FULL_OUTPUT.TXT", ios::out);
	Node* p = s.head;
	while (p != NULL)
	{
		x = p->info;
		OutputFullToFileTXT(fileout, x);
		fileout << endl;
		p = p->next;
	}
	fileout.close();
}

// Sort Data List
void Swap(stud& x1, stud& x2)
{
	stud x3 = x1;
	x1 = x2;
	x2 = x3;
}
/*
unsigned int CountSpaceInName(stud x)
{
	unsigned int i = 0, j = 0;
	for (i; i < x.name.length(); i++)
	{
		if (x.name[i] == ' ') {
			j += 1;
		}
	}
	return j;
}
unsigned int Pivot(stud x)
{
	unsigned int i = 0, j = 0;
	for (i; i < x.name.length(); i++)
	{
		if (x.name[i] == ' ') {
			j += 1;
			if (j == CountSpaceInName(x)) break;
		}
	}
	return i;
}
string FormatNameToSort(stud x)
{
	unsigned int i = 0, t = Pivot(x), k = 0;
	string a, a1, a2;
	for (i; i < x.name.length(); t++)
	{
		if (i < Pivot(x)) {
			a1[i] = x.name[i];
		}
		if (i == Pivot(x)) {
			break;
		}
		if (i > Pivot(x)) {
			a2[i] = x.name[i];
		}
	}
	a = (a2 + ' ') + a1;
	return a;
}
*/
void SelectionSortID(List& s)
{
	Node* p = s.head, * q, * min;
	while (p != NULL)
	{
		min = p;
		q = p->next;
		while (q != NULL)
		{
			if (q->info.ID < min->info.ID) {
				min = q;
			}
			q = q->next;
		}
		Swap(min->info, p->info);
		p = p->next;
	}

	cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Student list has been sorted by ID !!" << endl;
}
void ArrangeNamesInAlphabeticalOrder(List& s)
{
	Node* p = s.head, * q, * min;
	while (p != NULL)
	{
		min = p;
		q = p->next;
		while (q != NULL)
		{
			if (q->info.name < min->info.name) {
				min = q;
			}
			q = q->next;
		}
		Swap(min->info, p->info);
		p = p->next;
	}

	cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Student list has been sorted by name !!" << endl;
}
void SelectionSortCPA(List& s)
{
	Node* p = s.head, * q, * max;
	while (p != NULL)
	{
		max = p;
		q = p->next;
		while (q != NULL)
		{
			if (CPA(q->info) > CPA(max->info)) {
				max = q;
			}
			q = q->next;
		}
		Swap(max->info, p->info);
		p = p->next;
	}
	cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Student list has been sorted by descending GPA !!" << endl;
}

// Find student
void FindStudentsByID(List s)
{
	Node* p = s.head;
	bool found = false;
	stud x1;
	cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter the Student ID to search: ";
	cin.ignore();
	cin >> x1.ID;
	while (p != NULL)
	{
		if (x1.ID == p->info.ID) {
			found = true;
		}
		if (found) break;
		else {
			p = p->next;
		}
	}
	if (found) {
		cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   | Student ID found" << endl;
		cout << endl;
		cout << " ______" << "_______________________________" << "___________" << "______" << "________________" << "___________" << "___________" << "___________" << "___________" << "___________" << "___________" << "__________" << "______________________________" << endl;
		cout << "|  NO  |" << "             NAME             |" << "    ID    |" << " GEN |" << " DATE OF BIRTH |" << "   MATH   |" << "   PHYS   |" << "   CHEM   |" << "   LITE   |" << "   ENGL   |" << "   *CPA   |" << "  CLASS  |" << "            MAJOR            |" << endl;
		cout << "|______|" << "______________________________|" << "__________|" << "_____|" << "_______________|" << "__________|" << "__________|" << "__________|" << "__________|" << "__________|" << "__________|" << "_________|" << "_____________________________|" << endl;
		cout << "|      |" << "                              |" << "          |" << "     |" << "               |" << "          |" << "          |" << "          |" << "          |" << "          |" << "          |" << "         |" << "                             |" << endl;
		cout << "| 0001 ";
		OutputFull(p->info);
	}
	else {
		cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   | Student ID not found !!!" << endl;
	}
}
void FindStudentsByName(List s)
{
	Node* p = s.head;
	bool found = false;
	stud x1;
	int i = 1;
	cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter the Student Name to search: ";
	cin.ignore();
	getline(cin, x1.name, '\n');
	FormatName(x1.name);
	cout << "\t\t\t\t\t\t\t" << "|   | The name you entered for search has been automatically corrected" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | to the correct form : " << FormatName(x1.name) << endl;
	cout << endl;
	while (p != NULL)
	{
		if (FormatName(x1.name) == p->info.name) {
			found = true;
			if (i == 1) {
				cout << " ______" << "_______________________________" << "___________" << "______" << "________________" << "___________" << "___________" << "___________" << "___________" << "___________" << "___________" << "__________" << "______________________________" << endl;
				cout << "|  NO  |" << "             NAME             |" << "    ID    |" << " GEN |" << " DATE OF BIRTH |" << "   MATH   |" << "   PHYS   |" << "   CHEM   |" << "   LITE   |" << "   ENGL   |" << "   *CPA   |" << "  CLASS  |" << "            MAJOR            |" << endl;
				cout << "|______|" << "______________________________|" << "__________|" << "_____|" << "_______________|" << "__________|" << "__________|" << "__________|" << "__________|" << "__________|" << "__________|" << "_________|" << "_____________________________|" << endl;
			}
			cout << "|      |" << "                              |" << "          |" << "     |" << "               |" << "          |" << "          |" << "          |" << "          |" << "          |" << "          |" << "         |" << "                             |" << endl;
			if (i < 10) {
				cout << "| 000" << setw(2) << left << i;
			}
			if (9 < i && i < 100) {
				cout << "| 00" << setw(3) << left << i;
			}
			OutputFull(p->info);
			p = p->next;
			i++;
		}
		else {
			p = p->next;
		}
	}
	if (!found) {
		cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   | Student not found !!!" << endl;
	}
}
void FindStudentsByClass(List s) {
	Node* p = s.head;
	bool found = false;
	stud x1;
	int i = 1;
	cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter the Student Class to search: ";
	cin.ignore();
	getline(cin, x1.Grade.Class, '\n');
	cout << endl;
	while (p != NULL)
	{
		if (x1.Grade.Class == p->info.Grade.Class) {
			found = true;
			if (i == 1) {
				cout << " ______" << "_______________________________" << "___________" << "______" << "________________" << "___________" << "___________" << "___________" << "___________" << "___________" << "___________" << "__________" << "______________________________" << endl;
				cout << "|  NO  |" << "             NAME             |" << "    ID    |" << " GEN |" << " DATE OF BIRTH |" << "   MATH   |" << "   PHYS   |" << "   CHEM   |" << "   LITE   |" << "   ENGL   |" << "   *CPA   |" << "  CLASS  |" << "            MAJOR            |" << endl;
				cout << "|______|" << "______________________________|" << "__________|" << "_____|" << "_______________|" << "__________|" << "__________|" << "__________|" << "__________|" << "__________|" << "__________|" << "_________|" << "_____________________________|" << endl;
			}
			cout << "|      |" << "                              |" << "          |" << "     |" << "               |" << "          |" << "          |" << "          |" << "          |" << "          |" << "          |" << "         |" << "                             |" << endl;
			if (i < 10) {
				cout << "| 000" << setw(2) << left << i;
			}
			if (9 < i && i < 100) {
				cout << "| 00" << setw(3) << left << i;
			}
			if (99 < i && i < 1000) {
				cout << "| 0" << setw(4) << left << i;
			}
			OutputFull(p->info);
			p = p->next;
			i++;
		}
		else {
			p = p->next;
		}
	}
	if (!found) {
		cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   | No student have class " << x1.Grade.Class << " !!!" << endl;
	}
}
void FindStudentsByCPA(List s)
{
	Node* p = s.head;
	bool found = false;
	stud x1;
	int i = 1;
	cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter the CPA to search: ";
	cin >> x1.score.CPA;
	cout << endl;
	while (p != NULL)
	{
		if (CPA(p->info) >= x1.score.CPA) {
			found = true;
			if (i == 1) {
				cout << " ______" << "_______________________________" << "___________" << "______" << "________________" << "___________" << "___________" << "___________" << "___________" << "___________" << "___________" << "__________" << "______________________________" << endl;
				cout << "|  NO  |" << "             NAME             |" << "    ID    |" << " GEN |" << " DATE OF BIRTH |" << "   MATH   |" << "   PHYS   |" << "   CHEM   |" << "   LITE   |" << "   ENGL   |" << "   *CPA   |" << "  CLASS  |" << "            MAJOR            |" << endl;
				cout << "|______|" << "______________________________|" << "__________|" << "_____|" << "_______________|" << "__________|" << "__________|" << "__________|" << "__________|" << "__________|" << "__________|" << "_________|" << "_____________________________|" << endl;
			}
			cout << "|      |" << "                              |" << "          |" << "     |" << "               |" << "          |" << "          |" << "          |" << "          |" << "          |" << "          |" << "         |" << "                             |" << endl;
			if (i < 10) {
				cout << "| 000" << setw(2) << left << i;
			}
			if (9 < i && i < 100) {
				cout << "| 00" << setw(3) << left << i;
			}
			if (99 < i && i < 1000) {
				cout << "| 0" << setw(4) << left << i;
			}
			OutputFull(p->info);
			p = p->next;
			i++;
		}
		else {
			p = p->next;
		}
	}
	if (!found) {
		cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   | No found student have CPA >= " << x1.score.CPA << " !!!" << endl;
	}
}

// Insert new student
void InsertNewStudent(List& s, stud x)
{
	Node* q = s.head;
	int count = CountStudent(s);
	int i = 1, t;
	do {
		cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   | Choose a position to insert students: ";
		cin >> t;
		if (t < 1 || t > count + 1) {
			cout << "\t\t\t\t\t\t\t" << "|   | Insert position is invalid, please select another insertion position !!" << endl;
		}
	} while (t < 1 || t > count + 1);
	InputNew(s, x);
	Node* p = CreateNode(x);
	if (t == 1) {
		AddFirst(s, p);
	}
	if (t == count + 1) {
		AddLast(s, p);
	}
	if (t > 1 && t < count + 1) {
		while (i != t - 1)
		{
			i++;
			q = q->next;
		}
		p->next = q->next;
		q->next = p;
	}
	cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Students have been added successfully !!" << endl;
}
// Add by entered
void AddByEntered(List& s, stud& x)
{
	int n;
	cout << "\t\t\t\t\t\t\t" << "|   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter the number of students: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int k = i % 10;
		int q = i % 100;
		string od;
		switch (k)
		{
		case 1:
			if (q == 11) { od = "th"; }
			else od = "st";
			break;
		case 2:
			if (q == 12) { od = "th"; }
			else od = "nd";
			break;
		case 3:
			if (q == 13) { od = "th"; }
			else od = "rd";
			break;
		default:
			od = "th";
			break;
		}
		cout << "\t\t\t\t\t\t\t" << "|   |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   | Enter the information of the " << i << od << " student" << endl;
		InputNew(s, x);
		Node* p = CreateNode(x);
		AddLast(s, p);
	}
}
// Add by load file .txt
void AddByLoadFileTXT(List& s, stud& x)
{
	ifstream filein;
	filein.open(ADDITIONAL_INPUT_STUDENT_LIST_FILE_NAME, ios::in);
	int line;
	filein >> line;
	string firstSpace;
	getline(filein, firstSpace);
	int i = 1;
	while (!filein.eof())
	{
		int percent = (100 * i) / line;
		InputDataFromFileTXT(filein, x);
		Node* p = CreateNode(x);
		AddLast(s, p);
		string space;
		getline(filein, space);
		cout << "\n\n\n";
		cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
		cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|>>>|    (2)  Load data from file .txt                             |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|---|--------------------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   |    Loading data...(" << setw(3) << right << percent << "%)                                     |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
		cout << "\t\t\t\t\t\t\t" << "|___|______________________________________________________________|" << endl;
		i += 1;
		system("cls");
	}
	filein.close();
}

// Remove student by ID
void RemoveStudentByID(List& s, stud x)
{
	Node* virtualNode = CreateNode(x);
	virtualNode->next = s.head;
	s.head = virtualNode;
	Node* p = s.head;
	Node* q;
	bool found = false;
	stud x1;
	cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter the Student ID to delete: ";
	cin >> x1.ID;
	while (p->next != NULL)
	{
		q = p->next;
		if (q->info.ID == x1.ID) {
			p->next = q->next;
			delete q;
			found = true;
			cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
			cout << "\t\t\t\t\t\t\t" << "|   | Successfully deleted the ID !!!" << endl;
			break;
		}
		else {
			p = p->next;
		}
	}
	if (!found) {
		cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   | ID not found !!!" << endl;
	}
	s.head = s.head->next;
	delete virtualNode;
}
// Remove student at position 
void DeleteInfoStudent(List& s, stud x)
{
	int count = CountStudent(s);
	Node* virtualNode = CreateNode(x);
	virtualNode->next = s.head;
	s.head = virtualNode;
	Node* p = s.head, * q;
	int i = 1, t;
	char yon;
	do {
		cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   | Select the delete loacation: ";
		cin >> t;
		if (t < 1 || t > count) {
			cout << "\t\t\t\t\t\t\t" << "|   | Delete location is invalid, please select a delete location again !!" << endl;
		}
	} while (t < 1 || t > count);
	cout << "\t\t\t\t\t\t\t" << "|   | Do you really want to delete this loacation (Y/N) ?  ";
	cin >> yon;
	if (yon == 'Y' || yon == 'y') {
		while (p->next != NULL)
		{
			if (i == t) {
				q = p->next;
				p->next = q->next;
				delete(q);
				cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
				cout << "\t\t\t\t\t\t\t" << "|   | Successfully deleted the location " << t << endl;
				break;
			}
			else {
				p = p->next;
				i += 1;
			}
		}
		s.head = s.head->next;
		delete virtualNode;
	}
}
// Remove all students has CPA <
void RemoveStudentsHaveCPA(List& s, stud x)
{
	Node* virtualNode = CreateNode(x);
	virtualNode->next = s.head;
	s.head = virtualNode;
	Node* p = s.head;
	Node* q;
	bool found = false;
	stud x1;
	cout << "\t\t\t\t\t\t\t" << "|   |-----------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Remove students from the list whose CPA is lower than the entered CPA " << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter CPA : ";
	cin >> x1.score.CPA;
	while (p->next != NULL)
	{
		q = p->next;
		if (CPA(q->info) < x1.score.CPA) {
			p->next = q->next;
			delete q;
			found = true;
		}
		else {
			p = p->next;
		}
	}
	if (found) {
		cout << "\t\t\t\t\t\t\t" << "|   |-----------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   | Successfully deleted all students has CPA < " << x1.score.CPA << " !!!" << endl;
	}
	else {
		cout << "\t\t\t\t\t\t\t" << "|   |-----------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t" << "|   | No students has CPA < " << x1.score.CPA << " !!!" << endl;
	}
	s.head = s.head->next;
	delete virtualNode;
}



// Input & Main Menu
void InputMenu()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|                      INPUT MENU                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (1)  Enter students list                               |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (2)  Load data from file .txt                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (0)  EXIT PROGRAM                                      |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |----------------------------------------------------------|   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | * NOTE *                                                 |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter the number to select the corresponding function    |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenu() {
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|                       MAIN MENU                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (1)  Print students list                               |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (2)  Sort students list                                |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (3)  Find students                                     |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (4)  Add student into the list                         |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (5)  Remove student out the list                       |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (6)  Export data list to file .txt                     |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (0)  GO BACK INPUT MENU                                |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |----------------------------------------------------------|   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | * NOTE *                                                 |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter the number to select the corresponding function    |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}

// Input menu funtion 1
void InputMenu1Start1()
{
	cout << "\t\t\t\t" << " _________________________________________________________________________________________________________________________" << endl;
	cout << "\t\t\t\t" << "|                                                                                                                         |" << endl;
	cout << "\t\t\t\t" << "|                                         o0o     STUDENT MANAGEMENT PROGRAM     o0o                                      |" << endl;
	cout << "\t\t\t\t" << "|_________________________________________________________________________________________________________________________|" << endl;
	cout << "\t\t\t\t" << "|   |                                                                                                                     |" << endl;
	cout << "\t\t\t\t" << "|   |                                                                                                                     |" << endl;
	cout << "\t\t\t\t" << "|>>>|                                                 ENTER STUDENTS LIST                                                 |" << endl;
	cout << "\t\t\t\t" << "|   |                                                                                                                     |" << endl;
	cout << "\t\t\t\t" << "|---|---------------------------------------------------------------------------------------------------------------------|" << endl;
	cout << "\t\t\t\t" << "|   | * SOME NOTES BEFORE YOU ENTER DATA *                                                                                |" << endl;
	cout << "\t\t\t\t" << "|   |                                                                                                                     |" << endl;
	cout << "\t\t\t\t" << "|   | (1) The input ID must be 8 consecutive characters, for example: the valid ID is 20181234; and the following ID      |" << endl;
	cout << "\t\t\t\t" << "|   |     must not be the same for all previous IDs, if the ID already exists, you will have to enter another ID.         |" << endl;
	cout << "\t\t\t\t" << "|   |                                                                                                                     |" << endl;
	cout << "\t\t\t\t" << "|   | (2) The name you entered will automatically convert to correct form.                                                |" << endl;
	cout << "\t\t\t\t" << "|   |     For example: Your name input: | buI   ViET    anH  |  will convert to  |Bui Viet Anh|                           |" << endl;
	cout << "\t\t\t\t" << "|   |                                                                                                                     |" << endl;
	cout << "\t\t\t\t" << "|   | (3) The date of birth is entered respectively from day to month then year, and between them is separated by the     |" << endl;
	cout << "\t\t\t\t" << "|   |     character 'space'; (Note: the number entered must be an integer).                                               |" << endl;
	cout << "\t\t\t\t" << "|   |     For example: 12 12 2000                                                                                         |" << endl;
	cout << "\t\t\t\t" << "|   |                                                                                                                     |" << endl;
	cout << "\t\t\t\t" << "|   | (4) The mandatory class name is 5 consecutive characters, with the first 2 characters representing an abbreviated   |" << endl;
	cout << "\t\t\t\t" << "|   |     major code, the last 2 characters are the class numbers, separated by the '-' character                         |" << endl;
	cout << "\t\t\t\t" << "|   |     For example: ET-07                                                                                              |" << endl;
	cout << "\t\t\t\t" << "|   |                                                                                                                     |" << endl;
	cout << "\t\t\t\t" << "|   | (5) You can enter subject scores as real numbers; For example: 9.75; 10; 6.96; etc                                  |" << endl;
	cout << "\t\t\t\t" << "|   |                                                                                                                     |" << endl;
	cout << "\t\t\t\t" << "|---|---------------------------------------------------------------------------------------------------------------------|" << endl;
	cout << "\t\t\t\t" << "|   |         ***     THE FOLLOWING IS A STANDARD FORMAT FOR ENTERING INFORMATION REQUIRED FOR A STUDENT     ***          |" << endl;
	cout << "\t\t\t\t" << "|   |                                                                                                                     |" << endl;
	cout << "\t\t\t\t" << "|   |                        _________________________________________________________________                            |" << endl;
	cout << "\t\t\t\t" << "|   |                       |                                                                 |                           |" << endl;
	cout << "\t\t\t\t" << "|   |                       | Enter the student ID :             20181234                     |                           |" << endl;
	cout << "\t\t\t\t" << "|   |                       | Enter student name:                buI   ViET    anH            |                           |" << endl;
	cout << "\t\t\t\t" << "|   |                       | Enter Gender (Male/Female):        M                            |                           |" << endl;
	cout << "\t\t\t\t" << "|   |                       | Enter student's date of birth:     12 12 2000                   |                           |" << endl;
	cout << "\t\t\t\t" << "|   |                       | Enter the grade of the student:    Vien Dien Tu - Vien Thong    |                           |" << endl;
	cout << "\t\t\t\t" << "|   |                       | Enter the class of the student:    ET-07                        |                           |" << endl;
	cout << "\t\t\t\t" << "|   |                       | Enter Math test scores:            8.96                         |                           |" << endl;
	cout << "\t\t\t\t" << "|   |                       | Enter Physics test scores:         9.69                         |                           |" << endl;
	cout << "\t\t\t\t" << "|   |                       | Enter Chemistry test scores:       8.85                         |                           |" << endl;
	cout << "\t\t\t\t" << "|   |                       | Enter Literature test scores:      7.26                         |                           |" << endl;
	cout << "\t\t\t\t" << "|   |                       | Enter English test scores:         8.15                         |                           |" << endl;
	cout << "\t\t\t\t" << "|   |                       |_________________________________________________________________|                           |" << endl;
	cout << "\t\t\t\t" << "|   |                                                                                                                     |" << endl;
	cout << "\t\t\t\t" << "|   |                                                                                                                     |" << endl;
	cout << "\t\t\t\t" << "|   | If you are ready to enter data, press 'Enter' to start typing                                                       |" << endl;
	cout << "\t\t\t\t" << "|___|_____________________________________________________________________________________________________________________|" << endl;
	cout << "\t\t\t\t" << "|                                                                                    Program write by @VAnh               |" << endl;
	cout << "\t\t\t\t" << "|_________________________________________________________________________________________________________________________|" << endl;
	cout << endl;
}
void InputMenu1Start2()
{
	cout << " _______________________________________________________________________" << endl;
	cout << "|   |                                                                   |" << endl;
	cout << "|   |          o0o       STUDENT MANAGEMENT PROGRAM       o0o           |" << endl;
	cout << "|___|___________________________________________________________________|" << endl;
	cout << "|   |                                                                   |" << endl;
	cout << "|   |                                                                   |" << endl;
	cout << "|>>>|                        ENTER STUDENTS LIST                        |" << endl;
	cout << "|   |                                                                   |" << endl;
	cout << "|---|-------------------------------------------------------------------|" << endl;
}
void Menu1InputEnd()
{
	cout << "|   |                                                                   |" << endl;
	cout << "|   |                                                                   |" << endl;
	cout << "|   |                                                                   |" << endl;
	cout << "|___|___________________________________________________________________|" << endl;
	cout << endl;
}
// Input menu function 2
void InputMenu2Start()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|    (2)  Load data from file .txt                             |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |    Loading data...(  0%)                                     |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|______________________________________________________________|" << endl;
}
void InputMenu2Finish()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|    (2)  Load data from file .txt                             |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |    Successful load data !!                                   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|______________________________________________________________|" << endl;
	cout << endl;
}
// Input warning function
void InputMenuWarning() {
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|                   WARNING MENU !!!                           |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|--------------------------------------------------------------|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |    Make sure you have saved the data to file !!!             |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                              |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |--------------------------------------------------------------|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | * NOTE *                                                     |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Press Y(yes) to continue                                     |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Press N(no) to return to the main menu                       |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|______________________________________________________________|" << endl;
	cout << endl;
	cout << endl;
}

// Main menu funtion 1
void MainMenuFunction1()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|                   PRINT STUDENTS LIST                    |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (1)  Print 'FULL' students list                        |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (2)  Print '*CPA' students list                        |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (0)  GO BACK MAIN MENU                                 |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |----------------------------------------------------------|   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | * NOTE *                                                 |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter the number to select the corresponding function    |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenuFunction1F1()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                   PRINT STUDENTS LIST                    |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|   (1)  Print 'FULL' students list                        |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenuFunction1F2()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                   PRINT STUDENTS LIST                    |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|   (2)  Print '*CPA' students list                        |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
// Main menu funtion 2
void MainMenuFuntion2()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|                        SORT LIST                         |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (1)  Sort by ascending ID                              |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (2)  Arrange names in alphabetical order               |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (3)  Sort by descending CPA                            |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (0)  GO BACK MAIN MENU                                 |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |----------------------------------------------------------|   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | * NOTE *                                                 |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter the number to select the corresponding function    |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenuFunction2F1()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                        SORT LIST                         |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|   (1)  Sort by ascending ID                              |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenuFunction2F2()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                        SORT LIST                         |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|   (2)  Arrange names in alphabetical order               |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenuFunction2F3()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                        SORT LIST                         |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|   (3)  Sort by descending CPA                            |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
// Main menu funtion 3
void MainMenuFunction3()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|                       FIND STUDENT                       |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (1)  Find students by ID                               |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (2)  Find students by name                             |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (3)  Find students by class                            |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (4)  Find students by CPA (>=)                         |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (0)  GO BACK MAIN MENU                                 |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |----------------------------------------------------------|   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | * NOTE *                                                 |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter the number to select the corresponding function    |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenuFunction3F1()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                       FIND STUDENT                       |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|   (1)  Find students by ID                               |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenuFunction3F2()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                       FIND STUDENT                       |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|   (2)  Find students by name                             |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenuFunction3F3()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                       FIND STUDENT                       |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|   (3)  Find students by class                            |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenuFunction3F4()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                       FIND STUDENT                       |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|   (4)  Find students by CPA (>=)                         |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
// Main menu funtion 4
void MainMenuFunction4()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|                       ADD STUDENTS                       |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (1)  Add student to the selected position              |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (2)  Add more students to the list                     |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (0)  GO BACK MAIN MENU                                 |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |----------------------------------------------------------|   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | * NOTE *                                                 |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter the number to select the corresponding function    |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenuFunction4F1()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                       ADD STUDENTS                       |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|   (1)  Add student to the selected position              |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenuFunction4F2()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|                         ADD MORE                         |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (1)  Add by entered info student                       |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (2)  Add load file .txt                                |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (0)  GO BACK ADD STUDENTS MENU                         |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |----------------------------------------------------------|   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | * NOTE *                                                 |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter the number to select the corresponding function    |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenuFunction4F2F1()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                         ADD MORE                         |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|   (1)  Add by entered info student                       |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenuFunction4F2F2()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                         ADD MORE                         |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|   (2)  Add load file .txt                                |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
// Main menu funtion 5
void MainMenuFunction5()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|                     REMOVE STUDENTS                      |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (1)  Remove student at position                        |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (2)  Remove student by ID                              |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (3)  Remove student have CPA (<)                       |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (0)  GO BACK MAIN MENU                                 |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |----------------------------------------------------------|   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | * NOTE *                                                 |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter the number to select the corresponding function    |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenuFunction5F1()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                     REMOVE STUDENTS                      |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|   (1)  Remove student at position                        |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenuFunction5F2()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                     REMOVE STUDENTS                      |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|   (2)  Remove student by ID                              |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenuFunction5F3()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                     REMOVE STUDENTS                      |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|   (3)  Remove student have CPA (<)                       |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
// Main menu funtion 6
void MainMenuFunction6()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|                       EXPORT DATA                        |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (1)  Export *CPA data to file .txt                     |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (2)  Export 'FULL' info to file .txt                   |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |   (0)  GO BACK MAIN MENU                                 |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |----------------------------------------------------------|   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | * NOTE *                                                 |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Enter the number to select the corresponding function    |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenuFunction6F1()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                       EXPORT DATA                        |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|   (1)  Export *CPA data to file .txt                     |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void MainMenuFunction6F2()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                       EXPORT DATA                        |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|---|----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|>>>|   (2)  Export 'FULL' info to file .txt                   |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}


void Logic(List s, stud x)
{
	bool entered = false;
	bool entered2 = false;
	programExit = false;
	int kIM, kMM; // key choose in InputMenu and MainMenu
	do
	{
		if (entered2)
		{
			MainMenu();
			do {
				cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
				cout << "\t\t\t\t\t\t\t" << "|   | Enter your selection: ";
				cin >> kMM;
				if (kMM < 0 || kMM > 6)
				{
					cout << "\t\t\t\t\t\t\t" << "|   | The selection is not available. Please choose again!           " << endl;
					cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
					continue;
				}
				else cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
				cout << "\t\t\t\t\t\t\t";
				system("PAUSE");
			} while (kMM < 0 || kMM > 6);
			system("cls");
			switch (kMM)
			{
			case 0: entered2 = false; break;
			case 1:
				int kMM1;
				MainMenuFunction1();
				do {
					cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t" << "|   | Enter your selection: ";
					cin >> kMM1;
					if (kMM1 < 0 || kMM1 > 2)
					{
						cout << "\t\t\t\t\t\t\t" << "|   | The selection is not available. Please choose again!           " << endl;
						cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
						continue;
					}
					else cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
				} while (kMM1 < 0 || kMM1 > 2);
				system("cls");
				switch (kMM1)
				{
				case 0: break;
				case 1:
					MainMenuFunction1F1();
					ExportFullInfoOfStudent(s, x);
					cout << endl << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
					system("cls");
					break;
				case 2:
					MainMenuFunction1F2();
					ExportCPAInfoOfStudent(s, x);
					cout << endl << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
					system("cls");
					break;
				}
				break;
			case 2:
				int kMM2;
				MainMenuFuntion2();
				do {
					cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t" << "|   | Enter your selection: ";
					cin >> kMM2;
					if (kMM2 < 0 || kMM2 > 3)
					{
						cout << "\t\t\t\t\t\t\t" << "|   | The selection is not available. Please choose again!           " << endl;
						cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
						continue;
					}
					else cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
				} while (kMM2 < 0 || kMM2 > 3);
				system("cls");
				switch (kMM2)
				{
				case 0: break;
				case 1:
					MainMenuFunction2F1();
					SelectionSortID(s);
					cout << endl << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
					system("cls");
					break;
				case 2:
					MainMenuFunction2F2();
					ArrangeNamesInAlphabeticalOrder(s);
					cout << endl << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
					system("cls");
					break;
				case 3:
					MainMenuFunction2F3();
					SelectionSortCPA(s);
					cout << endl << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
					system("cls");
					break;
				}
				break;
			case 3:
				int kMM3;
				MainMenuFunction3();
				do {
					cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t" << "|   | Enter your selection: ";
					cin >> kMM3;
					if (kMM3 < 0 || kMM3 > 4)
					{
						cout << "\t\t\t\t\t\t\t" << "|   | The selection is not available. Please choose again!           " << endl;
						cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
						continue;
					}
					else cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
				} while (kMM3 < 0 || kMM3 > 4);
				system("cls");
				switch (kMM3)
				{
				case 0: break;
				case 1:
					MainMenuFunction3F1();
					FindStudentsByID(s);
					cout << endl << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
					system("cls");
					break;
				case 2:
					MainMenuFunction3F2();
					FindStudentsByName(s);
					cout << endl << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
					system("cls");
					break;
				case 3:
					MainMenuFunction3F3();
					FindStudentsByClass(s);
					cout << endl << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
					system("cls");
					break;
				case 4:
					MainMenuFunction3F4();
					FindStudentsByCPA(s);
					cout << endl << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
					system("cls");
					break;
				}
				break;
			case 4:
				int kMM4;
				MainMenuFunction4();
				do {
					cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t" << "|   | Enter your selection: ";
					cin >> kMM4;
					if (kMM4 < 0 || kMM4 > 2)
					{
						cout << "\t\t\t\t\t\t\t" << "|   | The selection is not available. Please choose again!           " << endl;
						cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
						continue;
					}
					else cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
				} while (kMM4 < 0 || kMM4 > 2);
				system("cls");
				switch (kMM4)
				{
				case 0: break;
				case 1:
					MainMenuFunction4F1();
					InsertNewStudent(s, x);
					cout << endl << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
					system("cls");
					break;
				case 2:
					int kMM42;
					bool function4F2 = false;
					do
					{
						MainMenuFunction4F2();
						do {
							cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
							cout << "\t\t\t\t\t\t\t" << "|   | Enter your selection: ";
							cin >> kMM42;
							if (kMM42 < 0 || kMM42 > 2)
							{
								cout << "\t\t\t\t\t\t\t" << "|   | The selection is not available. Please choose again!           " << endl;
								cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
								continue;
							}
							else cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
							cout << "\t\t\t\t\t\t\t";
							system("PAUSE");
						} while (kMM42 < 0 || kMM42 > 2);
						system("cls");
						switch (kMM42)
						{
						case 0: function4F2 = true; break;
						case 1:
							MainMenuFunction4F2F1();
							AddByEntered(s, x);
							cout << endl << endl;
							cout << "\t\t\t\t\t\t\t";
							system("PAUSE");
							system("cls");
							break;
						case 2:
							MainMenuFunction4F2F2();
							AddByLoadFileTXT(s, x);
							InputMenu2Finish();
							cout << endl << endl;
							cout << "\t\t\t\t\t\t\t";
							system("PAUSE");
							system("cls");
							break;
						}
					} while (function4F2);
					break;
				}
				break;
			case 5:
				int kMM5;
				MainMenuFunction5();
				do {
					cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t" << "|   | Enter your selection: ";
					cin >> kMM5;
					if (kMM5 < 0 || kMM5 > 3)
					{
						cout << "\t\t\t\t\t\t\t" << "|   | The selection is not available. Please choose again!           " << endl;
						cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
						continue;
					}
					else cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
				} while (kMM5 < 0 || kMM5 > 3);
				system("cls");
				switch (kMM5)
				{
				case 0: break;
				case 1:
					MainMenuFunction5F1();
					DeleteInfoStudent(s, x);
					cout << endl << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
					system("cls");
					break;
				case 2:
					MainMenuFunction5F2();
					RemoveStudentByID(s, x);
					cout << endl << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
					system("cls");
					break;
				case 3:
					MainMenuFunction5F3();
					RemoveStudentsHaveCPA(s, x);
					cout << endl << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
					system("cls");
					break;
				}
				break;
			case 6:
				int kMM6;
				MainMenuFunction6();
				do {
					cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t" << "|   | Enter your selection: ";
					cin >> kMM6;
					if (kMM6 < 0 || kMM6 > 2)
					{
						cout << "\t\t\t\t\t\t\t" << "|   | The selection is not available. Please choose again!           " << endl;
						cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
						continue;
					}
					else cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
				} while (kMM6 < 0 || kMM6 > 2);
				system("cls");
				switch (kMM6)
				{
				case 0: break;
				case 1:
					MainMenuFunction6F1();
					ExportCPAToFileTXT(s, x);
					cout << endl << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
					system("cls");
					break;
				case 2:
					MainMenuFunction6F2();
					ExportFullToFileTXT(s, x);
					cout << endl << endl;
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
					system("cls");
					break;
				}
				break;
			}
		}
		else {
			InputMenu();
			do {
				cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
				cout << "\t\t\t\t\t\t\t" << "|   | Enter your selection: ";
				cin >> kIM;
				if (kIM < 0 || kIM > 2)
				{
					cout << "\t\t\t\t\t\t\t" << "|   | The selection is not available. Please choose again!           " << endl;
					cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
					continue;
				}
				else cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
				cout << "\t\t\t\t\t\t\t";
				system("PAUSE");
			} while (kIM < 0 || kIM > 2);
			system("cls");
			switch (kIM)
			{
			case 0: programExit = true; break;
			case 1:
				if (entered) {
					char yon1;
					InputMenuWarning();
					cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t" << "|   | Are you sure you want to continue?: ";
					cin >> yon1;
					if (yon1 == 'y' || yon1 == 'Y') {
						RemoveList(s);
						system("cls");
						entered = false;
					}
					else {
						entered2 = true;
						system("cls");
						break;
					}
				}
				else {
					InputMenu1Start1();
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
					system("cls");
					InputMenu1Start2();
					EnterStudentInfo(s, x);
					Menu1InputEnd();
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
					system("cls");
					entered = true;
					entered2 = true;
				}
				break;
			case 2:
				if (entered) {
					char yon2;
					InputMenuWarning();
					cout << "\t\t\t\t\t\t\t" << "|   |-------------------------------------------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t" << "|   | Are you sure you want to continue?: ";
					cin >> yon2;
					if (yon2 == 'y' || yon2 == 'Y') {
						RemoveList(s);
						system("cls");
						entered = false;
					}
					else {
						entered2 = true;
						system("cls");
						break;
					}
				}
				else {
					InputMenu2Start();
					Sleep(500);
					system("cls");
					LoadDataFromFileTXT(s, x);
					InputMenu2Finish();
					cout << "\t\t\t\t\t\t\t";
					system("PAUSE");
					system("cls");
					entered = true;
					entered2 = true;
				}
				break;
			}
		}
	} while (!programExit);
}


void Start()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |               WELCOME TO THE PROGRAM  !!!                |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Version: 2.0 update03052020                              |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Program write by@VAnh                                    |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}
void Finish()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t" << " __________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|          o0o       STUDENT MANAGEMENT PROGRAM       o0o          |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|                                                                  |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|__________________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |            THANKS FOR USING THE PROGRAM  !!!             |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |                                                          |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   |----------------------------------------------------------|---|" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Version: 2.0 update03052020                              |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|   | Program write by@VAnh                                    |   |" << endl;
	cout << "\t\t\t\t\t\t\t" << "|___|__________________________________________________________|___|" << endl;
	cout << endl;
	cout << endl;
}


int main()
{
	List s{};
	stud x;
	Start();
	cout << "\t\t\t\t\t\t\t";
	system("PAUSE");
	system("cls");
	Logic(s, x);
	cout << endl;
	RemoveList(s);
	cout << endl;
	system("cls");
	Finish();
	cout << "\t\t\t\t\t\t\t";
	system("PAUSE");
	return 1;
}