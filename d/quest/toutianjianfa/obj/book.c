
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"͵�콣��" NOR, ({ "book","jian pu","pu"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","����һ������͵�콣�����鼮��\n");
                set("unit", "��");
	        set("material", "ֽ");              
                set("no_save",1);               
        }
        setup();
}

int is_get_of(object ob,object obj)
{
  if(ob->query("job_office_number/�����������")<10
  ||ob->query_skill("toutian-jianfa",1)
  ||ob->query("dtsl_quest_toutianjf_fail")
  ||ob->query("dtsl_quest_toutianjf_ok")
  ||ob->query_temp("cannot_get_jianpu")
  )
  return 0;
  
  set("owner",ob);
  
  return 1;
}

string long()
{
  object ob=this_player();
  
  if(query("owner")!=ob||
  ob->query("dtsl_quest_toutianjf_ok")
  ||query("no_use"))
   return query("long");
  
  ob->set("dtsl_quest_toutianjf_ok",1);
  ob->set_skill("toutian-jianfa",10);
  set("no_use",1);
  
  if(random(ob->query_quest_kar())<27)
  	tell_object(ob,"\n�������ᵽ��һ��͵�콣����Ƥë��\n");
  else{
  	tell_object(ob,"\n�������ᵽ��һ��͵�콣���ľ��裡\n");
  	ob->set("perform_quest/toutian",1);
  }
  
  return "";
}