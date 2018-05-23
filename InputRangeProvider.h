#ifndef InputRangeProvider_h
#define InputRangeProvider_h

// An interface for providing maximum and minimum input values

class InputRangeProvider {
public:
  virtual int getMinInputValue() const = 0;
  virtual int getMaxInputValue() const = 0;
};

#endif
