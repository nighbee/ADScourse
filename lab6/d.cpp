#include <bits/stdc++.h>
using namespace std;

struct Date {
    int day, month, year;
};

bool compare(const Date &d1, const Date &d2) {
    if (d1.year < d2.year)
        return true;
    if (d1.year == d2.year && d1.month < d2.month)
        return true;
    if (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day)
        return true;
    return false;
}

void sortDate(Date arr[], int n) {
    sort(arr, arr + n, compare);
}

int main() {
    int n;
    cin >> n;
    Date arr[n];
    for (int i = 0; i < n; i++) {
        string date;
        cin >> date;
        sscanf(date.c_str(), "%d-%d-%d", &arr[i].day, &arr[i].month, &arr[i].year);
    }

    sortDate(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%02d-%02d-%04d\n", arr[i].day, arr[i].month, arr[i].year);
    }
}
