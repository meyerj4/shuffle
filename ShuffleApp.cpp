#include "ShuffleApp.h"

#include "ConsoleShuffleParamaeterProvider.h"
#include "ArrayPrinter.h"
#include "ArrayElementSwappingShuffler.h"
#include "StdRandomShuffleShuffler.h"
#include "HashMapShuffler.h"

#include <iostream>
#include <exception>

ShuffleApp::ShuffleApp() :
runAgain(true)
{

}

void ShuffleApp::run()
{
  while (shouldRun())
  {
    try
    {
      ArrayElementSwappingShuffler shuffler;
      ConsoleShuffleParamaeterProvider parameterProvider(shuffler);

      unsigned int numberOfNumbersToShuffle = parameterProvider.getNumberOfNumbersToShuffle();
      shuffler.shuffleNumbers(numberOfNumbersToShuffle);
      ArrayPrinter().printList(shuffler.getShuffledNumbers());

      runAgain = false;
    }
    catch (std::exception&)
    {
      handleShufflingError();
    }
  }
}

void ShuffleApp::handleShufflingError()
{
  std::cout << "An error occured. Try again." << std::endl;
  runAgain = true;
}

bool ShuffleApp::shouldRun() const
{
  return runAgain;
}
