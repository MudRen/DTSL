
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("½¹Ð°",({ "jiao xie","jiao","xie"}) );
        set("gender", "ÄÐÐÔ" );
        set("nickname",HIR"¶áÃüµ¶"NOR);
        set("age", 32);
   set("long", "ÕâÊÇÂþÌìÍõÆìÏÂµÄ'¶áÃüµ¶'½¹Ð°¡£\n");       
   set("combat_exp",100000);
   set("per", 21);
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
   set_skill("duoming-dao",80);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/blade")->wield();
}

