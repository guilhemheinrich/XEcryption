#ifndef STRINGHELPER
#define STRINGHELPER

#include <string>
typedef unsigned long ul;
#include <vector>

std::vector<ul> findAll(std::string in_sInputString, std::string in_sSplitter);
std::vector<std::string> splitOver(std::string in_sInputString, std::string in_sSplitter);

#include <sstream>
template<typename T> std::string printTab(const T *in_tabdToString, ul in_ulRange)
{
    std::ostringstream strs;
    for (ul ulIndex = 0; ulIndex < in_ulRange; ulIndex++)
    {
        strs << (T) in_tabdToString[ulIndex];
        if (ulIndex != in_ulRange - 1)
        {
            strs << ",";
        }
    }
    strs << "\n Ended print tab \n";
    std::string str = strs.str();
    return str;
}


template <typename Data>
std::string asString(Data dataToConvert)
{
    // From http://stackoverflow.com/questions/332111/how-do-i-convert-a-double-into-a-string-in-c
    std::ostringstream strs;
    strs << dataToConvert;
    return strs.str();
}

#endif // STRINGHELPER

