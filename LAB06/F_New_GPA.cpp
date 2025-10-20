#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
using namespace std;

bool compare_students(const pair<string, double>& a, const pair<string, double>& b) {
    if (a.second != b.second) {
        return a.second < b.second;
    }
    return a.first < b.first;
}



void quick_sort(vector<pair<string, double>> &student, long long left, long long right){
    long long i = left; 
    long long j = right;
    pair<string, double> pivot = student[(i+j)/2]; 
    while (i <= j)
    {
        while (student[i].second < pivot.second ||(student[i].second == pivot.second && student[i].first < pivot.first)) i++;
        while (student[j].second > pivot.second ||(student[j].second == pivot.second && student[j].first > pivot.first)) j--;
        
        if(i <= j){
            swap(student[i],student[j]);
            i++;
            j--;
        }
    }

    if(left < j) quick_sort(student, left, j);
    if(right > i) quick_sort(student,i, right);
}

void bubble_sort(vector<pair<string, double>> &student, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (student[j].second > student[j + 1].second) { 
                swap(student[j], student[j + 1]);
            }
        }
    }
}

double get_point(string a){
    if(a == "A+") return 4.0;
    else if (a == "A") return 3.75;
    else if (a == "B+") return 3.50;
    else if (a == "B") return 3.00;
    else if (a == "C+") return 2.50;
    else if (a == "C") return 2.00;
    else if (a == "D+") return 1.50;
    else if (a == "D") return 1.00;
    return 0.0;
}


int main(){
    int n; cin >> n;
    vector<pair<string, double>> student;
    for(int i = 0; i < n; i++){
        string last_name; cin >> last_name;
        string first_name; cin >> first_name;
        string fullname = last_name + " " + first_name;
        long long t; cin >> t;
        long long summ_of_credit = 0;
        double total_points = 0;
        for(int j = 0; j < t; j++){
            string point; cin >> point;
            double tmp = get_point(point);
            int credit; cin >> credit;
            summ_of_credit += credit;
            total_points += credit * tmp;
        }
        double gpa = total_points / summ_of_credit; 
        student.push_back({fullname,gpa});
    }

    quick_sort(student,0,n-1);

    cout << fixed << setprecision(3);

    for(auto pair:student){
        cout << pair.first << " " << pair.second << endl;
    }
}
