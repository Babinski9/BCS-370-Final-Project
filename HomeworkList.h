//HomeworkList header file
#pragma once

#include <list>
#include "Homework.h"

using namespace std;


class HomeworkList {
public:
	// Constructor
	HomeworkList();

	// List manipulation
	void addAssignment(Homework assignment);
	void removeAssignment(int index);

	// Important functions
	void showList();

	// Searches
	void search(int days);
	void search(string course);

	// Setters/getters
	list<Homework> getAssignmentList();
	Homework getHomeworkAt(int index);
	void updateEstimatedTime(double estTime, int index);
	void updatePoints(double pts, int index);
	void updateCourse(string course, int index);
	void updateDueDate(int days, int index);
	int getSize();
	bool checkEmpty();



private:
	// Member variables
	int index;
	list<Homework> assignmentList{};
};