
#include <ansi.h>
inherit ROOM;

int do_xiulian();
void create ()
{
  set ("short",HIW"����Ժ"NOR);
  set ("long", @LONG
�����ǴȺ���ի������Ժ���ǴȺ���ի�������յĵط����Ⱥ���ի
��ͽ�ϸ����Ե��Ӳ��Ǻܶࡣ
LONG);

  set("exits", ([ 

  "northeast":__DIR__"zoulang1",
  "south":__DIR__"woshi",
    ]));
  set("objects",([
	  __DIR__"npc/geyunqing":1,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}
/*

void init()
{
    add_action("do_xiulian","xiulian");
}

int do_xiulian()
{
  object me;string str;
  me=this_player();
  if(me->query("family/family_name")!="�Ⱥ���ի")
  return notify_fail("ֻ�дȺ���ի���˿���������������\n");
  if(me->is_fighting())
  return notify_fail("ս�������������\n");
  if(me->is_busy())
  return notify_fail("�㻹���������ɣ�\n");
  message_vision("$N������������ʼ����[����ָ]��\n",me);
  str="$N�ھ���������";
  str=replace_string(str,"$N",me->name());
  me->set_temp("apply/short",({str}));
  me->start_busy((:call_other,this_object(),"doing_xiulian",me:),
                 (:call_other,this_object(),"halt_xiulian",me:));
  return 1;
}

int doing_xiulian(object me)
{
   if(me->query("gin")<10||
      me->query("sen")<10)
    {
      message_vision("$N������һ������������Щƣ����վ��������\n",me);
      me->delete_temp("apply/short");
      return 0;
    }
   if(me->query("potential")<40-me->query_int()/2)
    {
      message_vision("$N��Ǳ�ܲ����ˣ�������Ҳ�����м�Ч�ˡ�\n",me);
      me->delete_temp("apply/short");
      return 0;
    }
   me->add("sen",-10);
   me->add("gin",-10);
   me->add("potential",-40+me->query_int()/2);
   me->improve_skill("xiuluo-zhi",me->query_int()/2+(40-me->query_int()/2)*25
                     +me->query_skill("xiuluo-zhi",1)/5);
   return 1;
}

int halt_xiulian(object me)
{
   message_vision("$N�����˿�����վ��������\n",me);
   return 1;
}
*/
