
inherit NPC;

void create()
{
   set_name("Ұ��",({ "rabbity"}) );
        set("race", "Ұ��" );
        set("combat_exp",20000);
     set("long", "����һֻҰ�á�\n");
	 set("verbs",({"bite"}));
     set("limbs",({"ͷ","����","��"}));
  setup();

}

void die()
{
  object ob;
  ob=this_object()->query_temp("last_damage_from");
  if(!ob) return ::die();
  message_vision("ͻȻһ���˾��Ÿ�[���ﱣ��Э��]�����ӣ�������Ҫ�������\n"+
                 "���һ�Ű�$N���˸�ͷ��\n",ob);
   return ::die();
}              