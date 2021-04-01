#include <iostream>
using namespace std;


int get_remainder(int solution, int modulo) {
	if (solution < 0){ 
		return solution % modulo + modulo;
	}
	return solution % modulo;
}

int get_inverse(int value, int modulo) {
	int result=1;
	for (int i = 0; i < modulo - 2; i++){ 
		result = (result * value) % modulo;
	}
	return result;
}


int garner_solution(int remainder[], int modulo[], int size) {

	int cross_modulo = modulo[0];
	int modulo_cross = 1;
	int result = remainder[0];
	for (int i = 1; i < size; i++) {
		modulo_cross = modulo_cross * modulo[i - 1];
		remainder[i] = get_remainder( (remainder[i] - result) * get_inverse(modulo_cross, modulo[i]), modulo[i]);
		result = (result + remainder[i] * modulo_cross);
	}
	return result;
}

int main() {
	/*int re[4] = {1,2,3,4};
	int mo[4] = { 2,3,5,7 };*/
	int re[3] = {2,3,2};
	int mo[3] = {3,5,7};
	//int re[8] = { 0,2,4,6,13,12,22,30};
	//int mo[8] = { 2,3,5,7,17,19,23,31};
	int result=garner_solution(re, mo, sizeof(mo) / sizeof(int));
	
	//검사
	cout << "결과: "<< result << " " << result%mo[1] << endl;
	return 0;
}
