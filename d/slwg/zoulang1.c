
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
������ʯ����ݵ����ȡ��ϱ�����ݵĴ��š��������ߣ��������
�������ˡ��кܶ����������������ȥ���������ǳ����֡����߲�ʱ��
�����������������
LONG
);


	set("exits", ([
		"north" :__DIR__"zoulang2",
                "south":__DIR__"damen",
                "east":__DIR__"zhangfang",
                "west":__DIR__"bingqipu",                
                "������":"/d/yinkui/door",
                "������Ժ":"/d/chanyuan/miaodoor",
                "����":"/d/luoyang/zhonggulou",
                "�Ⱥ���ի":"/d/jingzhai/door",
                "ͻ��":"/d/changan/xpdajie6",
                "������":"/d/dongming/gangkou2",
                "�Ľ���":"/d/gaoli/xingguan",
                "�μұ�":"/d/lingnan/door",
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}

int valid_leave(object ob,string dir)
{
  
   if(ob->query("combat_exp")<20000&&dir=="south")
     return notify_fail("�㾭����ô�ͣ������̫Σ���ˣ�\n");
    
   return ::valid_leave(ob,dir);
}