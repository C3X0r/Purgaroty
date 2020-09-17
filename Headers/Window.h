#pragma once
#include"WindowsIsAMeme.h"
class spawnWindow {
public:
	spawnWindow(int width, int height, const char* wndClassName, const char* wndName)noexcept;
	static LRESULT CALLBACK instanceProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
private:
	int width;
	int height;
	const char* wndClassName;
	const char* wndName;
	HWND hWnd;
	HINSTANCE hInst;
};
