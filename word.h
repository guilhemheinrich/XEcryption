#ifndef WORD_H
#define WORD_H


struct Word
{
public:
    Word();
    // i1 = (ANSCII value + key) / 3 + rand(10)
    // i2 = (ANSCII value + key) / 3 + rand(10)
    // i3 = (ANSCII value + key) - i1 -i2
    // Therefore, i1 + i2 +i3 = ANSCII value + key
    Word(int i1, int i2, int i3);

    char decode(int key) const;

    int m_stabiEncrypted[3];
    int m_iANSCIIplusKey;
private:


};

#endif // WORD_H
