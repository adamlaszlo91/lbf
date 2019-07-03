#ifndef BRAINFUCKEXECUTOR_H
#define BRAINFUCKEXECUTOR_H

#include <iostream>
#include "InstructionProvider.h"
#include "InputProvider.h"
#include "Tape.h"

class BrainfuckExecutor{
  public:
    BrainfuckExecutor(InstructionProvider* instructionProviderm, InputProvider* inputProvider);
    void execute();

  protected:

  private:
    Tape* tape;
    InstructionProvider* instructionProvider;
    InputProvider* inputProvider;
    short dataPointer = 0;

    void executeInstruction(char instruction);
    bool isDataPointerOnZero();

    // TODO: Destructor
};

#endif // BRAINFUCKEXECUTOR_H
