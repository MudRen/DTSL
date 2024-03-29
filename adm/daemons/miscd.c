// miscd.c

// #pragma optimize

inherit F_DBASE;

#include <ansi.h>
#include "find.map"


void create()
{

   seteuid(getuid());
   set("name", "监控精灵");
   set("id", "miscd");

}

//此函数用于找具体的位置。如扬州的东大街
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
	  answer=maps[filename1]+"的"+where->query("short");;
	} else if(where->is_character()) {
	  answer=where->query("name")+"身上";
        } else if(sscanf(filename,"/obj/home#%*s")==1) {
          answer="住家里";
        } else {
          answer=undefinedp(where->query("short"))?
		  where->short():
		  where->query("short");
        }

	return answer;
}

//此函数用于找模糊的位置，如扬州地区。
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
	    return "某人的身上";
	  else
	    return "未知的地方";
	}

	answer=maps[here[i]];

	return answer;
}
