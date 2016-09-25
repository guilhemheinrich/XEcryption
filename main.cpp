#include <QCoreApplication>
#include <fstream>
#include <iostream>
#include "stringhelper.h"
#include "word.h"
#include "text.h"

using namespace std;
typedef unsigned long ul;
int main(int argc, char *argv[])
{
    std::string input;
    std::vector<std::string> splitted_content;
    Text text;
    QCoreApplication a(argc, argv);
    std::string output;
    std::ofstream decryptedFileStream("decrypted_text.txt", std::ios::out);
    if (!decryptedFileStream.is_open())
    {
        return 0;
    }

    ifstream inputFile ("encrypted_text.txt");
    if (inputFile.is_open())
    {
        getline (inputFile,input);
        inputFile.close();
    }


//    std::getline(std::cin, input);

    cout << input.size() <<endl;
    splitted_content = splitOver(input, ".");
    splitted_content.erase(splitted_content.begin());

     cout << splitted_content.size() / 3 << endl;
    for (ul ulWordCount = 0; ulWordCount < splitted_content.size() / 3; ulWordCount++)
    {
        decryptedFileStream << Word((int)atoi(splitted_content[ulWordCount * 3 + 0].c_str()), (int)atoi(splitted_content[ulWordCount * 3 + 1].c_str()),
                (int)atoi(splitted_content[ulWordCount * 3 + 2].c_str())).decode(250);
        cout << Word((int)atoi(splitted_content[ulWordCount * 3 + 0].c_str()), (int)atoi(splitted_content[ulWordCount * 3 + 1].c_str()),
                (int)atoi(splitted_content[ulWordCount * 3 + 2].c_str())).decode(250);
    }
    decryptedFileStream.close();

#if 1
    while (true)
    {      
        cin >> input;
        splitted_content = splitOver(input, ".");
        splitted_content.erase(splitted_content.begin());

         cout << splitted_content.size() / 3 << endl;
        for (ul ulWordCount = 0; ulWordCount < splitted_content.size() / 3; ulWordCount++)
        {
            cout << Word((int)atoi(splitted_content[ulWordCount * 3 + 0].c_str()), (int)atoi(splitted_content[ulWordCount * 3 + 1].c_str()),
                    (int)atoi(splitted_content[ulWordCount * 3 + 2].c_str())).decode(250);
        }
    }
#endif

    return a.exec();
}

