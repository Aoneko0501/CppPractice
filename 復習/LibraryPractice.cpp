/*

#include<iostream>
using namespace std;

// �}���ٓI�ȃv���O����

#define SIZE 10	// �ۊǂł���{��10���܂�

class Book {
	char title[40];	// �^�C�g��
	char witter[40];// ���Җ�
	int year;		// ���s�N
public:
	Book() {}

	void SetBook();	// �����͗p�֐�

	char* GetTitle();				// �^�C�g��
	char* GetWitter();				// ���Җ�
	int GetYear();					// ���s�N
	void Show();					// ���̖{�̏��
};

class Library {
	Book books[SIZE];	// �{
	int tos;		// �ۊǍ���

public:

	int selectMode;	// �A�邩�A��Ȃ����̊m�F

	Library();
	~Library();

	void Reception();	// ��t�F�����Ŗ{��ǉ����邩�ǂ����I��
	void MakeBook();
	void ShowBooks();
	void BorrowBook();

	void SortBooks(int bNum);	// �{���؂��ꂽ�ꍇ�̏���

};

Library::Library() {
	cout << "�悤�����B�h���S�j�J�}���قցB" << endl;
	// ������
	this->tos = 0;
	this->selectMode = 0;
}

Library::~Library() {
	cout << "�܂��̂����p�����҂����Ă���܂��B" << endl;
}

void Library::Reception() {

	cout << "�y�P�F�{���񑡂���z\n�y�Q�F�{���؂��z\n�y�R�F�����ɂ���{��m�肽���z\n�y�O�F���ł��Ȃ��ł��z" << endl;
	cin >> this->selectMode;

	switch (selectMode) {
	case 1:
		MakeBook();
		break;
	case 2:
		BorrowBook();
		break;
	case 3:
		ShowBooks();
		break;
	default:
		this->selectMode = 0;
		break;
	}

}

void Library::MakeBook()
{
	cout << "�{�̊񑡂ł���\n";

	if (tos >= SIZE) {
		cout << "�\���󂲂����܂���A����ȏ゠�Ȃ�����{���񑡂��Ă��炤���Ƃ͂ł��܂���B\n";
	}
	else {
		Book b;
		b.SetBook();

		books[tos] = b;
		tos++;
	}
}

void Library::ShowBooks()
{
	if (tos == 0) {
		cout << "�\���󂲂����܂���B���}���قɂ��Ȃ�����񑡂���Ă���{�͂���܂���B\n";
	}
	else {
		cout << "���݂����̐}���قɂ��邠�Ȃ����񑡂����{�͈ȉ��̒ʂ�ɂȂ�܂��B\n";
		for (int i = 0; i < tos; i++) {
			cout << "-----------------------------\n";
			cout << "�yNo." << i + 1 << "�z\n";
			books[i].Show();
		}
	}
}

// �{���؂�Đ}���ق̖{���X�g����Y���̖{���폜����
void Library::BorrowBook()
{
	int borrowNum;

	char borrow;
	if (tos == 0) {
		cout << "�\���󂲂����܂���B���}���قɂ��Ȃ�����񑡂���Ă���{�͂���܂���B\n";
	}
	else {
		cout << "���݂����̐}���قɂ��邠�Ȃ����񑡂����{�͈ȉ��̒ʂ�ɂȂ�܂��B\n";
		for (int i = 0; i < tos; i++) {
			cout << "-----------------------------\n";
			cout << "�yNo." << i + 1 << "�z\n";
			books[i].Show();
		}
		cout << "�ǂ̖{���؂�Ă����܂����H:";
		cin >> borrowNum;

		if (tos <= borrowNum - 1 || borrowNum <= 0) {
			// �ۊǂ���Ă��Ȃ��������͂��ꂽ��
			cout << "�\���󂲂����܂��񂪁A���̔ԍ��̖{�͎؂��܂���B\n";
		}
		else {
			cout << "������̖{�ł��ˁH\n";
			books[borrowNum - 1].Show();
			cout << "�؂�Ă����܂����H(y/n)\n";
			cin >> borrow;

			if (borrow != 'y') {
				return;
			}
			else {
				cout << "�����p���肪�Ƃ��������܂����B\n";
				// �����Ɏw�肳�ꂽ�����̖{��z�񂩂���o���ĕ��ёւ��鏈��������B
				SortBooks(borrowNum-1);
				tos--;
			}
		}
	}
}

void Library::SortBooks(int bNum) {
	for (int i = bNum; i < tos; i++) {
		books[i] = books[i + 1];
	}
}

void Book::SetBook()
{
	cout << "���̖{�̃^�C�g���́H�F";
	cin >> this->title;
	cout << "\n";
	cout << "���̖{�̒��҂́H�F";
	cin >> this->witter;
	cout << "\n";
	cout << "���̖{�̔��s�N�́H�F";
	cin >> this->year;
	cout << "\n";

	cout << "�ۑ��������������܂����B�����p���肪�Ƃ��������܂��B" << endl;
	cout << "-----------------------------\n";
	cout << "�y���̖{�̏��z" << endl;
	this->Show();
}

char * Book::GetTitle()
{
	return this->title;
}

char * Book::GetWitter()
{
	return this->witter;
}

int Book::GetYear()
{
	return this->year;
}

void Book::Show() {

	cout << "�^�C�g���F" << this->GetTitle() << endl;
	cout << "���Җ��F" << this->GetWitter() << endl;
	cout << "���s�N�F" << this->GetYear() << endl;
}


int main() {

	Library* lib = new Library();

	cout << "�{���͂ǂ̂悤�Ȃ��p���ł��傤���H\n";

	lib->Reception();

	while (lib->selectMode != 0) {
		cout << "���ɉ������p���͂���܂��ł��傤���H\n";
		lib->Reception();
	}

	delete lib;

	return 0;
}
*/
