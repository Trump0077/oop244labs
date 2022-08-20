/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		MAY 20, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_QUIZ_H
#define SDDS_QUIZ_H

namespace quizzer {
	int LoadQuiz(const char* filename);
	int IsQuizValid();
	int HasMoreQuestions();
	void ShowNextQuestion();
	void ShowQuizResults();
}

#endif
