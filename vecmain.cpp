#include "./vector3d.h"
#include <iostream>

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
	return 0;
}
