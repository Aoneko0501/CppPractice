/*

#include<iostream>
using namespace std;

// 図書館的なプログラム

#define SIZE 10	// 保管できる本は10冊まで

class Book {
	char title[40];	// タイトル
	char witter[40];// 著者名
	int year;		// 発行年
public:
	Book() {}

	void SetBook();	// 情報入力用関数

	char* GetTitle();				// タイトル
	char* GetWitter();				// 著者名
	int GetYear();					// 発行年
	void Show();					// この本の情報
};

class Library {
	Book books[SIZE];	// 本
	int tos;		// 保管冊数

public:

	int selectMode;	// 帰るか帰らないかの確認

	Library();
	~Library();

	void Reception();	// 受付：ここで本を追加するかどうか選択
	void MakeBook();
	void ShowBooks();
	void BorrowBook();

	void SortBooks(int bNum);	// 本が借りられた場合の処理

};

Library::Library() {
	cout << "ようこそ。ドラゴニカ図書館へ。" << endl;
	// 初期化
	this->tos = 0;
	this->selectMode = 0;
}

Library::~Library() {
	cout << "またのご利用をお待ちしております。" << endl;
}

void Library::Reception() {

	cout << "【１：本を寄贈する】\n【２：本を借りる】\n【３：ここにある本を知りたい】\n【０：何でもないです】" << endl;
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
	cout << "本の寄贈ですね\n";

	if (tos >= SIZE) {
		cout << "申し訳ございません、これ以上あなたから本を寄贈してもらうことはできません。\n";
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
		cout << "申し訳ございません。当図書館にあなたから寄贈されている本はありません。\n";
	}
	else {
		cout << "現在ここの図書館にあるあなたが寄贈した本は以下の通りになります。\n";
		for (int i = 0; i < tos; i++) {
			cout << "-----------------------------\n";
			cout << "【No." << i + 1 << "】\n";
			books[i].Show();
		}
	}
}

// 本を借りて図書館の本リストから該当の本を削除する
void Library::BorrowBook()
{
	int borrowNum;

	char borrow;
	if (tos == 0) {
		cout << "申し訳ございません。当図書館にあなたから寄贈されている本はありません。\n";
	}
	else {
		cout << "現在ここの図書館にあるあなたが寄贈した本は以下の通りになります。\n";
		for (int i = 0; i < tos; i++) {
			cout << "-----------------------------\n";
			cout << "【No." << i + 1 << "】\n";
			books[i].Show();
		}
		cout << "どの本を借りていきますか？:";
		cin >> borrowNum;

		if (tos <= borrowNum - 1 || borrowNum <= 0) {
			// 保管されていない数が入力された時
			cout << "申し訳ございませんが、その番号の本は借りれません。\n";
		}
		else {
			cout << "こちらの本ですね？\n";
			books[borrowNum - 1].Show();
			cout << "借りていきますか？(y/n)\n";
			cin >> borrow;

			if (borrow != 'y') {
				return;
			}
			else {
				cout << "ご利用ありがとうございました。\n";
				// ここに指定された数字の本を配列から取り出して並び替える処理をする。
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
	cout << "その本のタイトルは？：";
	cin >> this->title;
	cout << "\n";
	cout << "その本の著者は？：";
	cin >> this->witter;
	cout << "\n";
	cout << "その本の発行年は？：";
	cin >> this->year;
	cout << "\n";

	cout << "保存が完了いたしました。ご利用ありがとうございます。" << endl;
	cout << "-----------------------------\n";
	cout << "【この本の情報】" << endl;
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

	cout << "タイトル：" << this->GetTitle() << endl;
	cout << "著者名：" << this->GetWitter() << endl;
	cout << "発行年：" << this->GetYear() << endl;
}


int main() {

	Library* lib = new Library();

	cout << "本日はどのようなご用件でしょうか？\n";

	lib->Reception();

	while (lib->selectMode != 0) {
		cout << "他に何かご用件はありますでしょうか？\n";
		lib->Reception();
	}

	delete lib;

	return 0;
}
*/
