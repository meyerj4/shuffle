#include "ArrayElementSwappingShuffler.h"
#include "RandomNumberGenerator.h"

#include <utility>
#include <ctime>
#include <iostream>

using std::swap;
using std::vector;
using std::cerr;

ArrayElementSwappingShuffler::ArrayElementSwappingShuffler() :
numberOfNumbersToShuffle(0)
{
}

void ArrayElementSwappingShuffler::shuffleNumbers(unsigned int numberOfNumbersToShuffle)
{
  this->numberOfNumbersToShuffle = numberOfNumbersToShuffle;
  try
  {
    initializeArrayWithConsecutiveNumbers();
    swapAllElementsWithRandomElements();
  }
  catch (std::exception& e)
  {
    handleSwappingError(e);
  }
}

void ArrayElementSwappingShuffler::initializeArrayWithConsecutiveNumbers()
{
  arrayToShuffle.resize(numberOfNumbersToShuffle);
  for (unsigned int i = 0; i < numberOfNumbersToShuffle; ++i)
  {
    arrayToShuffle[i] = i + 1;
  }
}

void ArrayElementSwappingShuffler::swapAllElementsWithRandomElements()
{
  RandomNumberGenerator randomIndexGenerator;
  for (unsigned int i = 0; i < numberOfNumbersToShuffle; ++i)
  {
    int randomElement = randomIndexGenerator.generateRandomNumber(numberOfNumbersToShuffle);
    swap(arrayToShuffle[randomElement], arrayToShuffle[i]);
  }
}

void ArrayElementSwappingShuffler::handleSwappingError(std::exception& e)
{
  cerr << "Error randomizing elements: " << e.what() << std::endl;
  throw;
}

const vector<unsigned int>& ArrayElementSwappingShuffler::getShuffledNumbers() const
{
  return arrayToShuffle;
}

int ArrayElementSwappingShuffler::getMaxInputValue() const
{
  return arrayToShuffle.max_size();
}
