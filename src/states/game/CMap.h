#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

class CMap{

private:
    int w,h;

public:

    int getW(){return w;}
    int getH(){return h;}

    void init();
    void draw(int,int);
};

void CMap::init(){

    //-------------------------------
    //  INICIALIZA EL MAPA
    //-------------------------------

    ANCHO_MAPA = w = al_get_bitmap_width(bmp_map);
    ALTO_MAPA  = h = al_get_bitmap_height(bmp_map);

}

void CMap::draw(int xp, int yp){

    //-------------------------------
    //  DIBUJA EL MAPA
    //-------------------------------

    if(bmp_map != NULL){
        al_draw_bitmap(bmp_map,0,0,0);
        if(GameState.getGame_info())
            al_draw_bitmap(bmp_map_grid,0,0,0);
    }
}

bool specific_box(int x1, int y1, int w1, int h1, int x2, int y2, int columnas = 1, int filas = 1){

    int w2 = 32 * columnas;
    int h2 = 32 * filas;
    if(collision::boundingBox(x1,y1,w1,h1,x2,y2,w2,h2))
        return true;
    else return false;
}

int collision_map1(int x, int y, int w, int h){


    if(collision::boundingBox_coords(x,y,w,h,318,830,196+318,130+830)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,0,0,1120,252)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,320,447,480,542)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,478,449,639,510)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,640,447,767,543)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,320,610,481,701)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,480,641,640,704)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,640,610,767,703)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,608,832,800,960)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,895,479,928,705)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,930,448,961,545)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,960,448,991,512)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,991,448,1249,477)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,1247,448,1255,679)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,0,226,64,800)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,60,226,129,321)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,66,511,126,480)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,59,801,130,995)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,0,993,96,1278)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,0,1278,127,1532)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,160,1152,288,1220)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,194,1217,290,1347)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,286,1216,576,1308)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,446,1150,576,1224)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,1026,1152,1216,1313)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,1215,1207,1280,1247)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,896,736,927,893)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,930,832,991,927)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,989,893,1407,924)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,990,640,1025,769)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,1024,769,1155,800)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,1149,732,1316,770)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,1312,759,1630,770)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,1622,705,1630,770)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,1368,600,1600,700)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,1592,545,1600,606)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,1304,545,1593,552)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,1304,506,1313,548)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,1368,447,1470,549)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,1250,447,1376,455)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,1146,641,1250,680)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,1022,609,1062,646)) return WALL;
    if(collision::boundingBox_coords(x,y,w,h,1111,610,1183,641)) return WALL;
    if(specific_box(x,y,w,h,1343,800)) return WALL;
    if(specific_box(x,y,w,h,1505,800,1,2)) return WALL;
    if(specific_box(x,y,w,h,1601,801,3)) return WALL;
    if(specific_box(x,y,w,h,1664,768)) return WALL;
    if(specific_box(x,y,w,h,1633,674)) return WALL;
    if(specific_box(x,y,w,h,1698,512,2)) return WALL;
    if(specific_box(x,y,w,h,1761,575)) return WALL;
    if(specific_box(x,y,w,h,1726,606,4)) return WALL;
    if(specific_box(x,y,w,h,1757,639, 4, 3)) return WALL;
    if(specific_box(x,y,w,h,1727,734 ,4)) return WALL;
    if(specific_box(x,y,w,h,1761,769)) return WALL;
    if(specific_box(x,y,w,h,1631,447 ,5)) return WALL;
    if(specific_box(x,y,w,h,1855,447 ,3)) return WALL;
    if(specific_box(x,y,w,h,1856,479 ,4)) return WALL;
    if(specific_box(x,y,w,h,1889,511 ,3)) return WALL;
    if(specific_box(x,y,w,h,1952,544 ,1, 11)) return WALL;
    if(specific_box(x,y,w,h,1884,834 ,2, 3)) return WALL;
    if(specific_box(x,y,w,h,1855,864)) return WALL;
    if(specific_box(x,y,w,h,1535,895, 10)) return WALL;
    if(specific_box(x,y,w,h,2016,447 ,8 ,7 )) return WALL;
    if(specific_box(x,y,w,h,2017,670 ,4 ,4)) return WALL;
    if(specific_box(x,y,w,h,2305,577 ,9, 3)) return WALL;
    if(specific_box(x,y,w,h,1310,507 ,2)) return WALL;
    if(specific_box(x,y,w,h,1252,637 ,2)) return WALL;
    if(specific_box(x,y,w,h,1599,670)) return WALL;
    if(specific_box(x,y,w,h,1217,834, 2)) return WALL;
    if(specific_box(x,y,w,h,1213,222 ,20)) return WALL;
    if(specific_box(x,y,w,h,1121,176 ,3)) return WALL;
    if(specific_box(x,y,w,h,2559,257 ,12, 3)) return WALL;
    if(specific_box(x,y,w,h,2590,353)) return WALL;
    if(specific_box(x,y,w,h,2784,353)) return WALL;
    if(specific_box(x,y,w,h,2942,279 ,20)) return WALL;
    if(specific_box(x,y,w,h,3169,321 ,20 ,3)) return WALL;
    if(specific_box(x,y,w,h,3200,416 ,20 ,4)) return WALL;
    if(specific_box(x,y,w,h,3169,544 ,9 ,5)) return WALL;
    if(specific_box(x,y,w,h,2752,577 ,6 ,6)) return WALL;
    if(specific_box(x,y,w,h,2719,764 ,4 ,5)) return WALL;
    if(specific_box(x,y,w,h,2748,928 ,2)) return WALL;
    if(specific_box(x,y,w,h,2882,832 ,3 ,3 )) return WALL;
    if(specific_box(x,y,w,h,2914,804)) return WALL;
    if(specific_box(x,y,w,h,2910,926)) return WALL;
    if(specific_box(x,y,w,h,3165,895 ,7, 7 )) return WALL;
    if(specific_box(x,y,w,h,2719,604 ,1 ,6 )) return WALL;
    if(specific_box(x,y,w,h,3230,1123, 5 ,8 )) return WALL;
    if(specific_box(x,y,w,h,3105,1216, 4 ,4  )) return WALL;
    if(specific_box(x,y,w,h,2941,1152, 5 ,7 )) return WALL;
    if(specific_box(x,y,w,h,2624,1149, 6 ,3 )) return WALL;
    if(specific_box(x,y,w,h,2655,1247, 4 )) return WALL;
    if(specific_box(x,y,w,h,2689,1282, 2 )) return WALL;
    if(specific_box(x,y,w,h,2653,1312, 4  )) return WALL;
    if(specific_box(x,y,w,h,2621,1345, 6 ,3  )) return WALL;
    if(specific_box(x,y,w,h,2302,1149, 4 ,7 )) return WALL;
    if(specific_box(x,y,w,h,2016,1151, 3 ,4  )) return WALL;
    if(specific_box(x,y,w,h,2112,1184, 1 ,2 )) return WALL;
    if(specific_box(x,y,w,h,1826,1185, 6 ,2 )) return WALL;
    if(specific_box(x,y,w,h,1633,1156, 5 ,5  )) return WALL;
    if(specific_box(x,y,w,h,1796,125,0 )) return WALL;
    if(specific_box(x,y,w,h,1601,1184, 1, 3 )) return WALL;
    if(specific_box(x,y,w,h,1628,1310, 5, 2 )) return WALL;
    if(specific_box(x,y,w,h,3456,637 ,20 )) return WALL;
    if(specific_box(x,y,w,h,3614,671 ,5  )) return WALL;
    if(specific_box(x,y,w,h,3709,705 ,1 ,6  )) return WALL;
    if(specific_box(x,y,w,h,3520,897 ,10, 3 )) return WALL;
    if(specific_box(x,y,w,h,3579,992 ,10, 3 )) return WALL;
    if(specific_box(x,y,w,h,3517,1087, 7, 13 )) return WALL;
    if(specific_box(x,y,w,h,3485,1503, 8, 2 )) return WALL;
    if(specific_box(x,y,w,h,3519,1570, 3, 2 )) return WALL;
    if(specific_box(x,y,w,h,3615,1565, 6  )) return WALL;
    if(specific_box(x,y,w,h,3745,1598, 2 )) return WALL;
    if(specific_box(x,y,w,h,384,1314 ,6 )) return WALL;
    if(specific_box(x,y,w,h,0,1534, 3 )) return WALL;
    if(specific_box(x,y,w,h,2332,798 ,8 ,5)) return WALL;
    if(specific_box(x,y,w,h,415,1664 ,5 ,5)) return WALL;
    if(specific_box(x,y,w,h,0,1729 ,3, 13)) return WALL;
    if(specific_box(x,y,w,h,95,1728 ,10 ,2)) return WALL;
    if(specific_box(x,y,w,h,64,2333 ,20 ,3)) return WALL;
    if(specific_box(x,y,w,h,510,2173 ,5 ,10)) return WALL;
    if(specific_box(x,y,w,h,255,1953 ,4, 8)) return WALL;
    if(specific_box(x,y,w,h,127,1793 ,1 ,3)) return WALL;
    if(specific_box(x,y,w,h,671,2206 ,10 ,10)) return WALL;
    if(specific_box(x,y,w,h,830,2174 ,13 ,10)) return WALL;
    if(specific_box(x,y,w,h,1250,2207 ,8 ,10)) return WALL;
    if(specific_box(x,y,w,h,1471,2239 ,1 ,1 )) return WALL;
    if(specific_box(x,y,w,h,1505,2271 ,17, 10)) return WALL;
    if(specific_box(x,y,w,h,1985,2206 ,6 ,4)) return WALL;
    if(specific_box(x,y,w,h,2175,2175 ,14 ,10)) return WALL;
    if(specific_box(x,y,w,h,2624,2046 ,4 ,20)) return WALL;
    if(specific_box(x,y,w,h,2750,2368 ,20, 2)) return WALL;
    if(specific_box(x,y,w,h,734,1600 ,3 ,12)) return WALL;
    if(specific_box(x,y,w,h,823,1760 ,5 ,7)) return WALL;
    if(specific_box(x,y,w,h,994,1791 ,8 ,4)) return WALL;
    if(specific_box(x,y,w,h,1052,1920 ,4 ,2)) return WALL;
    if(specific_box(x,y,w,h,1245,1920 ,4, 2)) return WALL;
    if(specific_box(x,y,w,h,1302,1791 ,10, 1)) return WALL;
    if(specific_box(x,y,w,h,1373,1886 ,4 ,1)) return WALL;
    if(specific_box(x,y,w,h,1468,1919 ,1 ,2)) return WALL;
    if(specific_box(x,y,w,h,1626,1825 ,2 ,1)) return WALL;
    if(specific_box(x,y,w,h,1691,1858 ,1 ,1)) return WALL;
    if(specific_box(x,y,w,h,1724,1891 ,1 ,3)) return WALL;
    if(specific_box(x,y,w,h,1853,1758 ,4 ,2)) return WALL;
    if(specific_box(x,y,w,h,1855,1856 ,7 ,4)) return WALL;
    if(specific_box(x,y,w,h,2207,1694 ,7 ,9)) return WALL;
    if(specific_box(x,y,w,h,2081,1600 ,6 ,3)) return WALL;
    if(specific_box(x,y,w,h,2432,1633 ,1 ,2)) return WALL;
    if(specific_box(x,y,w,h,2592,1632 ,2 ,2)) return WALL;
    if(specific_box(x,y,w,h,2622,1696 ,2 ,2)) return WALL;
    if(specific_box(x,y,w,h,2588,1760 ,1 ,4)) return WALL;
    if(specific_box(x,y,w,h,2686,1695 ,4 ,1)) return WALL;
    if(specific_box(x,y,w,h,2659,1857 ,3 ,2)) return WALL;
    if(specific_box(x,y,w,h,2690,1826 ,1 ,1)) return WALL;
    if(specific_box(x,y,w,h,2722,1792 ,4 ,3)) return WALL;
    if(specific_box(x,y,w,h,2880,2050 ,10 ,4)) return WALL;
    if(specific_box(x,y,w,h,3201,2078 ,2 ,5)) return WALL;
    if(specific_box(x,y,w,h,2976,2177 ,9, 2)) return WALL;
    if(specific_box(x,y,w,h,225,1793 ,6 ,1)) return WALL;
    if(specific_box(x,y,w,h,0,2145, 2 ,10)) return WALL;
    if(specific_box(x,y,w,h,1248,1790, 2, 4)) return WALL;
    if(specific_box(x,y,w,h,2623,1886 ,1, 1)) return WALL;
    if(specific_box(x,y,w,h,3807,1536 ,3, 1)) return WALL;

    // colision con el agua

    if(specific_box(x,y,w,h,0,1567 ,3 ,5)) return WATER;
    if(specific_box(x,y,w,h,96,1537 ,3 ,6)) return WATER;
    if(specific_box(x,y,w,h,194,1441 ,4 ,9)) return WATER;
    if(specific_box(x,y,w,h,320,1347 ,2 ,12)) return WATER;
    if(specific_box(x,y,w,h,385,1344 ,7 ,8)) return WATER;
    if(specific_box(x,y,w,h,736,1377 ,1 ,7)) return WATER;
    if(specific_box(x,y,w,h,799,1376 ,1 ,7)) return WATER;
    if(specific_box(x,y,w,h,833,1375 ,22 ,12)) return WATER;
    if(specific_box(x,y,w,h,1344,1216 ,7 ,5)) return WATER;
    if(specific_box(x,y,w,h,1535,1439 ,11, 10)) return WATER;
    if(specific_box(x,y,w,h,1952,1440 ,2 ,6)) return WATER;
    if(specific_box(x,y,w,h,2079,1440 ,6 ,5)) return WATER;
    if(specific_box(x,y,w,h,2305,1439 ,5 ,7)) return WATER;
    if(specific_box(x,y,w,h,2591,1441 ,6 ,6)) return WATER;
    if(specific_box(x,y,w,h,2784,1504 ,2 ,5)) return WATER;
    if(specific_box(x,y,w,h,2656,1632 ,4 ,1)) return WATER;
    if(specific_box(x,y,w,h,2848,1568 ,2 ,3)) return WATER;
    if(specific_box(x,y,w,h,2911,1504 ,13, 5)) return WATER;
    if(specific_box(x,y,w,h,3103,1666 ,8 ,6)) return WATER;
    if(specific_box(x,y,w,h,3360,1664 ,3 ,3)) return WATER;
    if(specific_box(x,y,w,h,3457,1698 ,20 ,20)) return WATER;
    //if(specific_box(x,y,w,h,

    return -1;
}



#endif // MAP_H_INCLUDED
