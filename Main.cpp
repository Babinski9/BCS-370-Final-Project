/*
Chris Babinski
Started: 04/12/2023
Ended: 04/28/2023
BCS-370
FinalProject:
College Student Homework Mananagement System
*/

#include <iostream>
#include <fstream>
#include "HomeworkList.h"

using namespace std;

double generateEstimatedTime() {
	double randTime = (double)rand() / RAND_MAX;
	randTime = randTime * 60;
	randTime = floor(randTime * 10 + 0.5) / 10; // add 0.5 and then round down to floor
	return randTime;
}

int generateDueDate() {
	int randDate = rand() % 59 + 1;
	return randDate;
}

double generatePoints() {
	double randPoints = (double)rand() / RAND_MAX;
	randPoints = randPoints * 100;
	randPoints = floor(randPoints * 100 + 0.5) / 100; // add 0.5 and then round down to floor
	return randPoints;
}

string generateAssignmentName() {
	string nameArray[5] = { "Practice Assignment", "Textbook Problems", "Comparative Essay", "Research Paper", "Group Project" };
	int size = sizeof(nameArray);
	int randNum = rand() % 5;
	return nameArray[randNum];
}

string generateCourseName() {
	string courseArray[6]{ "Math", "Physics", "English", "History", "Computer Science", "Spanish" };
	int size = sizeof(courseArray);
	int randNum = rand() % 6;
	return courseArray[randNum];
}

void printDatatoConsole(ifstream& file) {
	cout << "\t*PRINTING THE DATA FILE*" << endl;
	cout << "###########################################" << endl;
	if (file.is_open()) {
		string data;
		while (getline(file, data)) {
			cout << data << endl;
		}
		file.close();
	}
	else {
		cout << "Error printing the data file to console. " << endl;
	}
	cout << "###########################################" << endl << endl;
}

void saveHomeworkList(ofstream& file, HomeworkList list) {
	int numElements = 0;
	while (!list.checkEmpty()) {
		Homework currentHomework = list.getHomeworkAt(0);
		currentHomework.save(file);
		list.removeAssignment(0);
		numElements++;
	}
	cout << endl << "---------------------------------------" << endl;
	cout << "Saving " << numElements << " objects to assignment_data.dat" << endl;
	cout << "---------------------------------------" << endl << endl;
	file.close();
}

int main() {
	// Setting up rand() function
	srand(time(0));
	int time = rand();
	
	// Creating the main list
	HomeworkList myList = HomeworkList();

	// Adding a number of randomly-generated assignments to the list
	int numSimulatedAssignments = 200;
	for (int i = 0; i < numSimulatedAssignments; i++) {
		Homework hw = Homework();
		hw.setCourse(generateCourseName());
		hw.setEstimatedTime(generateEstimatedTime());
		hw.setPoints(generatePoints());
		hw.setName(generateAssignmentName());
		hw.setDueDate(generateDueDate());
		myList.addAssignment(hw);
	}
	
	// Displaying each element in the list
	myList.showList();

	// Opening and saving the data file
	ofstream file("assignment_data.dat", ios::out | ios::binary);
	if (!file.is_open()) {
		cerr << "Error: could not open " << "assignment_data.dat" << endl;
	}
	else {
		HomeworkList myListCopy = myList;
		saveHomeworkList(file, myListCopy);
	}

	// Reading back the data file and printing to console
	ifstream inputFile("assignment_data.dat", ios::out | ios::binary);
	printDatatoConsole(inputFile);

	 
	return 0;
}
	




/*
Homework/Assignment Object
	Required Variables:
		- estimatedTime (estimated time to spend on the assignment)
		- Weight (how many credits, or %, of the total grade)
	Additional Variables?:
		- Name
		- Course
		- Due date/time
		- etc?
	Required Functions:
		- Add (add an assignment)
		- Update (update an assignment... update the due date, or other attributes)
		- Search (or lookup)
			- Search assignments which are due within a # of days from today (0 means today, 1 means tomorrow...)
			- Search by course
		- Display all assignments that are in progress
		- Delete a completed assignment (or mark the assignment as "complete")

*/

//workflow for writeup:

/*
First, i made a class "Homework" for all of the variable names that would describe any assignments (double estimatedTime, double points, string name, string course, struct dueDate (TALK ABOUT WHY YOU USED STRUCT FOR "DUEDATE")
I would also need to provide the appropriate functions that Homework objects would need to use
Then, i needed to figure out which data structure i would need to store all of the Homework objects





*/

