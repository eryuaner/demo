#include<iostream>
using namespace std;
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

void text() {
	settextcolor(RED);
	settextstyle(50,0,TEXT("Î¢ÈíÑÅºÚ"));
	int wid = textwidth(TEXT("ÒôÀÖ²¥·ÅÆ÷1.0"));
	setbkmode(TRANSPARENT);
	outtextxy((545 / 2) - wid / 2, 50, TEXT("ÒôÀÖ²¥·ÅÆ÷1.0"));
}


int main() {
		initgraph(545, 307,SHOWCONSOLE);
		HWND hwnd = GetHWnd();
		SetWindowText(hwnd, TEXT("ÒôÀÖ²¥·ÅÆ÷"));
		bool index = false;//ÒôÀÖ¿ª¹Ø

		mciSendString(TEXT("open ./bgm.mp3"), 0, 0, 0);
		IMAGE img2;
		loadimage(&img2, TEXT("./ÔÝÍ£.png"), 90, 98);
		putimage(227, 220, &img2);

		BeginBatchDraw();//¿ªÊ¼ÅúÁ¿¼ÓÔØ
		while (true) {
		IMAGE img;
		loadimage(&img, TEXT("./v2.jpg"),545,307);
		putimage(0, 0, &img);
		text();
		IMAGE img2;
		loadimage(&img2, TEXT("./ÔÝÍ£.png"), 90, 98);
		if(!index)
			putimage(227, 220, &img2);
		IMAGE img3;
		loadimage(&img3, TEXT("./²¥·Å.png"),90,98);
		if(index)
			putimage(227, 220, &img3);
		FlushBatchDraw();
		if (MouseHit()) {
			MOUSEMSG msg;
			msg = GetMouseMsg();
			
			if (msg.x > 227 && msg.y > 220 && msg.x < 317 && msg.y < 318 ) {
				//cout << msg.x << msg.y << endl;
				switch (msg.uMsg) {
				case WM_LBUTTONDOWN:index = !index; break;
				}
			}
		}
		if (index) {
			mciSendString(TEXT("play ./bgm.mp3 repeat"), 0, 0, 0);
		}
		else {
			mciSendString(TEXT("close ./bgm.mp3"), 0, 0, 0);
		}

		
		cleardevice();
	
	}
	closegraph();
	return 0;
}
