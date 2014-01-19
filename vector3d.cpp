#include <cmath>
#include <iostream>
#include "vector3d.h"

Vector3d::Vector3d(){
	coords[0] = coords[1] = coords[2] = 0;
}

Vector3d::Vector3d(double x, double y, double z){
	coords[0] = x, coords[1] = y, coords[2] = z;
}

Vector3d::Vector3d(double coords[3]){
	coords[0] = coords[0], coords[1] = coords[1];
	coords[2] = coords[2];
}

Vector3d::Vector3d(const Vector3d& cp){
	coords[0] = cp.coords[0];
	coords[1] = cp.coords[1];
	coords[2] = cp.coords[2];
}

Vector3d::~Vector3d(){}

Vector3d Vector3d::operator+(const Vector3d& summand){
	double x = summand.coords[0] + coords[0];
	double y = summand.coords[1] + coords[1];
	double z = summand.coords[2] + coords[2];
	return Vector3d(x, y, z);
}

Vector3d Vector3d::operator-(const Vector3d& subtrahend){
	double x = coords[0] - subtrahend.coords[0];
	double y = coords[1] - subtrahend.coords[1];
	double z = coords[2] - subtrahend.coords[2];
	return Vector3d(x, y, z);
}

double Vector3d::dotProd(const Vector3d& other){
	return (coords[0]*other.coords[0]) + (coords[1]*other.coords[1])
			+ (coords[2]*other.coords[2]);
}

Vector3d Vector3d::crossProd(const Vector3d& other){
	double x = (coords[1]*other.coords[2])-(coords[2]*other.coords[1]);
	double y = -((coords[0]*other.coords[2])-(coords[2]*other.coords[0]));
	double z = (coords[0]*other.coords[1])-(coords[1]*other.coords[0]);
	return Vector3d(x, y, z);
}

Vector3d Vector3d::scalarMul(double x){
	return Vector3d( x*coords[0], x*coords[1], x*coords[2]);
}

Vector3d Vector3d::negate(){
	return scalarMul(-1);
}

double Vector3d::magnitude(){
	double x = coords[0], y = coords[1], z = coords[2];
	return sqrt(x*x+y*y+z*z);
}

Vector3d Vector3d::unitVec(){
	double mag = magnitude();
	return scalarMul(1/mag);
}

double Vector3d::getX() const{ return coords[0]; }
double Vector3d::getY() const{ return coords[1]; }
double Vector3d::getZ() const{ return coords[2]; }

void Vector3d::print() const{
	std::cout << "(" << coords[0] << ", " << coords[1] << ", ";
	std::cout << coords[2] << ")" << std::endl;
}

int main(void){
	Vector3d v(1,2,3);
	Vector3d v2(2,4,6);
	v.print();
	v2.print();
	
	std::cout << "Dot product: " << v.dotProd(v2) << std::endl;
	
	(v+v2).print();
	(v.scalarMul(10)).print();
	Vector3d unit = v.unitVec();
	unit.print();
	std::cout << unit.magnitude() << std::endl;
	(v.crossProd(v2)).print();
}
	
	
