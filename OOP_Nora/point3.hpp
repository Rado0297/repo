class Point3
{
private:
	int x, y, z;

public:
	Point3(int = 0, int = 0, int = 0);
	Point3(const Point3&);

	//Getters
	int getX() const;
	int getY() const;
	int getZ() const;

	//Setters
	void setX(int _x);
	void setY(int _y);
	void setZ(int _z);

	void print() const;
};