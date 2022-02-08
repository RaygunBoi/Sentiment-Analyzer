// Title: Lab 2 - Database.cpp
//
// Purpose: Implementations for the functions declared in Database.h.
//
// Class: CSC 2430 Winter 2022
// Author: Reagan Gunawan

#include "Database.h"

// This is the value used to score a word not found in the database
const double NEUTRAL = 2.0;

// Initializes the database needed to store records of words
// Parameters:
//      capacity - the amount of words the database is able to hold
//      records - the database itself
//      size - the size of the amount of records held within the database. Changes
//      depending on the amount of words stored within the database.
void InitDatabase(int capacity, Record records[], int& size) {
    size = 0;
    records[capacity];
}

// Adds word to database. If the word already exists, adds to the total occurrences of that word and also
// adds to the total score. Otherwise, adds word to the end of the database.
// Parameters:
//      database - the word database
//      word - the word that will be added to the database
//      score - the score of the word
// Returns:
//      true indicates word was successfully added, false indicates the database is full
bool AddWordToDatabase(int capacity, Record records[], int& size, const string& word, int score) {
    //iterates through database to check if word is already there
    for (int i = 0; i < size; ++i) {
        if (word == records[i].GetWord()) {
            records[i].SetCount(records[i].GetCount() + 1);
            records[i].SetScoreTotal(records[i].GetScoreTotal() + score);
            return true;
        }
    }

    //checks if size has reached capacity; otherwise, add word
    if (size > capacity) {
        return false;
    }
    else {
        records[size].SetWord(word);
        records[size].SetCount(1);
        records[size].SetScoreTotal(score);
        size++;
        return true;
    }
}

// Finds word within database. If the word is found, it returns the occurrences and the average score of that word.
// Parameters:
//      database - the word database
//      word - the word that needs to be found in the database
//      occurrences - the amount of times the word is found in the file
//      averageScore - the average of all the scores of the word
void FindWordInDatabase(const Record records[], int size, const string& word, int& occurrences, double& averageScore) {
    for(int i = 0; i < size; ++i) {
        if (word == records[i].GetWord()) {
            occurrences = records[i].GetCount();
            averageScore = records[i].GetScoreTotal() / static_cast<double>(occurrences);
            break;
        }
        else {
            occurrences = 0;
            averageScore = NEUTRAL;
        }
    }
}

// Gets the information about the database and calculates the average maximum and minimum scores
// Parameters:
//      database - the word database
//      numberWords - the total number of words in the file
//      maxOccurrences - the maximum amount of occurrences of a word in the database
//      minOccurrences - the minimum amount of occurrences of a word in the database
//      maxScore - the maximum average score of the total amount of scores in the database
//      minScore - the minimum average score of the total amount of scores in the database
void GetInfoAboutDatabase(const Record records[], int size, int& numberWords, int& maxOccurrences,
                          int& minOccurrences, double& maxScore, double& minScore){
    minOccurrences = records[0].GetCount();
    maxOccurrences = records[0].GetCount();
    minScore = static_cast<double>(records[0].GetScoreTotal());
    maxScore = static_cast<double>(records[0].GetScoreTotal());
    numberWords = size;
    for (int i = 1; i < size; ++i) {
        if (records[i].GetCount() < minOccurrences) {
            minOccurrences = records[i].GetCount();
        }
        if (records[i].GetCount() > maxOccurrences) {
            maxOccurrences = records[i].GetCount();
        }
        if (records[i].GetScoreTotal() < minScore) {
            minScore = records[i].GetScoreTotal() / static_cast<double>(records[i].GetCount());
        }
        if (records[i].GetScoreTotal() > maxScore) {
            maxScore = records[i].GetScoreTotal() / static_cast<double>(records[i].GetCount());
        }
    }
}