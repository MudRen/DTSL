// /d/yazhang/huanggong.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�ʹ�����");
	set("long", @LONG
�����Ƕ�ͻ�ʵĻʹ����ʹ���ڻԻͣ����Ĺ��Ž����ţ�������
��ͻ����ʿ�ᵶ�����������Żʹ��İ�ȫ�����˴������˶��Ƕ�ͻ�ʵ�
�߹ٴ�Ա��
LONG
	);
set("outdoors", "/d/yazhang");
set("exits", ([
                 "south" : __DIR__"beidajie1",
                 "west": "/d/clone/room/cityroom/dingxiang"  
	]));
	set("objects",([
	"/d/tujue/kehan":1,
	]));
       setup();
	replace_program(ROOM);
}	
