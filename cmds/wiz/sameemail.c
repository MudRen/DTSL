// modified by fengfei

#include <ansi.h>

inherit F_CLEAN_UP;
string ip2add(string);
int strnotlast(string, string);

int main(object me, string arg)
{
  object who, ob;
  int i, j, count;
  string *dir, *ppls, name, address;

  if (!wizardp(me))
    return notify_fail("��û��Ȩ��ʹ�����ָ�\n");

  if (!arg)
    return notify_fail("ָ���ʽ��sameemail <ʹ��������> | <email ��ַ>\n");

  count = strlen(arg);
  while(count--)
    if( arg[count] == '@' ) {
      name=arg;
      break;
    }
  seteuid(getuid());

if (name != arg) {
  name=arg;
  if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__)<0 )
    return notify_fail("û����λʹ���ߡ�\n");

  who = new(LOGIN_OB);
  who->set("id", name);
  if (! who->restore())
    return notify_fail("û����λʹ���ߡ�\n");

  write(who->query("name")+"�ϴδ� "+who->query("email")+" ���ߡ�\n");
  if (! who->query("email"))
    return notify_fail("");
  address = (string)who->query("email");
}
else address = arg;

  write("Ѱ��email�� "+address+" ��ʹ���ߣ�\n");
  count = 0;
  dir = get_dir(DATA_DIR + "login/");
  i = 0;
  call_out ("search_dir",0,count,dir,i,address,me);
  return 1;
}

void search_dir (int count, string *dir, int i, string address, object me)
{
  object ob;
  int j;
  string *ppls, name, str, adr, s1, s2, s3, s4;
  string info;

  if (i == sizeof(dir)) {
     tell_object(me,"����"+to_chinese(count)+"λʹ���ߴ������ַ���ߡ�\n");
  } else {
    ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
    for(j=0; j<sizeof(ppls); j++) {
      reset_eval_cost();
      if (sscanf(ppls[j], "%s.o", str)==1) {
// What are these for??? Where was "name" assigned? 
//        if (name == str)
//          continue;
        ob = new(LOGIN_OB);
        ob->set("id", str);
        if (! ob->restore()) {
          destruct(ob);
          continue;
        }
        if (! ob->query("email")) {
          destruct(ob);
          continue;
        }
        adr = ob->query("email");
        if (strsrch(adr, address)==-1) {
          destruct(ob);
          continue;
        }

        info = sprintf("%-10s%-14s%-11s%-6s%s\n", 
                       ob->query("id"),
                       ob->query("name"),
                       ctime(ob->query("last_on"))[0..10],
                       ctime(ob->query("last_on"))[20..24],
                       ob->query("email"));
        tell_object (me,info);

        destruct(ob);
        count ++;
      }
    }
    i++;
    call_out ("search_dir",0,count,dir,i,address,me);
  }
}

int help(object me)
{
write(@HELP
ָ���ʽ�� sameemail <ʹ��������> | <email ��ַ>

����������ʹ������ͬemail��ʹ���ߡ�
HELP
  );
    return 1;
}
