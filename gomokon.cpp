#pragma once
#include "minimax_tree.h"
#define MAIN 0
#define GAME 3
#define SETTING 7
enum KEY
{
	KEY_ENTER = 13, KEY_SPACE = 32, KEY_BACKSPACE = 8, KEY_TAP = 9,
	KEY_0 = '0', KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9,
	KEY_A = 'a', KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G, KEY_H, KEY_I, KEY_J, KEY_K,
	KEY_L, KEY_M, KEY_N, KEY_O, KEY_P, KEY_Q, KEY_R, KEY_S, KEY_T, KEY_U, KEY_V, KEY_W, KEY_X, KEY_Y, KEY_Z,
	KEY_F1 = 59, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10,
	KEY_LEFT = 75, KEY_RIGHT = 77, KEY_UP = 72, KEY_DOWN = 80
};

string menulist[20];
clock_t startt, midt, endt;
double duration;
int svduration, ckduration, inpint[5];
bool sdmd, sameend;

thread tc, st;
HANDLE COUT;
HANDLE CIN;
DWORD prevMode;
void game_setting();
void chs_menu(int screen);
int show_menu(int screen);
string aisetshow(int numb);
void update_menu(int screen, int menuint[5]);
void start_game();
void check_time();
void player_stone();
void ai_stone();
void update_map();
void playing_game();
void pause_game();
void erase_game();
void gotoxy(int x, int y);
COORD getXY();
void CursorView(bool show);
int keyinput(int swtch, int sint[5]);
KEY getkey();
int be_input();
int get_input(WORD* vkey, COORD* pos);
void get_cur(int* ver, int* hor);
void savegamelog(int which);
int main()
{
	out.open("log.txt", ios::out | ios::app);
	if (out.is_open() == false) {
		ofstream md("log.txt");
		md.close();
		out.close();
		out.open("log.txt", ios::out | ios::app);
	}
	gameout.open("gamelog.txt", ios::out | ios::app);
	if (gameout.is_open() == false) {
		ofstream md("gamelog.txt");
		md.close();
		gameout.close();
		gameout.open("log.txt", ios::out | ios::app);
	}
	fstream aio;
	aio.open("aiset.txt", ios::in);
	if (aio.is_open()) {
		aio >> gameset.ai.maxdepth >> gameset.ai.firstweight;
		aio >> gameset.ai.secondweight >> gameset.ai.threeweight >> gameset.ai.fourweight;
		aio >> gameset.ai.maxtime >> gameset.time;
	}
	else {
		gameset.ai.maxdepth = 3;
		gameset.ai.firstweight = 100;
		gameset.ai.secondweight = 101;
		gameset.ai.threeweight = 10000;
		gameset.ai.fourweight = 50000;
		gameset.ai.maxtime = 55;
		gameset.time = 60;
	}
	gameset.ai.tfweight = gameset.ai.firstweight * 3;
	gameset.ai.tfweight += gameset.ai.firstweight / 2;
	aio.close();
	resetpoint();
	for (i = 0; i < 21; ++i) {
		for (j = 0; j < 21; ++j) {
			if (i == 0 || j == 0 || i == 20 || j == 20)map[i][j][0] = 3;
		}
	}
	int ver, hor;
	menulist[0] = "���� ����";
	menulist[1] = "AI ������";
	menulist[2] = "���α׷� ����";
	menulist[3] = "PLAYER vs PLAYER";
	menulist[4] = "PLAYER vs AI(��)";
	menulist[5] = "PLAYER vs AI(��)";
	menulist[6] = "���ư���";
	gameset.listnum = 6;
	menulist[7] = "�ִ� Ž�� ����";
	menulist[8] = "�⺻ ����ġ 1";
	menulist[9] = "�⺻ ����ġ 2";
	menulist[10] = "3�� ����ġ";
	menulist[11] = "4�� ����ġ";
	menulist[12] = "�ִ� ���ð�";
	menulist[SETTING + gameset.listnum] = "Ȯ��";
	CursorView(false);
//	get_cur(&ver, &hor);
	chs_menu(MAIN);
	aio.open("aiset.txt", ios::out | ios::trunc);
	aio << gameset.ai.maxdepth << " " << gameset.ai.firstweight << " ";
	aio << gameset.ai.secondweight << " " << gameset.ai.threeweight << " " << gameset.ai.fourweight;
	aio << " " << gameset.ai.maxtime << " " << gameset.time << endl;
	aio.close();
	return 0;
}
void game_setting()
{
	int getint, changecnt, inpt[5];
	bool qutc = true;
	while (qutc) {
		getint = show_menu(SETTING);
		if (getint == SETTING + gameset.listnum + 1) {
			qutc = false;
		}
	}
}
void chs_menu(int screen)
{
	int getint;
	switch (screen) {
	case MAIN:
		getint = show_menu(MAIN);
		switch (getint) {
		case 1:
			chs_menu(GAME);
			break;
		case 2:
			game_setting();
			chs_menu(MAIN);
			break;
		case 3:
			system("cls");
			cout << "���α׷��� �����մϴ�" << endl;
			break;
		default:
			system("cls");
			break;
		}
		break;
	case GAME:
		getint = show_menu(GAME);
		switch (getint) {
		case 4:
			pvp = true;
			turn = true;
			erase_game();
			start_game();
			chs_menu(MAIN);
			break;
		case 5:
			pvp = false;
			turn = true;
			erase_game();
			start_game();
			chs_menu(MAIN);
			break;
		case 6:
			pvp = false;
			turn = false;
			erase_game();
			start_game();
			chs_menu(MAIN);
			break;
		case 7:
			chs_menu(MAIN);
			break;
		default:
			system("cls");
			break;
		}
		break;
	}
}
int show_menu(int screen)
{
	CursorView(false);
	int minchs, maxchs, select = 1;
	switch (screen) {
	case MAIN:
		minchs = 1;
		maxchs = 3;
		inpint[2] = -1;
		break;
	case GAME:
		minchs = 1;
		maxchs = 4;
		inpint[2] = -1;
		break;
	case SETTING:
		minchs = 1;
		maxchs = gameset.listnum + 1;
		inpint[2] = 1;
		break;
	default:
		cout << "��� �޴��� ������� �� �� �����ϴ�. ���α׷��� �����մϴ�" << endl;
		select = -1;
		break;
	}
	if (select != -1) {
		inpint[0] = screen + minchs - 1;
		inpint[1] = screen + maxchs - 1;
		inpint[3] = minchs;
		inpint[4] = -1;
		update_menu(screen, inpint);
		inpint[3] = inpint[2];
		inpint[0] = minchs;
		inpint[1] = maxchs;
		inpint[2] = screen;
		inpint[4] = -1;
		select = keyinput(select, inpint);//ASDF
		select += screen;
	}
//	CursorView(true);
	return select;
}
string aisetshow(int numb)
{
	/*
	menulist[7] = "AI-�ִ� Ž�� ����";
	menulist[8] = "AI-�⺻ ����ġ 1";
	menulist[9] = "AI-�⺻ ����ġ 2";
	menulist[10] = "AI-3�� ����ġ";
	menulist[11] = "AI-4�� ����ġ";
	menulist[12] = "AI-�ִ� ���ð�";*/
	string swr = "ERROR";
	if (numb >= SETTING && numb < SETTING + gameset.listnum) {
		switch (numb) {
		case SETTING:
			swr = to_string(gameset.ai.maxdepth);
			break;
		case SETTING + 1:
			swr = to_string(gameset.ai.firstweight);
			break;
		case SETTING + 2:
			swr = to_string(gameset.ai.secondweight);
			break;
		case SETTING + 3:
			swr = to_string(gameset.ai.threeweight);
			break;
		case SETTING + 4:
			swr = to_string(gameset.ai.fourweight);
			break;
		case SETTING + 5:
			swr = to_string(gameset.ai.maxtime);
			break;
		}
	}
	return swr;
}
void update_menu(int screen, int menuint[5])//�޴�����, �޴���, �߰��޴�����, ���缱��, �߰��޴����ÿ���
{
	int pos = 0;
	system("cls");
	cout << endl;
	for (i = menuint[0]; i <= menuint[1]; ++i) {
		pos++;
		cout << "[";
		if (pos == menuint[3])cout << ">";
		else cout << " ";
		cout << pos << ". " << menulist[i];
		if (pos == menuint[3])cout << "<";
		else cout << " ";
		cout << "]";
		if (menuint[2] != -1) {
			if (menuint[4] == -1) {
				if (i != SETTING + gameset.listnum) {
					if (pos == menuint[3] && menuint[2] == 1)cout << " �� " << aisetshow(i);
					else if (pos != menuint[3] && menuint[2] == 1)cout << " �� " << aisetshow(i);
				}
			}
			else {
				if (pos == menuint[4]) {
				}
			}
		}
		cout << endl;
	}
}
void start_game()
{
	endchk = waitchk = false;
	startt = clock();
	midt = clock();
	svduration = 0;
	update_map();
	startt = clock();
	ckturn = true;
	sdmd = true;
	if (pvp == false && turn == false) {
		ckturn = false;
		turn = true;
		sdmd = false;
		tc = thread(check_time);
		st = thread(ai_stone);
		playing_game();
	}
	else {
		tc = thread(check_time);
		st = thread(player_stone);
		playing_game();
	}
}
void check_time()
{
	double dur;
	clock_t livet;
	int pt[2] = { 3, 1 };
	COORD ptc;
	while (waitchk == false) {
		livet = clock();
		dur = (double)(livet - midt) / CLOCKS_PER_SEC;
		ckduration = dur;
		if (svduration != ckduration) {
			svduration = ckduration;
			ptc = getXY();
			pt[0] = ptc.X;
			pt[1] = ptc.Y;
			dur = (double)(livet - startt) / CLOCKS_PER_SEC;
			ckduration = dur;
//			CursorView(false);
			gotoxy(5, 0);
			cout.width(5);
			cout.fill(' ');
			cout << ckduration;
			cout << "��. ���� ";
			cout.width(5);
			cout.fill(' ');
			cout << svduration;
			cout << "��";
//			CursorView(true);
			gotoxy(pt[0], pt[1]);
		}
	}
}
void player_stone()
{
	midt = clock();
	int inx = -1, iny = -1, crck = -1;
	bool qut = true;
	string inpt;
	char inp[1000];
	char* token;
	while (qut) {
		gotoxy(3, 1);
		get_cur(&iny, &inx);
		crck = 0;
		if (sdmd == true) {
			if (inx == (MSIZE - 1) / 2 + 1 && iny == (MSIZE - 1) / 2 + 1) {
				map[inx][iny][0] = 1 + turn;
				qut = false;
				sdmd = false;
			}
		}
		else {
			if (inx >= 1 && inx <= MSIZE && iny >= 1 && iny <= MSIZE)crck = check_rule(inx, iny, map);
			switch (crck) {
			case 0:
				update_map();
				break;
			case 1:
				map[inx][iny][0] = 1 + turn;
				insertlog.manystone[1]++;
				insertlog.stonelist[insertlog.stonelcnt][0] = inx;
				insertlog.stonelist[insertlog.stonelcnt][1] = iny;
				insertlog.stonelist[insertlog.stonelcnt][2] = 1 + turn;
				insertlog.stonelcnt++;
				qut = false;
				break;
			case 2:
				map[inx][iny][0] = 1 + turn;
				insertlog.manystone[1]++;
				insertlog.stonelist[insertlog.stonelcnt][0] = inx;
				insertlog.stonelist[insertlog.stonelcnt][1] = iny;
				insertlog.stonelist[insertlog.stonelcnt][2] = 1 + turn;
				insertlog.stonelcnt++;
				endchk = true;
				qut = false;
				break;
			}
		}
	}
}
void ai_stone()
{
	midt = clock();
	int getxp = -1, getyp = -1, crck;
	get_st_arr();
	tree(&getxp, &getyp);
	if (getxp != -1 && getyp != -1) {
		crck = check_rule(getxp, getyp, map);
		switch (crck) {
		case 0:
			system("cls");
			cout << "(" << getxp << "," << getyp << ")" << "��ǥ ����" << endl;
			cin.ignore(1000, '\n');
			endchk = true;
			break;
		case 1:
			map[getxp][getyp][0] = 1 + turn;
			insertlog.manystone[0]++;
			insertlog.stonelist[insertlog.stonelcnt][0] = getxp;
			insertlog.stonelist[insertlog.stonelcnt][1] = getyp;
			insertlog.stonelist[insertlog.stonelcnt][2] = 1 + turn;
			insertlog.stonelcnt++;
			break;
		case 2:
			map[getxp][getyp][0] = 1 + turn;
			insertlog.manystone[0]++;
			insertlog.stonelist[insertlog.stonelcnt][0] = getxp;
			insertlog.stonelist[insertlog.stonelcnt][1] = getyp;
			insertlog.stonelist[insertlog.stonelcnt][2] = 1 + turn;
			insertlog.stonelcnt++;
			endchk = true;
			break;
		}
	}
	else {
		system("cls");
		cout << "tree �Լ� ����" << endl;
		cin.ignore(1000, '\n');
		endchk = true;
	}
}
void update_map()
{
	system("cls");
	gotoxy(0, 0);
	int durt;
	endt = clock();
	duration = (double)(endt - startt) / CLOCKS_PER_SEC;
	durt = duration;
	cout << "��ü ";
	cout.width(5);
	cout.fill(' ');
	cout << durt;
	cout << "��. ���� ";
	duration = (double)(endt - midt) / CLOCKS_PER_SEC;
	durt = duration;
	cout.width(5);
	cout.fill(' ');
	cout << durt;
	cout << "��" << endl;
	cout << "?" << endl;
	for (i = 1; i < MSIZE + 1; ++i) {
		cout << "  ";
		for (j = 1; j < MSIZE + 1; ++j) {
			switch (map[i][j][0]) {
			case 1:
				cout << "��";//��
				break;
			case 2:
				cout << "��";//������
				break;
			default:
				if (i == 1) {
					if (j == 1)cout << "�� ";
					else if (j > 1 && j < MSIZE)cout << "�� ";
					else if (j == MSIZE)cout << "�� ";
				}
				else if (i > 1 && i < MSIZE) {
					if (j == 1)cout << "�� ";
					else if (j > 1 && j < MSIZE)cout << "�� ";
					else if (j == MSIZE)cout << "�� ";
				}
				else if (i == MSIZE) {
					if (j == 1)cout << "�� ";
					else if (j > 1 && j < MSIZE)cout << "�� ";
					else if (j == MSIZE)cout << "�� ";
				}
				break;
			}
		}
		cout << endl;
	}
	gotoxy(3, 1);
}
void playing_game()
{
	double ddkur, hkdur;
	clock_t lvt;
	while (endchk == false) {
		st.join();
		waitchk = true;
		tc.join();
		if (pvp == false) {//�ð� �ջ�
			lvt = clock();
			ddkur = (double)(lvt - startt) / CLOCKS_PER_SEC;
			hkdur = ddkur;
			if (ckturn) {
				insertlog.fulltime[1] += svduration;
				if (insertlog.fulltime[0] + insertlog.fulltime[1] < hkdur) {
					insertlog.fulltime[1] += hkdur - (insertlog.fulltime[0] + insertlog.fulltime[1]);
				}
			}
			else {
				insertlog.fulltime[0] += svduration;
				if (insertlog.fulltime[0] + insertlog.fulltime[1] < hkdur) {
					insertlog.fulltime[0] += hkdur - (insertlog.fulltime[0] + insertlog.fulltime[1]);
				}
			}
		}
		midt = clock();
		update_map();
		if (endchk == true)break;
		else {
			//���º� ���� ����
			sameend = false;
			turn = !turn;
			if (pvp == false)ckturn = !ckturn;
			waitchk = false;
			tc = thread(check_time);
			Sleep(10);
			if (ckturn)st = thread(player_stone);
			else st = thread(ai_stone);
		}
	}
	gotoxy(3, 1);
	if (pvp == false) {//AI���� ��� ������ ����
		inpint[0] = turn;
		if (sameend == true)insertlog.aiwin = 2;
		else if (insertlog.aistone - 1 == inpint[0])insertlog.aiwin = 1;
		else insertlog.aiwin = 0;
		if (insertlog.manystone[0] != 0)insertlog.aitime = insertlog.fulltime[0] / insertlog.manystone[0];
		savegamelog(1);
	}
	if (turn)cout << "�浹 ��";
	else cout << "�鵹 ��";
	gotoxy(2, MSIZE + 3);
	cout << "���͸� �Է��ϸ� �޴� ȭ������ ���ư��ϴ�";
	gotoxy(3, 1);
	inpint[0] = inpint[1] = inpint[2] = inpint[3] = 0;
	inpint[4] = -1;
	keyinput(3, inpint);
	erase_game();
}
void pause_game()
{
}
void erase_game()
{
	sameend = false;
	insertlog.aistone = 2 - turn;
	insertlog.aiwin = -1;
	insertlog.fulltime[0] = insertlog.fulltime[1] = 0.0;
	insertlog.manystone[0] = insertlog.manystone[1] = 0;
	insertlog.aitime = insertlog.stonelcnt = 0;
	int k;
	system("cls");
	for (i = 0; i < MSIZE + 2; ++i) {
		for (j = 0; j < MSIZE + 2; ++j) {
			if (i < MSIZE && j < MSIZE) {
				for (k = 0; k < 3; ++k)insertlog.stonelist[i*MSIZE + j][k] = -1;
			}
			for (k = 0; k < 4; ++k)map[i][j][k] = 0;
			if (i == 0 || j == 0 || i == 20 || j == 20)map[i][j][0] = 3;
		}
	}
}
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
COORD getXY() {
	COORD Cur;
	CONSOLE_SCREEN_BUFFER_INFO a;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &a);
	Cur.X = a.dwCursorPosition.X;
	Cur.Y = a.dwCursorPosition.Y;
	return Cur;
}
void CursorView(bool show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
int keyinput(int swtch, int sint[5])//�ּҰ�, �ִ밪, screen, �߰��޴�����, �߰��޴���ȣ
{
	int pp = -1, cnt = 0, clc[10], ii, kbchs, umint[5];
	bool qutc = true;
	KEY ap;
	for (ii = 0; ii < 10; ++ii)clc[ii] = 0;
	kbchs = sint[0];
	switch (swtch) {
	case 1://����Ű �޴� ����
		while (qutc) {
			ap = getkey();
			if (ap == KEY_ENTER) {
				pp = kbchs;
				qutc = false;
			}
			else {
				umint[0] = sint[2] + sint[0] - 1;
				umint[1] = sint[2] + sint[1] - 1;
				umint[2] = sint[3];
				umint[4] = sint[4];
				switch (ap) {
				case KEY_UP:
					if (kbchs > sint[0]) {
						kbchs--;
						umint[3] = kbchs;
						update_menu(sint[2], umint);
					}
					break;
				case KEY_DOWN:
					if (kbchs < sint[1]) {
						kbchs++;
						umint[3] = kbchs;
						update_menu(sint[2], umint);
					}
					break;
				case KEY_LEFT:
					if (kbchs > sint[0]) {
						kbchs--;
						umint[3] = kbchs;
						update_menu(sint[2], umint);
					}
					break;
				case KEY_RIGHT:
					if (kbchs < sint[1]) {
						kbchs++;
						umint[3] = kbchs;
						update_menu(sint[2], umint);
					}
					break;
				default:
					break;
				}
			}
		}
		break;
	case 2://AI ������ �޴�
		while (qutc) {
			ap = getkey();
			if (ap == KEY_ENTER) {
				pp = kbchs;
				qutc = false;
			}
			else {
				umint[0] = sint[2] + sint[0] - 1;
				umint[1] = sint[2] + sint[1] - 1;
				umint[2] = sint[3];
				umint[4] = sint[4];
				switch (ap) {
				case KEY_UP:
					if (kbchs > sint[0]) {
						kbchs--;
						umint[3] = kbchs;
						update_menu(sint[2], umint);
					}
					break;
				case KEY_DOWN:
					if (kbchs < sint[1]) {
						kbchs++;
						umint[3] = kbchs;
						update_menu(sint[2], umint);
					}
					break;
				case KEY_LEFT:
					if (kbchs > sint[0]) {
						kbchs--;
						umint[3] = kbchs;
						update_menu(sint[2], umint);
					}
					break;
				case KEY_RIGHT:
					if (kbchs < sint[1]) {
						kbchs++;
						umint[3] = kbchs;
						update_menu(sint[2], umint);
					}
					break;
				default:
					break;
				}
			}
		}
		break;
	case 3://���͸��Է�
		while (qutc) {
			ap = getkey();
			if (ap == KEY_ENTER)qutc = false;
		}
		break;
	default:
		break;
	}
	return pp;
}
KEY getkey()
{
	int nkey = _getch();
	if (nkey == 0 || nkey == 224)return (KEY)_getch();
	if (nkey >= 'A'&&nkey <= 'Z')nkey += 'a' - 'A';
	return (KEY)nkey;
}
int be_input()
{
	INPUT_RECORD input_record;
	DWORD input_count;

	PeekConsoleInput(CIN, &input_record, 1, &input_count);
	return input_count;
}

int get_input(WORD* vkey, COORD* pos)
{
	INPUT_RECORD input_record;
	DWORD input_count;

	ReadConsoleInput(CIN, &input_record, 1, &input_count);
	switch (input_record.EventType) {
	case MOUSE_EVENT:
		if (pos && (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)) {
			CONSOLE_SCREEN_BUFFER_INFO csbi;

			GetConsoleScreenBufferInfo(COUT, &csbi);

			*pos = input_record.Event.MouseEvent.dwMousePosition;
			pos->X -= csbi.srWindow.Left;
			pos->Y -= csbi.srWindow.Top;

			return MOUSE_EVENT;
		}
		break;

	}
	return 0;
}


void get_cur(int* ver, int* hor)
{
	HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(handle, &prevMode);
	SetConsoleMode(handle, prevMode & ~ENABLE_QUICK_EDIT_MODE);

	DWORD mode;
	WORD key;
	COORD pos;

	int event;
	int x;
	int y;

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1)
	{
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;
				y = pos.Y;

				if (x > 39 || x < 2) break;
				else if (y > 20 || y < 2) break;
				else {
					*ver = x / 2;
					*hor = y - 1;
					return;
				}
			}
		}
	}
}
void savegamelog(int which)
{
	int getdob, ixi;
	string sco[2];
	if (which == 1) {//�� ���Ӵ� ����-���� ���
		gameout << "AI: ";
		if (insertlog.aistone == 1)gameout << "�� ";
		else gameout << "�� ";
		gameout << "���: ";
		if (insertlog.aiwin == 1)gameout << "�� ";
		else if (insertlog.aiwin == 0)gameout << "�� ";
		else gameout << "�� ";
		gameout << "�� ��: ";
		gameout.width(3);
		gameout.fill(' ');
		gameout << insertlog.manystone[0] + insertlog.manystone[1];
		gameout << "(AI ";
		gameout.width(3);
		gameout.fill(' ');
		gameout << insertlog.manystone[0];
		gameout << ") �ð�-���: ";
		if (insertlog.aitime == 0)gameout << "1�ʹ̸�   ";
		else {
			gameout.width(2);
			gameout.fill('0');
			gameout << insertlog.aitime;
			gameout << "�� ��� ";
		}
		gameout << "�ð�-(USER/AI): ";
		getdob = insertlog.fulltime[1];
		gameout << getdob << "��/";
		getdob = insertlog.fulltime[0];
		gameout << getdob << "��" << endl;
		if (insertlog.aiwin == 0) {//�й�� �� ��� ���
			for (ixi = 0; ixi < insertlog.stonelcnt; ++ixi) {
				if (insertlog.stonelist[ixi][2] == 1) {//�鵹
					sco[0] = "[";
					sco[1] = "]";
				}
				else if (insertlog.stonelist[ixi][2] == 2) {//�浹
					sco[0] = "<";
					sco[1] = ">";
				}
				gameout << sco[0];
				gameout.width(2);
				gameout.fill(' ');
				gameout << insertlog.stonelist[ixi][0];
				gameout << ",";
				gameout.width(2);
				gameout.fill(' ');
				gameout << insertlog.stonelist[ixi][1];
				gameout << sco[1];
				if (ixi > 0)gameout << " ";
			}
			gameout << endl;
		}
		gamefull.push_back(insertlog);
	}
	else if (which == 2) {//vector ��ü ����
	}
}
/*
int check_rule(int ptx, int pty)
{
	int rx, ry, cnt, pos, pp;
	if (map[ptx][pty][0] != 0)return 0;//�̹� ���� ��������
	for (l = 0; l < 8; ++l) ckdirection[l][0] = ckdirection[l][1] = ckdirection[l][2] = 0;
	for (k = 1; k <= 5; ++k) {
		for (l = 0; l < 8; ++l) {
			rx = ptx + (direction[l][0] * k);
			ry = pty + (direction[l][1] * k);
			if (rx >= 1 && rx <= MSIZE && ry >= 1 && ry <= MSIZE) {
				if (map[rx][ry][0] == 1 + turn) {
					ckdirection[l][0]++;
					if (ckdirection[l][1] != -1)ckdirection[l][2]++;
					if (ckdirection[l][1] == 0)ckdirection[l][1] = 1;
				}
				else {
					ckdirection[l][1] = -1;
				}
			}
		}
	}
	cnt = pos = 0;
	pp = 1;
	for (l = 0; l < 4; ++l) {
		if (ckdirection[l][2] + ckdirection[7 - l][2] == 5)pp = 0;//����
		else if (ckdirection[l][2] + ckdirection[7 - l][2] == 4)return 2;//�¸�
		else if (ckdirection[l][2] == 2)cnt++;
		else if (ckdirection[l][2] == 3)pos++;
	}
	if (pp == 1) {
		for (l = 4; l < 8; ++l) {
			if (ckdirection[l][2] == 2)cnt++;
			else if (ckdirection[l][2] == 3)pos++;
		}
	}
	if (cnt >= 2 || pos >= 2)pp = 0;//�ݼ�
	return pp;
}*/