
inherit NPC;

void create()
{
   set_name("��ҩ��",({ "caiyao ren","ren"}) );
        set("gender", "����" );
        set("age", 22);
   set("long", "�����ڻ�ɽ��ҩ���ˣ����Ի�ɽ�Ĳ�ҩ���ǳ���Ϥ��\n");
       
   set("combat_exp", 20000);
   set("str", 18);
   set("per", 22);
   set("attitude", "friendly");
   set("inquiry",([
	   "��ҩ":"��ҩ�𣿻�ɽ��ҩ�����������ᶴ����Ů����ºͺ�ɽ�����¡�\n",
	   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

