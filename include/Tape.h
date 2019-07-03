#ifndef TAPE_H
#define TAPE_H

#include <algorithm>
#include <stdexcept>

const short TAPE_LENGTH = 30000;

class Tape{
  public:
    Tape();
    char getValueAtPointer(short dataPointer);
    void setValueAtPointer(short dataPointer, char value);
    void increaseValueAtPointer(short dataPointer);
    void decreaseValueAtPointer(short dataPointer);

  protected:

  private:
    char* cells;

    void checkPointerIntegrity(short dataPointer);
};

#endif // TAPE_H
