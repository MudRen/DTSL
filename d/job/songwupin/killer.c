//job.
// 送物品任务。
#include <ansi.h>
inherit NPC;
void create()
{
   set_name("杀手",({ "killer" }) );
        set("gender", "男性" );
        set("age",20+random(20));
        set("str",10+random(20));
   set("long", "这是荣凤祥的仇敌，黑巾蒙面，看不清楚面目。\n");
   set("max_force",1000);
   set("force",1000);

   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("tianmo-dafa",100);
   set_skill("dujie-zhi",100);
   set_skill("xiuluo-zhi",100);
//    set_skill("yuxiao-quanfa",100);
   set_skill("tianmo-huanzong",100);

  setup();

}
