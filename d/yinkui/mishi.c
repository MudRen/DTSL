
#include <ansi.h>
inherit ROOM;


void create ()
{
  
  set ("short",HIM"���ָ���"NOR);
  set ("long", @LONG
�����������ɱ�������ס��������д�������ָ��ء��ĸ����֡���
��������Σ�����Ҳ���Ǻܴ󣬿�����������һ�����ҡ��������аڷ�
��һ�Ŵ󴲣��Ա߻�����໪������İ��衣
LONG);
  set("exits",([
	  "southwest":__DIR__"chitang",
	  ]));
	  
  set("objects",([
    __DIR__"npc/pishouxuan":1,
    ]));
    
  set("valid_startroom", 1);
  setup();
 
}

/*
void reset()
{
   object *ob;
   object ob2;
    int i,j;
    
   ::reset();
   ob=children(__DIR__"obj/feibiao");
   j=0;
   for(i=0;i<sizeof(ob);i++)
      if(ob[i]&&environment(ob[i]))
      j +=ob[i]->query_amount();
      
   if(j<4){
   	
        ob2=new(__DIR__"obj/feibiao");
        ob2->set_amount(4-j);
        ob2->move((this_object()));
     }
    
}
*/
        
     
      