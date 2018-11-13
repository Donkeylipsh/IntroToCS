
#include <string>
#include <iostream>
#include <vector>
#include "ValSet.hpp"



using namespace std;
int main(){

ValSet<int> intValues;
int i = 0;

		for (i = 0; i < 10; i++) {
			intValues.add(10);
		}

		cout << "Testing isEmpty()" << endl;
		cout << "Is intValues empty: " << intValues.isEmpty() << endl;

		cout << "Removing all 10's from intValues..." << endl;
		intValues.remove(10);

		cout << "Is intValues empty: " << intValues.isEmpty() << endl;

	return 0;
}