#include "declarations.h"

int main()
{
	login();
	menu();

    return 0;
}


void login() 
{
    const std::string password = "adminpass";
    std::string ans{};
	std::string ans2{};
	int count{};
	bool corrpass = false;
	while (count <= 5) {
		std::cout << "Please enter the password: ";
		std::cin >> ans;
		
		for (int k{}; k < ans.size(); k++) {
			ans2.push_back(std::tolower(ans[k]));
		}

		for (int i{}; i < password.size(); i++) 
		{
			if (password[i] != ans2[i]) 
			{
				std::cout << "Wrong password, please try again." << std::endl;
				count++;
				break;
			}
			if (i == password.size() - 1) {
				corrpass = true;
			}
		}

		if (corrpass) 
		{
			std::cout << "Correct password." << std::endl;
			return;
		}
	}
	std::cout << "You wrote the wrong password too many times.";
	exit(0);
}

void menu() {
	int pos = 1;
	char ch{};
	while (true) {
		system("cls");
		std::cout << "You are in the main menu. Please select an option using W and S." << std::endl << std::endl;

		if (pos == 1) { std::cout << "->"; }
		std::cout << " | 1: Print names' Initials ans Lasts" << std::endl;

		if (pos == 2) { std::cout << "->"; }
		std::cout << " | 2: Students' exam result" << std::endl;

		if (pos == 3) { std::cout << "->"; }
		std::cout << " | 3: Typing a sentence" << std::endl;

		if (pos == 4) { std::cout << "->"; }
		std::cout << " | 4: Quit" << std::endl;

		ch = _getch();
		switch (ch) {
		case 'W':
		case 'w':
			if (pos <= 1) { pos = 4; break; }
			pos--;
			break;
		case 'S':
		case 's':
			if (pos >= 4) { pos = 1; break; }
			pos++;
			break;
		case 13: // Enter
			runTasks(pos);
			break;
		default:
			std::cout << "Please enter a valid input." << std::endl;
			system("pause");
			break;
		}
	}
}


void runTasks(int task) {
	system("cls");
	switch (task) {
	case 1:
		task2();
		break;
	case 2:
		task3();
		break;
	case 3:
		std::cout << "This task is not complete." << std::endl;
		system("pause");
		break;
	case 4:
		exit(0);
		break;
	}
}


void task2() {
	std::vector <std::string> names{};
	std::string name{};
	int ans{};
	int temp{};
	
	if (names.size() == 0) {
		std::cout << "The name list is empty. Please enter how many people you would like to add: ";
		std::cin >> ans;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << std::endl;

		for (int i{}; i < ans; i++) {
			std::cout << "Enter the persons first name: ";
			std::cin >> name;
			names.push_back(name);
			std::cout << "Added " << name << " to the list." << std::endl << std::endl;
		}
	}

	std::cout << "All the people are added. Here is the initial and last of every person:" << std::endl;

	for (int k{}; k < names.size(); k++) {
		temp = names[k].length();
		std::cout << names[k] << "'s initial is " << names[k][0] << std::endl;
		std::cout << names[k] << "'s final character is " << names[k][temp - 1] << std::endl;
		std::cout << std::endl;
	}
	system("pause");
}


void task3() {
	std::cout << "How many students do you want to add info for?: ";
	int ans{};
	std::cin >> ans;
	std::cin.ignore(1000, '\n');
	std::cin.clear();

	for (int i{}; i < ans; i++) {
		system("cls");
		getInfo();
	}

	system("cls");
	std::cout << "Info for all the students have been added. Here comes the list:" << std::endl;
	std::cout << "Name : Grade (number of correct answers)" << std::endl << std::endl;
	for (int k{}; k < students.size(); k++) {
		std::cout << students[k].name << ", " << students[k].grade() << std::endl;
	}

	std::cout << std::endl;

	int average{};
	int min = students[0].grade();
	int max = students[0].grade();

	for (int j{}; j < students.size(); j++) {
		average += students[j].grade();
		if (students[j].grade() < min) {
			min = students[j].grade();
		}
		if (students[j].grade() < max) {
			max = students[j].grade();
		}
	}
	average = average / students.size();

	std::cout << "Number of students: " << students.size() << std::endl;
	std::cout << "Average score: " << average << std::endl;
	std::cout << "Max score: " << max << std::endl;
	std::cout << "Min score: " << min << std::endl;
	system("pause");
}

void getInfo() {
	std::string name{}, answer{};
	std::cout << "Please enter the students name: ";
	std::getline(std::cin, name);

	std::cout << std::endl;
	
	std::cout << "Please enter the students answer, e.g. 'ABDCABDA': ";
	std::getline(std::cin, answer);
	std::cout << std::endl;
	/*std::cin.ignore(1000, '\n');
	std::cin.clear();*/
		
	student person;
	person.name = name;
	person.answers = answer;

	students.push_back(person);
}