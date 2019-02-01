#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * takes user input for score
 * @param prompt - user prompt for type of score to enter
 * @param minValue - minimum value accepted for score
 * @return score to add to vector
 */
int getScore(string prompt, int minValue) {
    int score;
    cout << prompt;
    cin >> score;
    while (!cin || score < minValue || score > 100) { //FIX ME
        if (!cin) {
            cout << "Sorry, your input must be an integer. Please try again." << endl;
        }
        else if (score < minValue || score > 100) {
            cout << "Sorry, your input must be between 0 and 100. Please try again." << endl;
        }
        cin.clear();
        cin.ignore(1024, '\n');
        cout << prompt;
        cin >> score;
    }
    return score;
}

/**
 * set vector limit and fill with homework scores
 * @param scores - vector to store homework scores
 */
void fillScores(vector<int>& scores) {
    string userPrompt = "Enter the score for a homework assignment: ";
    int currentScore;
    //get input for scores (loop)
    currentScore = getScore(userPrompt, -1);
    while (currentScore != -1) {
        scores.push_back(currentScore);
        currentScore = getScore(userPrompt, -1);
    }
}


/**
 * Finds median of vector
 * @param scores - vector of inputted scores
 * @return median of vector
 */
double FindMedianScore(vector<int>& scores) {
    double median;
    sort(scores.begin(), scores.end());
    // even
    if (scores.size() % 2 == 0) {
        median = (scores.at((scores.size()/2)) + scores.at(((scores.size() / 2) - 1))) / 2.0;
    }
    // odd
    else if (scores.size() % 2 == 1) {
        median = scores.at(scores.size() / 2);
    }
    return median;
}

/**
 * finds letter grade corresponding to total score
 * @param totalScore - total score of all inputted exams and median homework score
 * @return letter grade of scores
 */
string CalculateLetterGrade(int totalScore) {
    int score = totalScore;
    string letterGrade;
    if (score <= 180) {
        letterGrade = "fail";
    }
    else if (score <= 200 && score >= 181) {
        letterGrade = "D-";
    }
    else if (score <= 220 && score >= 201) {
        letterGrade = "D";
    }
    else if (score <= 240 && score >= 221) {
        letterGrade = "D+";
    }
    else if (score <=260 && score >= 241) {
        letterGrade = "C-";
    }
    else if (score <= 280 && score >= 261) {
        letterGrade = "C";
    }
    else if (score <= 300 && score >= 281) {
        letterGrade = "C+";
    }
    else if (score <= 320 && score >= 301) {
        letterGrade = "B-";
    }
    else if (score <= 340 && score >= 321) {
        letterGrade = "B";
    }
    else if (score <= 360 && score >= 341) {
        letterGrade = "B+";
    }
    else if (score <= 380 && score >= 361) {
        letterGrade = "A-";
    }
    else if (score <= 400 && score >= 381) {
        letterGrade = "A";
    }
    return letterGrade;
}

void getAllScores(int& midterm1, int& midterm2, int& finalExam, vector<int>& homeworkScores) {
    midterm1 = getScore("Please enter in the score for the first exam: ", 0);
    midterm2 = getScore("Please enter in the score for the second exam: ", 0);
    finalExam = getScore("Please enter in the score for the final exam: ", 0);
    fillScores(homeworkScores);
}

int main() {
    int midterm1;
    int midterm2;
    int finalExam;
    int totalScore;
    double homeworkMedian;
    vector<int> homeworkScores;

    cout << "Dr. DoLittle's Grading Program ....." << endl;

    getAllScores(midterm1, midterm2, finalExam, homeworkScores);
    homeworkMedian = FindMedianScore(homeworkScores);
    totalScore = midterm1 + midterm2 + finalExam + homeworkMedian;

    cout << endl;

    cout << "The median homework score was " << homeworkMedian << endl;
    cout << "The total points earned was " << totalScore << endl;
    cout << "The letter calculated letter grade is " << CalculateLetterGrade(totalScore) << endl;

    return 0;
}