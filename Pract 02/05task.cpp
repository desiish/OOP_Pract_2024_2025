#include <iostream>

using namespace std;

struct Exam {
    static const int SIZE = 50;
    int points;
    char answers[4][SIZE];
    char heading[SIZE];
    char correctAnsw;

    Exam(int pointsQ = 0, char answersQ[4][SIZE] = nullptr, char headingQ[SIZE] = nullptr, char correct = 'a')
        : points(pointsQ), correctAnsw(correct) {

        for (int i = 0; i < SIZE; i++) heading[i] = '\0';

        if (headingQ) {
            for (int i = 0; i < SIZE - 1 && headingQ[i] != '\0'; i++) {
                heading[i] = headingQ[i];
            }
            heading[SIZE - 1] = '\0'; 
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < SIZE; j++) answers[i][j] = '\0';

            if (answersQ) {
                for (int j = 0; j < SIZE - 1 && answersQ[i][j] != '\0'; j++) {
                    answers[i][j] = answersQ[i][j];
                }
                answers[i][SIZE - 1] = '\0';
            }
        }
    }

    void display() {
        cout << "Question: " << heading << endl;
        for (int i = 0; i < 4; i++) {
            if (answers[i][0] != '\0') { 
                cout << char('a' + i) << ") " << answers[i] << endl;
            }
        }
        cout << "Points: " << points << endl;
    }
};


int compareAnswers(Exam* exams, char* userAnswers, int numQuestions) {
    int totalPoints = 0;

    for (int i = 0; i < numQuestions; i++) {
        if (tolower(userAnswers[i]) == exams[i].correctAnsw) {
            totalPoints += exams[i].points;
        }
    }

    return totalPoints;
}

int main() {
    int numQuestions;
    cout << "Enter the number of questions: ";
    cin >> numQuestions;
    cin.ignore();

    Exam* exams = new Exam[numQuestions];

    for (int i = 0; i < numQuestions; i++) {
        char tempHeading[Exam::SIZE] = {};
        char tempAnswers[4][Exam::SIZE] = {};
        char correct;
        int points;

        cout << "Enter question " << i + 1 << ": ";
        cin.getline(tempHeading, Exam::SIZE);

        for (int j = 0; j < 4; j++) {
            cout << "Enter option " << char('a' + j) << ": ";
            cin.getline(tempAnswers[j], Exam::SIZE);
        }

        cout << "Enter correct answer (a/b/c/d): ";
        cin >> correct;
        correct = tolower(correct);
        cin.ignore();

        cout << "Enter points for this question: ";
        cin >> points;
        cin.ignore();

        exams[i] = Exam(points, tempAnswers, tempHeading, correct);
    }

    cout << "\nExam Questions:\n";
    for (int i = 0; i < numQuestions; i++) {
        exams[i].display();
        cout << "------------------\n";
    }

    char* userAnswers = new char[numQuestions];
    for (int i = 0; i < numQuestions; i++) {
        cout << "\nAnswer question " << i + 1 << " (a/b/c/d): ";
        cin >> userAnswers[i];
        userAnswers[i] = tolower(userAnswers[i]);
    }


    int finalResult = compareAnswers(exams, userAnswers, numQuestions);
    cout << "\nYour total score: " << finalResult << " points\n";

    delete[] userAnswers;
    delete[] exams;

}
