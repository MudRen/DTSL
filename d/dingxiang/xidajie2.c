// /d/yazhang/xidajie2.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
�����·�൱�Ŀ����ݺü�ƥ�����У������ĵ�·�ᴩ������
�����ǹ�ʦ�������������ʵĵ��̣�����ȫ���ֻ��۵��������㷢�ֲ�
��������ʿ����������̡�
LONG
	);
set("outdoors", "/d/yazhang");
set("exits", ([
                   "north" : __DIR__"guoshifu",  
                   "south" : __DIR__"dangpu",  
                  "east" : __DIR__"guangchang",  
                  "west" : __DIR__"xidajie1",    
	]));
set("objects",([
 "/d/job/tujuejy/zhang":1,
           ]));
 set("no_fight",1); set("no_exert",1);
       setup();
	replace_program(ROOM);
}	
