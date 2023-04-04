#include <iostream> 
using namespace std;

bool isPrime(int N) {
	setlocale(LC_ALL, "rus");
	int N2; // Тестируемое число 
	int F; // f- флаг: 1 – простое, 0 - нет 
	const int DVA = 2;
	N2 = N;
	__asm {
		XOR EDX, EDX		//Очищаем EDX
		MOV EAX, N			//Готовимся к делению
		DIV DVA				//Проверяем N на четность
		MOV N2, EAX			//N2 = N / 2 
		MOV F, EDX			//F - остаток от деления N / 2 
		CMP EDX, 0
		JE L02				//Если N четное = > N - составное
		MOV EBX, 3			//Первый нечетный делитель
		L01 :
		CMP EBX, N2			//EBX > N / 2
			JG L03
			XOR EDX, EDX
			MOV EAX, N
			DIV EBX
			CMP EDX, 0		//Если делитель = > N - составное
			JE L02
			ADD EBX, 2		//Проверяем только нечетные
			JMP L01
			L02 :
		MOV F, 0			//Устанавливаем флаг в 0 
			L03 :
			NOP
	}
	
	return F == 1;
}


int main() {
	int  n, j;
	j = 2;
	n = 1000;

	while (j < n) {
		for (int i = 2; i < j; ++i) {
			int a = j - i;
			if (isPrime(i) && isPrime(a)) {
				std::cout << j << "=" << i << "+" << a << "\n";
				break;
			}
		}
		j = j + 2;
	}
}