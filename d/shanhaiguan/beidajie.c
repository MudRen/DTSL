// /d/gaoli/beidajie
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
�����·�൱�Ŀ����ݺü�ƥ�����У������ĵ�·�ᴩ�ϱ���
������ɽ���صı���֣���Ϊɽ�������������ԭ�ؾ�֮·����������
�Ŀ����ر�࣬������ɽ���ص���վ��������һ�����У��ϱ���ɽ����
������㳡�� 
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
		"south" : __DIR__"guangchang",
		"north" : __DIR__"beichengmen",
                "east" : __DIR__"yizhan",   
                "west" : __DIR__"xingyilong",      
	]));
set("objects",([
  __DIR__"npc/shangren":1,
 ]));
 
       setup();
	replace_program(ROOM);
}	
