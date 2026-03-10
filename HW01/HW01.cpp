#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
	count--;
	*p_HPPotion += 20;
	*p_MPPotion += 20;
}

void pluscount(int* HP_count, int* MP_count) {
	(*HP_count)++;
	(*MP_count)++;
}

int main() {

	int HP, MP, Attack, Defence;
	int level = 0;
	int num;
	int h_count, m_count;
	int garbage = 0;
	bool bol = true;

	h_count = 5;
	m_count = 5;

	while (1) {
		cout << "HP를 입력해주세요 : ";
		cin >> HP;
		if (HP >= 50) break;
		cout << "HP를 50이상으로 입력해주세요." << endl;
	}

	while (1) {
		cout << "MP를 입력해주세요 : ";
		cin >> MP;
		if (MP >= 50) break;
		cout << "MP를 50이상으로 입력해주세요." << endl;
	}

	while (1) {
		cout << "Attack을 입력해주세요 : ";
		cin >> Attack;
		if (Attack >= 0) break;
		cout << "Attack을 0이상으로 입력해주세요." << endl;
	}

	while (1) {
		cout << "Defence를 입력해주세요 : ";
		cin >> Defence;
		if (Defence >= 0) break;
		cout << "Defence를 0이상으로 입력해주세요." << endl;
	}

	int status[4] = { HP, MP, Attack, Defence };

	while (bol) {
		cout << "1.HP UP / 2.MP UP / 3.공격력 UP / 4.방어력 UP / 5.현재 능력치 / 6.Level Up / 0.나가기 " << endl;
		cin >> num;

		switch (num) {
		case 1:
			if (h_count <= 0) {
				cout << "Potions Empty!" << endl;
			}
			else {
				setPotion(h_count, &HP, &garbage);
				h_count--;
				cout << "HP가 20 만큼 회복되었습니다." << endl;
				cout << "HP 포션 남은 개수 : " << h_count << ", 현재 MP : " << HP << endl;
			}
			break;

		case 2:
			if (m_count <= 0) {
				cout << "Potions Empty!";
			}
			else {
				setPotion(m_count, &garbage, &MP);
				m_count--;
				cout << "MP가 20 만큼 회복되었습니다." << endl;
				cout << "MP 포션 남은 개수 : " << m_count << ", 현재 MP : " << MP << endl;
			}
			break;

		case 3:
			cout << "공격력이 2배가 됩니다." << endl;
			Attack = Attack * 2;
			cout << "현재 공격력 : " << Attack << endl;
			break;

		case 4:
			cout << "방어력이 2배가 됩니다." << endl;
			Defence = Defence * 2;
			cout << "현재 방어력 : " << Defence << endl;
			break;

		case 5:
			cout << "[현재 능력치]" << endl;
			cout << "HP : " << HP << endl;
			cout << "MP : " << MP << endl;
			cout << "공격력 : " << Attack << endl;
			cout << "방어력 : " << Defence << endl;
			cout << " << 남은 포션 개수 >> " << endl;
			cout << "HP_potion : " << h_count << endl;
			cout << "MP_potion : " << m_count << endl;
			break;

		case 6:
			cout << "Level up!!" << endl;
			cout << "HP물약 + 1 , MP물약 + 1" << endl;
			level++;
			pluscount(&h_count, &m_count);
			break;

		case 0:
			cout << "Bye, Bye!" << endl;
			bol = false;
			break;

		default:
			cout << "Choose correct number!" << endl;
			break;
		}
	}

	return 0;
}