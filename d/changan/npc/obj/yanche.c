


inherit ITEM;

void create()
{
   set_name("�γ�", ({ "yan che","che"}) );
   set_weight(10000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
	 set("long","����һ�����εĳ�.\n");
     set("unit", "��");
  }
   if(clonep(this_object())) call_out("disappear",180,this_object());
   setup();
}

void disappear(object ob)
{
	tell_object(environment(ob),"һ���ٱ����˹����������γ������γ������ˣ�\n");
	destruct(ob);
	remove_call_out("disappear");
	return;
}
