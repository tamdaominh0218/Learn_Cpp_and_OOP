#include <iostream>
#include <algorithm>

class Shallow
{
public:
	Shallow(int data_val);
	~Shallow();
	void setData(int data_val);
	int getData();
	Shallow(const Shallow& other);

private:
	int* data;
};

Shallow::Shallow(int data_val)
	:data{ new int }
{
	std::cout << "**** This is constructor ****\n";
	*data = data_val;
}

Shallow::~Shallow()
{
	std::cout << "**** This is deconstructor ****\n";
	delete data;
}

Shallow::Shallow(const Shallow& other)
	:data{other.data}
{
	std::cout << "**** This is shallow copy constructor ****\n";
}

int Shallow:: getData() {
	return *data;
}

void Shallow::setData(int data_val) {
	*data = data_val;
}

void printObject(Shallow ob) {
	std::cout << "Data: " << ob.getData() << std::endl;
}

int main() {
	Shallow obj1(100);
	printObject(obj1);

	Shallow obj2{ obj1 };
	obj2.setData(200);
	printObject(obj1);
	printObject(obj2);
	return 0;
}