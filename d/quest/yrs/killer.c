
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("�ϰ���",({ "laoban niang","laoban"}) );
        set("gender", "Ů��" );
        set("age", 32);
   set("long","����������ջ���ϰ��\n");
   set("max_kee",300);
   set("max_gin",300);
   set("max_sen",300);
   set("combat_exp",200000);
   setup();
   carry_object(__DIR__"obj/caidao")->wield();
   carry_object(__DIR__"obj/skin");
  
}
void die()
{
  message_vision(HIR"$N˺���ѷεغ�������������Ҳ����Ź����ǣ�����\n"NOR,this_object());
  return ::die();
}