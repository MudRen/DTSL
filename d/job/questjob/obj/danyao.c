
inherit ITEM;

#include <ansi.h>

int do_action(string arg);

void create()
{
        set_name(HIY"ʥ��"NOR, ({"dan"}));
        set_weight(100);
        
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("base_unit","ö");
                set("unit","ö");
   set("long", "����һö���õĵ�ҩ������Է�[fu]���������Լ������ˡ�\n");
        set("material", "��ҩ");}
    setup();
        
}

void init()
{

  add_action("do_action","fu");
}

int do_action(string arg)
{
   object ob;
   object target;
   
   ob=this_player();
   
   if(!arg)
   return notify_fail("��Ҫ����ʲô������\n");
   if(!objectp(target=present(arg,ob)))
   return notify_fail("������û�����������\n");
   if(target!=this_object())
   return 0;
   
   if(query("am"))
   return 0;
   
   if(ob->query("eff_kee")>=ob->query("max_kee"))
    return notify_fail("������û�����ˣ����÷��õ�ҩ��\n");
    set("am",1);
   ob->set("eff_kee",ob->query("max_kee"));
   message_vision("$N������"+query("name")+"����ɫ�ָ������˿�����������˵����ӡ�\n",ob);
     call_out("des",1);
   return 1;
}

void des()
{
  destruct(this_object());
  return;
}