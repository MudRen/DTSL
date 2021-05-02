
inherit NPC;
string *name1=({"赵","钱","孙","周","吴","郑","王"});
string *name2=({"亮","剑","霸","云","笑","冷","寒","卓"});
void create()
{
   set_name(name1[random(sizeof(name1))]+name2[random(sizeof(name2))]
   ,({ "killer" }) );
        set("gender", "男性" );
        set("title","宋家堡的叛徒");
        set("age", 32);
   set("long", "这是宋家堡的叛徒。\n");
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
  //  set_skill("xukong-zhang",200);
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
  return notify_fail("对方根本不理会你的作战请求！\n");
  return 1;
}
