#include <ansi.h>
inherit ROOM;

int damage_flag=0;

void create ()
{
  set ("short","̶��");
  set ("long", @LONG
̶ˮ����̹ǣ����߲�͸�����а�����ӿ��̶�׾���������գ���
�����񱻾����ӿ����ؽ������޷������ˡ��������ֲ�����ָ�Ļ���
���˲�����������ڰ��ио���ˮ��һ����ӿ�����ƺ��д��͵Ķ�����
������ƾ����һ˿�־�С�
LONG);
  
  set("exits",([
   "up":"/d/emeishan/shuitan",
   ]));
  
  set("no_fight",1);
  set("no_exert",1);
  
  setup();

}

void init()
{
	add_action("do_mo","mo");
	if(!damage_flag){
		remove_call_out("do_damage");
		call_out("do_damage",5);
		damage_flag=1;
	}
}

int do_mo(string arg)
{
	object me,ob;
	
	me=this_player();
		
	if(me->is_busy())
		return notify_fail("�����ں�æ��ЪЪ��!\n");
	if(me->is_fighting())
		return notify_fail("�㻹���ȴ�������˵�ɣ�\n");
	if(time()-query("no_kaicai")<60*30)
		return notify_fail("��ʲôҲû������\n");
	message_vision("$N��ˮ�׺��ҵ�����������\n",me);
	me->start_busy(3);
		
	set("no_kaicai",time());
	
	if(random(100)<95){
	 message_vision("$NʲôҲû��������\n",me);
	 return 1;
	}
	
	ob=new(__DIR__"obj/tiekuang3");
	if(!ob->move(me)){
	  ob->move(environment(me));
	  tell_object(me,"�㸺�ع����ˣ�\n");
	}
	message_vision("$N������һ���С��������ȥ�ı������ʯͷ�����������Σ�\n"+
	               "������������յĵط���\n",me);
	me->move("/d/emeishan/shuitan");
	return 1;
}

void do_damage()
{
	object *ob;
	int i;
	
	ob=all_inventory(this_object());
	
	if(sizeof(ob)<=0){
		damage_flag=0;
		return;
	}
	
	for(i=0;i<sizeof(ob);i++){
	   if(living(ob[i])){
	    ob[i]->receive_damage("sen",800);
	    tell_object(ob[i],HIB"һ������ˮ������������˸����£�\n"NOR);
	   }
	   else
	    ob[i]->move("/d/emeishan/shuitan");
	}
	
    call_out("do_damage",5);
    
}