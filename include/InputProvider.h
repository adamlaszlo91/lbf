#ifndef INPUTPROVIDER_H
#define INPUTPROVIDER_H


class InputProvider
{
  public:
    virtual char getNextInput() = 0;
    virtual bool hasNextInput() = 0;

  protected:

  private:
};

#endif // INPUTPROVIDER_H
