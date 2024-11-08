#include <number.h>
#include "assert.h"

int main() {
  ASSERT((Rational{"1"} + Rational{"1"}).to_ratio_string(), "2/1");
  ASSERT((Rational{"999999999"} + Number{"1"}).to_ratio_string(), "1000000000/1");
  for(int i = -10000; i < 10000; ++i) {
    for(int j = -10000; j < 10000; ++j) {
      ASSERT((Rational{std::to_string(i)} + Rational{std::to_string(j)}).to_ratio_string(), std::to_string(i + j)+"/1");
    }
  }
  return 0;
}
