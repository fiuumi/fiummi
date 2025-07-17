#include <graphics.h>  
#include <conio.h>
#include <time.h>
#include "EasyXPng.h"  
#include <math.h>
#include <stdio.h>
#define block 20//砖块边长
#define picture 18
#define width 29
#define height 32
#define v 4//怪物移动速度
#define vp 5//吃豆人移动速度
int score;//得分
int blood = 3;//血量
int tim = 0;//无敌时间
int tim2[4];//囚禁怪物时间
int a[height][width] =                                      //绘制地图
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
  1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
  1,0,0,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,0,0,1,
  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,
  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,
  1,1,1,0,0,1,0,0,1,1,1,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,1,
  1,0,1,0,0,1,0,0,1,1,1,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,1,
  1,0,1,0,0,1,3,3,0,0,0,0,0,0,1,0,0,0,0,0,1,3,3,0,0,0,0,0,0,
  1,0,1,0,0,1,3,3,0,0,0,0,0,0,1,0,0,0,0,0,1,3,3,0,0,0,0,0,0,
  1,0,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,
  1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
  1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
  1,1,1,0,0,1,1,1,1,0,0,1,1,2,2,2,1,1,0,0,1,1,1,1,0,0,1,1,1,
  0,0,0,0,0,1,0,0,0,0,0,1,2,2,2,2,2,1,0,0,0,0,0,1,0,0,0,0,0,
  0,0,0,0,0,1,0,0,0,0,0,1,2,2,2,2,2,1,0,0,0,0,0,1,0,0,0,0,0,
  1,1,1,0,0,1,0,0,1,0,0,1,1,1,1,1,1,1,0,0,1,0,0,1,0,0,1,1,1,
  1,0,1,0,0,0,0,0,1,0,0,0,0,0,3,3,0,0,0,0,1,0,0,0,0,0,1,0,1,
  1,0,1,0,0,0,0,0,1,0,0,0,0,0,3,3,0,0,0,0,1,0,0,0,0,0,1,0,1,
  1,1,1,0,0,1,1,1,1,0,0,1,0,0,1,0,0,1,1,1,1,1,1,1,0,0,1,0,1,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
  1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,
  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,
  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,
  1,0,0,1,1,1,0,0,1,1,1,1,0,0,1,0,0,1,1,1,1,0,0,1,1,1,0,0,1,
  1,3,3,1,1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,1,3,3,1,
  1,3,3,1,1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,1,3,3,1,
  1,0,0,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,0,0,1,
  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
void drawblocks(int a, int b)//绘制砖块
{
	setlinecolor(RGB(176, 23, 31));
	setfillcolor(RGB(255, 192, 203));
	fillrectangle(a * block, b * block, (a + 1) * block, (b + 1) * block);
}
void drawfruit(int a, int b)//绘制樱桃
{
	IMAGE img;
	loadimage(&img, _T("./1/17.jpg"), 36, 36);
	putimagePng(a + block - picture, b + block - picture, &img);
}
void begin()//开始界面
{
	while (!_kbhit())
	{
		IMAGE img1;
		loadimage(&img1, _T("./1/6.jpg"), 500, 280);
		putimage(0, -30, &img1);
		TCHAR title[] = _T("吃豆人游戏");
		settextcolor(WHITE);
		settextstyle(50, 0, _T("Consolas"));
		outtextxy(160, 250, title);
		TCHAR explain1[] = _T("吃豆人游戏规则:");
		TCHAR explain2[] = _T("可以通过字母键'w''s''a''d'调整方向");
		TCHAR explain3[] = _T("按空格键进入隐身模式");
		TCHAR explain4[] = _T("吃到樱桃后将获得一段无敌时间");
		TCHAR explain5[] = _T("按空格键开始游戏");
		settextstyle(20, 0, _T("Consolas"));
		outtextxy(20, 370, explain1); outtextxy(20, 420, explain2); outtextxy(20, 470, explain3); outtextxy(20, 520, explain4); outtextxy(20, 570, explain5);
		Sleep(100);
	}
}
void finish1()//成功 显示界面
{
	setfillcolor(RGB(0, 0, 0));
	solidrectangle(0, 0, width * block, (height + 3) * block);
	IMAGE img1;
	loadimage(&img1, _T("./1/6.jpg"), 500, 280);
	putimage(0, 50, &img1);
	TCHAR title[] = _T("恭喜成功通关!");
	settextcolor(WHITE);
	settextstyle(50, 0, _T("Consolas"));
	outtextxy(140, 350, title);
	TCHAR prompt[] = _T("按任意键退出游戏");
	settextstyle(20, 0, _T("Consolas"));
	outtextxy(200, 450, prompt);
	FlushBatchDraw(); // 确保文本显示
	_getch(); // 等待任意按键
}
void finish2()//失败 显示界面
{
	setfillcolor(RGB(0, 0, 0));
	solidrectangle(0, 0, width * block, (height + 3) * block);
	IMAGE img1;
	loadimage(&img1, _T("./1/6.jpg"), 500, 280);
	putimage(0, 50, &img1);
	TCHAR title[] = _T("GAME OVER!");
	settextcolor(WHITE);
	settextstyle(50, 0, _T("Consolas"));
	outtextxy(160, 350, title);
	TCHAR prompt[] = _T("按任意键退出游戏");
	settextstyle(20, 0, _T("Consolas"));
	outtextxy(200, 450, prompt);
	FlushBatchDraw(); // 确保文本显示
	_getch(); // 等待任意按键
}
struct EnemyPlayer//怪物，吃豆人结构体
{
	IMAGE img;
	int x, y;
	int vx, vy;
}enemy[4], player;
void backgrounddraw()//背景绘制
{
	int temp = 0;
	setfillcolor(RGB(0, 0, 0));
	solidrectangle(0, 0, width * block, (height + 3) * block);
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			if (a[j][i] == 1)//绘制墙体
				drawblocks(i, j);
			if (a[j][i] == 0 && a[j + 1][i] == 0 && a[j + 1][i + 1] == 0 && a[j][i + 1] == 0)//绘制豆子并计算豆子数量
			{

				setfillcolor(RGB(255, 255, 255));
				solidcircle((i + 1) * block, (j + 1) * block, 2);
				temp++;
			}
			else if (a[j][i] == 3 && a[j + 1][i] == 3 && a[j + 1][i + 1] == 3 && a[j][i + 1] == 3)//绘制樱桃
			{
				drawfruit(i * block, j * block);
			}
		}
	}
	score = 303 - temp - 10;//分数计算
}
//敌人绘制和移动
void ini()//初始化
{
	enemy[0].x = 20 * block;
	enemy[1].x = 1 * block;
	enemy[2].x = 6 * block;
	enemy[3].x = 26 * block;
	player.x = 13 * block;
	enemy[0].y = 14 * block;
	enemy[1].y = 1 * block;
	enemy[2].y = 17 * block;
	enemy[3].y = 29 * block;
	player.y = 14 * block;
	enemy[0].vy = 0;
	enemy[1].vy = 0;
	enemy[2].vy = -v;
	enemy[3].vy = -v;
	player.vy = 0;
	enemy[0].vx = v;
	enemy[1].vx = v;
	enemy[2].vx = 0;
	enemy[3].vx = 0;
	player.vx = 0;
}
void Enemydraw0(int a, int b)//绘制敌人
{
	loadimage(&enemy[0].img, _T("./1/3.jpg"), 36, 36);
	putimagePng(a + block - picture, b + block - picture, &enemy[0].img);
}
void Enemydraw1(int a, int b)
{
	loadimage(&enemy[1].img, _T("./1/2.jpg"), 36, 36);
	putimagePng(a + block - picture, b + block - picture, &enemy[1].img);
}
void Enemydraw2(int a, int b)
{
	loadimage(&enemy[2].img, _T("./1/4.jpg"), 36, 36);
	putimagePng(a + block - picture, b + block - picture, &enemy[2].img);
}
void Enemydraw3(int a, int b)
{
	loadimage(&enemy[3].img, _T("./1/5.jpg"), 36, 36);
	putimagePng(a + block - picture, b + block - picture, &enemy[3].img);
}
int sum;//吃豆人动画效果
void playerdraw(int a, int b)//绘制吃豆人
{
	if (GetAsyncKeyState(' '))//隐身状态
	{
		loadimage(&player.img, _T("./1/11.jpg"), 36, 36);
		putimagePng(a + 1 * block - picture, b + 1 * block - picture, &player.img);
	}
	else//普通形态
	{
		if (sum % 3 == 0)//动画效果
		{
			loadimage(&player.img, _T("./1/7.jpg"), 36, 36);
			putimagePng(a + block - picture, b + block - picture, &player.img);
		}
		else
		{
			if (player.vx > 0 && player.vy == 0)
				loadimage(&player.img, _T("./1/1.jpg"), 36, 36);
			else if (player.vx < 0 && player.vy == 0)
				loadimage(&player.img, _T("./1/9.jpg"), 36, 36);
			else if (player.vx == 0 && player.vy > 0)
				loadimage(&player.img, _T("./1/10.jpg"), 36, 36);
			else if (player.vx == 0 && player.vy < 0)
				loadimage(&player.img, _T("./1/8.jpg"), 36, 36);
			putimagePng(a + 1 * block - picture, b + 1 * block - picture, &player.img);
		}
	}
}
void redplayerdraw(int a, int b)//绘制狂暴吃豆人
{
	if (sum % 3 == 0)
	{
		loadimage(&player.img, _T("./1/12.jpg"), 36, 36);
		putimagePng(a + block - picture, b + block - picture, &player.img);
	}
	else
	{
		if (player.vx > 0 && player.vy == 0)
			loadimage(&player.img, _T("./1/15.jpg"), 36, 36);
		else if (player.vx < 0 && player.vy == 0)
			loadimage(&player.img, _T("./1/13.jpg"), 36, 36);
		else if (player.vx == 0 && player.vy > 0)
			loadimage(&player.img, _T("./1/16.jpg"), 36, 36);
		else if (player.vx == 0 && player.vy < 0)
			loadimage(&player.img, _T("./1/14.jpg"), 36, 36);
		putimagePng(a + 1 * block - picture, b + 1 * block - picture, &player.img);
	}
}
void scoredraw()//得分绘制
{
	TCHAR s[10];
	swprintf_s(s, _T("%d"), score);
	settextstyle(40, 0, _T("宋体"));
	outtextxy(20, 653, s);
}
void blooddraw()//生命值绘制
{
	IMAGE img;
	loadimage(&img, _T("./1/18.jpg"), 36, 36);
	if (blood > 0)
		putimagePng(180, 653, &img);
	if (blood > 1)
		putimagePng(220, 653, &img);
	if (blood > 2)
		putimagePng(260, 653, &img);

}
void Enemyupdate()//怪物数据更新
{
	for (int i = 0; i < 4; i++)
	{
		if (enemy[i].x == 14 * block && enemy[i].y == 14 * block && tim2[i] > 0)//被囚禁
		{
			enemy[i].vy = 0;
			enemy[i].vx = 0;
		}
		else if (enemy[i].x == 14 * block && enemy[i].y == 14 * block && tim2[i] == 0)//释放
		{
			enemy[i].vy = -v;
			enemy[i].vx = 0;
		}
		//碰撞砖块转向
		//向右
		if (enemy[i].vx > 0 && enemy[i].vy == 0 && getpixel(enemy[i].x + 2 * block, enemy[i].y + 1 * block + 5) == RGB(255, 192, 203) && getpixel(enemy[i].x + 1 * block + 5, enemy[i].y - 0.5 * block) == RGB(255, 192, 203))
		{
			enemy[i].x = enemy[i].x - v;
			enemy[i].vy = v;
			enemy[i].vx = 0;
		}
		else if (enemy[i].vx > 0 && enemy[i].vy == 0 && getpixel(enemy[i].x + 2 * block, enemy[i].y + 1 * block + 5) == RGB(255, 192, 203) && getpixel(enemy[i].x + 1 * block + 5, enemy[i].y + 2.5 * block) == RGB(255, 192, 203))
		{
			enemy[i].x = enemy[i].x - v;
			enemy[i].vy = -v;
			enemy[i].vx = 0;
		}
		else if (enemy[i].vx > 0 && enemy[i].vy == 0 && getpixel(enemy[i].x + 2 * block, enemy[i].y + 1 * block + 5) == RGB(255, 192, 203))
		{
			enemy[i].x = enemy[i].x - v;
			enemy[i].vx = 0;
			int sum = rand() % 100;
			if (sum > 40)
				enemy[i].vy = v;
			else
				enemy[i].vy = -v;
		}
		//向左
		else if (enemy[i].vx < 0 && enemy[i].vy == 0 && getpixel(enemy[i].x, enemy[i].y + 1 * block + 5) == RGB(255, 192, 203) && getpixel(enemy[i].x + 1 * block + 5, enemy[i].y - 0.5 * block) == RGB(255, 192, 203))
		{
			enemy[i].x = enemy[i].x + v;
			enemy[i].vy = v;
			enemy[i].vx = 0;
		}
		else if (enemy[i].vx < 0 && enemy[i].vy == 0 && getpixel(enemy[i].x, enemy[i].y + 1 * block + 5) == RGB(255, 192, 203) && getpixel(enemy[i].x + 1 * block + 5, enemy[i].y + 2.5 * block) == RGB(255, 192, 203))
		{
			enemy[i].x = enemy[i].x + v;
			enemy[i].vy = -v;
			enemy[i].vx = 0;
		}
		else if (enemy[i].vx < 0 && enemy[i].vy == 0 && getpixel(enemy[i].x, enemy[i].y + 1 * block + 5) == RGB(255, 192, 203))
		{
			enemy[i].x = enemy[i].x + v;
			enemy[i].vx = 0;
			int sum = rand() % 100;
			if (sum > 50)
				enemy[i].vy = v;
			else
				enemy[i].vy = -v;
		}
		//向上
		else if (enemy[i].vx == 0 && enemy[i].vy < 0 && getpixel(enemy[i].x + 1 * block + 5, enemy[i].y) == RGB(255, 192, 203) && getpixel(enemy[i].x + 2.5 * block, enemy[i].y + 1 * block + 5) == RGB(255, 192, 203))
		{
			enemy[i].y = enemy[i].y + v;
			enemy[i].vy = 0;
			enemy[i].vx = -v;
		}
		else if (enemy[i].vx == 0 && enemy[i].vy < 0 && getpixel(enemy[i].x + 1 * block + 5, enemy[i].y) == RGB(255, 192, 203) && getpixel(enemy[i].x - 0.5 * block, enemy[i].y + 1 * block + 5) == RGB(255, 192, 203))
		{
			enemy[i].y = enemy[i].y + v;
			enemy[i].vy = 0;
			enemy[i].vx = v;
		}
		else if (enemy[i].vx == 0 && enemy[i].vy < 0 && getpixel(enemy[i].x + 1 * block + 5, enemy[i].y) == RGB(255, 192, 203))
		{
			enemy[i].y = enemy[i].y + v;
			enemy[i].vy = 0;
			int sum = rand() % 100;
			if (sum > 50)
				enemy[i].vx = v;
			else
				enemy[i].vx = -v;
		}
		//向下
		else if (enemy[i].vx == 0 && enemy[i].vy > 0 && getpixel(enemy[i].x + 1 * block + 5, enemy[i].y + 2 * block) == RGB(255, 192, 203) && getpixel(enemy[i].x + 2.5 * block, enemy[i].y + 1 * block + 5) == RGB(255, 192, 203))
		{
			enemy[i].y = enemy[i].y - v;
			enemy[i].vy = 0;
			enemy[i].vx = -v;
		}
		else if (enemy[i].vx == 0 && enemy[i].vy > 0 && getpixel(enemy[i].x + 1 * block + 5, enemy[i].y + 2 * block) == RGB(255, 192, 203) && getpixel(enemy[i].x - 0.5 * block, enemy[i].y + 1 * block + 5) == RGB(255, 192, 203))
		{
			enemy[i].y = enemy[i].y - v;
			enemy[i].vy = 0;
			enemy[i].vx = v;
		}
		else if (enemy[i].vx == 0 && enemy[i].vy > 0 && getpixel(enemy[i].x + 1 * block + 5, enemy[i].y + 2 * block) == RGB(255, 192, 203))
		{
			enemy[i].y = enemy[i].y - v;
			enemy[i].vy = 0;
			int sum = rand() % 100;
			if (sum > 50)
				enemy[i].vx = v;
			else
				enemy[i].vx = -v;
		}
		//当遇到岔路口时转向
		else if ((enemy[i].x == 3 * block || enemy[i].x == 9 * block || enemy[i].x == 18 * block || enemy[i].x == 24 * block) && (enemy[i].y == 4 * block || enemy[i].y == 8 * block || enemy[i].y == 11 * block || enemy[i].y == 14 * block || enemy[i].y == 17 * block || enemy[i].y == 20 * block || enemy[i].y == 23 * block || enemy[i].y == 29 * block))
		{
			//向右
			if (enemy[i].vx > 0 && enemy[i].vy == 0)
			{
				int sum = rand() % 150;
				if (sum >= 0 && sum < 60)
				{
					enemy[i].vx = v;
					enemy[i].vy = 0;
				}
				else if (sum > 59 && sum < 120)
				{
					enemy[i].vx = 0;
					enemy[i].vy = v;
				}
				else if (sum > 119 && sum < 150)
				{
					enemy[i].vx = 0;
					enemy[i].vy = -v;
				}
			}
			//向左
			else if (enemy[i].vx < 0 && enemy[i].vy == 0)
			{
				int sum = rand() % 150;
				if (sum >= 0 && sum < 60)
				{
					enemy[i].vx = -v;
					enemy[i].vy = 0;
				}
				else if (sum > 59 && sum < 120)
				{
					enemy[i].vx = 0;
					enemy[i].vy = v;
				}
				else if (sum > 119 && sum < 150)
				{
					enemy[i].vx = 0;
					enemy[i].vy = -v;
				}
			}
			//向下
			else if (enemy[i].vx == 0 && enemy[i].vy > 0)
			{
				int sum = rand() % 100;
				if (sum >= 0 && sum < 20)
				{
					enemy[i].vx = v;
					enemy[i].vy = 0;
				}
				else if (sum > 19 && sum < 41)
				{
					enemy[i].vx = -v;
					enemy[i].vy = 0;
				}
				else if (sum > 40 && sum < 100)
				{
					enemy[i].vx = 0;
					enemy[i].vy = v;
				}

			}
		}
		//穿越
		else if (enemy[i].x == 28 * block && (enemy[i].y == 8 * block || enemy[i].y == 14 * block))
		{
			enemy[i].x = 0;
			int random;
			random = rand() % 2;
			if (random % 2 == 1)
				enemy[i].y = 14 * block;
			else
				enemy[i].y = 20 * block;
		}
		else if (enemy[i].x == 0 && (enemy[i].y == 14 * block || enemy[i].y == 20 * block))
		{
			enemy[i].x = 28 * block;
			int random;
			random = rand() % 2;
			if (random % 2 == 1)
				enemy[i].y = 8 * block;
			else
				enemy[i].y = 14 * block;
		}
		enemy[i].x = enemy[i].x + enemy[i].vx;
		enemy[i].y = enemy[i].y + enemy[i].vy;
	}
}
void Playerupdate()//吃豆人数据更新
{
	//碰撞砖块停止
	//向右
	if (player.vx > 0 && player.vy == 0 && (getpixel(player.x + 2 * block, player.y + 2 * block - 1) == RGB(255, 192, 203) || getpixel(player.x + 2 * block, player.y + 1) == RGB(255, 192, 203) || getpixel(player.x + 2 * block, player.y + block) == RGB(255, 192, 203)))
	{
		player.x = player.x - vp;
		player.vx = 0;
		player.vy = 0;
	}
	//向左
	else if (player.vx < 0 && player.vy == 0 && (getpixel(player.x, player.y + 2 * block - 1) == RGB(255, 192, 203) || getpixel(player.x, player.y + 1) == RGB(255, 192, 203) || getpixel(player.x, player.y + block) == RGB(255, 192, 203)))
	{
		player.x = player.x + vp;
		player.vx = 0;
		player.vy = 0;
	}
	//向上

	else if (player.vx == 0 && player.vy < 0 && (getpixel(player.x + 2 * block - 1, player.y) == RGB(255, 192, 203) || getpixel(player.x + 1, player.y) == RGB(255, 192, 203) || getpixel(player.x + block, player.y) == RGB(255, 192, 203)))
	{
		player.y = player.y + vp;
		player.vx = 0;
		player.vy = 0;
	}
	//向下
	else if (player.vx == 0 && player.vy > 0 && (getpixel(player.x + 2 * block - 1, player.y + 2 * block) == RGB(255, 192, 203) || getpixel(player.x + 1, player.y + 2 * block) == RGB(255, 192, 203) || getpixel(player.x + block, player.y + 2 * block) == RGB(255, 192, 203)))
	{
		player.y = player.y - vp;
		player.vx = 0;
		player.vy = 0;
	}
	//当遇到岔路口时停止
	else if ((player.x == 3 * block || player.x == 6 * block || player.x == 9 * block || player.x == 12 * block || player.x == 15 * block || player.x == 18 * block || player.x == 21 * block || player.x == 24 * block) && (player.y == 4 * block || player.y == 8 * block || player.y == 11 * block || player.y == 14 * block || player.y == 17 * block || player.y == 20 * block || player.y == 23 * block || player.y == 29 * block))
	{
		player.vx = 0;
		player.vy = 0;
	}
	else if ((player.x == 13 * block || player.x == 14 * block) && player.y == 14 * block)
	{
		player.vx = 0;
		player.vy = 0;
	}
	//穿越
	else if (player.x == 28 * block && (player.y == 8 * block || player.y == 14 * block))//触碰到边界随机更新位置
	{
		player.x = 0;
		int random;
		random = rand() % 2;
		if (random % 2 == 1)
			player.y = 14 * block;
		else
			player.y = 20 * block;
	}
	else if (player.x == 0 && (player.y == 14 * block || player.y == 20 * block))
	{
		player.x = 28 * block;
		int random;
		random = rand() % 2;
		if (random % 2 == 1)
			player.y = 8 * block;
		else
			player.y = 14 * block;
	}
}
void meetupdate()//被怪物抓到
{
	for (int i = 0; i < 4; i++)
	{
		if (GetAsyncKeyState(' '))//隐身
		{
		}
		else
		{
			if ((abs(player.x - enemy[i].x) < 3 && abs(player.y - enemy[i].y) < block) || (abs(player.y - enemy[i].y) < 3 && abs(player.x - enemy[i].x) < block))
			{
				player.x = 13 * block;//玩家返回出生地
				player.y = 14 * block;
				blood--;
			}
		}
	}
}
void redmeetupdate()//把怪物吃掉
{
	for (int i = 0; i < 4; i++)
	{
		if ((abs(player.x - enemy[i].x) < 3 && abs(player.y - enemy[i].y) < block) || (abs(player.y - enemy[i].y) < 3 && abs(player.x - enemy[i].x) < block))
		{
			enemy[i].x = 14 * block;//怪物回家
			enemy[i].y = 14 * block;
		}
	}
}
void updateWithInput() // 和输入有关的更新
{
	if (GetAsyncKeyState(' '))
	{
		player.vx = 0; player.vy = 0;
	}
	else// 当按键时，切换角色显示图片，更改位置
	{
		if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))  // 按下D键或右方向键
		{
			player.vx = vp; player.vy = 0;
		}
		if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))// 按下A键或左方向键
		{
			player.vx = -vp; player.vy = 0;
		}
		if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))     // 按下W键或上方向键
		{
			player.vx = 0; player.vy = -vp;
		}
		if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))     // 按下S键或下方向键
		{
			player.vx = 0; player.vy = vp;
		}
	}
	player.x = player.x + player.vx;
	player.y = player.y + player.vy;
	sum++;//吃豆人动画
}
void arrayupdate()//吃豆
{
	a[int(player.y / block)][int(player.x / block)] = 2;
}
void timeupdate()//时间更新
{
	if (a[player.y / block][player.x / block] == 3)//当吃到樱桃时，无敌时间更新
		tim = 250;
	tim--;
	for (int i = 0; i < 4; i++)//怪物在一段时间后被放出
	{
		if ((abs(player.x - enemy[i].x) < 3 && abs(player.y - enemy[i].y) < block) || (abs(player.y - enemy[i].y) < 3 && abs(player.x - enemy[i].x) < block))
		{
			tim2[i] = 150;//怪物放出时间时间更新
		}
		tim2[i]--;//无敌时间计算
	}
}
//合并在一起
void startup()//初始化
{
	ini();
}
void show()  // 显示
{
	// 显示场景相关信息
	Enemydraw0(enemy[0].x, enemy[0].y); Enemydraw1(enemy[1].x, enemy[1].y); Enemydraw2(enemy[2].x, enemy[2].y); Enemydraw3(enemy[3].x, enemy[3].y);
	if (tim > 0)//狂暴形态
		redplayerdraw(player.x, player.y);
	else //普通形态
		playerdraw(player.x, player.y);
	scoredraw();
	blooddraw();
	FlushBatchDraw();
	Sleep(1); // 暂停若干毫秒
}
void update()
{
	Enemyupdate();
	Playerupdate();
	timeupdate();
	arrayupdate();
	if (tim > 0)//吃怪物
		redmeetupdate();
	else//被怪物吃
		meetupdate();
}
int pd;//判断成功与否
int main()
{
	initgraph(width * block, (height + 3) * block);
	cleardevice();
	begin();
	cleardevice();
	startup();
	BeginBatchDraw();
	while (1)
	{
		backgrounddraw();
		show();
		update();
		updateWithInput();
		if (score == 293)//判断是否成功通关
		{
			pd = 1;
			break;
		}
		if (blood == 0)
		{
			pd = 0;
			break;
		}
	}
	EndBatchDraw();
	if (pd == 1)
		finish1();
	if (pd == 0)
		finish2();
	return 0;
}
