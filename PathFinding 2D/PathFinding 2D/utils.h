#pragma once
#include <iostream>
#include <random>
#include <vector>

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
