#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

void login();
void menu();
void runTasks(int);
void task2();
void task3();
void getInfo();
void task4();

const std::string correctAnswer = "ABDCABDA";

struct student {
	std::string name{};
	std::string answers{};
	int grade() { 
		int temp{};
		for (int i{}; i < answers.length(); i++) {
			if (answers[i] == correctAnswer[i]) {
				temp++;
			}
		}
		return temp;
	}
};

std::vector <student> students{};