#include	<iostream>
#include	<cstdlib>
#include	<cstdio>
#include    <fstream>
#include    <string>
#include	"List.h"
#include    "LibStudent.h"
#include    "LibBook.h"

#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

int main();
bool ReadFile(string, List *);
bool DeleteRecord(List *, char *);
bool Display(List *, int, int);
bool InsertBook(string, List *);
bool SearchStudent(List *, char *id, LibStudent &);
bool computeAndDisplayStatistics(List *);
bool printStuWithSameBook(List *, char *);
bool displayWarnedStudent(List *, List *, List *);
int menu();

List list, type1, type2;
string input = "";
char *id, *callNum;
int choice1, choice2;


int main() {

	LibStudent student;

	int choice = menu();

	switch (choice) {
	case 1:

		system("cls");

		cout << "\t**************************************************" << endl;
		cout << "\t|                                                |" << endl;
		cout << "\t|                    READ FILE                   |" << endl;
		cout << "\t|                                                |" << endl;
		cout << "\t**************************************************" << endl;

		if (ReadFile("student.txt", &list) == 0)
			cout << "\n\tOpps! Fail to open the file. Please try again.\n\n\t";

		system("pause");
		system("cls");
		main();

		break;

	case 2:

		system("cls");

		cout << "\t**************************************************" << endl;
		cout << "\t|                                                |" << endl;
		cout << "\t|                   DELETE RECORD                |" << endl;
		cout << "\t|                  Example:1300899               |" << endl;
		cout << "\t|                                                |" << endl;
		cout << "\t**************************************************" << endl;

		cout << "\n\tPlease enter the student id of the student that you want to delete: ";
		cin >> input;
		id = &input[0];

		if (DeleteRecord(&list, id) == 0)
			cout << "\n\tUnsuccessfully delete the record! Please try again.\n\n\t";
		else
			cout << "\n\tSuccessfully delete the student record with student ID " << input << ".\n\n\t";

		system("pause");
		system("cls");
		main();

		break;

	case 3:

		system("cls");

		cout << "\t**************************************************" << endl;
		cout << "\t|                                                |" << endl;
		cout << "\t|                SEARCH RECORD                   |" << endl;
		cout << "\t|               Example:1300899                  |" << endl;
		cout << "\t|                                                |" << endl;
		cout << "\t**************************************************" << endl;
		cout << "\n\tPlease enter the student id of the student that you want to search: ";
		cin >> input;
		id = &input[0];

		if (SearchStudent(&list, id, student) == 1) {
			student.print(cout);
			cout << "\n\tThese are the Data of the student with student ID " << input << ".\n\n\t";
		}
		else
			cout << "\n\t ID record Cannot be found !!!! \n\n\t";

		system("pause");
		system("cls");
		main();

		break;

	case 4:

		system("cls");

		cout << "\t**************************************************" << endl;
		cout << "\t|                                                |" << endl;
		cout << "\t|                    INSERT BOOK                 |" << endl;
		cout << "\t|                                                |" << endl;
		cout << "\t**************************************************" << endl;

		if (InsertBook("book.txt", &list) == 1)
			cout << "\n\tBooks inserted successfully to student list.\n\n\t";
		else
			cout << "\n\tUnsuccessfully insert the book to student list! Please try again.\n\n\t";

		system("pause");
		system("cls");
		main();

		break;

	case 5:

		system("cls");

		cout << "\t**************************************************" << endl;
		cout << "\t|                                                |" << endl;
		cout << "\t|                    Display                     |" << endl;
		cout << "\t|                                                |" << endl;
		cout << "\t**************************************************" << endl;

		cout << "\n\tWhere do you want to display the output (1:file / 2:screen): ";
		cin >> choice1;
		cout << "\n\tDo you want to display the book info (1:yes / 2:no): ";
		cin >> choice2;

		if (Display(&list, choice1, choice2) == 1)
			cout << "\n\tSuccessfully display output\n\n\n\t";
		else
			cout << "\n\tSomethings is wrong.\n\n\n\t";

		system("pause");
		system("cls");
		main();

		break;

	case 6:

		system("cls");

		cout << "\t**************************************************" << endl;
		cout << "\t|                                                |" << endl;
		cout << "\t|        COMPUTE AND DISPLAY STATISTICS          |" << endl;
		cout << "\t|                                                |" << endl;
		cout << "\t**************************************************\n\n";

		if (computeAndDisplayStatistics(&list) == 0)
			cout << "\n\tUnsuccessfully compute and display statistics! Please try again.\n\n\t";

		system("pause");
		system("cls");
		main();

		break;

	case 7:

		system("cls");

		cout << "\t**************************************************" << endl;
		cout << "\t|                                                |" << endl;
		cout << "\t|             STUDENT WITH SAME BOOK             |" << endl;
		cout << "\t|             Example:QA76.73.C153S26            |" << endl;
		cout << "\t|                                                |" << endl;
		cout << "\t**************************************************" << endl;
		cout << "\n\tPlease enter the student id of the student that you want to search: ";
		cin >> input;
		callNum = &input[0];

		if (printStuWithSameBook(&list, callNum) == 0)
			cout << "\n\tUnsuccessfully get the student with same book! Please try again.\n\n\t";

		system("pause");
		system("cls");
		main();

		break;

	case 8:

		system("cls");

		cout << "\t**************************************************" << endl;
		cout << "\t|                                                |" << endl;
		cout << "\t|             DISPLAY WARNED STUDENT             |" << endl;
		cout << "\t|                                                |" << endl;
		cout << "\t**************************************************\n\n";

		if (displayWarnedStudent(&list, &type1, &type2) == 0)
			cout << "\n\tUnsuccessfully display warned student! Please try again.\n\n\t";

		system("pause");
		system("cls");
		main();

		break;

	case 9:

		system("cls");

		cout << "\tAre you sure you want to exit? (Yes=1, No=0) : ";
		cin >> input;

		if (input == "1") {
			cout << "\n\n\tThank you and have a nice day ^o^\n\n";
			exit(0);
		}
		else {
			system("cls");
			main();
		}

	default:
		cout << "\n\n";
		cout << "\tPlease enter the number in the Menu (1-9).\n\n\t";
		system("pause");
		system("cls");
		main();
	}

	cout << "\n\n";
	system("pause");
	return 0;
}

bool ReadFile(string filename, List *list) {

	int count = 0, b = 1;  //int b is used to test the duplicate record
	LibStudent student;
	string temp;
	ifstream infile;
	string ID[10000];     //save the stu_ID in student.txt and assume that there are max 10000 student.
	infile.open(filename);

	if (infile.fail())
		return false;

	//read the file
	while (!infile.eof()) {

		for (int i = 0; i < 3; i++)
			infile >> temp;
		infile >> student.id;

		for (int i = 0; i < 2; i++)
			infile >> temp;
		getline(infile, temp);
		strcpy(student.name, temp.c_str());

		for (int i = 0; i < 2; i++)
			infile >> temp;
		infile >> student.course;

		for (int i = 0; i < 3; i++)
			infile >> temp;
		infile >> student.phone_no;

		//Ensure there is no duplicate record of student stored in the list
		if (count == 0) {
			list->insert(student);
			ID[count] = student.id;
			count++;
		}
		else {

			for (int a = 0; a <= count; a++) {

				if (ID[a] == student.id) {
					b = 0;   //b equal to 0 means there has duplicate record.
					cout << "\n\tThe Duplicate record of the student with ID: " << student.id << " is found and ignored.\n";
				}
			}
			if (b != 0) {       // insert the information of student if there are no duplicate record.
				list->insert(student);
				ID[count] = student.id;
				count++;
			}
			b = 1;
		}
	}
	cout << "\n\t" << count << " records have been successfully read.\n\n\t";

	infile.close();
	return true;
}

bool DeleteRecord(List *list, char *id) {

	LibStudent student;
	int size = list->size();

	if (list->empty()) {
		cout << "\n\tOpps! The student list is empty now!! Please back to menu and read file first.\n\n\t";
		return false;
	}

	//delete the record 
	for (int i = 1; i <= size; i++) {
		list->get(i, student);

		if (strcmp(id, student.id) == 0) {
			list->remove(i);
			return true;
		}
	}

	cout << "\n\tThis student haven't in student list.\n\n\t";
	return false;

}

bool SearchStudent(List *list, char *id, LibStudent &stu) {

	LibStudent searchRecord;
	int size = list->size();

	if (list->empty()) {
		cout << "\n\tOpps! The student list is empty now!! Please back to menu and read file first.\n\n\t";
		return false;
	}

	//search the record 
	for (int i = 1; i <= size; i++) {
		list->get(i, searchRecord);

		if (strcmp(id, searchRecord.id) == 0) {
			stu = searchRecord;
			return true;
		}
	}

	cout << "\n\tThis student haven't in student list.\n\n\t";
	return false;
}

bool InsertBook(string filename, List *list) {

	if (list->empty()) {
		cout << "\n\tOpps! The student list is empty now!! Please back to menu and read file first.\n\n\t";
		return false;
	}

	ifstream infile;
	LibBook book;
	string id, borrowDate, dueDate;
	char tempAuthor[50], tempPublisher[30];
	char *ID;
	int array[10000] = { 0 };     //save the number of borrowed book for each student
	type insertbook;            //as a temporary struct LibStudent for update the struct LibStudent in student list
	char tempTitle[250];

	infile.open(filename);

	if (infile.fail()) {
		cout << "\n\tOpps! Fail to open the file.\n\n\t";
		return false;
	}

	while (!infile.eof()) {

		double fine = 0;     //initiate the fine for each borrowed book equal to 0

		infile >> id;
		ID = &id[0];

		infile >> tempAuthor;
		infile >> tempTitle;
		infile >> tempPublisher;
		infile >> book.ISBN;
		infile >> book.yearPublished;
		infile >> book.callNum;
		infile >> borrowDate;
		getline(infile, dueDate);


		//remove the underscore of the title of book insert to book.title
		for (int i = 0; i < 250; i++) {
			if (tempTitle[i] == '_')
				tempTitle[i] = ' ';

		}
		strcpy(book.title, tempTitle);

		//remove the underscore of the publisher of book insert to book.publisher
		for (int i = 0; i < sizeof(tempPublisher); i++) {

			if (tempPublisher[i] == '_')
				tempPublisher[i] = ' ';
		}
		strcpy(book.publisher, tempPublisher);

		//insert the borrow and due date into struct LibStudent
		vector<int> v;
		stringstream ss(borrowDate);
		for (int j; ss >> j;) {
			v.push_back(j);
			if (ss.peek() == '/')
				ss.ignore();
		}
		book.borrow.day = v[0];
		book.borrow.month = v[1];
		book.borrow.year = v[2];

		vector<int> x;
		stringstream sss(dueDate);
		for (int j; sss >> j;) {
			x.push_back(j);
			if (sss.peek() == '/')
				sss.ignore();
		}
		book.due.day = x[0];
		book.due.month = x[1];
		book.due.year = x[2];


		//calculate number of expired days if expired and assume the current date is 29/3/2020
		int totalExpDay = 0;
		if ((book.due.day < 29 && book.due.month == 3) || book.due.month < 3) {
			int monthDays[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

			if (book.due.month == 3)
				totalExpDay = 29 - book.due.day;
			else {
				for (int i = book.due.month; i < 3; i++)
					totalExpDay += monthDays[i];

				totalExpDay += 29 - book.due.day;
			}
		}
		fine += (totalExpDay*0.5);


		//insert all information of book for each student
		LibStudent student;
		int size = list->size();

		for (int s = 1; s <= size; s++) {

			list->get(s, student);

			if (strcmp(ID, student.id) == 0) {

				strcpy(student.book[array[s]].title, book.title);


				//remove the underscore of the author's name
				for (int j = 0; j < sizeof(tempAuthor); j++) {

					if (tempAuthor[j] == '_')
						tempAuthor[j] = ' ';
				}

				//separate the author and insert to student list
				char authortemp[30];
				int c = 0, m = 0;
				for (int j = 0; j < sizeof(tempAuthor); j++)
				{

					if ((tempAuthor[j]) != '/') {
						authortemp[m] = tempAuthor[j];
						m++;
					}

					if (tempAuthor[j] == '/' || j == strlen(tempAuthor) - 1) {
						book.author[c] = new char[30];
						authortemp[m] = '\0';
						strcpy(book.author[c], authortemp);
						student.book[array[s]].author[c] = book.author[c];
						c++;
						m = 0;
					}
				}

				strcpy(student.book[array[s]].publisher, book.publisher);
				strcpy(student.book[array[s]].ISBN, book.ISBN);
				student.book[array[s]].yearPublished = book.yearPublished;
				student.book[array[s]].borrow.day = book.borrow.day;
				student.book[array[s]].borrow.month = book.borrow.month;
				student.book[array[s]].borrow.year = book.borrow.year;
				student.book[array[s]].due.day = book.due.day;
				student.book[array[s]].due.month = book.due.month;
				student.book[array[s]].due.year = book.due.year;
				strcpy(student.book[array[s]].callNum, book.callNum);
				student.book[array[s]].fine = fine;


				//update the student list				
				list->get(s, insertbook);
				insertbook.book[array[s]] = student.book[array[s]];
				list->set(s, insertbook);

				array[s]++;
			}

			for (int x = 1; x <= size; x++) {

				//insert the total book for each student
				list->get(x, insertbook);
				insertbook.totalbook = array[x];
				list->set(x, insertbook);

				//insert the total_fine for each student
				list->get(x, insertbook);
				insertbook.calculateTotalFine();
				list->set(x, insertbook);

			}
		}
	}
	infile.close();

	return true;
}

bool Display(List *list, int source, int detail) {

	if (list->empty()) {
		cout << "\n\tOpps! The student list is empty now!! Please back to menu to read file and insert books first.\n\n\t";
		return false;
	}

	LibStudent display;
	ofstream outfile;
	int Bookcount = 1;

	if (source == 1 && detail == 1) {

		outfile.open("student_booklist.txt");
		if (outfile.fail())
			return false;

		for (int i = 1; i <= list->size(); i++) {
			list->get(i, display);
			outfile << "\nSTUDENT " << i;
			display.print(outfile);
			Bookcount = 1;
			outfile << "\nBOOK LIST: \n";

			for (int j = 0; j < display.totalbook; j++) {
				outfile << "\nBook " << Bookcount << "\n";
				display.book[j].print(outfile);
				Bookcount++;
			}
			outfile << "\n*****************************************************************************************\n\n";
		}
		outfile.close();
		cout << "\n\n\tSuccessfully display output to student_booklist.txt\n\n";

		return true;
	}


	if (source == 1 && detail == 2) {

		outfile.open("student_info.txt");
		if (outfile.fail())
			return false;

		for (int i = 1; i <= (list->size()); i++) {
			list->get(i, display);
			outfile << "\nSTUDENT " << i;
			display.print(outfile);
			outfile << "\n*****************************************************************************************\n\n";
		}
		outfile.close();
		cout << "\n\n\tSuccessfully display output to student_info.txt\n\n";

		return true;
	}


	if (source == 2 && detail == 1) {

		for (int i = 1; i <= (list->size()); i++) {
			list->get(i, display);
			cout << "\nSTUDENT " << i;
			display.print(cout);
			Bookcount = 1;
			cout << "\nBOOK LIST: \n";

			for (int j = 0; j < display.totalbook; j++) {
				cout << "\nBook " << Bookcount << "\n";
				display.book[j].print(cout);
				Bookcount++;
			}
			cout << "\n*****************************************************************************************\n\n";
		}

		return true;
	}

	if (source == 2 && detail == 2) {

		for (int i = 1; i <= (list->size()); i++) {
			list->get(i, display);
			cout << "\nSTUDENT " << i;
			display.print(cout);
			cout << "\n*****************************************************************************************\n\n";
		}

		return true;
	}

	return false;
}

bool computeAndDisplayStatistics(List *list) {

	if (list->empty()) {
		cout << "\n\tOpps! The student list is empty now!! Please back to menu to read file and insert books first.\n\n\t";
		return false;
	}

	int CScountStu = 0, CScountB = 0, CScountOverB = 0;
	double CStotalOverF = 0;
	int IAcountStu = 0, IAcountB = 0, IAcountOverB = 0;
	double IAtotalOverF = 0;
	int IBcountStu = 0, IBcountB = 0, IBcountOverB = 0;
	double IBtotalOverF = 0;
	int CNcountStu = 0, CNcountB = 0, CNcountOverB = 0;
	double CNtotalOverF = 0;
	int CTcountStu = 0, CTcountB = 0, CTcountOverB = 0;
	double CTtotalOverF = 0;

	LibStudent student;
	int size = list->size();


	//compute statistics
	for (int i = 1; i <= size; i++) {

		list->get(i, student);

		if (strcmp(student.course, "CS") == 0) {
			CScountStu++;
			CScountB += student.totalbook;
			for (int j = 0; j < student.totalbook; j++) {
				if (student.book[j].fine != 0) {
					CScountOverB++;
					CStotalOverF += student.book[j].fine;
				}
			}
		}
		else if (strcmp(student.course, "IA") == 0) {
			IAcountStu++;
			IAcountB += student.totalbook;
			for (int j = 0; j < student.totalbook; j++) {
				if (student.book[j].fine != 0) {
					IAcountOverB++;
					IAtotalOverF += student.book[j].fine;
				}
			}
		}
		else if (strcmp(student.course, "IB") == 0) {
			IBcountStu++;
			IBcountB += student.totalbook;
			for (int j = 0; j < student.totalbook; j++) {
				if (student.book[j].fine != 0) {
					IBcountOverB++;
					IBtotalOverF += student.book[j].fine;
				}
			}
		}
		else if (strcmp(student.course, "CN") == 0) {
			CNcountStu++;
			CNcountB += student.totalbook;
			for (int j = 0; j < student.totalbook; j++) {
				if (student.book[j].fine != 0) {
					CNcountOverB++;
					CNtotalOverF += student.book[j].fine;
				}
			}
		}
		else if (strcmp(student.course, "CT") == 0) {
			CTcountStu++;
			CTcountB += student.totalbook;
			for (int j = 0; j < student.totalbook; j++) {
				if (student.book[j].fine != 0) {
					CTcountOverB++;
					CTtotalOverF += student.book[j].fine;
				}
			}
		}
	}

	//display statistics
	cout << "\tCourse  Number of  Total Books\tTotal\t Total" << endl;
	cout << "\t        Students    Borrowed  \tOverdue\t Overdue" << endl;
	cout << "\t                               \tBooks  \t Fine(RM)" << endl;
	cout << "\t  CS\t    " << CScountStu << "  \t     " << CScountB << "\t         " << CScountOverB << "\t " << setprecision(2) << fixed << CStotalOverF << endl;
	cout << "\t  IA\t    " << IAcountStu << "  \t     " << IAcountB << "\t         " << IAcountOverB << "\t " << setprecision(2) << fixed << IAtotalOverF << endl;
	cout << "\t  IB\t    " << IBcountStu << "  \t     " << IBcountB << "\t         " << IBcountOverB << "\t " << setprecision(2) << fixed << IBtotalOverF << endl;
	cout << "\t  CN\t    " << CNcountStu << "  \t     " << CNcountB << "\t         " << CNcountOverB << "\t " << setprecision(2) << fixed << CNtotalOverF << endl;
	cout << "\t  CT\t    " << CTcountStu << "  \t     " << CTcountB << "\t         " << CTcountOverB << "\t " << setprecision(2) << fixed << CTtotalOverF << "\n\n\t";

	return true;
}

bool printStuWithSameBook(List *list, char *callNum) {

	if (list->empty()) {
		cout << "\n\tOpps! The student list is empty now!! Please back to menu to read file and insert books first.\n\n\t";
		return false;
	}

	LibStudent student;
	int countStu = 0;
	int size = list->size();

	//to calculate the number of student borrow same book
	for (int i = 1; i <= size; i++) {

		list->get(i, student);

		for (int j = 0; j < student.totalbook; j++) {

			if (strcmp(callNum, student.book[j].callNum) == 0)
				countStu++;
		}
	}

	cout << "\n\tThere are " << countStu << " students that borrow the book with call number " << callNum << " as shown below:\n\n\n";

	if (countStu != 0) {

		//to display the information of student that borrow same book
		for (int i = 1; i <= size; i++) {
			list->get(i, student);

			for (int j = 0; j < student.totalbook; j++) {

				if (strcmp(callNum, student.book[j].callNum) == 0) {
					cout << "\tStudent Id = " << student.id << endl;
					cout << "\tName = " << student.name << endl;
					cout << "\tCourse = " << student.course << endl;
					cout << "\tPhone Number = " << student.phone_no << endl;
					cout << "\tBorrow Date: ";
					student.book[j].borrow.print(cout);
					cout << "\n\tDue Date: ";
					student.book[j].due.print(cout);
					cout << "\n\n\n";
				}
			}
		}
	}
	cout << "\t";

	return true;
}

bool displayWarnedStudent(List *list, List *type1, List *type2) {

	while (!type1->empty())
		type1->remove(1);

	while (!type2->empty())
		type2->remove(1);

	if (list->empty()) {
		cout << "\n\tOpps! The student list is empty now!! Please back to menu to read file and insert books first.\n\n\t";
		return false;
	}

	int size = list->size();
	LibStudent student, display;

	//insert the type1 and type2 list based on the conditions
	for (int i = 1; i <= size; i++) {
		list->get(i, student);
		int countOverTen = 0;      //represent the no. of student has >2 book that are overdue for >=10 days
		int countOver = 0;         //represent the no. of book are overdue for each student


		//calculate number of expired days if expired and assume the current date is 29/3/2020 
		int totalExpDay = 0;
		for (int j = 0; j < student.totalbook; j++) {

			if ((student.book[j].due.day < 29 && student.book[j].due.month == 3) || student.book[j].due.month < 3) {
				int monthDays[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

				if (student.book[j].due.month == 3)
					totalExpDay = 29 - student.book[j].due.day;
				else {
					for (int i = student.book[j].due.month; i < 3; i++)
						totalExpDay += monthDays[i];

					totalExpDay += 29 - student.book[j].due.day;
				}
				countOver++;
				if (totalExpDay >= 10)
					countOverTen++;
			}
		}
		if (countOverTen > 2)
			type1->insert(student);

		if (countOver == student.totalbook && student.total_fine > 50)
			type2->insert(student);
	}


	//display the type1 and type2 list	
	if (type1->size() == 0)
		cout << "\tThere has no student in list of type1.\n\n";
	else {
		cout << "\n\n****************************************** The list of Type 1 ***************************************\n\n";
		for (int k = 1; k <= (type1->size()); k++) {
			type1->get(k, display);
			cout << "\nSTUDENT " << k;
			display.print(cout);
			int Bookcount = 1;

			cout << "\nBOOK LIST: \n";
			for (int l = 0; l < display.totalbook; l++) {
				cout << "\nBook " << Bookcount << "\n";
				display.book[l].print(cout);
				Bookcount++;
			}
			cout << "\n*********************************************************************************\n";
		}
		cout << "\n";
	}

	if (type2->size() == 0)
		cout << "\tThere has no student in list of type2.\n\n";
	else {
		cout << "\n\n****************************************** The list of Type 2 ***************************************\n\n";
		for (int k = 1; k <= (type2->size()); k++) {
			type2->get(k, display);
			cout << "\nSTUDENT " << k;
			display.print(cout);
			int Bookcount = 1;

			cout << "\nBOOK LIST: \n";
			for (int l = 0; l < display.totalbook; l++) {
				cout << "\nBook " << Bookcount << "\n";
				display.book[l].print(cout);
				Bookcount++;
			}
			cout << "\n*********************************************************************************\n\n";
		}
	}

	return true;
}

int menu() {
	int choice;
	system("color 57"); //background and text color 

	cout << "\t**************************************************" << endl;
	cout << "\t|                                                |" << endl;
	cout << "\t|                      Menu                      |" << endl;
	cout << "\t|                                                |" << endl;
	cout << "\t**************************************************" << endl;
	cout << "\n\t--------------------------------------------------  " << endl;
	cout << "\t|\t1.Read File.\t\t\t\t | " << endl;
	cout << "\t|\t2.Delete Record. \t\t\t |" << endl;
	cout << "\t|\t3.Search student. \t\t\t | " << endl;
	cout << "\t|\t4.Insert book.\t\t\t\t | " << endl;
	cout << "\t|\t5.Display output.\t\t\t |" << endl;
	cout << "\t|\t6.Compute and Display Statistics.\t | " << endl;
	cout << "\t|\t7.Student with Same Book.\t\t | " << endl;
	cout << "\t|\t8.Display Warned Student.\t\t | " << endl;
	cout << "\t|\t9.Exit. \t\t\t\t | " << endl;
	cout << "\t--------------------------------------------------  \n" << endl;

	cout << "\tEnter your choice: ";

	cin >> choice;
	return choice;
}
