#ifndef FIXEDINPUTPROVIDER_H
#define FIXEDINPUTPROVIDER_H

#include "InputProvider.h"
#include <iostream>

class FixedInputProvider : public InputProvider{
  public:
    FixedInputProvider(std::string input);
    char getNextInput();
    bool hasNextInput();

  protected:

  private:
    std::string input;
    int indexOnInput;
};

#endif // FIXEDINPUTPROVIDER_H
