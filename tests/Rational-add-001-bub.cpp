#include <rational.h>
#include "assert.h"

int main() {
	ASSERT((Rational("0.7") + Rational("0.7")).numerator.num, "7");
	ASSERT((Rational("0.7") + Rational("0.7")).denominator.num, "5");
	return 0;
}