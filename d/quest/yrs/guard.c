
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("����",({ "hu wei","hu","wei"}) );
        set("gender", "����" );
        set("age",28);
   set("long","�����ӻ��̵Ļ�����\n");
   set("max_kee",300);
   set("max_gin",300);
   set("max_sen",300);
   set("combat_exp",200000);
   setup();
   carry_object(__DIR__"obj/mianfen");
}
void die()
{
  message_vision(HIR"$N���������ؿ������Ե��ϰ�һ�ۣ������Ϊ��ƴ������ȴ��ſ������˯����\n"NOR,this_object());
  return ::die();
}