#ifndef STDINPUTPROVIDER_H
#define STDINPUTPROVIDER_H

#include <iostream>
#include <InputProvider.h>
#include <conio.h>

class StdInputProvider : public InputProvider{
  public:
    StdInputProvider();
    char getChar();

  protected:

  private:
};

#endif // STDINPUTPROVIDER_H
