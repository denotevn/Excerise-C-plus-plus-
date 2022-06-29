/**
 * InstrumentWinMain.cpp by Olivia Stone for Code Clinic: C++
 **/

#include <windows.h>

#include "Instrument.hpp"

// instrument is global because both functions reference it
Instrument instrument;

// process messages from the main window
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_LBUTTONDOWN:
		{
            // retrieve mouse position within window
		    int x = (short)LOWORD(lParam);
		    int y = (short)HIWORD(lParam);
            
            // retrieve window dimensions
            RECT rect;
            GetWindowRect(hWnd, &rect);
            int winWidth = rect.right - rect.left;
            int winHeight = rect.bottom - rect.top;
            instrument.play(x, y, winWidth, winHeight);
		}
		break;
	case WM_LBUTTONUP:
		{
            instrument.pause();
		}
	break;
	case WM_MOUSEMOVE:
		{
            if (wParam & MK_LBUTTON) // check if left button is held down
            {
                // retrieve mouse position within window
                int x = (short)LOWORD(lParam);
                int y = (short)HIWORD(lParam);
                
                // retrieve window dimensions
                RECT rect;
                GetWindowRect(hWnd, &rect);
                int winWidth = rect.right - rect.left;
                int winHeight = rect.bottom - rect.top;
                instrument.play(x, y, winWidth, winHeight);
            }
        }
		break;
    case WM_DESTROY:
        instrument.destroy();
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// "main()" function for Windows application
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpCmdLine,
                     int nCmdShow)
{
    // define a window class
    WNDCLASSEX wcex;
    wcex.cbSize        = sizeof(WNDCLASSEX);
    wcex.style         = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc   = (WNDPROC)WndProc;
    wcex.cbClsExtra    = 0;
    wcex.cbWndExtra    = 0;
    wcex.hInstance     = hInstance;
    wcex.hIcon         = 0;
    wcex.hCursor       = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName  = 0;
    wcex.lpszClassName = "InstrumentWindowClass";
    wcex.hIconSm       = 0;
    
    // register the window class
    RegisterClassEx(&wcex);

    // create the window
    HWND hWnd = CreateWindow("InstrumentWindowClass", // class name
                             "Instrument",            // window name
                             WS_OVERLAPPEDWINDOW,     // style
                             CW_USEDEFAULT,           // x position
                             CW_USEDEFAULT,           // y position
                             CW_USEDEFAULT,           // width
                             CW_USEDEFAULT,           // height
                             NULL,                    // parent window
                             NULL,                    // menu
                             hInstance,               // program instance
                             NULL);                   // additional parameters

    // display the window
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // main message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}