#include "HashMapShuffler.h"
#include "RandomNumberGenerator.h"

#include <utility>
#include <vector>

using std::vector;
using std::swap;

HashMapShuffler::HashMapShuffler() :
numbersOfNumbersToShuffle(0)
{
}

void HashMapShuffler::shuffleNumbers(unsigned int numbersToShuffle)
{
  this->numbersOfNumbersToShuffle = numbersToShuffle;
  initializeHashMap();
  swapAllElementsWithRandomElements();
}

const std::vector<unsigned int>& HashMapShuffler::getShuffledNumbers() const
{
  for (auto mapIterator : mapToShuffle) {
    randomNumberArray.push_back(mapIterator.second);
  }
  return randomNumberArray;
}

void HashMapShuffler::initializeHashMap()
{
  mapToShuffle.reserve(numbersOfNumbersToShuffle);
  for (unsigned int i = 0; i < numbersOfNumbersToShuffle; ++i)
  {
    mapToShuffle[i] = i+1;
  }
}

void HashMapShuffler::swapAllElementsWithRandomElements()
{
  RandomNumberGenerator randomNumberGenerator;

  for (unsigned int i = 0; i < numbersOfNumbersToShuffle; ++i)
  {
    int indexToSwap = randomNumberGenerator.generateRandomNumber(numbersOfNumbersToShuffle);
    unsigned int& sequentialElement = mapToShuffle[i];
    unsigned int& randomElement = mapToShuffle[indexToSwap];
    swap(sequentialElement, randomElement);
  }
}

int HashMapShuffler::getMaxInputValue() const
{
  return mapToShuffle.max_size();
}
