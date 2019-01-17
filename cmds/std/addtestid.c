

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	
    if(!wizardp(me)&&me->query("id")!="sky")
    return 0;
    
    if(!arg)
    return notify_fail("ÇëÊäÈë²âÊÔµÄID\n");
    log_file("testid",arg+"\n");
    
    tell_object(me,"ÄãÔö¼ÓÁË²âÊÔID£º"+arg+"\n");
    
    "/adm/daemons/logind.c"->create();
    
    return 1;	
	
}
