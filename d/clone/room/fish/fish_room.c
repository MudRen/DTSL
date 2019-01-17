// ����.c 

inherit ROOM; 

#include <ansi.h>

#define DEBUG 1

void create() 
{ 
set("short",HIY"��"HIR"��"HIW"̨"NOR); 
set("long", @LONG 
���߽�����ۣ��кö�������������ѽ����ʱ�Ĵ����˷ܵĺ�
��������϶�������˭�����˴��㣬��������ææµµ���˷ܵ����ӣ�
�㻹��ʲôֵ����ԥ�ģ��Ͽ��ú������ܿ�ʼ����(diao)�ɣ� 
LONG ); 

set("exits", ([ 
"down" : __DIR__"room", 
]));

set("objects",([
 __DIR__"yufu":1,
 ]));
 
set("no_fight", 1); 
set("no_clean_up", 0); 

setup(); 

} 
void init() 
{ 
add_action("do_fish", "fish"); 
add_action("do_fish", "diao"); 
} 

int do_fish(string arg) 
{ 

object me; 
me = this_player(); 

if (me->query("combat_exp") >100000&&!DEBUG) { 
message_vision(HIG"����һ������һ���ӻ�����$N��\n" + 
HIR "һ����������$N��ȣ����뵷�ң�������ô���˻������㣬��ò������۸����ְɣ�\n\n\n"NOR,me); 
me->move("/d/yangzhou/hotel"); 
return 1; 
} 
if (me->query("age") >13&&!DEBUG) { 
message_vision(HIG"����һ������һ���ӻ�����$N��\n" + 
HIR "һ����������$N��ȣ����Ƕ�ͯ���ֳ���,��ֻ����һ�Կ��ţ�\n\n\n"NOR,me); 
me->move("/d/yangzhou/hotel"); 
return 1; 
} 

if ( !arg || ( arg != "yu" ) ) 
return notify_fail("��Ҫ��ʲô��?\n");  


if(!me->query_temp("apply/yugan"))
return notify_fail("���������ô���㰡��\n");

if (me->query("kee") < 20 ) 
return notify_fail("���֧�ֲ�ס�ˣ���Ъ����ɣ�\n"); 


if (me->is_busy()) 
return notify_fail ("����æ���أ�\n"); 

if(me->query_temp("is_fishing"))
return notify_fail("ע�⿴��Ư��һ�Ĳ��ܶ��á�\n");

me->set_temp("is_fishing",1);

message_vision("$N����һ�ѵ�������ڴ�ʯͷ�ϵ�������������\n", me); 

call_out("do_fishing",8+random(7),me);

return 1;

}

void do_fishing(object me)
{
  object fish;
  
  if(!me) return;
  if(environment(me)!=this_object())
  return;

switch(random(10)) { 
case 0 : 
message_vision("$Nһ��ˣ�������һ��"+ HIR "������"NOR +"����ϲ����ϲ�� \n\n",me); 
fish=new(__DIR__"obj/fish");
fish->set("name",HIR "������"NOR);
fish->set("long","����һ��������㡣\n");
fish->set("value",100);
fish->move(me);
me->receive_damage("kee",15); 
break; 
case 1 : 
message_vision("$N��һ��ˣ�������"+ CYN "һ���Ʋ�ñ"NOR +"�������������� \n",me); 
message_vision(HIW "$N�����Ʋ�ñ���ɵķ����ˡ� \n\n" NOR,me); 
me->receive_damage("kee",5); 
break; 
case 2 : 
message_vision("$N������Ư�ζ���$N����һ�����͵�һ��ˣ�$N������"+ RED "һ����ɫ�ĶǶ��� \n"NOR,me); 
message_vision(HIB "$N�����е��������������� \n\n" NOR,me); 
me->receive_damage("kee",7); 
break; 
case 3 : 
message_vision("$Nһ��ˣ�������һ��"+ HIC "����"NOR +"����ϲ����ϲ�� \n\n",me); 
fish=new(__DIR__"obj/fish");
fish->set("name",HIC "����"NOR);
fish->set("long","����һ�����㡣\n");
fish->set("value",80);
fish->move(me);
me->receive_damage("kee",6); 
break; 
case 4 : 
message_vision("$Nһ��ˣ�������һ��"+ HIG "����"NOR +"����ϲ����ϲ�� \n\n",me); 
fish=new(__DIR__"obj/fish");
fish->set("name",HIG "����"NOR);
fish->set("long","����һ�����㡣\n");
fish->set("value",50);
fish->move(me);
me->receive_damage("kee",12); 
break; 
case 5 : 
message_vision("$Nһ��ˣ�������һ��"YEL"����"NOR"����ϲ����ϲ�� \n\n",me); 
fish=new(__DIR__"obj/fish");
fish->set("name",YEL"����"NOR);
fish->set("long","����һ�����㡣\n");
fish->set("value",30);
fish->move(me);
me->receive_damage("kee",10); 
break; 
case 6 : 
message_vision("$Nһ��ˣ�������һ��"+ HIB "����"NOR +"����ϲ����ϲ�� \n\n",me); 
fish=new(__DIR__"obj/fish");
fish->set("name",HIB "����"NOR);
fish->set("long","����һ�����㡣\n");
fish->set("value",50);
fish->move(me);
me->receive_damage("kee",5); 
break; 
case 7 : 
message_vision("$N��һ��ˣ�������"+ WHT "һ���Ͼɵ�˯��"NOR +"�������������� \n",me); 
message_vision(HIY"$N���ŷϾɵ�˯�����۾����̺��ˡ� \n\n"NOR,me); 
me->receive_damage("kee",3); 
break; 
case 8 : 
message_vision("$N�͵�һ��ˣ�����̫���ˣ��߶��ˣ������ˣ���ϧ����ϧ�� \n",me); 
message_vision(HIC "$N���ɵ���������%%$#@@#@**�� \n\n" NOR,me); 
me->receive_damage("kee",7); 
break; 
default : 
message_vision("$Nһ��ˣ�������һ��"+ HIM "������"NOR +"����ϲ����ϲ�� \n\n",me); 
fish=new(__DIR__"obj/fish");
fish->set("name",HIM "������"NOR);
fish->set("long","����һ�������㡣\n");
fish->set("value",120);
fish->move(me);
me->receive_damage("kee",8); 
break; 
} 
me->start_busy(random(2)); 

me->delete_temp("is_fishing");

return; 
} 

int valid_leave(object me,string dir)
{
   if(me->query_temp("is_fishing"))
   return notify_fail("��Ȼ�Ѿ���ʼ�����ˣ��Ͱ������������߰ɣ�\n");
   
   return ::valid_leave(me,dir);
   
}