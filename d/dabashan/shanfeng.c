
#include <ansi.h>
inherit ROOM;

int do_chou(string arg);
int do_pai(string arg);
void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
�����Ǵ��ɽ��һ��ɽ�塣����������׵�������Ԩ��һ��紵
�������ʱ��������ࡣ�Ա߻��кܶ��ʯͷ����֪���ܲ��ܰ�������
ɽȥ��������˵���ָ��֣������ƾͿ��԰�������ɽȥ��
LONG);

  set("exits", ([ 

   "southwest":__DIR__"shanya",
       ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_chou","chou");
   add_action("do_pai","pai");
}

int do_chou(string arg)
{
   object me,weapon;
   me=this_player();
   if(!arg||arg!="ʯͷ")
   return notify_fail("��Ҫ��ʲô��\n");
   if(!objectp(weapon=me->query_temp("weapon")))
   return notify_fail("��Ҫ��ʲô����ʯͷ��\n");
   if(weapon->query("skill_type")!="whip")
   return notify_fail("����û��ñ�������ʯͷ�ɣ�\n");
   if(me->query("sen")<30)
   return notify_fail("�㾫��̫���ˣ�\n");
   if(me->query_skill("whip",1)>=101)
   return notify_fail("��Ļ����޷��ܸ��ˣ����ʯͷ�Ѿ�������һ���ˣ�\n");
   if(me->is_busy())
   return notify_fail("����æ���أ�\n");
   message_vision(YEL"$N���˿�����ʹ����ʯͷ���˹�ȥ��\n"NOR,me);
   me->improve_skill("whip",me->query_int()/2+20+random(5));
   me->add("sen",-30);
   if(me->query_skill("whip",1)<50)
   message_vision("$Nͣ�����������˼�������\n",me);
   else if(me->query_skill("whip",1)<100)
   message_vision("$Nֻ��ž��һ����ʯͷ��������һ���޺ۡ�\n",me);
   else if(me->query_skill("whip",1)<150)
   message_vision("$Nֻ��ž��һ����������һС����ʯ��\n",me);
   else if(me->query_skill("whip",1)<200)
   message_vision("ֻ��ž��һ����ʯͷ�ϳ���һ���Ѻۡ�\n",me);
   return 1;
}

int do_pai(string arg)
{
   object me,weapon;
   me=this_player();
   if(!arg||arg!="ʯͷ")
   return notify_fail("��Ҫ��ʲô��\n");
   if(objectp(weapon=me->query_temp("weapon")))
   return notify_fail("�㻹���������أ���Ѿ�����\n");
   if(me->query("sen")<30)
   return notify_fail("�㾫��̫���ˣ�\n");
   if(me->query_skill("strike",1)>=101)
   return notify_fail("��Ļ����Ʒ��ܸ��ˣ����Ǹ�ʯͷһ����·�ɣ�\n");
   if(me->is_busy())
   return notify_fail("����æ���أ�\n");
   message_vision(HIW"$N�������ƣ��͵س�ʯͷ���˹�ȥ��\n"NOR,me);
   me->improve_skill("strike",me->query_int()/2+20+random(5));
   me->add("sen",-30);
   if(me->query_skill("strike",1)<50)
   message_vision("$N����������Щ��ʹ��\n",me);
   else if(me->query_skill("strike",1)<100)
   message_vision("$N�ջ����ƣ�ʯͷ����һ�Ρ�\n",me);
   else if(me->query_skill("strike",1)<150)
   message_vision("$N�ջ����ƣ�ֻ��ʯͷ���Ѿ�ӡ����һ��ǳǳ����ӡ��\n",me);
   else if(me->query_skill("strike",1)<200)
   message_vision("$N����һ�ĵ�ʯͷ��ֻ����ʯ�׷ɣ�����һ�ء�\n",me);
   return 1;
}
