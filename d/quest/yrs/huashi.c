
inherit NPC;
#include <ansi.h>
string do_quest();
void create()
{
   set_name("��ʦ",({ "hua shi","shi"}) );
        set("gender", "����" );
        set("age",55);
   set("long","����һ����ʦ��\n");
   set("max_kee",300);
   set("max_gin",300);
   set("max_sen",300);
   set("combat_exp",200000);
   set("inquiry",([
     "����":"�ҵĻ��ܺã��������ȴû������ʶ����......\n",
     "����":(:do_quest:),
     ]));
   setup();
    
}
void die()
{
  message_vision(HIR"$N����һ̾��û�뵽��һ����ʦ��û������֮�أ�\n"NOR,this_object());
  return ::die();
}

string do_quest()
{
  object ob;
  object tool;
  ob=this_player();
  if(!ob->query_temp("yrs_find/pencil"))
  return "�㲻���滭�������ҵĻ���Ҳû�õģ�\n";
  tool=new(__DIR__"obj/pencil");
  tool->move(this_object());
  return "�ߣ������ҵĻ��ʣ���ɱ������˵���ˣ���\n";
}