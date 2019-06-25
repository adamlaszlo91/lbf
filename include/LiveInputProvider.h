#ifndef LIVEINPUTPROVIDER_H
#define LIVEINPUTPROVIDER_H

#include "InputProvider.h"


class LiveInputProvider : public InputProvider{
  public:
    LiveInputProvider();
    char getNextInput();
    bool hasNextInput();

  protected:

  private:
};

#endif // LIVEINPUTPROVIDER_H
