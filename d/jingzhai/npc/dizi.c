
inherit NPC;
void create()
{
   set_name("Ů����",({ "di zi","di","zi" }) );
        set("gender", "Ů��" );
        set("age", 16);
   set("long", "���ǴȺ���ի��Ů���ӡ�\n");
       
   set("combat_exp",100000);
  set("max_force",300);
   set("force",300);
   set("attitude", "peaceful");
   set_skill("sword",80);
   set_skill("cuff",80);
   set_skill("strike",80);
   set_skill("dodge",80);
   set_skill("finger",80);
   set_skill("literate",80);
   set_skill("force",80);
   set_skill("sekong-jianfa",80);  
   set_skill("xiuluo-zhi",80);
   set_skill("wuwang-jing",80);
   set_skill("qingxin-force",80);
   set_skill("lingyun-shenfa",80);
      
   create_family("�Ⱥ���ի",9,"����");
   setup();
   carry_object(__DIR__"obj/baiyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
}

