
inherit ROOM;
#include <ansi.h>
string give_msg();
void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǵ��ա�����İ��費�Ǻܺ�����������Ȼ�������ס����µ�
�ţ�����󷽡��������һ��������(pai)�������Ǹ������ɵ��ӿ��ġ�
LONG);
	set("exits", ([
		"out":__DIR__"chuan",
		]));
	set("objects",([
		"/d/clone/npc/jiandingman":1,
		]));
	set("item_desc",([
	  "pai":(:give_msg:),
	  ]));
      set("valid_startroom", 1);   
	setup();
       
       
}

string give_msg()
{
  object ob;
  ob=this_player();
  if(ob->query("family/family_name")!="������")
  return "����ģ�����壬����������ʲô�ּ���\n";
  return "��������ԭ�������Ѿ���ɣ������һص����鵺�ˣ�\n"+
         "�����˶���������ӵ�ѧϰ���Ǳ�Ǹ�����λ���ӵ�\n"+
         "���鵺��"+HIG+"[����ͤ]"+NOR+"���ҡ�\n\n"+
         "                                        "+HIW+"����\n"NOR;
}
