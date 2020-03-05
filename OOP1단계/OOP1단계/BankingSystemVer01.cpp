#include "pch.h"

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu();		// �޴����
void MakeAccount();		// ���°����� ���� �Լ�
void DepositMoney();	// �Ա�
void WithdrawMoney();	// ���
void ShowAllAccInfo();	// �ܾ���ȸ

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct
{
	int accID;
	int balnce;
	char cusName[NAME_LEN];
}Account;

Account accArr[100];
int accNum = 0;

int main()
{
	int choice;

	while (true)
	{
		ShowMenu();
		cout << "����: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		dsfault:
			cout << "Illegal selection.." << endl;
		}

	}

	return 0;
}

void ShowMenu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;

}

void MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�̸�: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << endl;

	accArr[accNum].accID = id;
	accArr[accNum].balnce = balance;
	strcpy_s(accArr[accNum].cusName, name);
	accNum++;
}

void DepositMoney()
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balnce += money;
			cout << "�ԱݿϷ�" << endl << endl;
			return; // ���������
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�. " << endl << endl;
}

void WithdrawMoney()
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			if (accArr[i].balnce < money)
			{
				cout << "�ܾ� ����" << endl << endl;
				return;
			}
			accArr[i].balnce -= money;
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "����ID: " << accArr[i].accID << endl;
		cout << "�̸�: " << accArr[i].cusName << endl;
		cout << "�ܾ�: " << accArr[i].balnce << endl << endl;
	}
}
