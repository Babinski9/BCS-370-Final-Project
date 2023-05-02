#pragma once

//Homework header file

#include <string>
#include <iostream>

using namespace std;


class Homework {
public:
	//Constructor
	Homework();

	// Important functions
	void save(ofstream& of);
	void showHomework();

	// Setters/Getters
	void setEstimatedTime(double estTime);
	double getEstimatedTime();
	void setPoints(double pts);
	double getPoints();
	void setCourse(string course);
	string getCourse();
	void setName(string name);
	string getName();
	void setDueDate(int days);
	int getDueDate();

private:
	// Member variables
	double estimatedTime;
	double points;
	string course;
	string name;
	int dueDate; // indicates "Days away"


};

