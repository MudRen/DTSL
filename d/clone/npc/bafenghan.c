
inherit NPC;

void create()
{
   int i;
   object *ob;
   set_name("�Ϸ溮",({ "ba fenghan","ba","fenghan"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "������ͻ�ʵ���ʿ�Ϸ溮��Ҳ�ǵ����������ս���ˡ�\n");
       
   set("combat_exp",1000000);
   set("per", 24);
   set("cor",30);
   set("str",30);
   set("jiali",200);
   set_temp("apply/armor",50);
   set_temp("apply/dodge",50);
   set_temp("apply/damage",50);
   set_skill("sword",200);
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("toutian-jianfa",200);
   
   set("max_kee",2000);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_force",2000);
   set("force",2000);
   set("inquiry",([
     "��ʪ��":"�Ǻǣ���Ҳ֪�����������º��ˣ��ǿ��ٺ������������ġ�\n",
     "����":"�Һþ�û�������ˣ���֪����������ô���ˡ�\n",
     "������":"��˵��ȥ�˳���ɽ����֪�����Ǽ١�\n",
     ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   ob=children(__DIR__"obj/toutian-jian");
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
   carry_object(__DIR__"obj/toutian-jian")->wield();
  
}

