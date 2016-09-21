//‰¡“|‚µ‚ÌŽOŠpŒ`‚ð•`‚­
#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int maxNum = 50;

	for (int i = 1; i < maxNum * 2; i++) {
		for (int j = 0; j <maxNum - abs(maxNum - i); j++) {
			cout << "#";
		}
		cout << "\n";
	}
}