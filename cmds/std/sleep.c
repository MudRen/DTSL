// sleep.c
// yanyan@dDtSl
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping fam;
	object where = environment(me);

	seteuid(getuid());
	if ( !where->query("sleep_room")
             || (where->query("no_sleep_room")) )
             return notify_fail("���ﲻ������˯�ĵط���\n");
   
	if (me->is_busy())
		return notify_fail("����æ���أ�\n");

	if( me->is_fighting() )
		return notify_fail("ս���в���˯����\n");        
    me->set("no_get",1);
    me->set("no_get_from",1);
	me->set("no_steal_from",1);
	
	if(me->query("con")<35)
		call_out("wakeup",10 + 35 - me->query("con"), me);
	else
		call_out("wakeup",10, me);
	write("��һ����������������ʼ˯����\n");
	write("��һ�������ͽ��������硣\n");	    
	tell_room(where,me->query("name")+"һ����������������һ�����������硣\n",({me}));
 	me->disable_player(" <˯����>");
    // my["con"] is a factor in sleep.
	return 1;
	
}

void wakeup(object me)
{
    int intp;int add;
if (!me){
    return;}

if(me->query_temp("netdead")){
    me->enable_player();
    //me->delete_temp("block_msg/all");
}

	intp=me->query_temp("sleep_interrupt");
    while(environment(me)->is_character())
                me->move(environment(environment(me)));//if someone get you... :-)
    add=time()-intp;
	add=35-add;
	if(add<=0) add=1;//you must sleep again after 30 seconds then you can full all.
	if(me->query("kee")<me->query("eff_kee"))
	me->add("kee", (me->query("eff_kee") - me->query("kee"))/add);
	if(me->query("gin")<me->query("eff_gin"))
	me->add("gin",  (me->query("eff_gin") - me->query("gin"))/add);
	if(me->query("force")<me->query("max_force"))
	me->add("force", (me->query("max_force") - me->query("force"))/2/add);
	if(me->query("sen")<me->query("eff_sen"))
        me->add("sen", (me->query("eff_sen") - me->query("sen"))/add);
	me->enable_player();
	if (add>1)
		message_vision("$Nһ��������������ػ��һ�½�ǡ�\n",me);
	else
		message_vision("$Nһ����������������ػ��һ�½�ǡ�\n",me);
	//me->delete_temp("block_msg/all");
	me->enable_player();
    me->set_temp("sleep_interrupt",time());
    me->delete("no_get");
    me->delete("no_get_from");
	me->delete("no_steal_from");
	me->start_busy(1);
	if (add>1)
		write("����˯��̫Ƶ��������þ����Ǻܺá�\n");
	else
		write("����þ������棬�ûһ���ˡ�\n");
	if(environment(me)->do_sleep(me));
       return;
}
