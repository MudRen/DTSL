
#include <ansi.h>
inherit ROOM;

int do_shangxian(string arg);
int do_ketou();

void create ()
{
  set ("short",WHT"�ն���"NOR);
  set ("long", @LONG
���Ǿ�����Ժ���ն��ã���ǰ������һ�����������д�ţ����ຣ
�ޱߣ���ͷ�ǰ�������෸�˹�����˶�����������濪������м�
��ɮ�������Ա����ž��飬�ƺ��ڳ��������ǵ����
LONG);

  set("exits", ([ 
	  "northwest":__DIR__"zhulin",
	  ]));

  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_shangxian","shangxiang");
   add_action("do_ketou","ketou");
}

int do_shangxian(string arg)
{
   object ob,obj;
   string name,msg;
   
   ob=this_player();
   
   
   if(!arg||sscanf(arg,"with %s",name)!=1)
   return notify_fail("����ʲô���㣿(shangxiang with xxx)\n");
   
   if(!objectp(obj=present(name,ob)))
   return notify_fail("������û�����������\n");
   if(!obj->query("jinxiang_goods"))
   return notify_fail("��������������㡣\n");
   if(ob->is_busy())
   return notify_fail("����æ���أ�\n");
   
   
   msg="\n$N��ȼ�����򣬹��������ز嵽����¯�С�\n\n";
   message_vision(msg,ob);
   ob->add_temp("jinxiang_times",5);
   ob->start_busy(1);
   destruct(obj);
   return 1;
}

int do_ketou()
{
   object ob;
   string msg;
   
   ob=this_player();
   
   if(ob->is_busy())
   return notify_fail("����æ���أ�\n");
   
   if(!ob->query_temp("jinxiang_times"))
   return notify_fail("��ȥ�������������ͷ�ɣ�\n");
   
   ob->add_temp("jinxiang_times",-1);
   msg="\n$N˫�ֺ�ʮ����������������ӷ��������ܳ����ҵ����\n";
   message_vision(msg,ob);
   ob->add("bellicosity",-10);
   if(ob->query("bellicosity")<=0)
   ob->set("bellicosity",0);
   ob->receive_damage("sen",200);
   ob->start_busy(2);
   return 1;
}
