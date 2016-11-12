/*

#include<iostream>
#include<cstring>

using namespace std;

enum yn { no, yes };
enum color { red, yellow, green, orange };
void out(enum yn x);
char *c[] = { "赤","黄","緑","オレンジ" };

// 汎用fruitクラス
class fruit {
	// 基本クラスでは全ての要素が公開
public:
	enum yn annual;		// 年代
	enum yn perennial;	// 多年生の
	enum yn tree;		// 木の
	enum yn tropical;	// 熱帯の
	enum color clr;		// 色
	char name[40];
};

// Appleクラスを派生する
class Apple : public fruit {
	enum yn cooking;
	enum yn crunchy;
	enum yn eating;
public:
	void seta(char *n, enum color c, enum yn ck, enum yn crchy, enum yn e);
	void show();
};

// Orengeクラスを派生
class Orange :public fruit {
	enum yn juice;
	enum yn sour;
	enum yn eating;
public:
	void seto(char *n, enum color c, enum yn j, enum yn sr, enum yn e);
	void show();
};

void Apple::seta(char * n,enum color c,enum yn ck,enum yn crchy,enum yn e)
{
	strcpy(name, n);
	annual = no;
	perennial = yes;
	tree = yes;
	tropical = no;
	clr = c;
	cooking = ck;
	crunchy = crchy;
	eating = e;
}

void Orange::seto(char *n, enum color c, enum yn j, enum yn sr, enum yn e)
{
	strcpy(name, n);
	annual = no;
	perennial = yes;
	tree = yes;
	tropical = yes;
	clr = c;
	juice = j;
	sour = sr;
	eating = e;
}

void Apple::show() {
	cout << name << "リンゴ：" << endl;
	cout << "一年生植物：";	out(annual);
	cout << "多年生植物：";	out(perennial);
	cout << "木：";			out(tree);
	cout << "熱帯性：";		out(tropical);
	cout << "色：" << c[clr] << endl;
	cout << "料理用：";		out(cooking);
	cout << "硬い：";		out(crunchy);
	cout << "食用：";		out(eating);
	cout << "\n";
}

void Orange::show() {
	cout << name << "オレンジ：" << endl;
	cout << "一年生植物：";	out(annual);
	cout << "多年生植物：";	out(perennial);
	cout << "木：";			out(tree);
	cout << "熱帯性：";		out(tropical);
	cout << "色：" << c[clr] << endl;
	cout << "ジュース用：";	out(juice);
	cout << "酸っぱい：";		out(sour);
	cout << "食用：";		out(eating);
	cout << "\n";
}

void out(enum yn x) {
	if (x == no) cout << "no" << endl;
	else cout << "yes" << endl;
}


int main() {
	Apple a1, a2;
	Orange o1, o2;

	a1.seta("レッドデリシャス",red,no,yes,yes);
	a2.seta("ジョナサン",red,yes,no,yes);

	o1.seto("ネーブル", orange, no, no, yes);
	o2.seto("バレンシア", orange, yes, yes, no);

	a1.show();
	a2.show();

	o1.show();
	o2.show();

	return 0;
}

*/
