#include "word.h"

Word::Word()
{

}

Word::Word(int i1, int i2, int i3)
{
    m_stabiEncrypted[0] = i1;
    m_stabiEncrypted[1] = i2;
    m_stabiEncrypted[2] = i3;
    m_iANSCIIplusKey = i1 +i2 +i3;
}

char Word::decode(int key) const
{
    return (char)(m_iANSCIIplusKey - key);
}

