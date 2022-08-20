/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		MAY 20, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <string>
#include "quiz.h"

using namespace std;

namespace quizzer {
    const int MAX_QUES = 60;
    const int MAX_ANSWER = 10;
    const int MAX_QUES_CHAR = 1024;
    const int MAX_ANSWER_CHAR = 128;
    // const char* filename = "quiz.txt";

    struct Question {
        std::string QuestionText;
        std::string Choices[MAX_ANSWER];
        int Answer;
    };
    struct Quiz {
        Question questions;
        int num_questions;
        char quizQuestions[MAX_QUES];
        int userScore;
        int shownQuestions;
        int remainingQuestions;
        char ifQuizTaken;
    };

    Quiz recs[MAX_QUES] = {};
    int noOfRecs = 0;
    int LoadQuiz(const char* filename) {
        Quiz quiz = {};
        bool ok = 0;
        FILE* fptr;
        fptr = fopen(filename, "r");
        if (fptr != NULL) {
            ok = 1;
            while (noOfRecs < MAX_QUES) {
                recs[noOfRecs++] = quiz;
            }
            if (fptr) fclose(fptr);
        }
        return ok;
    }
    int IsQuizValid() {
        int valid = 0;
        if (recs->questions->question >= 5 &&
            recs->questions->correctAnswers >= 1)
            valid = 1;
        return valid;
    }
    int HasMoreQuestions() {
        return recs->remainingQuestions;
    }
    void ShowNextQuestion() {

    }
    void ShowQuizResults() {
        cout << "QUIZ RESULTS: your score is " 
             << correctAnswer/num_question << "." << endl
    }

}