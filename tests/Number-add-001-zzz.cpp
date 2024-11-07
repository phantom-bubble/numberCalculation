#include <number.h>

#define ASSERT(var) if (!(var)) return -1

int main() {
  ASSERT((Number{"1"} + Number{"1"}).num == "2");
  ASSERT((Number{"999999999"} + Number{"1"}).num == "1000000000");
  return 0;
}
