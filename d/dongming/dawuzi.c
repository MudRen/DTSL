
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"����"NOR);
	set("long", @LONG
������һ�����Ĵ����ӡ������Ƕ���ܼ����µĵط����������
һ�Ŵ����ӣ�������˺ܶ��˱��ȶ���������ܼ�����������¡�����
�İ���ܼ򵥣�ûʲô�����Ķ�����
LONG);
	set("exits", ([	     		
		"south":__DIR__"echanglang1",
		
	]));
/*       set("objects",([
          "/d/job/dmjob/guanjia":1,
          ]));*/
       set("no_fight",1);
       set("valid_startroom", 1);   
    	setup();
       
       
}

