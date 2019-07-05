#ifndef BRAINFUCKEXECUTOR_H
#define BRAINFUCKEXECUTOR_H

#include "InstructionProvider.h"
#include "InputProvider.h"
#include "Display.h"
#include "Tape.h"

class BrainfuckExecutor{
  public:
    BrainfuckExecutor(InstructionProvider* instructionProviderm, InputProvider* inputProvider, Display* display);
    void execute();

  protected:

  private:
    short dataPointer = 0;

    Tape* tape;
    InstructionProvider* instructionProvider;
    InputProvider* inputProvider;
    Display* display;

    void executeInstruction(char instruction);
    bool isDataPointerOnZero();

    // TODO: Destructor
};

#endif // BRAINFUCKEXECUTOR_H
