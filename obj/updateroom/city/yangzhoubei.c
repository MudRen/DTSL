inherit F_DBASE;

mapping *city_map=({ /* sizeof() == 8 */
  ([ /* sizeof() == 3 */
    "npc" : "/d/yangzhoubei/npc/youke",
    "dir" : "/d/yangzhoubei/gaoyouhu.c",
    "count" : 2,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/yangzhoubei/npc/guanbing",
    "dir" : "/d/yangzhoubei/haibin2.c",
    "count" : 2,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/yangzhoubei/npc/youke",
    "dir" : "/d/yangzhoubei/haibin4.c",
    "count" : 2,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/yangzhoubei/npc/yetu",
    "dir" : "/d/yangzhoubei/hepan.c",
    "count" : 2,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/yangzhoubei/npc/qiangdao",
    "dir" : "/d/yangzhoubei/shanlu2.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/yangzhoubei/npc/shangren",
    "dir" : "/d/yangzhoubei/shanlu3.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/yangzhoubei/npc/she",
    "dir" : "/d/yangzhoubei/shulin4.c",
    "count" : 2,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/yangzhoubei/npc/yetu",
    "dir" : "/d/yangzhoubei/xiaoxi1.c",
    "count" : 1,
  ])
});

mapping *query_citymap(){
	return city_map;
}

int query_timeout(){
	return sizeof(city_map);
}

string query_mapname(){
	return "yangzhoubei map";
}