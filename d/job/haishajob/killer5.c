
inherit NPC;
string *name1=({"��"});
string *name2=({"��","��","��","��","Ц","��","��","׿"});
void create()
{
   set_name(name1[random(sizeof(name1))]+name2[random(sizeof(name2))]
   ,({ "killer" }) );
        set("gender", "����" );
        set("title","�����ɵ���ͽ");
        set("age", 32);
   set("long", "���Ƕ����ɵ���ͽ��\n");
   set("combat_exp", 800000);
   set("str", 30);
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("max_force",3000);
   set("force",3000);
   set_skill("force",200);
   set_skill("piaomeng-jianfa",200);
   set_skill("sword",200);
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("nishang-piaoming",200);
   set("dodge",({"nishang-piaoming"}));
   set("sword",({"piaomeng-jianfa"}));
   set("chat_chance_combat",60);
   set("chat_msg_combat",({
   	(:perform_action,"lianhuan":),
   	}));
   set("accept_kill",1);
   setup();
   carry_object(__DIR__"cloth")->wear();
   carry_object(__DIR__"changjian")->wield();
}
int accept_kill(object killer,object me)
{
  if(me->query("target_id")!=killer->query("id"))
  return notify_fail("�Է���������������ս����\n");
  return 1;
}