// /d/zhuojun/xiaoxiang.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "�Ը�");
	set("long", @LONG
�����ǵԽ��ĸ�ۡ��ֻ������ɭ�ϣ���ʱ�н���������룬��ͥ��
�֣��Լ��Խ������ٷǳ��Եÿ���
LONG
	);
set("outdoors", "/d/zhuojun");
set("exits", ([
                "west"  :__DIR__"beidajie1",
	]));
	
      set("objects",([
            "/d/job/questjob/npc/zhaijiao":1,
            ]));
       setup();
	replace_program(ROOM);
}	
