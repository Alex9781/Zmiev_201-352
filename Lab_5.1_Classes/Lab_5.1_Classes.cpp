#include <iostream>

class Bird
{
private:
	std::string name = "Bird";
public:

	Bird()
	{
		std::cout << "bird" << std::endl;
	}
	~Bird()
	{
		std::cout << "bird died" << std::endl;
	}

	void Fly()
	{
		std::cout << "flying" << std::endl;
	}

	std::string GetName()
	{
		return name;
	}

	void SetName(std::string name)
	{
		this->name = name;
	}
};

class Parrot : public Bird
{
private:

public:
	Parrot()
	{
		std::cout << "parrot" << std::endl;
	}
	~Parrot()
	{
		std::cout << "parrot died" << std::endl;
	}
};

class Penguin : public Bird
{

};

class Sparrow : public Bird
{

};

int main()
{
	//Bird b = Bird();
	//b.Fly();

	//Parrot p = Parrot();
	//p.SetName("Kesha");
	//std::cout << p.GetName() << std::endl;

	Parrot p2 = Parrot();
	p2.SetName("Kesha");
	std::cout << p2.GetName() << std::endl;
	p2.SetName("neKesha");
	std::cout << p2.GetName() << std::endl;
}