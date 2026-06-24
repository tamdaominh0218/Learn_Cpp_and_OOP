#include <iostream>
#include <algorithm>

class Deep
{
public:
	Deep(int data_val);
	~Deep();
	void setData(int data_val);
	int getData();
	Deep(const Deep& other);

private:
	int* data;
};

Deep::Deep(int data_val)
	:data{ new int }
{
	std::cout << "**** This is constructor ****\n";
	*data = data_val;
}

Deep::~Deep()
{
	std::cout << "**** This is deconstructor ****\n";
	delete data;
}

Deep::Deep(const Deep& other)
	:data( new int(*other.data))
{
	std::cout << "**** This is Deep copy constructor ****\n";
}

int Deep::getData() {
	return *data;
}

void Deep::setData(int data_val) {
	*data = data_val;
}

void printObject(Deep ob) {
	std::cout << "Data: " << ob.getData() << std::endl;
}

int main() {
	Deep obj1(100);
	printObject(obj1);

	Deep obj2{ obj1 };
	obj2.setData(200);
	printObject(obj1);
	printObject(obj2);

	return 0;
}