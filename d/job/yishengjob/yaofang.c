inherit ITEM;
void create()
{
	set_name("ҩ��",({"yaofang"}) );
	set("long","����� read yaofang��\n");
      set("no_sell",1);
      set("no_drop",1);
      set("no_give",1);
      set("no_steal",1);
	set_weight(5);
	set("unit","��");
	set("value",0);
}

void init()
{
	add_action("do_read","read");
}
int do_read(string arg)
{
	object me = this_player();
	string msg = me->query("quest/final/yao/name");
	string msg1 = me->query("quest/final/yao/med");
	string msg2 = me->query("quest/final/yao/med2");
	string msg3 = me->query("quest/final/yao/med3");
	string msg4 = me->query("quest/final/yao/med4");
	string msg5 = me->query("quest/final/yao/med5");
	if(arg=="yaofang" && me->query("quest/final/yao/name")) {
		tell_object(me,msg+"�Ĳ���\n");
		tell_object(me,msg1+"\n");
		tell_object(me,msg2+"\n");
		tell_object(me,msg3+"\n");
		tell_object(me,msg4+"\n");
		tell_object(me,msg5+"\n");
		return 1;
	}
	 else return 0;
}
int is_get_of(object pal,object ob)
{
 return notify_fail("�㲻�������Ƕ�����\n");
}
