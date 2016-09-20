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
	cout << "タイトル：" << title << endl;
	cout << "著者名：" << witter << endl;
	cout << "在庫冊数：" << stock << endl;
}

int main()
{
	Card book1, book2, book3;
	book1.Store("とつくにの少女", "ながべ", 2);
	book2.Store("サマーウォーズ", "細田守", 1);
	book3.Store("ゲームを作って思うこと", "桜井政博", 20);

	book1.Show();
	book2.Show();
	book3.Show();

	return 0;

}