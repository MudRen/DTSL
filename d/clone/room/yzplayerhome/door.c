
inherit ROOM;
void create()	
{
	set("short","������Ҵ���");
	set("long", @LONG
������������Ҵ�Ĵ�ڡ���Ҵ��Ǵ����н�Ϊ�򸾵�����
��ʿ��ס�ĵط���Ŀǰ���ﻹû��ʲô�˿ڡ��ϱ߾������ݵĳ�
�������ˣ���������Կ������������Ľ�ˮ�������ǽ�����ӵ�
��·��ֻ���������Ц���ֵ��������ƺ��ǳ����֡�
LONG);
    set("exits", ([
	        "southeast" :"/d/hangzhou/jiangbei",
	        "north":__DIR__"nandajie1",
 	]));
 	
      setup();
      replace_program(ROOM);
	
}
