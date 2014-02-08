#ifndef VEC_H
#define VEC_H
class Vector3d{
	private:
		double coords[3];
	public:
		Vector3d();
		Vector3d(double,double,double);
		Vector3d(double[3]);
		Vector3d(const Vector3d&);
		~Vector3d();
		
		Vector3d operator+(const Vector3d&);
		Vector3d operator-(const Vector3d&);
		
		double dotProd(const Vector3d&);
		Vector3d crossProd(const Vector3d&);
		Vector3d scalarMul(double);
		
		Vector3d negate();
		double magnitude();
		Vector3d unitVec();
		
		double getX() const;
		double getY() const;
		double getZ() const;
		const double *getCoords() const;
		
		void print() const;
};
#endif
