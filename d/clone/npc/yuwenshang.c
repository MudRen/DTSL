
inherit NPC;
#include <ansi.h>
void create()
{
   object *ob;
   set_name("������",({ "yuwen shang","yuwen"}) );
        set("gender", "����" );
        set("age", 32);
   set("long","�������ķ��ķ��������ķ��ĵ�һ����.");
   set("max_kee",2000);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_force",2000);
   set("force",2000);
   set("combat_exp",1600000);
   set_skill("parry",260);
   set_skill("dodge",260);
   set_skill("force",260);
   set_skill("strike",260);
   set_skill("hanbing-zhang",260);
   set("jiali",100);
    setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
