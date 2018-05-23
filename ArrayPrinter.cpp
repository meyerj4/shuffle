#include "ArrayPrinter.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::ostream_iterator;

ArrayPrinter::ArrayPrinter()
{
}

void ArrayPrinter::printList(const std::vector<unsigned int>& listToPrint) const
{
  std::cout << "Results of shuffling:" << std::endl;
  std::copy(
    listToPrint.begin(),
    listToPrint.end(),
    std::ostream_iterator<int>(std::cout, " "));
  cout << endl;
}
