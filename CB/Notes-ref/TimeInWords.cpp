#include<iostream>
using namespace std;
char timer[][300] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight",

                     "nine", "ten",
                     "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                     "sixteen", "seventeen", "eighteen", "nineteen",
                     "twenty", "twenty one", "twenty two", "twenty three",
                     "twenty four", "twenty five",
                     "twenty six", "twenty seven", "twenty eight", "twenty nine"
                    };

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);

// #endif
	int hour, min;
	cin >> hour >> min;

	if (min == 0) {
		cout << timer[hour] << " o'clock";
	}

	else if (min < 30 and min != 15) {
		cout << timer[min] << " minutes past " << timer[hour];
	}

	else if (min == 15) {
		cout << "quarter past " << timer[hour];
	}
	else if (min == 30) {
		cout << "half past " << timer[hour];
	}

	else if (min > 30 && hour != 12) {
		int rem = 60 - min;
		if (rem != 15) {
			cout << timer[rem] << " minutes to " << timer[hour + 1];
		}
		else {
			cout << "quarter to " << timer[hour + 1];
		}
	}

	else if (min > 30 && hour == 12) {
		int rem = 60 - min;
		if (rem != 15) {
			cout << timer[rem] << " minutes to one";
		}
		else {
			cout << "quarter to one";
		}
	}


}