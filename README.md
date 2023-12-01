## Goal: 
This C++ program reads in a file of movie reviews extracted from the Rotten Tomatoes movie review website and uses the information to build a database of the words it finds in the review data. It then determins whether the movie review entered indicates a generally positive, negative, or neutral sentiment.  

## Running the program with a very small movie review file

Below is the screenshot showing a run of the program where the movie review file `aFewReviews.txt` was entered.

![image](https://user-images.githubusercontent.com/58283777/147018919-3636e038-17e3-4006-af6c-36cdd7cf6272.png)

As you can see the program begins by prompting the user to enter the name of a movie review file.  Unless you enter a full path name, the program expects the file to be in the `cmake-build-debug` directory of your project.

The program then builds a “database” from the information in the file.  When it finishes this task, it prints the time it took to read the file and build the database.  Your times will likely differ from the ones shown in the screenshots. You don't need to worry about the code to measure the time, it has been provided to you.

Next, the program prints summary information about the database that will give you some idea whether your database implementation is correct.

Following that, the user is prompted to type in a “review” for a movie so the program can determine numerical rating for the movie.  In the run shown above, just one or two words were entered for the review, so it is easier to understand how it works, but you can enter as many words as you would like before hitting [ENTER].

The user is allowed to enter as many reviews as desired.   When a blank line is entered, the program terminates.

## How the average score for a review is calculated

The file `aFewReviews.txt` looks like this:

 ![image](https://user-images.githubusercontent.com/58283777/147019058-200d2cfb-1716-4143-a20e-13011e4b194d.png)

It contains only three lines – the first and third lines are word wrapped because of their length.  Each line starts with an integer rating for a movie, followed by the text of the review.  The name of the movie is not given, because that isn’t important for what we are doing.

When the program opens a movie review file, it reads it line by line.  First it reads the numerical rating (score) and then it breaks the rest of the line into “words.”  For example, the “words” it finds on the second line would be:
```
This
quiet
,
introspective
and
entertaining
independent
is
worth
seeking
.
```
Note that a comma by itself or a period by itself is treated as a “word.”  If there were no blank characters between the letters of a word and the punctuation mark, then the letters and the punctuation mark together would form a “word.”  Blank characters  are used to break the string into words, but the blanks themselves never are “words” themselves.

Each time the program encounters a “word” it will record it in an in-memory “word database.” This database keeps track of how many times each word is seen (occurrence count) and maintains a running total of rating numbers (score totals). 

Here’s how it calculated the scores for the “reviews” entered in the run shown in the first screenshot in [Section 1](#Running-the-program-with-a-very-small-movie-review-file):
-	the word “`escapades`” is found once in the first review and nowhere else.  It would be recorded in the database with occurrence count of 1 and score total of 1 since the review it appeared once in a review that had rating 1.  Its average rating is 1/1 = 1.
-	the word “`introspective`” is found once in the second review and nowhere else.  It would be recorded in the database with occurrence count of 1 and score total of 4 since the review it appeared in had rating 4. Its average rating is 4/1 = 1.
-	The words “`This`” and “`this`” (**case matters!**) each appear once.  “`This`” appears on line 2 which has a rating of 4, so its average score is 4.  “`this`” appears on line 1 which has a rating of 1, so its average score is 1.
-	The word “`is`” appears twice in the first review, and once in the second review.  Hence, it will be stored in the database with occurrence count 3, and the score total will be 1+1+4 = 6.  It is 1+1 because of the two occurrences in a sentence with score 1, and adds the additional 4 because of the score of the second review. Its average rating is 6/3=2.
-	The word “`fantastic`” does not appear on any line.  It is not stored in the database, but when you query for its rating, the neutral rating of 2.0 is displayed.
-	When you enter multiple words, it takes the average of the word ratings.  So “`This is fantastic`” gets the score (4 + 2 + 2) / 3 = 2.66667, while “`this is fantastic`” gets the score (1 + 2 + 2) / 3 = 1.66667.


## Running the program with the full set of movie reviews

When everything seems to be working, you should try running with the file `movieReviews.txt`. You can type the name of the file if you wish, but if you enter a blank line, it defaults to this file. This is a considerably longer file.

![image](https://user-images.githubusercontent.com/58283777/147019513-8c6111de-95a7-4b99-83ae-59614ceb69d4.png)

