#include <iostream>
#include <cmath>
#include <climits>
#include <cfloat>
#include <iomanip>

using namespace std;


//converts char to int (1->1, 9->9, A->10, Z->35)
int chartoint(char charnumber) {
	int intnumber;
	if ((charnumber - '0') > 9) {
		intnumber = charnumber - 55;
	} else {
		intnumber = charnumber - 48;
	}
	return intnumber;
}

//converts user input to int and removes other chars
int userinputtoint() {
	char input;
	int number = 0;
	cin.get(input);
	//if input == /n, then next char
	while (input == '\n') {
		cin.get(input);
	}
	//get all numbers as long as char != \n
	while (input != '\n') {
		if (input >= '0' && input <= '9') {
            if (number * 10 + chartoint(input) > INT_MAX) {
                return 0;
            } else {
                number = number * 10 + chartoint(input);
            }
            
		}
		//next char
		cin.get(input);
	}
	return number;
}

int main () {
    int denominators = 0; //denominator iterations
    long double bestdifference = 1; //closest difference to pi
    long double bestvalue = 0; //best value
    int currentnominatorint = 0; //nominator being tested (int)
    double currentnominatordbl = 0; //nominator being tested (double)

    cout << "How many denominators should be tested? (max 100000000)" << endl;
    //denominators
    while (denominators == 0 && denominators <= 100000000) {
        cout << "Amount: ";
        denominators = userinputtoint();
    }
    cout << endl << endl;

    //test
    for (int i = 1; i < denominators; i++) {
        currentnominatorint = int(M_PI * i);
        currentnominatordbl = double(currentnominatorint);
        if (abs(currentnominatordbl / i - M_PI) < bestdifference) {
            bestvalue = currentnominatordbl / i;
            bestdifference = abs(bestvalue - M_PI);
            cout << currentnominatorint << '/' << i << " - " << setprecision(30) << bestvalue << endl;
        }
        if (abs((currentnominatordbl + 1) / i - M_PI) < bestdifference) {
            bestvalue = (currentnominatordbl + 1)/i;
            bestdifference = abs(bestvalue - M_PI);
            cout << currentnominatorint + 1 << '/' << i << " - " << setprecision(30) << bestvalue << endl;
        }
    }

    return 0;
}