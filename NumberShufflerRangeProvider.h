#ifndef NumberShufflerRangeProvider_h
#define NumberShufflerRangeProvider_h

#include "InputRangeProvider.h"

// Provides a minimum range value for use in all number shufflers
// 1 is the minimum number of numbers that can be shuffled (but is trivial)

class NumberShufflerRangeProvider :
  public InputRangeProvider
{
public:
  virtual int getMinInputValue() const { return 1; }
};

#endif
