
inherit ROOM;
#include <ansi.h>
#include <job_money.h>
void create()	
{
	set("short", MAG"����ͤ"NOR);
	set("long", @LONG
�����ǻ��Ͼ�������ЪϢ�ĵط���ͤ��Ϊ�ڱ̲����룬����������
������������������������ɫ����Ů���������裬ͤ���м��Ǹ�����
ʯ�������ϰ��������Ƽ��ȣ�������һȦ�����ʯ���� ��chair������
��������ǰ���ɾ���ס�ˡ�
LONG);
        set("exits",([
          "west":"/d/cahc/yuhuayuan",
          ]));
        set("objects",([
          __DIR__"girl1":1,
          __DIR__"girl2":1,
          __DIR__"girl3":1,
          __DIR__"girl4":1,
          ]));
        set("item_desc",([
        "chair":"����һ���麺�����̳ɵ�ʯ�Ρ�\n",
        ]));
        set("no_fight",1);
 	set("no_quit",1);
        setup();
	
}

void init()
{
  object ob;
  ob=previous_object();
  if(ob->query_temp("liyuan_job/step")!=14)
   return;
  if(ob->query("gender")=="����")
  call_out("do_ok1",5,ob);
  else call_out("do_ok5",5,ob);
}

void do_ok1(object ob)
{
  if(!ob) return;
  tell_object(ob,HIR"������Ů"+NOR+"�ߵ������ǰ��������˫�ַ���һ�����ơ�\n");
  call_out("do_ok2",5,ob);
  return;
}

void do_ok2(object ob)
{
  if(!ob) return;
  tell_object(ob,"\n"+BLU+"������Ů"+NOR+"Ʈ���������Ϊ������İ�Ħ������Ū��ˬˬ�ġ�\n");
  call_out("do_ok3",5,ob);
  return;
}

void do_ok3(object ob)
{
  if(!ob) return;
  tell_object(ob,"\n"+HIG+"������Ů"+NOR+"���������������ķ���������һ�����Ѹ���\n");
  call_out("do_ok4",5,ob);
  return;
}

void do_ok4(object ob)
{
  if(!ob) return;
  tell_object(ob,"\n"+HIY+"������Ů"+NOR+"��ӯ�����������ת��תȥ����ʱ�����㰵���ﲨ��\n");
  call_out("do_ok5",5,ob);
  return;
}

void do_ok5(object ob)
{
   int exp,silver,pot;
   
   if(!ob) return;
   
   if(ob->query_temp("killer_comes")<2)
   exp=200+random(50);
   else
   exp=4000+random(50);
   pot=600+random(100);
   silver=8000;
   
   ob->delete_temp("dtsl_job");
   ob->delete_temp("liyuan_job");
   ob->delete_temp("killer_comes");
   
   ob->add("combat_exp",exp);
   ob->add("potential",pot);
   if(ob->query("potential")>ob->query("max_pot")*2)
    ob->set("potential",ob->query("max_pot")*2);
   ob->add("deposit",silver);
   
   tell_object(ob,"\n\nһ���ܼҴ��������˳������������һ������\n"+
      "��������ж��еõ���"+HIW+chinese_number(exp)+NOR+"�㾭�飬\n"+
      "                    "+HIY+chinese_number(pot)+NOR+"��Ǳ�ܣ�\n"+
      "                    "+MONEY_D->money_str(silver)+"\n");
   add_shili(ob,exp/8,silver/8);
   tell_object(ob,"��Ǯׯ�Ĵ�������ˣ�\n");
   
   ob->start_busy(random(2));
   ob->set("busy_time",time());
   return;
}
