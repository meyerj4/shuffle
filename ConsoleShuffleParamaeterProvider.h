#ifndef ConsoleShuffleParamaeterProvider_h
#define ConsoleShuffleParamaeterProvider_h

#include <string>

class InputRangeProvider;

// Provides necessary parameters for shuffling a list of numbers
// Input is provided from the console

class ConsoleShuffleParamaeterProvider
{
public:
  ConsoleShuffleParamaeterProvider(const InputRangeProvider& rangeProvider);
  unsigned int getNumberOfNumbersToShuffle();

private:
  void askForParameters();
  void askForInputFromConsole();
  void clearStream();
  bool inputIsValid();
  bool errorInInput();
  std::string getRangeString();

  int numberOfNumbersToShuffle;
  bool userHasInputData;
  const InputRangeProvider& inputRangeProvider;
};

#endif
