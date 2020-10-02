#include <iostream>
#include <string>

void task1();
void task2();
double fact(double num);
void task3();
void task4();
void chooseTask();

int main()
{
	chooseTask();
	return 0;
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
		std::cout << "error" << std::endl;
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
	double n;
	std::cout << "enter n: ";
	std::cin >> n;

	for (int i = 0; i <= n; i++)
	{
		std::cout << fact(n) / (fact(n - i) * fact(i)) << " ";
	}
	std::cout << std::endl;

	chooseTask();
}

double fact(double num)
{
	if (num == 0) return 1;
	else return num * fact(num - 1);
}

void task3()
{
	getchar();
	std::cout << "enter numbers. empty enter is stop \n";
	int sum, count;
	std::string S = "";
	sum = 0;
	count = 0;

	while (true)
	{
		std::getline(std::cin, S);
		if (S.empty()) break;		
		else
		{
			int buf = std::atoi(S.c_str());
			if (!buf) continue;
			sum += buf;
			count++;
		}
	}
	std::cout << "average: " << float(sum) / count << std::endl;

	chooseTask();
}

void task4()
{
	std::exit(0);
}