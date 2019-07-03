#include <iostream>
#include <fstream>
#include "include/InstructionProvider.h"
#include "include/FixedInstructionProvider.h"
#include "include/LiveInstructionProvider.h"
#include "include/BrainfuckExecutor.h"
#include "include/StdInputProvider.h"

using namespace std;

string readFileContent(string fullPath){
  ifstream fileStream(fullPath);
  string content((std::istreambuf_iterator<char>(fileStream) ),(std::istreambuf_iterator<char>()) );
  return content;
}

bool doesFileExist(string fullPath){
  FILE *file;
  if((file = fopen(fullPath.c_str(),"r"))!=NULL){
    fclose(file);
    return true;
  }else{
    return false;
  }
}

int main(int argc, char *argv[]){
  InstructionProvider* instructionProvider;
  // TODO: argc > 1
  if (argc > 0){
    // TODO: Use parameter
    string path = "examples\\reverse.bf";
    if (doesFileExist(path)){
      string fileContent = readFileContent(path);
      instructionProvider = new FixedInstructionProvider(fileContent);
    }else{
      cerr << "The input file does not exist: " << path;
      return 1;
    }
  }else{
    instructionProvider = new LiveInstructionProvider();
  }

  BrainfuckExecutor* executor = new BrainfuckExecutor(instructionProvider, new StdInputProvider());
  try{
    executor->execute();
  }catch( const std::exception& e ) {
    // do stuff with exception...
    cerr << e.what();
  }

  return 0;
}
