
inherit NPC;

void create()
{
   set_name("����",({ "fa nan","fa","nan" }) );
        set("gender", "����" );
        set("age",43);
        set("nickname","��ɮ");
   set("long", "������˳ƶ�ɮ�ķ��ѣ��ߴ��׶�\n");
   set("class","bonze");
   set("combat_exp",200000);
   set("attitude", "peaceful");
   set_skill("parry",80);
   set_skill("dodge",80);
   set_skill("force",80);
   set_skill("cuff",80);
   set_skill("tianmo-huanzong",80);
   set_skill("linglong-yuquan",80);
   set_skill("tianmo-dafa",80);
   set("str",30);
   set("cor",30);
   set("max_gin",800);
   set("max_kee",800);
   set("max_sen",800);
   set("max_force",800);
   set("force",800);
   set("chat_chance_combat",60);
   set("chat_msg_combat",({
   	(:"apply_action","linglong-yuquan",2,10:),
   	}));
   setup();
   carry_object(__DIR__"sengpao")->wear();
   carry_object(__DIR__"tougu")->wear();
}
