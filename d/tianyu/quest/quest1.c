// Obj quest1.c

inherit SKILL;
#include <ansi.h>;

mapping *quest = ({
        ([      "name":                 "铜智",
		"party":		"少林派",
                "where_place":          "/d/shaolin/guangchang1",
        ]),
        ([      "name":                 "铜慧",
		"party":		"少林派",
                "where_place":          "/d/shaolin/guangchang1",
        ]),
        ([      "name":                 "铜人",
		"party":		"少林派",
                "where_place":          "/d/shaolin/shanmen",
        ]),
        ([      "name":                 "铁石",
		"party":		"少林派",
                "where_place":          "/d/shaolin/guangchang2",
        ]),
        ([      "name":                 "铁心",
		"party":		"少林派",
                "where_place":          "/d/shaolin/guangchang2",
        ]),
        
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
