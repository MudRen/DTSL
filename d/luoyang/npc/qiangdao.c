
inherit NPC;

void create()
{
   set_name("ǿ��",({ "qiang dao","qiang","dao" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����ר���������ٵ�ǿ��,�޶�����\n");
       
   set("combat_exp",200000);
   set("str", 26);
   set("per", 22);
  set("attitude", "aggressive");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
}

