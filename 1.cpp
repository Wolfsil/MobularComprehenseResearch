#include <iostream>
using namespace std;


int get_remainder(int solution, int modular) {
	while (solution < 0) { solution = modular + solution; }
	return solution % modular;
}

int get_inverse(int value, int modular) {
	int result=1;
	value =get_remainder(value, modular);
	for (int i = 0; i < modular - 2; i++){ result = (result * value) % modular;}
	return result;
}


int modular_solution(int remainder[],int modular[],int size) {

	int cross_modural = modular[0];
	int modular_cross = 1; 
	int result = remainder[0];
	for (int i = 1; i < size; i++) {
		modular_cross = modular_cross * modular[i - 1];
		remainder[i] = get_remainder((remainder[i] - result), modular[i])
			*get_inverse(modular_cross,modular[i])%modular[i];
		result = (result + remainder[i] * modular_cross);
	}
	printf("단 하나의 해는: %d", result);
	return 0;
}


int main() {
	int solution = 57;
	/*int re[4] = {1,2,3,4};
	int mo[4] = { 2,3,5,7 };*/
	/*int re[3] = {2,3,2};
	int mo[3] = {3,5,7};*/
	int re[5] = { 0,0,0,0 };
	int mo[5] = { 2,3,5,7 };
	modular_solution(re, mo ,sizeof(mo)/sizeof(typeid(mo).name()));
	return 0;
}
