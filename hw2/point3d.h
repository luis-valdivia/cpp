#ifndef POINT3D_H
#define POINT3D_H
class Point3d
        {
        public:
                // CONSTRUCTOR
                Point3d(double x, double y, double z);
                // MEMBER FUNCTIONS
                void setX(double x);
                void setY(double y);
                void setZ(double z);
                //axis is either 0, 1, 2 for shifting along x, y, z dimension
                void shift(int axis, double distance);
                // CONSTANT MEMBER FUNCTIONS
				double getX() const;
        		double getY() const;
        		double getZ() const;
				private:
				double x;
				double y;
				double z;
		};
// NON-MEMBER FUNCTIONS
bool operator == (const Point3d& p1, const Point3d& p2);

#endif
