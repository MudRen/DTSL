
#include <ansi.h>
inherit ROOM;

int do_ci(string arg);

void create ()
{
  set ("short",HIG"����"NOR);
  set ("long", @LONG
������һƬ���֡�һ����紵������Ҷ����΢�粻ס�ذڶ�������
���Ա߲���һ�����ʣ��������Ѿ���Щ��ͷ�ˡ�Զ���м��������ĵ���
����������������������������ȵ�������
LONG);
  set("exits",([
	  
	  "southwest":__DIR__"xiaojing",
	  ]));

  set("outdoors","yjp");

  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_ci","ci");
}

int do_ci(string arg)
{
   object me,weapon;
   me=this_player();
   if(!arg||arg!="����")
   return notify_fail("��Ҫ��ʲô��\n");
   if(!objectp(weapon=me->query_temp("weapon")))
   return notify_fail("û����������Ҫ�ý�����\n");
   if(weapon->query("skill_type")!="sword")
   return notify_fail("��Ӷ�"+weapon->name()+"���˼��£����ֺ����ô���\n");
   if(weapon->query("flag")==1)
   return notify_fail("���ɥ�ķ������еı����Ѿ��ϵ��ˣ�\n");
   if(me->query("sen")<20)
   return notify_fail("�㾫��̫���ˣ�\n");
   if(me->query_skill("sword",1)>=101)
   return notify_fail("��Ļ��������ܸ��ˣ���Щ����ûʲô�õģ�\n");
   if(me->is_busy())
   return notify_fail("����æ���أ�\n");
   message_vision(YEL"$N�������������ڷ��аڶ������ӣ�ͻȻһ�����˳�ȥ��\n"NOR,me);
   me->improve_skill("sword",me->query_int()/2+20+random(5));
   me->add("sen",-20);
   if(me->query_skill("sword",1)<50)
   message_vision("$N�ս�վס��������Щ���ȡ�\n",me);
   else if(me->query_skill("sword",1)<100)
   message_vision("$N���ŷ���Ʈ������Ҷ������¶����Ц�⡣\n",me);
   else if(me->query_skill("sword",1)<150)
   message_vision("$N�ս�ͣ��˿�����ң������������졣\n",me);
   else if(me->query_skill("sword",1)<200)
   message_vision("$N������һ�ս�������һ���������ַ緶��\n",me);
   return 1;
}
