#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cctype>
#include <utility>
#include <vector>

using namespace std;

int getCreditReceived(string grade)
{
    transform(grade.begin(), grade.end(), grade.begin(), ::tolower);
    if (grade == "aa")
        return 10;
    else if (grade == "ab")
        return 9;
    else if (grade == "bb")
        return 8;
    else if (grade == "bc")
        return 7;
    else if (grade == "cc")
        return 6;
    else if (grade == "cd")
        return 5;
    else if (grade == "dd")
        return 4;
    else if (grade == "ff")
        return 0;
    return -1;
}

bool isNumber(const string &str)
{
    if (str.empty())
        return false;
    bool unseen = true;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '+' || str[i] == '-')
            if (i == 0)
                continue;
            else
                return false;
        if (str[i] == '.')
        {
            if (i != 0 && unseen)
            {
                unseen = false;
                continue;
            }
            else
                return false;
        }
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

pair<float, float> getSGPA()
{

    string n;
    while (!isNumber(n))
    {
        cout << "Enter the number of courses: ";
        cin >> n;
    }
    int numCourses = stoi(n);

    float sum = 0;
    float creditTotal = 0;

    vector<pair<string, float>> subjects(numCourses);

    for (int i = 0; i < numCourses; i++)
    {

        cout << "Enter subject: ";
        cin >> subjects[i].first;

        while (true)
        {
            cout << "Enter subject credit: ";
            string subjectReceived;
            cin >> subjectReceived;
            if (isNumber(subjectReceived) && stof(subjectReceived) > 0)
            {
                subjects[i].second = stof(subjectReceived);
                break;
            }
            else
            {
                cout << "Invalid input. Please enter a positive number." << endl;
            }
        }

        auto [subject, fixedGrade] = subjects[i];
        cout << "Enter the grade received for the subject " << subject << ": ";
        string grade;
        cin >> grade;
        int received = getCreditReceived(grade);
        if (received == -1)
        {
            cout << "Invalid grade entered" << endl;
            i--;
            continue;
        }
        creditTotal += fixedGrade;
        sum += (received * fixedGrade);
    }

    return {(sum / creditTotal), sum};
}

int main()
{

    char sems;

    while (!isdigit(sems) || !((sems - '0') >= 1 && (sems - '0') <= 8))
    {
        cout << "Which semester are you in? ";
        cin >> sems;
    }
    int sem = sems - '0';
    float cgpa = 0;
    float totalCredits = 0;
    if (sem != 1)
    {
        while (true)
        {
            cout << "Enter your previous semester's CGPA: ";
            string inpCG;
            cin >> inpCG;
            if (isNumber(inpCG) && stof(inpCG) <= 10 && stof(inpCG) >= 0)
            {
                cgpa = stof(inpCG);
                break;
            }
            else
            {
                cout << "Invalid input. Please enter a number." << endl;
            }
        }
        while (true)
        {
            cout << "Enter your previous semester's cummulative total credits: ";
            string inpCreds;
            cin >> inpCreds;
            if (isNumber(inpCreds))
            {
                totalCredits = stof(inpCreds);
                break;
            }
            else
            {
                cout << "Invalid input. Please enter a number." << endl;
            }
        }
    }
    auto [currSGPA, currSum] = getSGPA();
    float newCGPA = (cgpa * totalCredits + currSGPA * currSum) / (totalCredits + currSum);
    cout << "Your new CGPA is: " << newCGPA << endl;
    cout << "Your current semester's SGPA is: " << currSGPA;

    return 0;
}