#include <iostream>
#include <fstream>
#include "include/InputProvider.h"
#include "include/FixedInputProvider.h"
#include "include/LiveInputProvider.h"

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
  InputProvider* inputProvider;
  // TODO: argc > 1
  if (argc > 0){
    // TODO: Use parameter
    string path = "examples\\hw.bf";
    if (doesFileExist(path)){
      string fileContent = readFileContent(path);
      cout << fileContent;  // TODO: remove
      inputProvider = new FixedInputProvider(fileContent);
    }else{
      cerr << "The input file does not exist: " << path;
      return 1;
    }
  }else{
    inputProvider = new LiveInputProvider();
  }

  return 0;
}
