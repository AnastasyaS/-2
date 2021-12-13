#pragma once
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

int getIntValue(int lowLimit, int upLimit);

int getIntValue(int lowLimit, int upLimit, int mySeconds);	//ввод данных, зависящих от времени


string getStringValue();

bool isInvalidInput(string line);

double getDoubleValue(double lowLimit, double upLimit);
