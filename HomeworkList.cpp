//HomeworkList cpp file

#include "HomeworkList.h"

using namespace std;


HomeworkList::HomeworkList() {
	this->index = 0;
	this->assignmentList = list<Homework>();
}

void HomeworkList::addAssignment(Homework assignment) {
	this->assignmentList.push_front(assignment);
}

void HomeworkList::removeAssignment(int index) {
	if (index < 0 || index >= this->assignmentList.size()) {
		cout << "Error: Invalid index" << endl;
		return;
	}
	list<Homework>::iterator it = this->assignmentList.begin();
	advance(it, index);
	this->assignmentList.erase(it);
}

void HomeworkList::showList() {
	list<Homework>::iterator it = this->assignmentList.begin();
	int elementNum = 1;
	cout << "Displaying the Assignment List: " << endl;
	for (it = this->assignmentList.begin(); it != assignmentList.end(); ++it) {
		cout << "\tElement #" << elementNum << ": " << endl;
		Homework hw = *it;
		hw.showHomework();
		elementNum++;
	}
}

void HomeworkList::search(int days) {
	list<Homework>::iterator it = this->assignmentList.begin();
	int indexStart = 0;
	cout << "SEARCHING: These assignments are due within:  " << days << " days" << endl;
	for (it = this->assignmentList.begin(); it != assignmentList.end(); ++it) {
		Homework hw = *it;
		if (hw.getDueDate() <= days) {
			hw.showHomework();
		}
	}
}

void HomeworkList::search(string course) {
	list<Homework>::iterator it = this->assignmentList.begin();
	cout << "SEARCHING:  These assignments are from the course:  " << course << endl;
	for (it = this->assignmentList.begin(); it != assignmentList.end(); ++it) {
		Homework hw = *it;
		if (hw.getCourse()._Equal(course)) {
			hw.showHomework();
		}
	}
}

list<Homework> HomeworkList::getAssignmentList() {
	return this->assignmentList;
}

Homework HomeworkList::getHomeworkAt(int index) {
	list<Homework>::iterator it = this->assignmentList.begin();
	int indexStart = 0;
	for (it = this->assignmentList.begin(); it != assignmentList.end(); ++it) {
		if (indexStart == index) {
			return *it;
		}
		else {
			index++;
		}
	}
}

Homework HomeworkList::getHomeworkAtRec(int index, list<Homework>::iterator it) {
	if (index == 0) {
		return *it;
	}
	else {
		return getHomeworkAtRec(index - 1, ++it);
	}
}

Homework HomeworkList::getHomeworkAt(int index) {
	list<Homework>::iterator it = this->assignmentList.begin();
	return getHomeworkAtRec(index, it);
}

void HomeworkList::updateEstimatedTime(double estTime, int index) {
	this->getHomeworkAt(index).setEstimatedTime(estTime);
}

void HomeworkList::updatePoints(double pts, int index) {
	this->getHomeworkAt(index).setPoints(pts);
}

void HomeworkList::updateCourse(string course, int index) {
	this->getHomeworkAt(index).setCourse(course);
}


void HomeworkList::updateDueDate(int days, int index) {
	this->getHomeworkAt(index).setDueDate(days);
}

int HomeworkList::getSize() {
	return this->assignmentList.size();
}

bool HomeworkList::checkEmpty() {
	if (this->assignmentList.empty() == true) {
		return true;
	}
	return false;
}

