 
#define MAX_ENV_VARS   20
 
inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
    int i;
    string term, *terms, *wiz_only, *allowed;
    mixed data;
    mapping env;
 
    wiz_only = ({"invisibility", "immortal","msg_min","msg_mout","msg_home","wiz_look"});
    allowed=({  "block_tell", "brief", "brief_message", "brief_all","yield","hanghui",
     "no_accept", "no_teach", "wimpy","kill_msg","no_story","skill_list","dazuo_msg",
     "tuna_msg","sandu"});
 
   if( me != this_player(1) ) return 0;
 
   env = me->query("env");
 
   if( !arg || arg=="" ) {
     write("��Ŀǰ�趨�Ļ��������У�\n");
     if( !mapp(env) || !sizeof(env) )
        write("\tû���趨�κλ���������\n");
     else {
        terms = keys(env);
        for(i=0; i<sizeof(terms); i++)
          printf("%-20s  %O\n", terms[i], env[terms[i]]);
     }
     return 1;
   }
 
   if( sscanf(arg, "%s %s", term, data)!=2 ) {
     if(member_array(arg,allowed)==-1)
     	return help();
     term = arg;
     data = "YES";
   }
  if( term && term!="" ) {
     if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
        return notify_fail("����Ļ�������̫���ˣ������� unset ɾ�������ɡ�\n");     
   if(member_array(term, allowed) == -1&&member_array(term,wiz_only)==-1)
        return help();
   if((wiz_level(me) == 0) && (member_array(term, wiz_only) != -1))
		return notify_fail("ֻ����ʦ��������趨��\n");

   if(term == "wimpy" && (sscanf(data, "%d", data)!=1||intp(data) < 0 || intp(data) > 80))  {
      return COMMAND_DIR"usr/wimpy"->help(me);
   }
    if(stringp(data)&&(strsrch(data,"/")!=-1||strsrch(data,"\\")!=-1))
    	return help();
    if(strlen(data)>80)
    	return notify_fail("���趨������̫���ˣ����ʡһЩ�ɣ�\n");	

	me->set("env/" + term, data);
	printf("�趨����������%s = %O\n", term, data);
	return 1;
   }
   return help();
}
 
int help()
{
   write(@TEXT
ָ���ʽ��set <������> [<����ֵ>]
 
���ָ�������趨һЩ�������������Ӳ���ʱ����ʾ��Ŀǰ�趨�Ļ�����������ָ��
����ֵ�����ڶ�ֵΪ "YES"��
 
ȡ�������趨���� unset ָ�
Ŀǰ����˫��֧�ֵĻ�������Ϊ��
block_tell ����������˵��
brief      ����ʾ�������� 
no_accept  �����ܱ�����Ʒ
wimpy      ����ս�����ܵ���ͷ�Χ
yield      ��ܲ�����
kill_msg   �趨���ʱ��������$NΪ�Լ���$nΪ�Է�
           �磺$N��$n�ȵ������첻�����������һ��
           ֧����ɫ�ַ����μ� help nick
hanghui    �������л����Ϣ��
no_story   ��������СƷ��Ϣ
skill_list ʹ��skills����鿴ʱ����ʾΪ�ٷ�����
dazuo_msg  �ھ���ﵽ 3M �Ժ󣬿����趨����ʱ������
           �磺$N�����۾���ʼ����
           ֧����ɫ�ַ����μ� help nick
tuna_msg   �ھ���ﵽ 3M �Ժ󣬿����趨����ʱ������
           �磺$N�����۾���ʼ����
           ֧����ɫ�ַ����μ� help nick
sandu	   ����ҩʦ����ɢ��
TEXT
   );
   return 1;
}
