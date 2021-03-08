//Car sorting problem-cars are palced at diff location in (x,y) plane

//Use of vector by implementing class

#include <bits/stdc++.h>
using namespace std;

class Car {

public:
	string car_name;
	int x;
	int y;

	Car(string name, int x, int y) {

		car_name = name;
		this->x = x;
		this->y = y;
	}

	int dist()
	{
		return sqrt(x * x + y * y);
	}
};

bool compare(Car A, Car B) {
	int da = A.dist();
	int db = B.dist();

	if (da == db)
	{
		return A.car_name.length() < B.car_name.length();
	}

	return da < db;
}

int main()
{
	int n;
	cin >> n;

	vector<Car> v;

	for (int i = 0; i < n; i++)
	{
		string name;
		int x, y;
		cin >> name >> x >> y;

		Car temp(name, x, y); //making an object

		v.push_back(temp);
	}

	sort(v.begin(), v.end(), compare);

	for (auto c : v)
	{
		cout << c.car_name << " " << c.dist() << " " << c.x << " " << c.y << endl;
	}

	return 0;
}