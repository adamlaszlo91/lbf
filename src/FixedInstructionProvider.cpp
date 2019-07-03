#include "FixedInstructionProvider.h"

using namespace std;

FixedInstructionProvider::FixedInstructionProvider(string instructionString){
  this->instructionString = instructionString;
}

char FixedInstructionProvider::getNextInstruction(){
  char instruction = instructionString.at(instructionPointer);
  instructionPointer++;
  return instruction;
}

bool FixedInstructionProvider::hasNextInstruction(){
  return instructionPointer < instructionString.length();
}

void FixedInstructionProvider::seekToMatchingOpeningBracketInstruction(){
  int bracketCounter = 0;
  int pointer = instructionPointer - 1;
  while (pointer >= 0){
    char instruction = instructionString.at(pointer);
    if (instruction == '['){
      bracketCounter++;
    }else if (instruction == ']'){
      bracketCounter--;
    }
    if (bracketCounter == 0){
      instructionPointer = pointer;
      return;
    }

    pointer--;
  }

  throw out_of_range("Could not find matching opening bracket instruction for pointer: " + instructionPointer);
}

void FixedInstructionProvider::seekToMatchingClosingBracketInstruction(){
  int bracketCounter = 0;
  int pointer = instructionPointer - 1;
  while (pointer < instructionString.length()){
    char instruction = instructionString.at(pointer);
    if (instruction == '['){
      bracketCounter++;
    }else if (instruction == ']'){
      bracketCounter--;
    }
    if (bracketCounter == 0){
      instructionPointer = pointer;
      return;
    }

    pointer++;
  }

  throw out_of_range("Could not find matching closing bracket instruction for pointer: " + instructionPointer);
}

