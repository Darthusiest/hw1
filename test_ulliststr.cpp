#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
ULListStr* unrolled_LL = new ULListStr();

unrolled_LL->push_back("1");
unrolled_LL->push_front("7");
unrolled_LL->push_back("4");

std::cout << unrolled_LL->get(0) << ", " << unrolled_LL->get(1) << ", " << unrolled_LL->get(2) << std::endl;
std::cout << "Size: " << unrolled_LL->size() << std::endl;

unrolled_LL->pop_front();
unrolled_LL->pop_back();

std::cout << unrolled_LL->get(0) << std::endl;

delete unrolled_LL;

  return 0;
}
