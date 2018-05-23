#ifndef StdRandomShuffleShuffler_h
#define StdRandomShuffleShuffler_h

#include "NumberShuffler.h"

#include <vector>
#include <unordered_set>
#include "NumberShufflerRangeProvider.h"

// Shuffles a list of numbers using the std::random_shuffle algorithm on a vector
// This is algorithm is efficient but is 5-10% slower than the ArraySwappingShuffler

class StdRandomShuffleShuffler :
  public NumberShuffler, public NumberShufflerRangeProvider
{
public:
  StdRandomShuffleShuffler();
  virtual void shuffleNumbers(unsigned int numbersToShuffle);
  virtual const std::vector<unsigned int>& getShuffledNumbers() const;

  virtual int getMaxInputValue() const;

private:
  void initializeArrayWithConsecutiveNumbers();

  unsigned int numberOfNumbersToShuffle;
  std::vector<unsigned int> numbersToShuffle;
};

#endif