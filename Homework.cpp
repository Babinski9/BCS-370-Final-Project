//Homework cpp file

#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <fstream>
#include "Homework.h"

using namespace std;


Homework::Homework() {
	this->estimatedTime = 0;
	this->points = 0;
	this->name = "";
	this->course = "";
	this->dueDate = 0;
}

void Homework::setEstimatedTime(double estTime) {
	this->estimatedTime = estTime;
}

double Homework::getEstimatedTime() {
	return this->estimatedTime;
}

void Homework::setPoints(double pts) {
	this->points = pts;
}

double Homework::getPoints() {
	return this->points;
}

void Homework::setCourse(string course) {
	this->course = course;
}

string Homework::getCourse() {
	return this->course;
}

void Homework::setName(string name) {
	this->name = name;
}

string Homework::getName() {
	return this->name;
}

void Homework::setDueDate(int days) {
	this->dueDate = days;
}

int Homework::getDueDate() {
	return this->dueDate;
}



void Homework::showHomework() {
	cout << "\tAssignment Name: \t" << this->name << endl;
	cout << "\t\tCourse: " << this->course << endl;
	cout << "\t\tPoints: " << this->points << " points" << endl;
	cout << "\t\tDue Date (days away): " << this->dueDate << endl;
	cout << "\t\tEstimated Time: " << this->estimatedTime << " hours" << endl;
}


void Homework::save(ofstream& file) {
	file << this->name << endl;
	file << this->course << endl;
	file << this->points << endl;
	file << this->dueDate << endl;
	file << this->estimatedTime << endl;
}