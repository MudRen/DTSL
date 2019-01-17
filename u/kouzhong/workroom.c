#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",HIW"�״ﶨλ"NOR);
    set("long","\n");
    set("no_death", 1);

    set("exits",([
                "out" : "/u/yanyan/workroom",
      ]));

   
    set("can_make_room", 1);
    remove_call_out("do_show");
    call_out("do_show",10);
    setup();
}

void init()
{
    if( geteuid(this_player()) == "kouzhong" )     add_action("do_output","output");
    add_action("do_show","show");
    message_vision("$N��������ҿ��ܰ���\n", this_player());

}
int do_show()
{
    int n;
    object *user;
    string msg;

    user =  filter( users() , (: environment($1) :));
    msg = HIW"\n��ȫ�����Ƕ�λϵͳ��\n"NOR;
    msg += "����������£�\n";
    for(n=0;n<sizeof(user);n++) {
        msg += sprintf("������"+HIW+"%8s%-10s"+NOR+"  λ�ã�%s\n",
          (string)user[n]->query("name"),
          "("+capitalize(user[n]->query("id"))+")",
          environment(user[n])->query("short") +"��"+HIY+ file_name(environment(user[n]))+NOR
        );
    }
    msg += "��������\n";

    tell_room(this_object(),msg);
    if (strlen(msg) < 8000 ) this_object()->set("long",msg);
    remove_call_out("do_show");
    call_out("do_show",120);
    return 1;
}
int do_output(string arg)
{
    arg = replace_string(arg,"$n","\n");
    arg = replace_string(arg, "$RED$", RED);
    arg = replace_string(arg, "$GRN$", GRN);
    arg = replace_string(arg, "$YEL$", YEL);
    arg = replace_string(arg, "$BLU$", BLU);
    arg = replace_string(arg, "$MAG$", MAG);
    arg = replace_string(arg, "$CYN$", CYN);
    arg = replace_string(arg, "$WHT$", WHT);
    arg = replace_string(arg, "$HIR$", HIR);
    arg = replace_string(arg, "$HIG$", HIG);
    arg = replace_string(arg, "$HIY$", HIY);
    arg = replace_string(arg, "$HIB$", HIB);
    arg = replace_string(arg, "$HIM$", HIM);
    arg = replace_string(arg, "$HIC$", HIC);
    arg = replace_string(arg, "$HIW$", HIW);
    arg = replace_string(arg, "$NOR$", NOR);
    arg = replace_string(arg, "$BLINK$", BLINK);
    arg += NOR;
    arg += "\n";
    write(arg);
    shout(arg);
    return 1;
}
