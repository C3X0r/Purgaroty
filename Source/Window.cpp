#include"WindowsIsAMeme.h"
#include"Window.h"
#include"Log.h"
spawnWindow::spawnWindow(int width, int height, const char* wndClassName, const char* wndName) noexcept
	:width(width), height(height), wndClassName(wndClassName), wndName(wndName) {
	
	this->hInst = GetModuleHandleA(NULL);
	WNDCLASSEX wc{ 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = instanceProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = this->hInst;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = wndClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);
	this->hWnd = CreateWindowExA(
		WS_EX_CLIENTEDGE,
		wndClassName,
		wndName,
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT,
		width, height,
		NULL, NULL, hInst, NULL);
	ShowWindow(hWnd, SW_SHOW);
}

LRESULT CALLBACK spawnWindow::instanceProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg){
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
