#include "FixedInputProvider.h"

using namespace std;

FixedInputProvider::FixedInputProvider(string input){
  this->input = input;
}

char FixedInputProvider::getNextInput(){
  // TODO: Implement
  return '.';
}

bool FixedInputProvider::hasNextInput(){
  // TODO: Implement
  return true;
}


