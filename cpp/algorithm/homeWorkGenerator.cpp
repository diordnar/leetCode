#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <random>
#include <ctime>

using namespace std;

const int TOTAL = 95;

unsigned int random_int_gen(void)
{
    static default_random_engine e(time(0));
    static uniform_int_distribution<unsigned int> dis(1, TOTAL);

    return dis(e);
}

const char *t1 = R"( 
.^o ~\
Y /'~) }      _____
l/  / /    ,-~     ~~--.,_
   ( (    /  ~-._         ^.
    \ "--'--.    "-._       \
     "-.________     ~--.,__ ^.
               "~r-.,___.-'-. ^.
                YI    \      ~-.\
                ||     \        `\
                ||     //
                ||    //
                ||   //
                ||  //     
                || ( c
   ___._ __  ___I|__`--__._ __  _
 "~     ~  "~   ::  ~~"    ~  ~~
                ::
                .:
                 .)";
const char *t2 = R"( 
                       ,ood8888booo,
                    ,oda8a888a888888bo,
                 ,od88888888aa888aa88a8bo,
               ,da8888aaaa88a888aaaa8a8a88b,
              ,oa888aaaa8aa8888aaa8aa8a8a88o,
             ,88888aaaaaa8aa8888a8aa8aa888a88,
             8888a88aaaaaa8a88aa8888888a888888
             888aaaa88aa8aaaa8888; ;8888a88888
             Y888a888a888a8888;'   ;888888a88Y
              Y8a8aa8a888a88'      ,8aaa8888Y
               Y8a8aa8aa8888;     ;8a8aaa88Y
                `Y88aa8888;'      ;8aaa88Y'
        ,,;;;;;;;;'''''''         ;8888Y'
     ,,;                         ,888P
   ,;  ,;,                      ;""
  ;       ;          ,    ,    ,;
 ;  ;,    ;     ,;;;;;   ;,,,  ;
;  ; ;  ,' ;  ,;      ;  ;   ;  ;
; ;  ; ;  ;  '        ; ,'    ;  ;
`;'  ; ;  '; ;,       ; ;      ; ',
     ;  ;,  ;,;       ;  ;,     ;;;
      ;,,;             ;,,;)";

const char *t3 =
    R"(############################################################# 
###################################################   ####### 
###############################################   /~\   #####
############################################   _- `~~~', ####
##########################################  _-~       )  ####
#######################################  _-~          |  ####
####################################  _-~            ;  #####
##########################  __---___-~              |   #####
#######################   _~   ,,                  ;  `,,  ##
#####################  _-~    ;'                  |  ,'  ; ##
###################  _~      '                    `~'   ; ###
############   __---;                                 ,' ####
########   __~~  ___                                ,' ######
#####  _-~~   -~~ _                               ,' ########
##### `-_         _                              ; ##########
#######  ~~----~~~   ;                          ; ###########
#########  /          ;                        ; ############
#######  /             ;                      ; #############
#####  /                `                    ; ##############
###  /                                      ; ###############
#                                            ################)";

const char *t4 = R"(
__   (__`\
(__`\   \\`\
 `\\`\   \\ \
   `\\`\  \\ \
     `\\`\#\\ \#
       \_ ##\_ |##
       (___)(___)##
        (0)  (0)`\##
         |~   ~ , \##
         |      |  \##
         |     /\   \##         __..---'''''-.._.._
         |     | \   `\##  _.--'                _  `.
         Y     |  \    `##'                     \`\  \
        /      |   \                             | `\ \
       /_...___|    \                            |   `\\
      /        `.    |                          /      ##
     |          |    |                         /      ####
     |          |    |                        /       ####
     | () ()    |     \     |          |  _.-'         ##
     `.        .'      `._. |______..| |-'|
       `------'           | | | |    | || |
                          | | | |    | || |
                          | | | |    | || |
                          | | | |    | || |     
                    _____ | | | |____| || |
               jgs /     `` |-`/     ` |` |
                   \________\__\_______\__\
                    """""""""   """""""'""")";
const char *t5 = R"(
                    /^\/^\
                  _|__|  O|
         \/     /~     \_/ \
          \____|__________/  \
                 \_______      \
                         `\     \                 \
                           |     |                  \
                          /      /                    \
                         /     /                       \
                       /      /                         \ \
                      /     /                            \  \
                    /     /             _----_            \   \
                   /     /           _-~      ~-_         |   |
                  (      (        _-~    _--_    ~-_     _/   |
                   \      ~-____-~    _-~    ~-_    ~-_-~    /
                     ~-_           _-~          ~-_       _-~ 
                        ~--______-~                ~-___-~)";
const char *t6 = R"(
                                 ,ood8888booo,
                              ,od8           8bo,
                           ,od                   bo,
                         ,d8                       8b, 
                        ,o                           o,    ,a8b    
                       ,8                             8,,od8  8    
                       8'                             d8'     8b   
                       8                           d8'ba     aP'   
                       Y,                       o8'         aP'    
                        Y8,                      YaaaP'    ba      
                         Y8o                   Y8'         88      
                          `Y8               ,8"           `P      
                            Y8o        ,d8P'              ba      
                       ooood8888888P"""'                  P'     
                    ,od                                  8       
                 ,dP     o88o                           o'       
                ,dP          8                          8        
               ,d'   oo       8                       ,8         
               $    d$"8      8           Y    Y  o   8          
              d    d  d8    od  ""boooooooob   d"" 8   8         
              $    8  d   ood' ,   8        b  8   '8  b         
              $   $  8  8     d  d8        `b  d    '8  b        
               $  $ 8   b    Y  d8          8 ,P     '8  b       
               `$$  Yb  b     8b 8b         8 8,      '8  o,     
                    `Y  b      8o  $$o      d  b        b   $o   
                     8   '$     8$,,$"      $   $o      '$o$$    
                     $o$$P"                 $$o$  )";

const char *table[] = {t1, t2, t3, t4, t5, t6};

int main(int argc, char *argv[])
{
    ifstream ifs("completed.txt");
    stringstream ss;
    string str;
    map<int, int> hash;
    int tmp;
    if (ifs.is_open())
    {

        while (getline(ifs, str))
        {
            //ss.str(str);
            ss << str;
            while (ss >> tmp)
            {
                //cout << tmp << " ";
                hash[tmp] = tmp;
            }
            ss.clear();
            ss.str("");
        }
        ifs.close();
    }

    unsigned num = random_int_gen();
    while (hash.find(num) != hash.end())
    {
        num = random_int_gen();
    }
    cout << endl
         << "\t\t\t\t"
         << num << endl

         << endl;
    static default_random_engine eg(time(0));
    static uniform_int_distribution<unsigned int> dis(0, sizeof(table) / sizeof(table[0]) - 1);
    cout << table[dis(eg)];

    return 0;
}