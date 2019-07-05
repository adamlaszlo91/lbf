#ifndef FIXEDINSTRUCTIONPROVIDER_H
#define FIXEDINSTRUCTIONPROVIDER_H

#include <string>
#include <stdexcept>
#include "InstructionProvider.h"

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
