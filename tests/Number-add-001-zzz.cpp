#include <number.h>

#define ASSERT(var) if (!(var)) return -1

int main() {
  ASSERT((Number{"1"} + Number{"1"}).num == "2");
  return 0;
}
