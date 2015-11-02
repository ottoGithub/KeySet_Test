#include "stdafx.h"
#include "PrintLog.h"

void OutPutText(HWND hWnd,const TCHAR* szText,RECT& rect)
{
	HDC hdc;
	hdc = GetDC(hWnd);
	InvalidateRect(hWnd,&rect,TRUE);
	DrawText (hdc, szText, -1, &rect,DT_SINGLELINE | DT_CENTER | DT_VCENTER) ;
	ReleaseDC(hWnd,hdc);
}