
inherit NPC;
void create()
{
   set_name("������",({ "liu heita","liu","heita"}) );
        set("gender", "����" );
       set("age", 32);
   set("long", "����񼽨�µ����������ˣ�Ϊ����ֱ��ʵ��\n");       
   set("combat_exp",300000);
   set("per", 20);
   set("str",28);
   set("max_kee",800);
   set("max_gin",800);
   set("max_sen",800);
   set("max_force",800);
   set("force",800);
   set("attitude", "peaceful");
   set_skill("blade",80);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("force",80);
   set("inquiry",([
   "�����":"����һֱ���Ұ�����ϧ����û���ҵ���\n",
   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
}

