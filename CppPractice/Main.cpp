#include<iostream>
#include<cstring>
using namespace std;

class Card {
	char title[256];
	char witter[256];
	int stock;
public:
	void Store(char *t, char *w, int s);
	void Show();
};

void Card::Store(char *t, char *w, int s) {
	strcpy(title, t);
	strcpy(witter, w);
	stock = s;
}

void Card::Show() {
	cout << "�^�C�g���F" << title << endl;
	cout << "���Җ��F" << witter << endl;
	cout << "�݌ɍ����F" << stock << endl;
}

int main()
{
	Card book1, book2, book3;
	book1.Store("�Ƃ��ɂ̏���", "�Ȃ���", 2);
	book2.Store("�T�}�[�E�H�[�Y", "�דc��", 1);
	book3.Store("�Q�[��������Ďv������", "���䐭��", 20);

	book1.Show();
	book2.Show();
	book3.Show();

	return 0;

}