/*
��ʦ��ַ����
������helpbu����������
written by yanyan.
*/
inherit ITEM;
inherit F_SAVE;
#include <ansi.h>

int do_add(string arg);
int do_edit(string arg);
int do_list(string arg);
int do_discard(string arg);
int do_help();
void do_edit_count(string arg,object ob,mapping *counts,int i,string msg);
string query_save_file()
{
  return "/data/yanyan_homework_box";
}
void create()
{
	set_name(HIY"��ʦ��ַ��"NOR,({ "bu"}) );  	
   	set("long", "������ʦ��ַ���������÷���ʹ��helpbu�鿴��\n");
   	set_weight(10);       
   	set("unit","��");
   	set("value",100000000);
   	setup();
   	restore();
 
}

int is_get_of(object pal,object ob)
{
	return notify_fail("�������������������\n");
}
void init()
{
	add_action("do_help","helpbu");
   	add_action("do_add","addcount");
   	add_action("do_edit","editcount");
   	add_action("do_list","listcount");
   	add_action("do_discard","delcount");
   
}

int do_add(string arg)
{
	object ob;
	mapping *counts;
	mapping newcount;
   	int num,i;
   	ob=this_player();
   	if(!wizardp(ob))
   	return 0;
   	if(!arg) return notify_fail("������Ҫ��ӵ�ID��\n");

   	counts=query("counts");
   	num=sizeof(counts);
   	for(i=0;i<sizeof(num);i++){
      	if(counts[i]["id"]==arg) break;
    }
   	if(i<sizeof(num))
   		return notify_fail("����ʺ��Ѿ�����ˣ����Ҫ�༭����ʹ��editcount��\n");
   	newcount=allocate_mapping(6);
   	newcount["id"]=arg;
   	newcount["e-mail"]="none";
   	newcount["oicq"]="none";
   	newcount["tel"]="none";
   	newcount["hand_tel"]="none";
   	newcount["call"]="none";
   	if(counts)
   		counts+=({newcount});
   	else 
   		counts=({newcount});
   	set("counts",counts);
   	save();
   	tell_object(ob,arg+"����ʺ������ϣ������Ҫ��Ӿ������ݣ���ʹ��editcount��\n");
   	return 1;
}

int do_edit(string arg)
{
	object ob;
  	mapping *counts;
  	int num,i;
  	
  	ob=this_player();
   	if(!wizardp(ob))
   		return 0;
  	if(!arg)
  		return notify_fail("��Ҫ�༭ʲô�ʺţ�\n");

  	counts=query("counts");
  	num=sizeof(counts);
  	for(i=0;i<num;i++)
   		if(counts[i]["id"]==arg) break;
  	if(i==num)
  		return notify_fail("û������ʺţ�\n");
  	if(counts[i]["email"]){
  		write("Ŀǰ"+arg+"����ʺŵ�E-MAIL�ǣ�"+counts[i]["e-mail"]+"\n"+
        		"��Ҫ�����������Ҫ����ֱ�������µ�E-MAIL������Ҫ��������n(N)\n");
  		input_to("do_edit_count",ob,counts,i,"e-mail");
  		return 1;
  	}
  	else{
  		write("Ŀǰ"+arg+"����ʺ�û��E-MAIL��\n"+
        		"��Ҫ�����������Ҫ����ֱ�������µ�E-MAIL������Ҫ��������n(N)\n\n����:");
  		input_to("do_edit_count",ob,counts,i,"e-mail");
  		return 1;
  	}
}

string new_string(string msg)
{
  	switch(msg){
  
  		case "e-mail":return "oicq";
  		case "oicq": return "tel";
  		case "tel": return "hand_tel";
  		case "hand_tel": return "call_tel";
  		case "call_tel": return "over";
  		default: return "over";
  	}
}

string swap_chinese(string msg)
{
  	switch(msg){
  
  		case "e-mail":return "�����ʼ�";
  		case "oicq": return "oicq";
  		case "tel": return "�绰";
  		case "hand_tel": return "�ֻ�";
  		case "call_tel": return "����";
  		default: return "����";
  	}
}

void do_edit_count(string arg,object ob,mapping *counts,int i,string msg)
{
	string newmsg;
	
   	newmsg=new_string(msg);
   	
	if((arg=="n"||arg=="N")&&newmsg!="over"){
    	write(swap_chinese(msg)+"û�и��ġ�\n\n");
    	write("Ŀǰ����ʺŵ�"+swap_chinese(newmsg)+"�ǣ�"+counts[i][newmsg]+"\n"+
        		"��Ҫ�����������Ҫ����ֱ�������µ�"+swap_chinese(newmsg)+"������Ҫ��������n(N)\n����:");
        input_to("do_edit_count",ob,counts,i,newmsg);
        return;
    }
	counts[i][msg]=arg;
   	write("����"+swap_chinese(msg)+"Ϊ��"+arg+"\n");
   	if(newmsg=="over"){
    	set("counts",counts);
    	save();
    	write("�ʺŸ�����ϣ�\n");
    	return;
    }
   	write("Ŀǰ����ʺŵ�"+swap_chinese(newmsg)+"�ǣ�"+counts[i][newmsg]+"\n"+
        		"��Ҫ�����������Ҫ����ֱ�������µ�"+swap_chinese(newmsg)+"������Ҫ��������n(N)\n����:");
	input_to("do_edit_count",ob,counts,i,newmsg);
	return;
}

int do_list(string arg)
{
	object ob;
   	mapping *counts;
   	int num,i;
	string msg;
	
   	ob=this_player();
   	if(!wizardp(ob)) return 0;

   	counts=query("counts");
   	num=sizeof(counts);
   	if(num==0) return notify_fail("Ŀǰû���κ���ϵ��ַ��\n");
   	msg="������������������������������������������������������\n";
   	if(!arg){
    	for(i=0;i<num;i++){
     		msg +="ID:"+counts[i]["id"]+"\n";
     		msg +="�����ʼ�:"+counts[i]["e-mail"]+"\n";
     		msg +="OICQ:"+counts[i]["oicq"]+"\n";
     		msg +="�ֻ�:"+counts[i]["hand_tel"]+"\n";
     		msg +="�绰:"+counts[i]["tel"]+"\n";
     		msg +="����:"+counts[i]["call_tel"]+"\n\n\n";
     	}
		msg +="������������������������������������������������������\n";
     	ob->start_more(msg);
     	return 1;
    }
	for(i=0;i<num;i++){
		if(counts[i]["id"]==arg) break;
	}
	if(i==num)
		return notify_fail("Ŀǰ��ַ����û�д��ʺţ���ʹ��addcount��Ӵ��ʺţ�\n");
	msg +="ID      :"+counts[i]["id"]+"\n";
	msg +="�����ʼ�:"+counts[i]["e-mail"]+"\n";
	msg +="OICQ    :"+counts[i]["oicq"]+"\n";
	msg +="�ֻ�    :"+counts[i]["hand_tel"]+"\n";
	msg +="�绰    :"+counts[i]["tel"]+"\n";
	msg +="����    :"+counts[i]["call_tel"]+"\n\n\n";
	msg +="������������������������������������������������������\n";
	ob->start_more(msg);
	return 1;
}

int do_discard(string arg)
{
  object ob;
  mapping *counts;
  int num,i;
  
  ob=this_player();
  if(!wizardp(ob))
  return 0;
  restore();
  counts=query("counts");
  num=sizeof(counts);
  if(!arg)
  return notify_fail("��Ҫɾ��˭�ĵ�ַ��\n");
  if(num==0)
  return notify_fail("��ַ���ǿյģ�\n");
  for(i=0;i<num;i++)
   if(counts[i]["id"]==arg) break;
  if(i==num) 
  return notify_fail("û������ʺţ�\n");
  
  counts=counts[0..i-1]+counts[i+1..num-1];
  set("counts",counts);
  save();
  write("�ӵ�ַ���������"+arg+"�ĵ�ַ��\n");
  return 1;
}

int do_help()
{
  object ob;
  string msg;
  ob=this_player();
  if(!wizardp(ob))
  return 0;
  msg="����һ����ʦ�ĵ�ַ���������ʹ���������
  
  addcount      �ڵ�ַ�������һ���ʺš�
  
  editcount     �༭��ַ����һ���ʺš�
  
  listcount     ��û�в���ʱ����ʾ���е�ַ�����в���ʱ��
                ��ʾ���뿴�ĵ�ַ��
            
  discardcount  �ӵ�ַ����ɾ��һ����ʦ�ĵ�ַ��
  
  �˵�ַ����Ҳ���ʹ�ã���������ʦ֮��û���趨Ȩ��
  �����ƣ�Ҳ����˵wizard Ҳ����ɾ�� admin �ĵ�ַ��
  ���λ��ʦ�Ծ�ʹ�á�
  
                          �����(Yanyan)@����˫��
  \n";
  ob->start_more(msg);
  return 1;
}