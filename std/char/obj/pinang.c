
inherit ITEM;

void create()
{
	set_name("Ƥ��", ({ "pi nang","pi","nang","liangong_fight_objects"}));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "Щ");
		set("long", "����һЩľ�飬����ƴװ[pinzhuang]��Ƥ���ܡ�\n");
		set("no_give",1);
	}
	setup();
}

void init()
{
  add_action("do_action1","pinzhuang");
 
}

int do_action1(string arg)
{
  object ob,target;
  string msg;
  
  ob=this_player();
  
  if(!arg)
  return notify_fail("��Ҫƴװʲô��\n");
  if(!id(arg))
  return notify_fail("�����������ƴװ��\n");
  
  msg="$N��Ƥ��ɢ��������ÿ��λ�ã���Ƥ��ƴװ����һ��Ƥ���ܣ�\n";
  message_vision(msg,ob);
  target=new(__DIR__"fighter3");
  target->set_status(ob);
  target->move(environment(ob));
  ob->add_temp_array("job_temp_killer",target);
  destruct(this_object());
  return 1;
}