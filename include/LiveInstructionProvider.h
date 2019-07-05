#ifndef LIVEINSTRUCTIONPROVIDER_H
#define LIVEINSTRUCTIONPROVIDER_H

#include "InstructionProvider.h"

class LiveInstructionProvider : public InstructionProvider{
  public:
    LiveInstructionProvider();
    char getNextInstruction();
    bool hasNextInstruction();
    void seekToMatchingOpeningBracketInstruction();
    void seekToMatchingClosingBracketInstruction();

  protected:

  private:
};

#endif // LIVEINSTRUCTIONPROVIDER_H
