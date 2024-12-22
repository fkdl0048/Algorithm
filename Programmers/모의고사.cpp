#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> student1 = {1, 2, 3, 4, 5};
    vector<int> student2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> student3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    vector<int> scores(3, 0);

    for (int i = 0; i < answers.size(); ++i) {
        if (answers[i] == student1[i % student1.size()]) ++scores[0];
        if (answers[i] == student2[i % student2.size()]) ++scores[1];
        if (answers[i] == student3[i % student3.size()]) ++scores[2];
    }

    int maxScore = *max_element(scores.begin(), scores.end());

    vector<int> result;
    for (int i = 0; i < scores.size(); ++i) {
        if (scores[i] == maxScore) {
            result.push_back(i + 1);
        }
    }

    return result;
}