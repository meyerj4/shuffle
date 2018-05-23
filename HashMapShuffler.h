#ifndef HashMapShuffler_h
#define HashMapShuffler_h

#include "NumberShuffler.h"
#include "NumberShufflerRangeProvider.h"
#include <unordered_map>
#include <vector>

// Shuffles a list of numbers using a hash map
// Hash map is indexed by 0..numberOfNumbers-1 and corresponding values at that index
// This implementation is highly inefficient due to lengthy insertion and access times
// when the hash map becomes large.
// I thought a hash map might have advantages such as a larger
// maximum size, but sadly, this is not the case.

class HashMapShuffler :
  public NumberShuffler, public NumberShufflerRangeProvider
{
public:
  HashMapShuffler();

  void shuffleNumbers(unsigned int numberOfNumbers);
  const std::vector<unsigned int>& getShuffledNumbers() const;

  virtual int getMaxInputValue() const;

private:
  void swapAllElementsWithRandomElements();
  void initializeHashMap();

  std::unordered_map<unsigned int, unsigned int> mapToShuffle;
  unsigned int numbersOfNumbersToShuffle;
  mutable std::vector<unsigned int> randomNumberArray;
};

#endif
