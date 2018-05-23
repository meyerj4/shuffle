#include "RandomNumberGenerator.h"

#include <algorithm>
#include <ctime>

// We need to seed the random number generator
// Creating a static RandomNumberGenerator ensures this happens
static RandomNumberGenerator seeder;

RandomNumberGenerator::RandomNumberGenerator()
{
  seedRandomNumberGenerator();
}

void RandomNumberGenerator::seedRandomNumberGenerator()
{
  srand((unsigned)time(NULL));
}

int RandomNumberGenerator::generateRandomNumber(unsigned int maxRandomValue)
{
  // rand() becomes less random for large values of maxValue.
  // Consider using std::default_random_engine if more randomness is required
  // Warning: std::default_random_engine is slower than rand()
  return rand() % maxRandomValue;
}


