#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int loadData(const char filename[], int ids[], int scores[], int maxSize) {
    ifstream infile(filename);
    if (!infile) return 0;

    string header;
    getline(infile, header);

    int count = 0;
    char comma;
    while (count < maxSize && infile >> ids[count] >> comma >> scores[count])
        count++;

    return count;
}
void printAll(int ids[], int scores[], int size) {
    for (int i = 0; i < size; i++)
        cout << "StudentID: " << ids[i] << "   Score: " << scores[i] << endl;
}
void computeStats(int scores[], int size, double &avg, int &minScore, int &maxScore) {
    if (size == 0) return;

    int sum = 0;
    minScore = maxScore = scores[0];
    for (int i = 0; i < size; i++) {
        sum += scores[i];
        if (scores[i] < minScore) minScore = scores[i];
        if (scores[i] > maxScore) maxScore = scores[i];
    }
    avg = double(sum) / size;
}
void computeGradeDistribution(int scores[], int size,
                              int &A, int &B, int &C, int &D, int &F) {
    A = B = C = D = F = 0;
    for (int i = 0; i < size; i++) {
        if (scores[i] >= 70) A++;
        else if (scores[i] >= 60) B++;
        else if (scores[i] >= 50) C++;
        else if (scores[i] >= 45) D++;
        else F++;
    }
}
int pickRandomPassingStudent(int ids[], int scores[], int size) {
    int passing[100], count = 0;
    for (int i = 0; i < size; i++)
        if (scores[i] >= 50) passing[count++] = i;

    if (count == 0) return -1;
    return passing[rand() % count];
}
void saveSummary(const char filename[], double avg, int minScore, int maxScore,
                 int A, int B, int C, int D, int F) {
    ofstream out(filename);
    if (!out) return;

    out << "Metric,Value\n";
    out << "Average Score," << avg << "\n";
    out << "Minimum Score," << minScore << "\n";
    out << "Maximum Score," << maxScore << "\n";
    out << "A Count," << A << "\n";
    out << "B Count," << B << "\n";
    out << "C Count," << C << "\n";
    out << "D Count," << D << "\n";
    out << "F Count," << F << "\n";
}
int main() {
    srand(time(0));

    const int MAX = 100;
    int ids[MAX], scores[MAX];

    int size = loadData("scores.csv", ids, scores, MAX);
    cout << "\nTotal students loaded: " << size << "\n\n";

    printAll(ids, scores, size);

    double avg;
    int minScore, maxScore;
    computeStats(scores, size, avg, minScore, maxScore);
    cout << "\nAverage: " << avg << "  Min: " << minScore << "  Max: " << maxScore << "\n\n";

    int A, B, C, D, F;
    computeGradeDistribution(scores, size, A, B, C, D, F);
    cout << "Grade Distribution: A:" << A << " B:" << B << " C:" << C
         << " D:" << D << " F:" << F << "\n\n";

    int index = pickRandomPassingStudent(ids, scores, size);
    if (index == -1) cout << "No passing students.\n";
    else cout << "Random Passing Student ID: " << ids[index]
              << " Score: " << scores[index] << "\n";

    saveSummary("summary.csv", avg, minScore, maxScore, A, B, C, D, F);
    cout << "summary.csv created.\n";

    return 0;
}