
inherit NPC;

#include <ansi.h>

void create()
{
   set_name("���",({ "fu jian","fu"}) );
        set("gender", "����" );
        set("age",35);
     	
   set("long", "�����¹Ȼ�ķ�幣�ǹ�����ǲ��ס�\n");
       
   set("combat_exp", 800000);
   set("str", 30);
   set("per", 24);
   
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("spear",200);
   
   set_skill("level3-qiang",200);
   set_skill("niaozong-shu",200);
   
   set("max_kee",2500);
   set("max_gin",2500);
   set("max_sen",2500);
   set("force",2500);
   set("max_force",2500);
   
   set("inquiry",([
        "����":"�������ҵĳ�У��л���һ��ɱ������\n",
        "����":"�Һܾ�û�������ˣ�����������Ϣ��\n",
        "������":"����˲�ͬ���죬��ϧ�ܾ�û��������Ϣ�ˡ�\n",
        ]));
   
   setup();
   carry_object(__DIR__"obj/spear")->wield();
  
}
