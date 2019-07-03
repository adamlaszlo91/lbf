#ifndef INSTRUCTIONPROVIDER_H
#define INSTRUCTIONPROVIDER_H


class InstructionProvider{
  public:
    virtual char getNextInstruction() = 0;
    virtual bool hasNextInstruction() = 0;
    virtual void seekToMatchingOpeningBracketInstruction() = 0;
    virtual void seekToMatchingClosingBracketInstruction() = 0;

  protected:

  private:
};

#endif // INSTRUCTIONROVIDER_H
