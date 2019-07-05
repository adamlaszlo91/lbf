#include <iostream>

#include "include/InstructionProvider.h"
#include "include/FixedInstructionProvider.h"
#include "include/LiveInstructionProvider.h"
#include "include/BrainfuckExecutor.h"
#include "include/StdInputProvider.h"
#include "include/StdDisplay.h"
#include "include/IO.h"

using namespace std;

void warnIfToManyArgumentsPassed(int argc){
  if (argc > 2){
    cout << "WARNING: Too many parameters passed, only the first one will be used." << endl;
  }
}

InstructionProvider* createInstructionProvider(int argumentCount, char* argumentValues[]){
  if (argumentCount <= 1){
    return new LiveInstructionProvider();
  }else{
    if (IO::fileExists(argumentValues[1])){
      string fileContent = IO::readFileContent(argumentValues[1]);
      return new FixedInstructionProvider(fileContent);
    }else{
      throw invalid_argument("The input file does not exist.");
    }
  }
}

int main(int argc, char *argv[]){
  warnIfToManyArgumentsPassed(argc);
  try{
    InstructionProvider* instructionProvider = createInstructionProvider(argc, argv);
    BrainfuckExecutor* executor = new BrainfuckExecutor(instructionProvider, new StdInputProvider(), new StdDisplay());
    executor->execute();
  }catch( const std::exception& e ) {
    cerr << "ERROR: " << e.what();
    return 1;
  }
  return 0;
}


