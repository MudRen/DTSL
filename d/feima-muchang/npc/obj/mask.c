
#include <ansi.h>

inherit ITEM;
int do_wear(string arg);
int do_unwear(string arg);
void create()
{
   set_name(HIB"��Ƥ���"NOR, ({ "mask"}) );
   set_weight(20);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
	 set("long","����һ��������������Ƥ��ߣ����ӿ�����������������������[�Ե�]��ɽ��\n");
     set("unit", "��");
   
   }
   setup();
}

void init()
{
	add_action("do_wear","wear");
	add_action("do_unwear","unwear");
}

int do_wear(string arg)
{
	object ob;
	ob=this_player();
	if(!arg||arg!="mask")
		return notify_fail("��Ҫ��ʲô��\n");
	if(query("weared"))
	return notify_fail("���Ѿ���������ˡ�\n");
	message_vision("$N�ó���Ƥ��ߴ�����ͷ�ϡ�\n",ob);
	set("no_give",1);
	set("no_drop",1);
	set("no_sell",1);
	set("no_steal",1);
	set("weared",1);
    ob->set_temp("apply/name",({"��ɽ"}));
	//ob->set_temp("apply/id",({"yue shan"}));
	//ob->set_temp("apply/short",({"��ɽ"}));
	ob->set_temp("apply/long",({"��ͺ������������������������ɽ\n"}));
	return 1;
}

int do_unwear(string arg)
{
	object ob;
	ob=this_player();
	if(!arg||arg!="mask")
		return notify_fail("��Ҫ�ѵ�ʲô��\n");
	if(!query("weared"))
	return notify_fail("��û�д�����ߡ�\n");
	message_vision("$N������ժ����Ƥ��ߣ��������С�\n",ob);
	delete("no_give");
	delete("no_drop");
	delete("no_sell");
	delete("no_steal");
	delete("weared");
	//ob->delete_temp("apply/short");
	ob->delete_temp("apply/name");
	ob->delete_temp("apply/long");
	//ob->delete_temp("apply/id");
	return 1;
}