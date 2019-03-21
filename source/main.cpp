#include <Windows.h>
#include "res.h"
#include <cstdlib>
#include <ctime>

INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
int charToInt(char ch[], int lengthChar);
int randomNumber;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
  srand(time(NULL));
  randomNumber = rand() % 101;
  int guessNumber;
  HWND hwndMainWindow = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINVIEW), NULL, DialogProc);
  ShowWindow(hwndMainWindow, iCmdShow);

  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  
  return 0;

}



INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg)
  {
  case WM_COMMAND:
    switch (HIWORD(wParam))
    {
    case BN_CLICKED:
      switch (LOWORD(wParam))
      {
      case IDC_BUTTON_GUESS:
        CHAR szText[4];
        HWND hwndEditBox = GetDlgItem(hwndDlg, IDC_NUMBER_GUESS);
        int iTextLength = GetWindowTextLength(hwndEditBox);
        GetWindowText(hwndEditBox, szText, iTextLength + 1);
        int iNumberBox = charToInt(szText, iTextLength);
        if(iNumberBox < randomNumber) MessageBox(hwndDlg, TEXT("wincyj"), TEXT("klikniecie"), MB_OK);
        else
        {
         if(iNumberBox > randomNumber) MessageBox(hwndDlg, TEXT("mniyj"), TEXT("klikniecie"), MB_OK);
         else MessageBox(hwndDlg, TEXT("zagdłeś"), TEXT("klikniecie"), MB_OK);
        }
        return TRUE; 
      }
    }
    return FALSE;
  case WM_LBUTTONDOWN:
    CHAR szTex[200];
    wsprintf(szTex, "Klinkales myszka x=%d, y=%d", LOWORD(lParam), HIWORD(lParam));
    MessageBox(hwndDlg, szTex, TEXT("Klikniecie"), MB_OK);
    break;
  case WM_CLOSE:
    DestroyWindow(hwndDlg); // niszczenie
    PostQuitMessage(0); // umieszczenie w pętli komnuikaktoów
    return TRUE;
  }
  return FALSE;
}

int charToInt(char ch[], int lengthChar)
{
  int outInt = 0;
  if (lengthChar == 1) return ch[0] - '0';
  else
  {
    if (lengthChar == 2) return (ch[1] - '0' + (ch[0] - '0') * 10);
    else  return (ch[2] - '0' + (ch[1] - '0') * 10 + (ch[0] - '0') * 100);
  }
  return 0;
}

/*

zmodyfikuj kod aby zmiana napisu była w momencia zakocnzenia edycji tekstu

EN_CHENGE


gra :D zganij ale comp losuje


*/