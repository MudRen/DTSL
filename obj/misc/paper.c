inherit ITEM;
int do_write(string arg);
void create()
{
   set_name("��ֽ", ({ "paper"}) );
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ�Ű�ֽ�������������д��(xie)��\n");
     set("material", "��ֽ");
     set("unit", "��");
     set("value",2);
   }
   setup();
}

void init()
{
  add_action("do_write","xie");
}

int do_write(string arg)
{
  object ob;
  ob=this_player();
  if(!arg)
  return notify_fail("��Ҫдʲô��\n");
  this_object()->set("long","����һ�Ű�ֽ������д��:\n"+arg);
  message_vision("$N�ڰ�ֽ��д�˼����֡�\n",ob);
  return 1;
}