#ifndef RECORD_H
#define RECORD_H

#include <string>
using std::string;

class Record {
public:
    string GetWord() const;
    int GetCount() const;
    int GetScoreTotal() const;

    void SetWord(string word);
    void SetCount(int count);
    void SetScoreTotal(int scoreTotal);

private:
    string _word;
    int _count;
    int _scoreTotal;
};

#endif //RECORD_H
