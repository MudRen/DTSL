#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", RED "ԡѪ����" NOR);
        set("long", HIR "                Ϧ     ��\n" + NOR + RED +
                "�ѽ���������Ⱦ��Ѫ��ɫ����·����ᵽһ��Ѫ��֮����" + NOR + "\n ");
        set("exits", ([ /* sizeof() == 1 */
        ]));
        set("no_magic", 1);
        set("no_quit", 1);
        set("fight_room", "/d/biwu/biwu_dating");
        setup();
}

void init()  
{ 
        object me = this_player();  
        add_action("discmds", ({  
                   "steal", "cast", "conjure", "array", "fight", "hit", "milu",   
                   "recall", "kill", "ansuan", "touxi", "miss",
        }));  
} 

int discmds() 
{ 
        tell_object(this_player(), "�����ǹ������󣬲������ף�\n");  
        return 1;  
} 

void relay_message(string msg)
{
        object look_fight_room, look_room;
        string *msgs;
        int i;
        
        if (! look_fight_room = find_object("/d/biwu/biwu_dating"))
                look_fight_room = load_object("/d/biwu/biwu_dating");
                
        if (! look_room = find_object("/u/kouzhong/chatroom"))
                look_room = load_object("/u/kouzhong/chatroom");
                                
        msgs = explode(msg, "\n");
        for (i = 0; i < sizeof(msgs); i++)
        if (strlen(msgs[i]) > 5)
        {
                message("vision", NOR + BOLD + ">>" + NOR + msgs[i] + "\n", look_fight_room);
                message("vision", NOR + BOLD + ">>" + NOR + msgs[i] + "\n", look_room);
        }
}



