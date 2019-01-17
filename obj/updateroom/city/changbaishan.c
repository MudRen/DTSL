inherit F_DBASE;

mapping *city_map=({ /* sizeof() == 11 */
  ([ /* sizeof() == 3 */
    "npc" : "/d/changbaishan/npc/erlengzi",
    "count" : 1,
    "dir" : "/d/changbaishan/baiyun-feng.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/changbaishan/npc/youke",
    "count" : 2,
    "dir" : "/d/changbaishan/guanri-feng.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/changbaishan/npc/qiangdao",
    "count" : 1,
    "dir" : "/d/changbaishan/longmen-feng.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/changbaishan/npc/tufei",
    "count" : 1,
    "dir" : "/d/changbaishan/luming-feng.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/changbaishan/npc/lieren",
    "count" : 1,
    "dir" : "/d/changbaishan/shanlu6.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/changbaishan/npc/caishenren",
    "count" : 1,
    "dir" : "/d/changbaishan/shulin1.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/changbaishan/npc/she",
    "count" : 2,
    "dir" : "/d/changbaishan/shulin2.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/changbaishan/npc/she",
    "count" : 2,
    "dir" : "/d/changbaishan/shulin3.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/changbaishan/npc/qiaofu",
    "count" : 1,
    "dir" : "/d/changbaishan/yingzui-feng.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/changbaishan/npc/gongzi",
    "count" : 1,
    "dir" : "/d/changbaishan/yuzhu-feng.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/changbaishan/npc/youke",
    "count" : 2,
    "dir" : "/d/changbaishan/zixia-feng.c",
  ])
});

mapping *query_citymap(){
	return city_map;
}

int query_timeout(){
	return sizeof(city_map);
}

string query_mapname(){
	return "changbaishan map";
}