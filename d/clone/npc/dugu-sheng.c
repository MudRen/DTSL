
inherit NPC;

void create()
{
   set_name("����ʢ",({ "dugu sheng","dugu","sheng" }) );
        set("gender", "����" );
        set("age", 32);
        set("tetle","����ͳ��");
   set("long", "���Ƕ��·��ĸ��ֶ���ʢ�����峯�Ĵ�������ͳ�졣\n");
   set("shili","dugu");
   set("combat_exp",600000);
   set("str", 28);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",160);
   set_skill("dodge",160);
   set_skill("parry",160);
   set_skill("force",160);
   set_skill("sword",160);
   set_skill("cuff",160);
   set_skill("dugu-jianfa",160);
   set_skill("youming-zhang",160);
   set("max_gin",1500);
   set("max_sen",1500);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/guanxue")->wear();
   carry_object(__DIR__"obj/sword")->wield();
}

