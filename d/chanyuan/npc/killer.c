
inherit NPC;

void create()
{
   set_name("��Ӱ",({ "hei ying","ying" }));
   set("gender", "����" );
   set("combat_exp",50000);
  setup();
  
}

void die()
{
   object ob,obj;
   
   ob=query_temp("last_damage_from");
   
   if(!ob||ob->query("id")!=query("target_id"))
   destruct(this_object());
   
   obj=new(__DIR__"obj/quest_sengyi");
   obj->set("owner_id",ob->query("id"));
   
   tell_object(environment(ob),query("name")+"ͻȻ���ڵ��ϣ�һ�������ˡ�\n\n");
   
   obj->move(environment(ob));
   
   destruct(this_object());
}