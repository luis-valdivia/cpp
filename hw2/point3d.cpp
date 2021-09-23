#include <iostream>
#include "point3d.h"
using namespace std;

//constructor
Point3d::Point3d(double x, double y, double z){
	this -> x = x;
	this -> y = y;
	this -> z = z;
}

// MEMBER FUNCTIONS
void Point3d::setX(double x){
	this -> x = x;
}

void Point3d::setY(double y){
	this -> y = y;
}

void Point3d::setZ(double z){
	this -> z = z;
}

// CONSTANT MEMBER FUNCTIONS
double Point3d::getX() const{
	return x;
}

double Point3d::getY() const{
	return y;
}

double Point3d::getZ() const{
	return z;
}

//axis is either 0, 1, 2 for shifting along x, y, z dimension
void Point3d::shift(int axis, double distance){
	if(axis == 0)
		setX(distance + getX());
	if(axis == 1)
		setY(distance + getY());
	if(axis == 2)
		setZ(distance + getZ());
}

// NON-MEMBER FUNCTIONS
bool operator == (const Point3d& p1, const Point3d& p2){
	return (p1.getX() == p2.getX() && p1.getY() == p2.getY() && p1.getZ() == p2.getZ());
}

int main(){
	// here we can use the functions, contructors, etc.
	return 0;
}
