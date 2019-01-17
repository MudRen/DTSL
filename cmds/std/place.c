//for dtsl.
#include <ansi.h>

inherit F_CLEAN_UP;

string DIR_MSG=
"
����������������������������
����ͼ����              �� 
������      ��   ����     ��
��                        ��
��       \\  |   /         ��
����   --����λ��--  ��   ��
��                        ��
��       /  |   \\         ��
������      ��   ����     ��
����������������������������
\n\n";

string template_map=
"nwnw nn nene \n"+
"nwl nl nel \n"+
"www wwl cc eel eee \n"+
"swl sl sel \n"+
"swsw ss sese\n";
 


string no_color(string arg)
{
    arg = replace_string(arg,  BLK, "");
	arg = replace_string(arg,  RED, "");
	arg = replace_string(arg,  GRN, "");
	arg = replace_string(arg,  YEL, "");
	arg = replace_string(arg,  BLU, "");
	arg = replace_string(arg,  MAG, "");
	arg = replace_string(arg,  CYN, "");
	arg = replace_string(arg,  WHT, "");
	arg = replace_string(arg,  HIR, "");
	arg = replace_string(arg,  HIG, "");
	arg = replace_string(arg,  HIY, "");
	arg = replace_string(arg,  HIB, "");
	arg = replace_string(arg,  HIM, "");
	arg = replace_string(arg,  HIC, "");
	arg = replace_string(arg,  HIW, "");
	arg = replace_string(arg,  NOR, "");
	arg = replace_string(arg,  BLINK, "");
	return arg;
}

string center(string str,int long)
{
	int space,len,i;
	string s,s2;
	s="";s2="";
	str=no_color(str);
	len=strlen(str);
	space=(long-len)/2;
	for(i=0;i<space;i++) s+=" ";
	for(i=0;i<long-len-space;i++) s2+=" ";
	return sprintf("%s%s%s",s,str,s2);
}

string leftblank(string str,int long)
{
	int space,len,i;
	string s;
	s="";
	str=no_color(str);
	len=strlen(str);
	space=(long-len);
	for(i=0;i<space;i++) s+=" ";
	return sprintf("%s%s",s,str);
}
string rightblank(string str,int long)
{
	int space,len,i;
	string s;
	s="";
	str=no_color(str);
	len=strlen(str);
	space=(long-len);
	for(i=0;i<space;i++) s+=" ";
	return sprintf("%s%s",str,s);
}



int main(object me)
{
   object room,where;
   string nw="",n="",ne="",w="",c="",e="",sw="",s="",se="";
   string nw_line="",n_line="",ne_line="",w_line="",e_line="",
   			sw_line="",s_line="",se_line="";
   string rname="",msg="",other_msg="";
   string *dirs;
   mapping exits;
   int i;
   
   where=environment(me);
   
   if(!where)
    return notify_fail("������һƬģ����ʲôҲ���������\n");
    
   exits=where->query("exits");
   dirs=keys(exits);
   /*
   for(i=0;i<sizeof(dirs);i++){
   	room=load_object(exits[dirs[i]]);
   	if(!room) continue;
   	rname=room->query("short");
   	rname=no_color(rname);
     switch(dirs[i]){
     	case "northwest":
     	 nw = center(rname,15);
     	 nw_line = center("\\",15);
     	 //template_map = replace_string(template_map,"nwnw",nw);
     	 //template_map = replace_string(template_map,"nwl",nw_line);
     	 nw = nw+"\n"+nw_line;

     	 break;
     	
     	case "north":
     	 n = center(rname,15);
     	 n_line = center("|",15);
     	 //template_map = replace_string(template_map,"nn",n);
     	 //template_map = replace_string(template_map,"nl",n_line);
     	 n = n+"\n"+n_line;
     	 break;
     	
     	case "northeast":
     	 ne = center(rname,15);
     	 ne_line = "/";
     	 //template_map = replace_string(template_map,"nene",ne);
     	 //template_map = replace_string(template_map,"nel",ne_line);
     	 ne = ne+"\n"+ne_line;
     	 break;
     	case "west":
     	 w = center(rname,15);
     	 w_line = "--";
     	 //template_map = replace_string(template_map,"www",w);
     	 //template_map = replace_string(template_map,"wwl",w_line);
     	 w = w+"\n"+w_line;
     	 break;
     	case "east":
     	 e = center(rname,15);
     	 e_line = "--";
     	 //template_map = replace_string(template_map,"eee",e);
     	 //template_map = replace_string(template_map,"eel",e_line);
     	 e = e+"\n"+e_line;
     	 break;
     	case "southwest":
     	 sw = rname;
     	 sw_line = "/";
     	 break;
     	case "south":
     	 s = rname;
     	 s_line = "|";
     	 break;
     	case "southeast":
     	 se = rname;
     	 se_line = "\\";
     	 break;
     	 
     	default:
     	 other_msg+=HIY+dirs[i]+NOR+"��"+rname+"\n";
     }
   }*/
	if(stringp(exits["northwest"])){
   		room=load_object(exits["northwest"]);
   		if(room){
   			rname=room->query("short");
   			rname=no_color(rname);
   			nw = center(rname,15);
     	 	nw_line = leftblank("\\",17);	
	   	}
	}else{
		nw = center(" ",15);
     	nw_line = leftblank(" ",17);
	}	
	
	if(stringp(exits["north"])){
   		room=load_object(exits["north"]);
   		if(room){
   			rname=room->query("short");
   			rname=no_color(rname);
   			n = center(rname,15);
     	 	n_line = leftblank("|",7);	
	   	}
	}else{
		n = center(" ",15);
     	n_line = leftblank(" ",7);
	}
	
	if(stringp(exits["northeast"])){
   		room=load_object(exits["northeast"]);
   		if(room){
   			rname=room->query("short");
   			rname=no_color(rname);
   			ne = center(rname,15);
     	 	ne_line = leftblank("/",7);	
	   	}
	}else{
		ne = center(" ",15);
     	ne_line = leftblank(" ",7);
	}
	
	if(stringp(exits["west"])){
   		room=load_object(exits["west"]);
   		if(room){
   			rname=room->query("short");
   			rname=no_color(rname);
   			w = center(rname,15);
     	 	w_line = center("--",1);	
	   	}
	}else{
		w = center(" ",15);
     	w_line = center(" ",5);
	}
	
	if(stringp(exits["east"])){
   		room=load_object(exits["east"]);
   		if(room){
   			rname=room->query("short");
   			rname=no_color(rname);
   			e = center(rname,15);
     	 	e_line = center("--",5);	
	   	}
	}else{
		e = center(" ",15);
     	e_line = center(" ",5);
	}
	
	if(stringp(exits["southwest"])){
   		room=load_object(exits["southwest"]);
   		if(room){
   			rname=room->query("short");
   			rname=no_color(rname);
   			sw = center(rname,15);
     	 	sw_line = leftblank("/",17);	
	   	}
	}else{
		sw = center(" ",15);
     	sw_line = leftblank(" ",17);
	}
	
	if(stringp(exits["south"])){
   		room=load_object(exits["south"]);
   		if(room){
   			rname=room->query("short");
   			rname=no_color(rname);
   			s = center(rname,15);
     	 	s_line = leftblank("|",7);	
	   	}
	}else{
		s = center(" ",15);
     	s_line = leftblank(" ",7);
	}
	
	if(stringp(exits["southeast"])){
   		room=load_object(exits["southeast"]);
   		if(room){
   			rname=room->query("short");
   			rname=no_color(rname);
   			se = center(rname,15);
     	 	se_line = leftblank("\\",7);	
	   	}
	}else{
		//se = center(" ",15);
     	//se_line = center(" ",15);
	}
   c = no_color(where->query("short"));
     	   	 
   msg = msg+nw+n+ne+"\n"+
   				nw_line+n_line+ne_line+"\n"+
   				w+w_line+center(c,15)+e_line+e+"\n"+
   				sw_line+s_line+se_line+"\n"+
   				sw+s+se;
   
   
   if(other_msg!="")
   msg=DIR_MSG+msg+"��������"+other_msg;
   else
   msg=DIR_MSG+msg;
    
   me->start_more(msg);
   
  
   return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : place
 
���ָ��������㷽��Ŀ�����Χ�ĵ�ͼ��һЩ������ in��out��
up��down����Ϊ���������С�

����˫����DTSL��.wizgroup
HELP
    );
    return 1;
}