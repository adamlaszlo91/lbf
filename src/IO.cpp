#include "IO.h"

using namespace std;

IO::IO(){
}

bool IO::fileExists(string path){
  FILE *file;
  if((file = fopen(path.c_str(),"r"))!=NULL){
    fclose(file);
    return true;
  }else{
    return false;
  }
}

string IO::readFileContent(string path){
  ifstream fileStream(path);
  string content((std::istreambuf_iterator<char>(fileStream) ),(std::istreambuf_iterator<char>()) );
  return content;
}
