// miscd.c

#pragma optimize

inherit F_DBASE;

#include <ansi.h>
#include "find.map"


void create()
{
   
   seteuid(getuid());
   set("name", "��ؾ���");
   set("id", "miscd");

}

//�˺��������Ҿ����λ�á������ݵĶ����
string find_place(object where)
{
	string fail, msg, filename, filename1, answer;
	int len;

	fail=""; // default fail message

        filename=file_name(where);
	len=strlen(filename);
	if(len<2) return fail;

        len--;
        while(filename[len]!='/' && len>0) {
	  len--;
	}
	if(len<2) return fail;

	filename1=filename[1..(len-1)];

        if(!undefinedp(maps[filename1])) {
	  answer=maps[filename1]+"��"+where->query("short");;
	} else if(where->is_character()) {
	  answer=where->query("name")+"����";
        } else if(sscanf(filename,"/obj/home#%*s")==1) {
          answer="ס����";
        } else { 
          answer=undefinedp(where->query("short"))?
		  where->short():
		  where->query("short");
        }

	return answer;
}

//�˺���������ģ����λ�ã������ݵ�����
string find_some_place(object where)
{
	string answer;
	string *here;
	int i;
	
	here=keys(maps);
	
	for(i=0;i<sizeof(here);i++)
	  if(strsrch(base_name(where),here[i])!=-1)
	    break;
	if(i==sizeof(here)){
	  if(where->is_character())
	    return "ĳ�˵�����";
	  else
	    return "δ֪�ĵط�";
	}
	  
	answer=maps[here[i]];
	
	return answer;
}
