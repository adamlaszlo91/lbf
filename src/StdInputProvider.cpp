#include "StdInputProvider.h"

StdInputProvider::StdInputProvider(){

}

char StdInputProvider::getChar(){
  return getch();
}
