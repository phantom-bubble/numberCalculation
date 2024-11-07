#pragma once

#include <iostream>
#define ASSERT(var) if (!(var)) { std::cout << #var << "\n"; return -1; }