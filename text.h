#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <QVector>
#include <QMap>
#include <QtAlgorithms>
#include "word.h"


class Text
{
public:
    Text();
    Text(QVector<Word> text);


    void reset();
    void add(Word letter);
    void computeScoreMap();
    void printBest3();
    std::string printKey(int key);

    QMap<int , int> m_scoreMap;

    std::vector<Word> m_wordContent;


    // Maximum value for the key
    int maxKey;
private:

};

#endif // TEXT_H
