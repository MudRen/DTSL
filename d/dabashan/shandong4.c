
#include <ansi.h>
#include <job_money.h>
inherit ROOM;

int do_wa();
void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
������һ��ɽ��������ں����ģ����ֲ�����ָ���ƺ���ʲô������
�㲻���ӱ�С���������㷢�ֵ��Ϻ����и��������ƺ�����ʲô������
LONG);

  set("exits", ([ 

   "southwest":__DIR__"shandong3",
              ]));
 set("objects",([ "/d/clone/npc/beast/yezhu":1,]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_wa","wa");
}

int do_wa()
{
   object me,ob,killer;object *armor;
   me=this_player();
   
   armor=children(__DIR__"npc/obj/armor");
   if(environment(me)->query("no_bao")||sizeof(armor)>2)
   return notify_fail("�����˰��죬����ʲôҲû�С�\n");
   message_vision("$N������ȥ����������������\n",me);
   environment(me)->set("no_bao",1);
   killer=new(__DIR__"npc/killer");
   killer->set_status(me);
   killer->set("name","������");
   killer->set("id","man");
   killer->set("nickname","������ʿ");
   killer->set("title","�ᱦ����");

   killer->move(environment(me));
   me->start_busy(2);
   message_vision(HIR"\n$N��Ц������Һ�����������֣��������ɣ���\n"NOR,killer);
   killer->kill_ob(me);
   return 1;
}
   
   

