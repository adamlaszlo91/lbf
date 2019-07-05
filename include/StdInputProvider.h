#ifndef STDINPUTPROVIDER_H
#define STDINPUTPROVIDER_H

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
