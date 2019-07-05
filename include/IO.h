#ifndef IO_H
#define IO_H

#include <fstream>

class IO{
  public:
    IO();
    static bool fileExists(std::string path);
    static std::string readFileContent(std::string path);

  protected:

  private:
};

#endif // IO_H
