#ifndef ArraySwappingShuffler_h
#define ArraySwappingShuffler_h

#include "NumberShuffler.h"
#include "NumberShufflerRangeProvider.h"

#include <vector>

// Shuffles a list of numbers using a vector
// This is the most efficient implementation I could find
// The algorithm is simple: for all elements of the array, swap the element with a random element

class ArrayElementSwappingShuffler :
  public NumberShuffler, public NumberShufflerRangeProvider
{
public:
  ArrayElementSwappingShuffler();

  void shuffleNumbers(unsigned int numbersToShuffle);
  const std::vector<unsigned int>& getShuffledNumbers() const;

  virtual int getMaxInputValue() const;

private:
  void initializeArrayWithConsecutiveNumbers();
  void swapAllElementsWithRandomElements();
  void handleSwappingError(std::exception& e);

  std::vector<unsigned int> arrayToShuffle;
  unsigned int numberOfNumbersToShuffle;
};

#endif
