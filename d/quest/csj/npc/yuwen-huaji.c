
inherit NPC;
#include <ansi.h>

void create()
{
   object *ob;
   set_name("���Ļ���",({ "yuwen huaji","yuwen"}) );
   set("gender", "����" );
   set("no_get", 1 );
   set("age", 32);
   set("long","�������ķ��ĸ���֮һ����˵����Ѱ�ҳ�������\n");
   set("max_kee",2000);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_force",2000);
   set("force",2000);
   set("combat_exp",600000);
   set_skill("parry",160);
   set_skill("dodge",160);
   set_skill("force",160);
   set_skill("strike",160);
   set_skill("hanbing-zhang",160);
   set("jiali",100);
   set("inquiry",([
      "������":"��֪���������������𣿿���߱�˧�������͵ģ�\n",
      "ʯ��":"��˵ʯ����С�Ӻܽƻ����ҵ�������ɲ�Ҫй¶������\n",
      "������":"ʲô���ҴӲ���ʶ��Щ����С��ģ�\n",
      "����":"ʲô���ҴӲ���ʶ��Щ����С��ģ�\n",
      "��ɩ":"��˵���������ĺܺã���ȥ���������ӻ����ɣ�\n",
      ]));
    setup();
   ob=children("/d/quest/csj/npc/obj/baojia");
   if(sizeof(ob)<=5)
   carry_object(__DIR__"obj/baojia")->wear();
  
}


int accept_object(object who,object ob)
{
  command("hoho "+who->query("id"));
  return 1;
}
