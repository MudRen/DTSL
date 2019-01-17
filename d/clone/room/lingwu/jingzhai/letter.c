
inherit ITEM;
int do_give(string arg);
void create()
{
   set_name("����", ({ "letter"}) );
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
     set("long","����һ����ͨ�����š�\n");
     set("unit", "��");
   }
   setup();
}

void init()
{
  add_action("do_give","song");
}

int do_give(string arg)
{
  object ob;
  object target;
  
  ob=this_player();
  if(!arg)
  return notify_fail("��Ҫ��"+query("name")+"�͸�˭��\n");
  
  if(!ob->query_temp("dtsl_fquest_jz/step5"))
  return notify_fail("��û���ʸ���������ţ�\n");
  
  if(!objectp(target=present(arg,environment(ob))))
  return notify_fail("����û������ˡ�\n");
  if(target==ob)
  return notify_fail("�������͸��Լ�����\n");
  if(userp(target))
  return notify_fail("�Է�����������㡣\n");
  if(base_name(target)!="/d/changan/npc/lishimin"){
  message_vision("$NЦ����лл�����ǿ������ң���һ�������ư����£�\n",target);
  destruct(this_object());
  return 1;}
  
  message_vision("$NЦ������һ����������ʦ̫������������ƽ�����£�\n"+
                 "ʹ���հ�����ҵ��\n",target);
  ob->delete_temp("dtsl_fquest_jz/step5");
  ob->set_temp("dtsl_fquest_jz/step6",1);
  destruct(this_object());
  return 1;
}