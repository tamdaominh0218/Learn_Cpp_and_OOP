#include <iostream>
#include <string>

class Player
{
public:
	Player(std::string name = "None", int age = 0, std::string fc = "None", int number = 0, int salary = 0);
	//copy constructor 
	Player(const Player& other); 
	std::string getFullName() const { return fullName; }
	int getAge() const { return age; }
	std::string getFC() const { return fc; }
	int getNumber() const { return number; }
	int getSalary() const { return salary; }
private:
	std::string fullName;
	int age;
	std::string fc;
	int number;
	int salary;
};

Player::Player(std::string name, int age, std::string fc, int number, int salary)
	: fullName{ name }, age{ age }, fc{ fc }, number{ number }, salary{ salary } 
{
	std::cout << "**** This is default constructor ****\n" << fullName << std::endl;
}

Player::Player(const Player& other)
	//: fullName{ other.fullName }, age{ other.age }, fc{ other.fc }, number{ other.number }, salary{ other.salary } 
	: Player(other.fullName, other.age, other.fc, other.number, other.salary)
{
	std::cout << "**** This is copy constructor ****\n" << fullName << std::endl;
}

void printObject(const Player p) {
	std::cout << "**** This is print detail infomation player ****\n";
	std::cout << p.getFullName() << std::endl;
	std::cout << p.getAge() << std::endl;
	std::cout << p.getFC() << std::endl;
}

//void printObject(const Player *p) {
//	std::cout << "**** This is print detail infomation player ****\n";
//	std::cout << p->getFullName() << std::endl;
//	std::cout << p->getAge() << std::endl;
//	std::cout << p->getFC() << std::endl;
//}

int main() {
	//Player *Kevin =  new Player("De Bruyne", 35, "Napoli", 17, 250000);
	//printObject(Kevin);
	//delete Kevin;

	Player Haaland("Erling Haaland", 26, "Man City", 9, 350000);
	printObject(Haaland);
	std::cout << std::endl;

	Player Rodri = Haaland;
	printObject(Haaland);

	return 0;
}