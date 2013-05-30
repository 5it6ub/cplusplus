#include <iostream>

class Test {
private:
  long* mp_l;
  int instance;
  static int counter;
public:
  Test(void);
  ~Test(void);
};

int Test::counter = 0;

Test::Test(void) {
  instance = ++counter;
  mp_l = new long;
  std::cout << "Constructing instance " << instance << " of Test" << std::endl;
}

Test::~Test(void) {
  delete mp_l;
  std::cout << "Destructing instnace " << instance << " of Test" << std::endl;
}

int main() {
  Test* p_Test = new Test[5];
  std::cout << "Memory before start of test = " <<
    std::hex << p_Test << std::endl <<
    "------------------------------------" << std::endl;
  std::cout << "Memory at enf of test = " <<
    std::hex << p_Test << std::endl;

  delete [] p_Test;

  return 0;
}
