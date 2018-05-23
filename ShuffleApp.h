#ifndef ShuffleApp_h
#define ShuffleApp_h

// Handles the logic of the shuffling app

class ShuffleApp
{
public:
  ShuffleApp();
  void run();
  bool shouldRun() const;

private:
  void handleShufflingError();

private:
  bool runAgain;
};

#endif
