inherit F_CLEAN_UP;

int main(object me, string arg){
	
	mixed *file;
	object room;
	string *objkeys;
	int i,j;
	
	mapping *citymap=({});
	mapping objs;
	
	if(!arg)
		return 0;
	
	file = get_dir( arg+"/*.c", -1 );
	
	for(i=0;i<sizeof(file);i++){
		if( file[i][1] > 0 ) {
			room = load_object(arg+"/"+file[i][0]);
			//tell_object(me,arg+"/"+file[i][0]+"\n");
			objs = room->query("objects");
			if(!mapp(objs))
				continue;
			objkeys = keys(objs);
			for(j=0;j<sizeof(objkeys);j++){
				citymap = citymap+({ (["npc":objkeys[j],"dir":arg+"/"+file[i][0],"count":objs[objkeys[j]] ]) });
			}
		}
	}
	if(sizeof(citymap)>70)
		this_player()->start_more(sprintf("%O",citymap));
	else
		printf("%O",citymap);
	
	return 1;
	
	
}