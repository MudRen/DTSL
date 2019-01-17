
#include <room.h>

inherit ROOM;

#include <ansi.h>

int do_heal();

void create()
{
	set("short", "������");
	set("long", @LONG
������ʯ����ݵ������ң�����������еĵ�����Ϊ�����������ˣ�
�����Ե��������ơ�ֻ��������ϥ���ż������ӣ�ͷ��ð��������̣���
�������˹����ˡ��������һ������(pai)��
LONG
);


	set("exits", ([
		"west" :__DIR__"beilang2",
               
	]));
	
	set("item_desc",([
	   "pai":"�����ʹ�� liaoshang �������˿ڡ�\n",
	   ]));
	
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
       set("can_exercise",1);
       set("can_respirate",1);
       //set("outdoors", "slwg");
	setup();
}

void init()
{
   add_action("do_heal","liaoshang");
}

int do_healing(object me);
int do_halt(object me);

int do_heal()
{
   object ob;
   string str;
   
   ob=this_player();
   
   
   if(ob->query("eff_kee")==ob->query("max_kee")&&
	   ob->query("eff_gin")==ob->query("max_gin"))
   return notify_fail("��û�����ˣ��������ˡ�\n");
   
   if(ob->is_busy())
   return notify_fail("����æ���أ�\n");
    
   str=HIW"$N��ϥ���£�ͷ��ð�����������\n"NOR;
   
   message_vision(str,ob);
	str=replace_string(str,"$N",ob->name());
	str=replace_string(str,"\n","");
	ob->set_temp("apply/short",({str}));
   
   ob->start_busy((:do_healing:),(:do_halt:));
   return 1;
}

int do_healing(object ob)
{
   int cost;
   
   cost=ob->query_con();
     
   ob->receive_heal("kee",cost);
   ob->receive_curing("kee",cost);
   
   ob->receive_heal("gin",cost);
   ob->receive_curing("gin",cost);
   
   if(ob->query("eff_kee")==ob->query("max_kee")&&
   ob->query("eff_gin")==ob->query("max_gin"))
   { message_vision(HIW"$N����������һ������վ��������\n"NOR,ob);
     ob->delete_temp("apply/short");
     return 0;
    }
   return 1;
}

int do_halt(object ob)
{
  message_vision("$N����Ϣѹ�ص��������һ������վ��������\n",ob);
  ob->delete_temp("apply/short");
  return 1;
}
