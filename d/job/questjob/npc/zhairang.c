
inherit NPC;

#include <ansi.h>

void create()
{
   set_name("����",({ "zhai rang","zhai"}) );
        set("gender", "����" );
        set("age",35);
     	
   set("long", "�����˳ơ�����ͷ�������߸ھ������졣\n");
       
   set("combat_exp", 800000);
   set("str", 30);
   set("per", 24);
   
   set_skill("strike",200);
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("cuff",200);
   
   set_skill("jiutian-huanzhang",200);

   set_skill("tianmo-huanzong",200);
   
   set("max_kee",2500);
   set("max_gin",2500);
   set("max_sen",2500);
   set("force",2500);
   set("max_force",2500);
   
   set("inquiry",([
        "������":"�����������߸�կ��ͷ�ž��£�\n",
        "����":"���������µ�һ�󽫣�����˵��Ҫ�췴���ҿ�ҪС��һЩ�ˡ�\n",
        "����":"���������Ľ�ɫ�ҿ�û��˵����\n",
        "������":"����ʲô����ҿ�û��˵���������š�\n",
        ]));
   
   setup();
  
}
