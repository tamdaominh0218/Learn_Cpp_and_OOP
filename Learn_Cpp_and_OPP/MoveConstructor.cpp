#include <iostream>
#include <algorithm>

class Move
{
public:
	Move(int data_val);
	~Move();
	void setData(int data_val);
	int getData();
	//Deep copy
	Move(const Move& other);
	//Copy assignment operator
	Move& operator=(Move&& other);
	//Move constructor
	Move(Move&& other) noexcept;

private:
	int* data;
};

Move::Move(int data_val)
	:data{ new int }
{
	std::cout << "**** This is constructor ****\n";
	*data = data_val;
}

Move::~Move()
{
	std::cout << "**** This is deconstructor ****\n";
	delete data;
}

Move::Move(const Move& other)
	//:Mode{*other.data}
	:data(new int(*other.data))
{
	std::cout << "**** This is copy constructor ****\n";
}

Move::Move(Move&& other) noexcept
	:data(other.data)
{
	other.data = nullptr;
	std::cout << "**** This is Move constructor ****" << " Data: " << *data << std::endl;
}

Move& Move::operator=(Move&& other) {
	if (this ==&other)
	{
		return *this;
	}

	int *newData = new int(*other.data);
	delete data;
	data = newData;
	return *this;
}

int Move::getData() {
	return *data;
}

void Move::setData(int data_val) {
	*data = data_val;
}

void printObject(Move ob) {
	std::cout << "Data: " << ob.getData() << std::endl;
}

int main() {
	Move obj1(100);
	printObject(obj1);

	Move obj2{ obj1 };
	obj2.setData(200);
	printObject(obj1);
	printObject(obj2);

	return 0;
}