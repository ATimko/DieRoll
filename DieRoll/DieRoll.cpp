#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;

const unsigned int TRIALS = 1'000;
const unsigned int RANDOM_UPPER_LIMIT = 1'000'000;

double estimatePI();

void mystery();
void printAverage();
void forLoopThing();

int main() {
	default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	uniform_int_distribution<unsigned int> randomInt{ 1, 6 };

	for (unsigned int counter{ 1 }; counter <= 5; ++counter) {
		cout << randomInt(engine) << endl;
	}

	cout << "PI: " << showpoint << estimatePI() << endl;
	mystery();
	printAverage();

	forLoopThing();
	system("pause");
	return 0;
	}

	void forLoopThing() {
		for (int i = 10; i >= 0; --i) {
			cout << i << endl;
			char ch = 'z';
			cin >> ch;
		}
	}

	void printAverage() {
		double total = 0.0;
		int count = 0;
		double number = 0.0;
		cout << "Enter a number: ";
		cin >> number;

		while (number >= 0.0) {
			total += number;
			++count;
			cout << "Enter a number: ";
			cin >> number;
		}
		if (count > 0) {
			cout << "average: " << total / count << endl;
		}
		else {
			cout << "We can't average zero numbers." << endl;
		}
	}

	void mystery() {
		for (unsigned int i{ 1 }; i <= 5; ++i) {
			for (unsigned int j{ 1 }; j <= 3; ++j) {
				for (unsigned int k{ 1 }; k <= 4; ++k) {
					cout << "*";
				}
				cout << endl;
			}
			cout << endl;
		}
	}

	double estimatePI() {
		default_random_engine engine{ static_cast<unsigned int>(time(0)) };
		uniform_int_distribution<unsigned int> randomInt{ 0, RANDOM_UPPER_LIMIT };
		unsigned int count = 0;

		for (unsigned int i{ 0 }; i < TRIALS; ++i) {
			double x = static_cast<double>(randomInt(engine) )/ RANDOM_UPPER_LIMIT;
			double y = static_cast<double>(randomInt(engine) )/ RANDOM_UPPER_LIMIT;
			double distance = sqrt(x * x + y * y) / RANDOM_UPPER_LIMIT / RANDOM_UPPER_LIMIT;
			if (distance < 1.0) {
				++count;
			}
		}
		return 4.0 * count / TRIALS;
}