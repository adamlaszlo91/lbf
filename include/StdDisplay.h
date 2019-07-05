#ifndef STDDISPLAY_H
#define STDDISPLAY_H

#include <iostream>
#include "Display.h"

class StdDisplay : public Display{
  public:
    StdDisplay();
    void printOutput(char output);

  protected:

  private:
};

#endif // STDDISPLAY_H
