/*
기능
1. 계좌개설
2. 입금
3. 출금
4. 전체고객 잔액조회

가정
1. 통장의 계좌번호 중복검사할 필요 없음.
2. 입금 및 출금액의 오류검사 안함.
3. 계좌번호, 고객이름, 고객의 잔액 3가지만 저장&관리 한다.
4. 둘 이상의 고객 정보 저장을 위해서 배열을 사용한다.

*/

#include "pch.h"
#include <iostream>

using namespace std;

struct bank {
	
	int pin;
	char name[20];
	int balance;

};

bank B[100];
int now = 0;

void Make();
void Deposit();
void Withdraw();
void Output();

int main()
{

	int putN;

	while (true)
	{
		cout << "-----Menu-----" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입금" << endl;
		cout << "3. 출금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택: ";
		cin >> putN;
		switch (putN)
		{
		case 1:
			Make();
			break;
		case 2:
			Deposit();
			break;
		case 3:
			Withdraw();
			break;
		case 4:
			Output();
			break;
		case 5:
			return 0;
			break;
		default:
			cout << "잘못 입력하셨습니다" << endl;
			break;
		}
	}
}
//1. 계좌개설
void Make()
{
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> B[now].pin;
	cout << "이름: ";
	cin >> B[now].name;
	cout << "입금액: ";
	cin >> B[now].balance;
	now++;
}
//2. 입금
void Deposit()
{
	int ID, price;

	cout << "[입 금]" << endl;
	cout << "계좌ID: ";
	cin >> ID;
	cout << "입금액: ";
	cin >> price;
	// pin번호를 찾아서 balance에 price를 더한다.
	for (int i = 0; i < now; i++)
		if (ID == B[i].pin)
			B[i].balance += price;

	cout << "입금완료" << endl;

}
//3. 출금
void Withdraw()
{
	int ID, price;
	cout << "[출 금]" << endl;
	cout << "계좌ID: ";
	cin >> ID;
	cout << "출금액: ";
	cin >> price;
	// pin번호를 찾아서 balance에 price를 뺀다.
	for (int i = 0; i < now; i++)
		if (ID == B[i].pin)
			B[i].balance -= price;

	cout << "출금완료" << endl;

}
//4. 전체고객 잔액조회
void Output()
{
	for (int i = 0; i < now; i++)
	{
		cout << "계좌ID: " << B[i].pin << endl;
		cout << "이름: " << B[i].name << endl;
		cout << "잔액: " << B[i].balance << endl << endl;
	}
}
