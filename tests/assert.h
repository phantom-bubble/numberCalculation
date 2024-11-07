#pragma once

#include <iostream>
#define ASSERT(expression, result) if ((expression) != (result)) { std::cout << (expression) << " != " << (result) << "\n"; return -1; }