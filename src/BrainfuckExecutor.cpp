#include "BrainfuckExecutor.h"

using namespace std;

BrainfuckExecutor::BrainfuckExecutor(InstructionProvider* instructionProvider, InputProvider* inputProvider){
  this->instructionProvider = instructionProvider;
  this->inputProvider = inputProvider;
  tape = new Tape();
}

void BrainfuckExecutor::execute(){
  while (instructionProvider->hasNextInstruction()){
    char instruction = instructionProvider->getNextInstruction();
    executeInstruction(instruction);
  }
}

bool BrainfuckExecutor::isDataPointerOnZero(){
  return tape->getValueAtPointer(dataPointer) == 0;
}

void BrainfuckExecutor::executeInstruction(char instruction){
  switch (instruction){
    case '<':
      dataPointer--;
      break;
    case '>':
      dataPointer++;
      break;
    case '+':
      tape->increaseValueAtPointer(dataPointer);
      break;
    case '-':
      tape->decreaseValueAtPointer(dataPointer);
      break;
    case '.':
      // TODO: Use Display class
      cout << tape->getValueAtPointer(dataPointer);
      break;
    case ',':
      tape->setValueAtPointer(dataPointer, inputProvider->getChar());
      break;
    case '[':
      // TODO Implement behavior for live instruction
      if (isDataPointerOnZero()){
        instructionProvider->seekToMatchingClosingBracketInstruction();
      }
      break;
    case ']':
      // TODO Implement behavior for live instruction
      if (!isDataPointerOnZero()){
        instructionProvider->seekToMatchingOpeningBracketInstruction();
      }
      break;
  }
}


