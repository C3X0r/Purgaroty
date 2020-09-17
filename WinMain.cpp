#include"WindowsIsAMeme.h"
#include"Window.h"
#include"Log.h"
#include<windowsx.h>
int CALLBACK WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow) {
    spawnWindow w(400, 600, "noclass", "I'm sorry Bjarne");
    //Message Pump
    MSG msg;
    while (TRUE) {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        switch (msg.message)
        {
        case WM_QUIT: {
            break;
        }
        case WM_CHAR: {
            LiveLog::lastKeyPressed = (char)msg.wParam;
            break;
        }
        case WM_MOUSEMOVE: {
            LiveLog::mousePos::x = (int)GET_X_LPARAM(msg.lParam);
            LiveLog::mousePos::y = (int)GET_Y_LPARAM(msg.lParam);
            switch (msg.wParam) {
            case MK_LBUTTON:
                LiveLog::lmb = true;
                break;
            case MK_RBUTTON:
                LiveLog::rmb = true;
                break;
            case MK_MBUTTON:
                LiveLog::mmb = true;
                break;
            }
        }
        default:
            break;
        }
    } 
    return msg.wParam;
}
