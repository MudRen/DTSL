
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short",HIC"���������"NOR);
	set("long", @LONG
�������־������֡�ժ���֡���ҹ�� (Strong) �������ᰮ
�޲��²�(cougar)����С�ݡ����²��ǵ������ֵ�һ��Ů������
����������Ӣ����ֻ���������һ�ŷ��������ż������ӣ�����
�ϻ���һ���ո���õĲ�ˮ������������̫ʦ�Σ��м����һ��
���������񡣱�����һ�����ҡ�
LONG);
    set("exits", ([
	        "east" : __DIR__"nandajie3",
	        "north":__DIR__"strong_cougar_woshi",
 	]));
    set("objects",([
       __DIR__"obj/lanxindie":1,
       ]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
