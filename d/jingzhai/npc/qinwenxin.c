
inherit "/std/lmaster.c";

#include <ansi.h>

void create()
{
   set_name("������",({ "qin wenxin","qin" }) );
   set("gender", "Ů��" );
   set("age", 25);
   set("long", "���ǴȺ���ի�������ģ������ڴȺ�����\n"+
   						"�������Ļ�֪ʶ��\n");
       
   set("combat_exp",100000);
   set("int", 25);
   set("per", 26);
   set("max_gin",1000);
   set("max_kee",1000);
   set("max_sen",1000);
   set("max_force",1000);
   set("force",1000);
    
   set_skill("literate",80);   
  
   create_family("�Ⱥ���ի",7,"����");
   setup();
   carry_object(__DIR__"obj/baiyi")->wear();
  
}

