
#include <ansi.h>
inherit ROOM;

string do_action1();

void create ()
{
  set ("short",HIY"�ؾ���"NOR);
  set ("long", @LONG
�����ǴȺ���ի�Ĳؾ�����������ŴȺ���ի����������ղأ�ȫ
���Ƿ�ұ��䡣�����ϻ�����һ���� (shu)������д�š��Ⱥ����䡱��
���֡����ǴȺ����ϳ���ѧ�伮����ͨ�˿��˲����кô��ġ�
LONG);

  set("exits", ([ 

  "east":__DIR__"wenzhitang",
   ]));
  set("objects",([
	  __DIR__"npc/dizi":1,
	  ]));
  set("item_desc",([
     "shu":(:do_action1:),
     ]));
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_lingwu","lingwu");

}

int do_lingwu()
{
	
   object ob;
   string msg;
   
   ob=this_player();
   
   if(ob->query_skill("qingxin-force",1)<180)
   return notify_fail("����������ƾ���Ϊ̫���ˣ��޷������κζ�����\n");
   
   if(ob->query_skill("siguanfa",1)){
      
      if(ob->query_skill("siguanfa",1)>=300)
      return notify_fail("���ط��Ѿ����򵽼��ޣ��޷�������ˣ�\n");
      if(ob->query("potential")<=0)
      return notify_fail("���Ǳ�ܲ��㣬�޷�����\n");
      ob->improve_skill("siguanfa",ob->query("potential")*ob->query_int()*2/3);
      ob->set("potential",0);
      msg="$N�����һ���ų�����������ط�����Ϊ������ߣ�\n";
      message_vision(msg,ob);
      return 1;
   }
   if(ob->query_skill("sashoufa",1)){
      
      if(ob->query_skill("sashoufa",1)>=300)
      return notify_fail("���ַ��Ѿ����򵽼��ޣ��޷�������ˣ�\n");
      if(ob->query("potential")<=0)
      return notify_fail("���Ǳ�ܲ��㣬�޷�����\n");
      ob->improve_skill("sashoufa",ob->query("potential")*ob->query_int()*2/3);
      ob->set("potential",0);
      msg="$N�����һ���ų�����������ַ�����Ϊ������ߣ�\n";
      message_vision(msg,ob);
      return 1;
   }
      
   
   if(ob->query("PKS")>=5
     ||ob->query("deadtimes")>=2
     ||ob->query("execute_quest/cihang_fail")){
     return notify_fail("��Ļ�Ե���ߣ������޷����Ⱥ��и߼����ķ��ˣ�\n");
   }
   if(random(100)>70){
     ob->set_skill("siguanfa",1);
     tell_object(ob,"�㽥�����򵽡�����ͨ������һ��Ƥë�����Ǿ��û��б�Ҫ�Ժ������ᡣ\n"); 
   }
   else{
     ob->set_skill("sashoufa",1);
  ob->set("execute_quest/xinyoulingxi");
     tell_object(ob,"��ͻȻ�е���Ѫ���ڣ��޷��������ȥ�ˣ�������ֻ�����򵽡�������Ϭ���ˣ�\n");
   }
   ob->set("cihang_menpai/cihang_MKS",ob->query("MKS"));
   ob->set("cihang_menpai/cihang_PKS",ob->query("PKS"));
   ob->set("cihang_menpai/cihang_deadtimes",ob->query("deadtimes"));
   
   return 1;
}


string do_action1()
{
  object ob;
  
  ob=this_player();
  
  if(ob->query("execute_quest/jianxintongming"))
  return "���Ѿ�������˽���ͨ����\n";
  if(ob->query("execute_quest/xinyoulingxi"))
  return "���Ѿ��������������Ϭ��\n";
  
  if( (ob->query_skill("siguanfa",1)<180
       &&ob->query_skill("sashoufa",1)<180)
      ||ob->query("family/cihang_xinfa_fail")
    ){
     ob->set("kee",0);
     ob->set("sen",0);
     ob->set("gin",0);
   return "��е���Ѫ�����������ٿ���ȥ�ˣ�\n";
  }
  if( ob->query("MKS")!=ob->query("cihang_menpai/cihang_MKS")
    ||ob->query("PKS")!=ob->query("cihang_menpai/cihang_PKS")
    ||ob->query("deadtimes")!=ob->query("cihang_menpai/cihang_deadtimes")
    ||ob->query("age")>=50
    ||ob->query("couple")
    ){
    ob->set("family/cihang_xinfa_fail",1);
    return "���޷��ٽ��Լ����ķ����һ����Σ�\n";
  }
  if(ob->query_skill("siguanfa",1)){
     ob->set("execute_quest/jianxintongming",1);
     return "��ӴȺ�������������˽���ͨ����\n";
  }
  if(ob->query_skill("sashoufa",1)){
     ob->set("execute_quest/xinyoulingxi",1);
     return "��ӴȺ��������������������Ϭ��\n";
  }
  return "����һ���Ⱥ����䡣\n";
}
