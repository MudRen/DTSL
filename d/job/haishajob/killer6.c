
inherit NPC;
string *name1=({"��","Ǯ","��","��","��","֣","��"});
string *name2=({"��","��","��","��","Ц","��","��","׿"});
void create()
{
   set_name(name1[random(sizeof(name1))]+name2[random(sizeof(name2))]
   ,({ "killer" }) );
        set("gender", "����" );
        set("title","�μұ�����ͽ");
        set("age", 32);
   set("long", "�����μұ�����ͽ��\n");
   set("combat_exp", 800000);
   set("str", 30);
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("max_force",3000);
   set("force",3000);
   set_skill("force",200);
   set_skill("tiangang-sanjue",200);
   set_skill("poyu-quan",200);
   set_skill("xukong-zhang",200);
   set_skill("strike",200);
   set_skill("cuff",200);
   set_skill("dodge",200);
   set_skill("parry",200);
     set_skill("anxiang-fuying",200);
   set("dodge",({"anxiang-fuying"}));
   set("hand",({"poyu-quan","xukong-zhang"}));
   set("force_skill",({"tiangang-sanjue"}));
   set("chat_chance_combat",60);
   set("chat_msg_combat",({
   	(:perform_action,"shuangjue":),
   	}));
   set("accept_kill",1);
   setup();
   carry_object(__DIR__"cloth")->wear();
  
}
int accept_kill(object killer,object me)
{
  if(me->query("target_id")!=killer->query("id"))
  return notify_fail("�Է���������������ս����\n");
  return 1;
}
