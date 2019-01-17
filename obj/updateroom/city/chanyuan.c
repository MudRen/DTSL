inherit F_DBASE;

mapping *city_map=({ /* sizeof() == 14 */
  ([ /* sizeof() == 3 */
    "npc" : "/d/chanyuan/obj/staff",
    "count" : 2,
    "dir" : "/d/chanyuan/bingqiku.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/job/jj/buzhi",
    "count" : 1,
    "dir" : "/d/chanyuan/cangjing-fang.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/chanyuan/npc/buju",
    "count" : 1,
    "dir" : "/d/chanyuan/caodi2.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/chanyuan/obj/rice",
    "count" : 4,
    "dir" : "/d/chanyuan/chufang.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/clone/npc/chuzi",
    "count" : 1,
    "dir" : "/d/chanyuan/chufang.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/chanyuan/npc/foxiang",
    "count" : 1,
    "dir" : "/d/chanyuan/daxiong-baodian.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/chanyuan/npc/heshang",
    "count" : 1,
    "dir" : "/d/chanyuan/miaodoor.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/chanyuan/npc/huikeseng",
    "count" : 1,
    "dir" : "/d/chanyuan/muwu.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/chanyuan/npc/budian",
    "count" : 1,
    "dir" : "/d/chanyuan/shilu1.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/chanyuan/npc/butan",
    "count" : 1,
    "dir" : "/d/chanyuan/songjingfang.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/chanyuan/npc/liaokong",
    "count" : 1,
    "dir" : "/d/chanyuan/tongdian.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/chanyuan/npc/buchi",
    "count" : 1,
    "dir" : "/d/chanyuan/wenshudian.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/chanyuan/npc/xuchen",
    "count" : 1,
    "dir" : "/d/chanyuan/wuchang.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/chanyuan/npc/buchen",
    "count" : 1,
    "dir" : "/d/chanyuan/wuliangdian.c",
  ])
});

mapping *query_citymap(){
	return city_map;
}

int query_timeout(){
	return sizeof(city_map);
}

string query_mapname(){
	return "chanyuan map";
}