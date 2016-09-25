#include "text.h"
#include "stringhelper.h"

Text::Text()
{

}

void Text::reset()
{
    m_wordContent.clear();
}

void Text::add(Word letter)
{
    m_wordContent.push_back(letter);
}

void Text::computeScoreMap()
{
    int score;
    char ANSCIIletter;
    maxKey = 1000;
    for (Word letter : m_wordContent)
    {
        if (maxKey > letter.m_iANSCIIplusKey) maxKey = letter.m_iANSCIIplusKey;
    }
    for (int key = 0; key <= maxKey; key++)
    {
        score = 0;
        for (Word letter : m_wordContent)
        {
            ANSCIIletter = letter.decode(key);
//            std::cout<< ANSCIIletter << std::endl;
            if (ANSCIIletter < 48 ||
                (ANSCIIletter > 57  && ANSCIIletter < 65) ||
                ANSCIIletter > 122 )
            {
                score ++;
            }
        }
        m_scoreMap.insert(key, score);
    }
}

void Text::printBest3()
{
    QList<int> sortedValues = m_scoreMap.values();
    qSort(sortedValues.begin(), sortedValues.end());
    QList<int> bo3Keys;

    for (long index = 0; index < 1; index++)
    {
        bo3Keys = m_scoreMap.keys(sortedValues[/*sortedValues.size() - 1 - */index]);
        std::cout << "score of " << sortedValues[index] << std::endl;
        for (int key : bo3Keys)
        {
            std::cout<< "key of " << key << std::endl;
            int letterCpt = 0;
            for (Word letter : m_wordContent)
            {
                std::cout << letter.decode(key);
//                letterCpt++;
//                if (letterCpt == 30)
//                {
//                    letterCpt = 0;
//                    std::cout << std::endl;
//                }
            }
            std::cout << std::endl;
        }
    }


}


std::string Text::printKey(int key)
{
    std::string out_string;
    out_string +=  "key of " + asString(key) +"\n";
    for (Word letter : m_wordContent)
    {
        out_string += asString(letter.decode(key));
//        letterCpt++;
//        if (letterCpt == 30)
//        {
//            letterCpt = 0;
//            std::cout << std::endl;
//        }
    }
    return out_string;
}

