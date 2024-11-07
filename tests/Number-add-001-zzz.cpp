#include <number.h>

#define ASSERT(var) if (!(var)) return -1

int main() {
  ASSERT((Number{"1"} + Number{"1"}).num == "2");
  ASSERT((Number{"999999999"} + Number{"1"}).num == "1000000000");
  for(int i = -1000000; i < 1000000; ++i) {
    for(int j = -1000000; j < 1000000; ++j) {
      ASSERT((Number{std::to_string(i)} + Number{std::to_string(j)}).num == std::to_string(i + j));
    }
  }
  return 0;
}
