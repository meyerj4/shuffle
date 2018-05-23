#ifndef ArrayPrinter_h
#define ArrayPrinter_h

#include <vector>

// Prints an array of numbers to the console

class ArrayPrinter
{
public:
  ArrayPrinter();
  void printList(const std::vector<unsigned int>& listToPrint) const;
};

#endif
