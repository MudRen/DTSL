
inherit BULLETIN_BOARD;

void create()
{
        set_name("���԰����", ({ "board" }) );
        set("location", "/d/wiz/qc");
        set("all_post_board",1);
        set("board_id", "all_post_b");
   set("long", "�����д���˫�������е����԰��е����ݡ�\n");
       
        setup();
        set("capacity",9999);
        
}

void done_post(object me, mapping note)
{
	mapping *notes;
        notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });

	// Truncate the notes if maximum capacity exceeded.
	if( sizeof(notes) > 9999 )
		notes = notes[9999 / 2 .. 9999];

	set("notes", notes);
	save();
        return;	
}