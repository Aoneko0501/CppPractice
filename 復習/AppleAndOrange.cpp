/*

#include<iostream>
#include<cstring>

using namespace std;

enum yn { no, yes };
enum color { red, yellow, green, orange };
void out(enum yn x);
char *c[] = { "��","��","��","�I�����W" };

// �ėpfruit�N���X
class fruit {
	// ��{�N���X�ł͑S�Ă̗v�f�����J
public:
	enum yn annual;		// �N��
	enum yn perennial;	// ���N����
	enum yn tree;		// �؂�
	enum yn tropical;	// �M�т�
	enum color clr;		// �F
	char name[40];
};

// Apple�N���X��h������
class Apple : public fruit {
	enum yn cooking;
	enum yn crunchy;
	enum yn eating;
public:
	void seta(char *n, enum color c, enum yn ck, enum yn crchy, enum yn e);
	void show();
};

// Orenge�N���X��h��
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
	cout << name << "�����S�F" << endl;
	cout << "��N���A���F";	out(annual);
	cout << "���N���A���F";	out(perennial);
	cout << "�؁F";			out(tree);
	cout << "�M�ѐ��F";		out(tropical);
	cout << "�F�F" << c[clr] << endl;
	cout << "�����p�F";		out(cooking);
	cout << "�d���F";		out(crunchy);
	cout << "�H�p�F";		out(eating);
	cout << "\n";
}

void Orange::show() {
	cout << name << "�I�����W�F" << endl;
	cout << "��N���A���F";	out(annual);
	cout << "���N���A���F";	out(perennial);
	cout << "�؁F";			out(tree);
	cout << "�M�ѐ��F";		out(tropical);
	cout << "�F�F" << c[clr] << endl;
	cout << "�W���[�X�p�F";	out(juice);
	cout << "�_���ς��F";		out(sour);
	cout << "�H�p�F";		out(eating);
	cout << "\n";
}

void out(enum yn x) {
	if (x == no) cout << "no" << endl;
	else cout << "yes" << endl;
}


int main() {
	Apple a1, a2;
	Orange o1, o2;

	a1.seta("���b�h�f���V���X",red,no,yes,yes);
	a2.seta("�W���i�T��",red,yes,no,yes);

	o1.seto("�l�[�u��", orange, no, no, yes);
	o2.seto("�o�����V�A", orange, yes, yes, no);

	a1.show();
	a2.show();

	o1.show();
	o2.show();

	return 0;
}

*/
