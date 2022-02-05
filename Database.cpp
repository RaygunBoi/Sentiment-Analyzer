// Title: Lab 2 - Database.cpp
//
// Purpose: **<state your purpose here>
//
// Class: CSC 2430 Winter 2022
// Author: **<your name goes here>

#include "database.h"

// This is the value used to score a word not found in the database
const double NEUTRAL = 2.0;

// **Add your implementations for InitDatabase, AddWordToDatabase, FindWordInDatabase, and GetInfoAboutDatabase
// **The parameter "records" is an array of Record objects.  Each Record stores information about one word.
// **The parameter "size" records the current number of slots in the array which are filled.
// **The parameter "capacity" specifies the maximum number of slots in the array.  If you were to
// **call AddWordToDatabase with a new word, and the current value of "size" was equal to "capacity" the
// **the function would not do the insertion and return false instead of true.

// **Don't forget to add header comments before each function using the following format:
// **<Describe what this function does
// Parameters:
//      **<parameter name> -- <description of parameter>
//      **<parameter name> -- <description of parameter>
//      **<parameter name> -- <description of parameter>
//      ...
// Returns:
//      **<describe meaning of return value or put "nothing" if this is a function declared void>
// Possible Errors:
//      **<describe possible errors>
//

