
inherit NPC;
void create()
{
   int i;
   object *ob;
   set_name("ŷ��ϣ��",({ "ouyang xiyi","ouyang"}) );
        set("gender", "����" );
       set("age", 52);
   set("long", "�������ѳ�����ʮ���ŷ��ϣ�ģ�������س������ˡ�\n");       
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
     tell_object(environment(ob[i]),"�����е�"+ob[i]->query("name")+"�����������ջ�ȥ�ˣ�\n");
     if(ob[i]->query("equipped"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"��һ�������ˡ�\n");
     destruct(ob[i]);}
     else destruct(ob[i]);
   carry_object(__DIR__"obj/chenshajian")->wield();
}

