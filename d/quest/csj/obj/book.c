
#include <ansi.h>
inherit ITEM;
int do_look(string arg);

void create()
{
        set_name(YEL"������" NOR, ({ "book"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	        set("material", "ֽ");
                set("no_drop",1);
                set("no_sell",1);
                set("no_give",1);
                set("no_steal",1);
                set("no_save",1);
        }
        setup();
}
void init()
{
  add_action("do_look","kan");
 
}
int do_look(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="������")
  return notify_fail("��Ҫ��ʲô��\n");
  if(ob->query_skill("changsheng-jue",1)>=20)
  return notify_fail("�Ȿ���Ѿ�ûʲô���ˣ��㻹����ɽ��������ɣ�\n");
  if(ob->query("gin")<20)
  return notify_fail("�㾫���㱣��޷���������ȥ��\n");
  if(ob->query("kee")<20)
  return notify_fail("��о���Ѫ��Ӿ���޷���������ȥ��\n");
  tell_object(ob,"���ų����е�����������ϵ����֣���������Щ�ջ�\n");
  ob->receive_damage("gin",20);
  ob->receive_damage("kee",20);
  ob->improve_skill("changsheng-jue",ob->query_int()/6+5);
  return 1;
}

int is_get_of(object pal,object ob)
{
 if(!pal->query("dtsl_quest_csj_ok"))
 return notify_fail("�㲻�������Ǳ��飡\n");
 return 1;
}
