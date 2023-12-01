#ifndef DATABASE_H
#define DATABASE_H

#include "Record.h"

const int CAPACITY  = 20000;

void InitDatabase(int capacity, Record records[], int& size);
bool AddWordToDatabase(int capacity, Record records[], int& size, const string& word, int score);
void FindWordInDatabase(const Record records[], int size,
        const string& word, int& occurrences, double& averageScore);
void GetInfoAboutDatabase(const Record records[], int size,
        int& numberWords, int& maxOccurrences, int& minOccurrences, double& maxScore, double& minScore);

#endif //DATABASE_H
