#ifndef NumberShuffler_h
#define NumberShuffler_h

#include <vector>

// An interface for all number shuffling classes

class NumberShuffler
{
public :
  virtual void shuffleNumbers(unsigned int numbersToShuffle) = 0;
  virtual const std::vector<unsigned int>& getShuffledNumbers() const = 0;
};

#endif
