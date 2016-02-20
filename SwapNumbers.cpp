#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

const unsigned int MAX_WORDS = 17;

void SwapNums(vector<string> &words);

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string line;

        while(getline(inputFile,line))
        {
            //cout << line << endl;

            vector<string> words;
            
            string temp;
            
            stringstream lineStream(line);

            while(getline(lineStream,temp,' '))
            {
                words.push_back(temp);
            }

            if(words.size() <= MAX_WORDS)
            {
                //cout << "NUMBER OF WORDS: " << words.size() << endl;
                SwapNums(words);
            }
            else
            {
                cout << "Too many words in the sentence. Max words is: " << MAX_WORDS << " , number of words in sentence: " << words.size() << endl;
            }

            unsigned int index = 0;

            for(vector<string>::const_iterator it=words.begin();
                it!=words.end();
                ++it)
            {
                if(index < words.size()-1)
                {
                    cout << *it << " ";
                }
                else
                {
                    cout << *it << endl;
                }

                ++index;
            }

            index = 0;

        }
    }
    else
    {
        cout << "error with input file" << endl;
    }

    return 0;
}

void SwapNums(vector<string> &words)
{
    string first;
    string last;

    for(vector<string>::iterator it=words.begin();
        it!=words.end();
        ++it)
    {
        first = *(it->begin());
        last = *(it->end()-1);

        //cout << "First: " << first << " last: " << last << endl;
        unsigned int f = first[0] - 48;
        unsigned int l = last[0] - 48;

        if(f>=0 && f<=9 && l>=0 && l<=9)
        {
            it->replace(it->begin(),it->begin()+1,last);
            it->replace(it->end()-1,it->end(),first);
        } 
        //cout << *it << endl;
    }
}
