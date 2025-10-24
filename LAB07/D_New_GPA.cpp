#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void merge(vector<pair<string,double>> &arr, int l, int m, int r){
    int n1 = m - l + 1;
    int n2  = r - m;
    vector<pair<string,double>> L(n1),R(n2);
    for(int i = 0; i < n1; i++){
        L[i] = arr[l+i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = arr[m+1+i];
    }

    int uk1 = 0; int uk2 = 0;
    int k = l;
    while (uk1 < n1 && uk2 < n2)
    {
        if(L[uk1].second < R[uk2].second){
            arr[k] = L[uk1];
            uk1++;
        }
        else if(L[uk1].second > R[uk2].second){
            arr[k] = R[uk2];
            uk2++;
        }
        else{
            if(L[uk1].first <= R[uk2].first){
                arr[k] = L[uk1];
                uk1++;
            }else{
                arr[k] = R[uk2];
                uk2++;
            }
        }
        k++;
    }
    

    while (uk1 < n1)
    {
        arr[k] = L[uk1];
        uk1++; k++;
    }

    while (uk2 < n2)
    {
        arr[k] = R[uk2];
        uk2++; k++;
    }
}

void merge_sort(vector<pair<string,double>> &arr, int l, int r){
    if(l < r){
        int m = (r + l) /2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
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
    vector<pair<string,double>> student;
    for(int i = 0; i < n; i++){
        string last_name; cin >> last_name;
        string first_name; cin >> first_name;
        string full_name = last_name + " " + first_name;
        int t; cin >> t;
        long long sum0fcredit = 0;
        double total_point = 0;
        for(int j = 0; j < t; j++){
            string point; cin >> point;
            double tmp = get_point(point);
            int credit; cin >> credit;
            sum0fcredit += credit;
            total_point += credit * tmp;
        }
        double gpa = total_point/sum0fcredit;
        student.push_back({full_name,gpa});
    }

    merge_sort(student,0,n-1);
    cout << fixed << setprecision(3);

    for(auto t:student){
        cout << t.first << " " << t.second << endl;
    }
}