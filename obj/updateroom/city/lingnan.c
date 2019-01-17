inherit F_DBASE;

mapping *city_map=({ /* sizeof() == 25 */
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/obj/guai",
    "dir" : "/d/lingnan/bingqishi.c",
    "count" : 3,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/obj/blade",
    "dir" : "/d/lingnan/bingqishi.c",
    "count" : 3,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/clone/npc/ouyangqian",
    "dir" : "/d/lingnan/caodi.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/job/sjbzahuo/song",
    "dir" : "/d/lingnan/changlang1.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/npc/songbang",
    "dir" : "/d/lingnan/changlang2.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/clone/npc/wangzhongxuan",
    "dir" : "/d/lingnan/changlang3.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/obj/niurou",
    "dir" : "/d/lingnan/chufang.c",
    "count" : 3,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/clone/npc/chuzi",
    "dir" : "/d/lingnan/chufang.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/obj/kaoya",
    "dir" : "/d/lingnan/chufang.c",
    "count" : 3,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/npc/songfaliang",
    "dir" : "/d/lingnan/donglang1.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/npc/yahuan",
    "dir" : "/d/lingnan/donglang2.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/npc/girl",
    "dir" : "/d/lingnan/door.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/npc/boy",
    "dir" : "/d/lingnan/door.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/npc/yahuan",
    "dir" : "/d/lingnan/huayuan1.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/npc/li",
    "dir" : "/d/lingnan/huowufang.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/npc/song-shuang",
    "dir" : "/d/lingnan/qingshilu1.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/npc/songque",
    "dir" : "/d/lingnan/woshi1.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/npc/songzhi",
    "dir" : "/d/lingnan/woshi2.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/npc/songyuzhi",
    "dir" : "/d/lingnan/woshi3.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/npc/songlu",
    "dir" : "/d/lingnan/wuchang.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/npc/boy",
    "dir" : "/d/lingnan/wuchang.c",
    "count" : 2,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/clone/npc/chenzhifo",
    "dir" : "/d/lingnan/xiaoqiao3.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/clone/npc/liu",
    "dir" : "/d/lingnan/xilang1.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/npc/songshidao",
    "dir" : "/d/lingnan/yuedongmen.c",
    "count" : 1,
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/lingnan/npc/zhao",
    "dir" : "/d/lingnan/zhangfang.c",
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
	return "lingnan map";
}