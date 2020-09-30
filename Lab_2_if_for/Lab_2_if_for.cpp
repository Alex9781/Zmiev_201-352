#include <iostream>

void task1();
void task2();
void task3();
void task4();
void chooseTask();

int main()
{
	chooseTask();
}

void chooseTask()
{
	int task = 0;
	std::cout << "choose task \n"
		<< "1. task 1 \n"
		<< "2. task 2 \n"
		<< "3. task 3 \n"
		<< "4. exit \n";

	std::cin >> task;

	switch (task)
	{
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	case 4:
		task4();
		break;
	default:
		std::cout << "error" <<std::endl;
		chooseTask();
		break;
	}
}

void task1()
{
	int num = 0;
	std::cout << "enter number: ";
	std::cin >> num;

	for (int i = 0; i <= num; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			std::cout << j;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	chooseTask();
}

void task2()
{

}

void task3()
{
	std::cout << "enter numbers. zero is stop \n";
	int sum, count, input;
	sum = 0;
	count = 0;

	while (true)
	{
		std::cin >> input;
		if (!input) // а как???
			break;
		sum += input;
		count++;
	}
	std::cout << "average: " << float(sum) / float(count) << std::endl;

	chooseTask();
}

void task4()
{
	std::exit(0);
}