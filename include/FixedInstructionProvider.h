#ifndef FIXEDINSTRUCTIONPROVIDER_H
#define FIXEDINSTRUCTIONPROVIDER_H

#include "InstructionProvider.h"
#include <iostream>

class FixedInstructionProvider : public InstructionProvider{
  public:
    FixedInstructionProvider(std::string instruction);
    char getNextInstruction();
    bool hasNextInstruction();
    void seekToMatchingOpeningBracketInstruction();
    void seekToMatchingClosingBracketInstruction();

  protected:

  private:
    std::string instructionString = "";
    short instructionPointer = 0;
};

#endif // FIXEDIINSTRUCTIONPROVIDER_H
