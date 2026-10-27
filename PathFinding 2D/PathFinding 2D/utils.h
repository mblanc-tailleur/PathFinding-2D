#pragma once
#include <iostream>
#include <random>
#include <vector>

#define REDWRITE "\x1b[31m"
#define BLUEWRITE "\x1b[34m"
#define WHITEWRITE "\x1b[37m"

#define BLACKBACKGROUND "\x1b[40m"
#define GREENBACKGROUND "\x1b[42m"

using namespace std;

using i8 = char;
using i16 = short;
using i32 = int;

class v2i16
{
public:
	i16 x;
	i16 y;

	bool operator==(const v2i16& other) const;
	bool operator!=(const v2i16& other) const;
};
