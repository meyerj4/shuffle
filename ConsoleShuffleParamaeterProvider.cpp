#include "ConsoleShuffleParamaeterProvider.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

#include "InputRangeProvider.h"

ConsoleShuffleParamaeterProvider::ConsoleShuffleParamaeterProvider(const InputRangeProvider& rangeProvider) :
userHasInputData(false),
numberOfNumbersToShuffle(0),
inputRangeProvider(rangeProvider)
{

}

unsigned int ConsoleShuffleParamaeterProvider::getNumberOfNumbersToShuffle()
{
  askForParameters();
  return numberOfNumbersToShuffle;
}

void ConsoleShuffleParamaeterProvider::askForParameters()
{
  do {
    askForInputFromConsole();
  } while (!inputIsValid());
}

void ConsoleShuffleParamaeterProvider::askForInputFromConsole()
{
  if (errorInInput())
  {
    clearStream();
    cout << "Input was invalid. Valid range is " << getRangeString() << endl;
  }
  
  cout << "Enter the number of numbers to shuffle " << getRangeString() << ": ";
  cin >> numberOfNumbersToShuffle;
  userHasInputData = true;
}

std::string ConsoleShuffleParamaeterProvider::getRangeString()
{
  std::string rangeString;
  rangeString = "[" +
    std::to_string(inputRangeProvider.getMinInputValue()) +
    ", " +
    std::to_string(inputRangeProvider.getMaxInputValue()) +
    "]";
  return rangeString;
}
bool ConsoleShuffleParamaeterProvider::errorInInput()
{
  return userHasInputData && !inputIsValid();
}

bool ConsoleShuffleParamaeterProvider::inputIsValid()
{
  return
    numberOfNumbersToShuffle >= inputRangeProvider.getMinInputValue() &&
    numberOfNumbersToShuffle <= inputRangeProvider.getMaxInputValue();
}

void ConsoleShuffleParamaeterProvider::clearStream()
{
  if (userHasInputData)
  {
    cin.clear();
    cin.ignore();
  }
}


