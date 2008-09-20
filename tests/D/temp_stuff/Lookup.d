module Lookup;

static this() {
  foreach (int index, char[] word; lookup08) {
    dictionary08[word] = index;
  }
  foreach (int index, char[] word; lookup16) {
    dictionary16[word] = index;
  }
  dictionary08.rehash;
  dictionary16.rehash;
}

int[char[]] dictionary08;
int[char[]] dictionary16;

char[][] lookup08 = [
"the","and","of","to","in","that","And","he",

"a","I","his","for","shall","is","be","you",
"they","with","will","not","all","your","have","was",

"my","it","from","their","on","are","which","unto",
"them","him","as","were","who","by","said","out",

"but","had","when","this","God","The","up","came",
"into","man","him,","one","there","thy","thou","me",

"said,","come","made","before","no","king","For","has",
"against","son","But","children","put","at","LORD","went",

"we","them,","you,","an","her","ye","Lord","go",
"give","may","make","Then","do","let","people","house",

"He","land","or","so","saying,","men","our","me,",
"even","because","if","upon","Israel","also","every","day",

"after","take","over","these","beginning","great","took","among",
"down","am","did","those","hath","sons","like","she",

"O","gave","us","things","what","So","hand","him.",
"away","Israel,","two","any","sent","then","Jehovah","Now",

"Jesus","whom","Yahweh","given","They","David","brought","them.",
"been","name","say","shalt","word","according","thee","it,",

"you.","know","saw","forth","nor","see","neither","should",
"good","You","evil","its","LORD,","set","through","days",

"Lord,","me.","place","about","now","bring","therefore","If",
"Let","hundred","more","than","would","people,","behold,","heart",

"thee,","Moses","holy","father","way","keep","saith","God.",
"time","done","without","words","own","heard","called","it.",

"When","three","might","where","Behold,","seven","taken","other",
"In","under","It","man,","yet","say,","hast","thousand",

"right","earth","first","This","offering","eat","Judah","house,",
"many","how","again","off","city","himself","whose","cast",

"eyes","back","Israel.","servant","full","Thus","years","voice",
"Yahweh,","Jehovah,","cut","hands","fear","work","turned","cause",

"servants","high","Therefore","says","What","young","until","priest"
];


char[][] lookup16 = [
"created","day,","commanded","send","land,","same","pass","face",

"Judah,","end","glory","thing","together","up,","My","five",
"found","round","death","them;","us,","living","men,","answered",

"speak","As","blood","A","thine","seen","four","toward",
"being","fire","law","son,","hand,","old","very","priests",

"year","side","life","king,","earth,","themselves","sin","Jerusalem,",
"rest","love","soul","Who","cities","another","Jerusalem","Moses,",

"her,","Saul","dwell","There","woman","some","All","both",
"Christ","LORD.","Thou","get","gone","fathers","much","kept",

"chief","Egypt,","hear","become","These","stood","kingdom","him;",
"daughter","between","pass,","became","Son","none","part","only",

"strong","king's","knowledge","having","nations","such","left","burnt",
"ten","flesh","able","them:","mouth","head","tell","near",

"told","certain","That","twenty","little","you;","spake","him:",
"concerning","Why","spoke","midst","till","power","Because","laid",

"We","city,","spirit","turn","David,","you:","faith","bread",
"Aaron","delivered","and,","thus","tribe","altar","mine","while",

"gathered","thereof","deliver","heaven","number","thee.","Solomon","Lord.",
"seed","earth.","mighty","me:","far","drink","thereof,","long",

"me;","water","day.","people.","heart,","peace","Jacob","comes",
"wise","waters","praise","can","Go","things,","pray","father,",

"out,","food","destroy","whole","fell","not,","lay","come,",
"brother","sword","offer","art","seek","lifted","wrath","well",

"heaven,","ark","To","How","six","angel","wife","wicked",
"nothing","spoken","though","mercy","gold","does","covenant","broken",

"fathers,","place,","it;","away,","land.","light","house.","why",
"burned","dead","Of","stand","unclean","Egypt","silver","Take",

"fruit","third","new","don't","save","Spirit","ever.","surely",
"God;","down,","Is","Give","now,","sight","Joshua","gold,",

"inhabitants","offerings","Jerusalem.","written","ear","got","brothers,","bear",
"family","serve","righteousness","second","return","Jews","Israel:","way,",

"princes","walk","didn't","Holy","places","sons,","works","offering,",
"answer","Yahweh.","sea","disciples","judge","going","fall","this,",

"God:","prophet","desire","war","sat","smote","lest","Levites",
"known","us.","lord","Israel;","book","Be","daughters","began",

"Your","body","His","strength","gives","built","righteous","door",
"coming","Jehovah.","Philistines","still","together,","Christ,","open","hold",

"ever","multitude","begat","Father","you?","days,","call","above",
"within","gate","Joseph","thirty","hand.","reigned","waste","men.",

"cry","priest,","forty","Jesus,","yourselves","twelve","false","eyes,",
"sea,","feet","passed","it:","child","there,","servant,","death.",

"receive","find","servants,","wisdom","name,","time,","ready","poor",
"place.","field","death,","night","Pharaoh","tabernacle","sword,","again,",

"mother","mount","brothers","month,","prophets","border","One","sacrifice",
"show","could","not.","never","joy","knew","clear","Abraham",

"whether","witness","build","blessed","cried","I,","makes","throughout",
"vessels","children,","carried","wine","Do","wife,","enter","returned",

"law,","cubits","middle","goes","life,","By","stone","destruction",
"grace","manner","fifty","ears","received","fire,","worship","dead,",

"Ye","women","help","anger","orders","nations,","me?","seventh",
"inheritance","filled","also,","elders","voice,","captain","LORD:","gather",

"asked","father's","saying","prayer","that,","world","town","kill",
"ways","offered","cannot","oil","valley","slew","most","hope",

"congregation","here","better","priests,",
"himself,","commandment","sought","silver,",
"Peter","LORD;","brethren,","Babylon,","true","must","sheep","gods",

"Jeremiah","looking","half","rose","man's","east","covered","Jacob,",
"meat","fat","burn","another,","male","side,","country","captains",

"look","there.","away.","named","departed","Babylon","shut","break",
"numbered","meet","king.","judgment","Have","brother,","water,","money",

"times","Samuel","King","burning","morning","heads","feast","army",
"thee;","seeing","lie","her.","families","month","Paul","therefore,",

"iniquity","houses","Even","Moreover","Egypt.","She","Aaron,","wilderness",
"wall","in,","fine","answered,","flesh,","words,","die","making",

"born","sins","night,","wherein","live","appointed","sound","heavens"
];

