//inherit F_DBASE;
/**
  *this is a object,that can update some speicail room,such as dinner room
  */
inherit ITEM;

string *rooms=({
    "/d/yinkui/chufang",
    "/d/xiangyang/bingqipu",
	"/d/jingzhai/chufang",
	"/d/luoyang/zhulou",
	"/d/chanyuan/chufang",
	"/d/dingxiang/yizhan",
	"/d/dongming/chufang",
	"/d/gaoli/yizhan",
	"/d/lingnan/chufang",
});

void ResetMap();

void create(){
	
	set_name("���µ�ͼϵͳ",({"GameMap Update System"}));
	set("channel_id","GameMap Update System");
	set("unit","��");
	set("map_name","��Ϸʳ�﷿��");
	set("internal_time",300);
	ResetMap();
	
}


void ResetMap(){
	
	remove_call_out("DoResetMap");
	
	CHANNEL_D->do_channel(this_object(),"sys",query("map_name")+" now update.It needs "+
							sizeof(rooms)+" seconds.\n");
	
	call_out("DoResetMap",1,0);
}

void DoResetMap(int i){
	object room;	
	
	if(i>=sizeof(rooms)){
		call_out("ResetMap",query("internal_time"));
		return;
	}
	//we use find_object not load_object,because we only update the room
	// loaded in the memory
	room = find_object(rooms[i]);
	if(objectp(room)){		
		room->reset();	
		
		CHANNEL_D->do_channel(this_object(),"sys",(i+1)+" "+rooms[i]+" update ok!\n");
	}	
	call_out("DoResetMap",1,i+1);
		
}
