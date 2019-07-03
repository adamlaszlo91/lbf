#include "Tape.h"

using namespace std;

Tape::Tape(){
  cells = new char[TAPE_LENGTH];
  fill_n(cells, TAPE_LENGTH, 0);
}

void Tape::checkPointerIntegrity(short dataPointer){
  if (dataPointer < 0 || dataPointer >= TAPE_LENGTH){
    throw out_of_range("Data pointer is out of tape size. Got value: " + dataPointer);
  }
}

char Tape::getValueAtPointer(short dataPointer){
  checkPointerIntegrity(dataPointer);
  return cells[dataPointer];
}

void Tape::setValueAtPointer(short dataPointer, char value){
  checkPointerIntegrity(dataPointer);
  cells[dataPointer] = value;
}

void Tape::increaseValueAtPointer(short dataPointer){
  checkPointerIntegrity(dataPointer);
  cells[dataPointer]++;
}

void Tape::decreaseValueAtPointer(short dataPointer){
  checkPointerIntegrity(dataPointer);
  cells[dataPointer]--;
}
