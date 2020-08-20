/*
** Gas mileage program
** Computes average gas mileages for traveling
*/

#include <windows.h>
#include <stdio.h>
#include "resource.h"


LRESULT CALLBACK DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_INITDIALOG:
		{
			SetDlgItemInt(hwnd,IDC_EDIT1,140,FALSE);
			SetDlgItemInt(hwnd,IDC_EDIT2,26,FALSE);
			SetDlgItemInt(hwnd,IDC_EDIT3,16,FALSE);
			SetDlgItemInt(hwnd,IDC_EDIT4,100,FALSE);

			SetFocus(GetDlgItem(hwnd,IDC_EDIT1));
			return 0;
		}
		break;
		case WM_COMMAND:
		{
			int wNotifyCode = HIWORD(wParam), wID = LOWORD(wParam);
			HWND hCtrl = (HWND)lParam;

			if (wID == IDC_BCALC && wNotifyCode == BN_CLICKED)
			{
				char szDue[16], szProfit[16];
				float due, profit;
				unsigned int iCentsPerGallon = GetDlgItemInt(hwnd,IDC_EDIT1,NULL,FALSE);
				unsigned int iReimbursement = GetDlgItemInt(hwnd,IDC_EDIT2,NULL,FALSE);
				unsigned int iMpg = GetDlgItemInt(hwnd,IDC_EDIT3,NULL,FALSE);
				unsigned int iMiles = GetDlgItemInt(hwnd,IDC_EDIT4,NULL,FALSE);

				due = ((float)iReimbursement * (float)iMiles) / 100;
				profit = ((float)iCentsPerGallon / (float)iMpg);
				profit = ((iReimbursement - profit) * iMiles) / 100;
				sprintf(szDue,"$%0.2f",due);
				sprintf(szProfit,"$%0.2f",profit);

				SetDlgItemText(hwnd,IDC_EDIT5,szDue);
				SetDlgItemText(hwnd,IDC_EDIT6,szProfit);
			}
		}
		break;
		case WM_DESTROY:
		case WM_CLOSE:
			EndDialog(hwnd,0);
		break;
		default:
			return FALSE;
	}

	return TRUE;
}
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow)
{
	DialogBox(hInst,MAKEINTRESOURCE(IDD_CALC),NULL,DlgProc);

	return 0;
}

