#ifndef RandomNumberGenerator_h
#define RandomNumberGenerator_h

// A random number generator

class RandomNumberGenerator
{
public:
  RandomNumberGenerator();
  static int generateRandomNumber(unsigned int maxRandomValue);

private:
  void seedRandomNumberGenerator();
};

#endif
