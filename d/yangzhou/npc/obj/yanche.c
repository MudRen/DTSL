

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
   setup();
}

int clean_up()
{
   if(time()-query("last_time")>900)
 { delete("no_clean_up");return 1;}
   return 0;
} 


int is_get_of(object me,object ob)
{
  return notify_fail("����������������ܼ�������\n");
}
