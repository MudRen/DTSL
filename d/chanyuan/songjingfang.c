
#include <ansi.h>
inherit ROOM;

string do_look();
void create ()
{
  set ("short","�о���");
  set ("long", @LONG
�����Ǿ�����Ժ���о�����ƽʱ��ʦ�����������о������ﾭ����
������ֻ����ʦ���о�����������֪�����Ƕ������ָ��֡�ǽ�Ϲ���
һ�����������������������öɽ�ָ�������գ��м���ɮ��������ؿ�
���������
LONG);

  set("exits", ([ 
	  "northup":__DIR__"changlang5",
	  "east":__DIR__"xiaolu6",
      ]));
  set("item_desc",([
     "hua":(:do_look:),
     "��":(:do_look:),
     ]));
  set("objects",([
     __DIR__"npc/butan":1,
     ]));
  set("valid_startroom", 1);
  setup();
 
}
string do_look()
{
	object me;
	me=this_player();
   
	if(me->query("sen")<20)
		return "�㾫��̫���ˣ�\n";
	if(me->query_skill("finger",1)>=101)
		return "��Ļ���ָ���ܸ��ˣ���Щ���Ѿ�ûʲô���ˣ�\n";
	if(me->is_busy())
		return "����æ���أ�\n";
	me->improve_skill("finger",me->query_int()/2+30+random(5));
	me->add("sen",-20);
	return "�㿴�Ż��е��������ָ������Ϊ������ߡ�\n";
}
   
