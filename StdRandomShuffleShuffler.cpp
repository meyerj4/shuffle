#include "StdRandomShuffleShuffler.h"
#include <time.h>
#include <ctime>
#include <algorithm>
#include "RandomNumberGenerator.h"

using std::vector;
using std::random_shuffle;

StdRandomShuffleShuffler::StdRandomShuffleShuffler() :
numberOfNumbersToShuffle(0)
{
}

void StdRandomShuffleShuffler::shuffleNumbers(unsigned int numberOfNumbersToShuffle)
{
  this->numberOfNumbersToShuffle = numberOfNumbersToShuffle;
  initializeArrayWithConsecutiveNumbers();

  random_shuffle(numbersToShuffle.begin(), numbersToShuffle.end(), RandomNumberGenerator::generateRandomNumber);
}

void StdRandomShuffleShuffler::initializeArrayWithConsecutiveNumbers()
{
  numbersToShuffle.resize(numberOfNumbersToShuffle);
  for (unsigned int i = 0; i < numberOfNumbersToShuffle; ++i)
  {
    numbersToShuffle[i] = i + 1;
  }
}

const vector<unsigned int>& StdRandomShuffleShuffler::getShuffledNumbers() const
{
  return numbersToShuffle;
}

int StdRandomShuffleShuffler::getMaxInputValue() const
{
  return numbersToShuffle.max_size();
}