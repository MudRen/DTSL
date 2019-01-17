

inherit F_CLEAN_UP;

#define READ_BOARD_DIR "/obj/board/"

mapping board=([
"�������԰�":"dajiang_b.c",
"�������԰�":"duzun_b.c",
"�����������԰�":"feima_b.c",
"�μұ����԰�":"songjia_b.c",
"��ɳ�����԰�":"haisha_b.c",
"��߸����԰�":"lifa_b.c",
"����������Ժ���԰�":"party_cy_b.c",
"�������������԰�":"party_yg_b.c",
"�Ⱥ�������ի���԰�":"party_jz_b.c",
"�Ľ����������԰�":"party_yj_b.c",
"�������������԰�":"party_hj_b.c",
"ͻ���������԰�":"party_tj_b.c",
"�������������԰�":"party_dm_b.c",
"���ݿ�ջ���԰�":"pal_b.c",
"�����о�ר��":"skill_b.c",
"��ʦ���԰�":"wiz_b.c",
]);

int do_help();

int main(object me, string arg)
{
   string *all_boards;
   int i;
   string item;
   string name;
   object ob;
   
   int num;
   mapping *notes, last_read_time;
   string myid;
   
   if(!arg) return do_help();
   if(sscanf(arg,"%s %s",name,item)!=2&&
    sscanf(arg,"%s",name)!=1)
   return notify_fail("��ʹ�� readpost ���԰����� �ڼ�������\n"+
                      "�� readpost ���԰�����  ��ʽ��\n");
   all_boards=keys(board);
   if(member_array(name,all_boards)==-1)
   return do_help();
   ob=load_object(READ_BOARD_DIR+board[name]);
   if(!ob)
   return notify_fail("������԰��Ѿ������ڣ���鿴�������԰档\n");
   if(!(item)){
     me->start_more(ob->long());
     return 1;}
   
   last_read_time = this_player()->query("board_last_read");
   myid =ob->query("board_id");
   notes =ob->query("notes");
   if( !pointerp(notes) || !sizeof(notes) )
   return notify_fail("���԰���Ŀǰû���κ����ԡ�\n");
   
   if( item=="new" || item=="next" ) {
		if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
			num = 1;
		else
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]["time"] > last_read_time[myid] ) break;
			
	} else if( !sscanf(item, "%d", num) )
		return notify_fail("��Ҫ���ڼ������ԣ�\n");
  
   if( num < 1 || num > sizeof(notes) )
		return notify_fail("û���������ԡ�\n");
	num--;
	me->start_more( sprintf(
"[%d] %-40s %s(%s)\n----------------------------------------------------------------------\n",
		num + 1, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"])[0..9])
		+ notes[num]["msg"] );

	// Keep track which post we were reading last time.
	if( !mapp(last_read_time) )
		me->set("board_last_read", ([ myid: notes[num]["time"] ]) );
	else 
		if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
			last_read_time[myid] = notes[num]["time"];
   return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : readpost ���԰����� 
           readpost ���԰����� �ڼ�������
           readpost ���԰����� next
           readpost ���԰����� new
         
         ����ָ����������Ķ��������е����԰档
         ʹ�� readpost ����֪�������Ķ������԰档
         ʹ�÷�����
         ��
         readpost ��߸����԰�
         ���ǿ� ��߸����԰� ���е�����
         
         readpost ��߸����԰� 1
         ���ǿ� ��߸����԰� ��һ������
         
         readpost ��߸����԰� next
         ���ǿ� ��û�п�������߸����԰��µ�����
         
         readpost ��߸����԰� new
         ���ǿ� ��û�п�������߸����԰��µ�����
         
         �����Ҫ������԰���������޸� /cmds/wiz/readpost.c
         
                              �����(Yanyan)@����˫��
         
HELP
    );
    return 1;
}

int do_help()
{
  string *all_boards;
  string msg;
  object ob;
   int i;
   msg="Ŀǰ�����Ķ��������԰棺\n";
   ob=this_player();
  all_boards=keys(board);
  for(i=0;i<sizeof(all_boards);i++){
  	
    msg+=all_boards[i]+"\n";}
  ob->start_more(msg);
  return 1;
}