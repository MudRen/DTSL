// /d/gaoli/xiaojiuguan
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "С�ƹ�");
	set("long", @LONG
�ƹݲ����������ҵİ��˼��ŷ������������ʡ�С��̨�ϰ���Щ
��̳������Ҳ������Щ�����ף��ϰ׸�֮�ࡣ����İ׸ɺ󾢴�����
��ľƿ�ȴ���١�
LONG
	);
set("exits", ([
                "west" : __DIR__"nandajie",       
	]));
   set("objects",([
      __DIR__"npc/wang":1,
      ]));
       setup();
	replace_program(ROOM);
}	
