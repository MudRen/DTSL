
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("����",({ "shan yan","shan","yan" }) );
   set("gender", "Ů��" );
   set("nickname","��������");
   set("age", 23);
   set("long", "���Ƕ����ɵ��Ĵ󻤷�����֮һ��\n");
       
   set("combat_exp",600000);
   set("per", 25);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   set_skill("whip",150);
  
   set_skill("dongming-xinfa",150);
   set_skill("bihai-force",150);
   set_skill("shuiyun-xiufa",150);
   set_skill("nishang-piaoming",150);
   set_skill("literate",150);
   
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   create_family("������",5,"����");
 
   setup();
   carry_object(__DIR__"obj/caiyi")->wear();
   carry_object(__DIR__"obj/whip")->wield();
  
}
