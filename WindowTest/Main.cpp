#include <Windows.h>
#include <tchar.h>

// ウィンドウプロシージャ、ウィンドウに対するメッセージ処理を行う
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg) {
		// ウィンドウが破棄された時
	case WM_DESTROY:
		PostQuitMessage(0);		// WM_QUITメッセージをメッセージキューに送る
		return 0;
	}
	// デフォルトのメッセージ処理を行う
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

// WinMain関数(アプリケーションの開始関数)
// コンソールアプリケーションと違い、コンソールを開かない
int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	const TCHAR* WC_BASIC = _T("BASIC_WINDOW");
	// シンプルウィンドウクラスの作成
	WNDCLASSEX wcex = {
		sizeof(WNDCLASSEX),
		CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		WndProc,
		0,
		0,
		hInstance,
		(HICON)LoadImage(NULL,MAKEINTRESOURCE(IDI_APPLICATION),IMAGE_ICON,0,0,LR_DEFAULTSIZE | LR_SHARED),
		(HCURSOR)LoadImage(NULL,MAKEINTRESOURCE(IDC_ARROW),IMAGE_CURSOR,0,0,LR_DEFAULTSIZE | LR_SHARED),
		(HBRUSH)GetStockObject(WHITE_BRUSH),
		NULL,
		WC_BASIC,
		NULL };

	// シンプルウィンドウクラス登録
	if (!RegisterClassEx(&wcex)) return false;

	// ウィンドウ幅、高さはディスプレイに依存する。基本は４：３
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;
	// ウィンドウの作成
	HWND hWnd = CreateWindowEx(
		0,
		WC_BASIC,
		_T("Application"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_VISIBLE,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	// メッセージループ
	MSG msg = {};
	while (msg.message != WM_QUIT) {
		// アプリケーションに送られてくるメッセージキューから取得する
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			DispatchMessage(&msg); // アプリケーションの各ウィンドウプロシージャにメッセージを転送する
		}
		// メッセージを処理していないとき
		else {
			// (ここにDirectXの処理を書く)
		}
	}
	return 0;
}