inherit F_DBASE;

mapping *city_map=({ /* sizeof() == 1 */
  ([ /* sizeof() == 3 */
    "npc" : "/d/clone/room/fish/yufu",
    "count" : 1,
    "dir" : "d/clone/room/fish/fish_room.c",
  ])
});

mapping *query_citymap()
{
	return city_map;
}

int query_timeout()
{
	return sizeof(city_map);
}

string query_mapname()
{
	return "fish room map";
}
