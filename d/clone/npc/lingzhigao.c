
inherit NPC;

void create()
{
   set_name("��־��",({ "ling zhigao","ling"}) );
        set("gender", "����" );
        set("age",31);
        set("nickname","˫ǹ����");
        set("long","����Ǻ�ɳ���е���־�ߣ������������ຽ�����\n");
               
        set("combat_exp",250000);
        set_skill("parry",130);
        set_skill("dodge",130);
        set_skill("force",130);
        set_skill("spear",130);
        set_skill("normal-spear",130);
        set_skill("babu-ganchan",140);
        add_money("coin",20);
        set("shili/name","haisha_b");
    setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/spear")->wield();
  
}

