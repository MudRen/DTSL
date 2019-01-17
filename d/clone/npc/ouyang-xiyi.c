
inherit NPC;
void create()
{
   int i;
   object *ob;
   set_name("欧阳希夷",({ "ouyang xiyi","ouyang"}) );
        set("gender", "男性" );
       set("age", 52);
   set("long", "这是早已成名数十年的欧阳希夷，最近又重出江湖了。\n");       
   set("combat_exp",600000);
   set("per", 22);
   set("str",28);
   set("max_kee",1000);
   set("max_gin",1000);
   set("max_sen",1000);
   set("max_force",1000);
   set("force",1000);
   set("attitude", "peaceful");
   set_skill("sword",120);
   set_skill("dodge",120);
   set_skill("parry",120);
   set_skill("force",120);
   set_skill("chensha-jianfa",150);
   set("sword",({"chensha-jianfa"}));  
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   ob=children(__DIR__"obj/chenshajian");
   for(i=0;i<sizeof(ob);i++)
     if(environment(ob[i])&&userp(environment(ob[i]))){
     tell_object(environment(ob[i]),"你手中的"+ob[i]->query("name")+"被它的主人收回去了！\n");
     if(ob[i]->query("equipped"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"被一阵风卷走了。\n");
     destruct(ob[i]);}
     else destruct(ob[i]);
   carry_object(__DIR__"obj/chenshajian")->wield();
}

