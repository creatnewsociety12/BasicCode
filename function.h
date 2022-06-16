

//定义一个桌子状态类型，用于桌子的状态，比如桌子是否空的，桌子FREE，桌子是否被占用，桌子是否被清理，玩家是否都坐满，玩家是否都已经准备，该桌子是否已经开始游戏，该桌子是否已经结束游戏。
enum TableState
{
    TABLE_FREE,
    TABLE_OCCUPIED,
    TABLE_CLEAR,
    TABLE_PLAYER_FULL,
    TABLE_PLAYER_READY,
    TABLE_START,
    TABLE_END
};

// 定义一个玩家状态类型，用于玩家的状态，比如玩家是否在游戏中，玩家是否已经准备，玩家是否已经离开游戏，玩家是否已经被踢出游戏。 
enum PlayerState
{
    InGame,
    Ready,
    LeaveGame,
    KickOut
};

//宏定义一个麻将桌子的人数最大为4人
#define MAX_PLAYER 4

// 宏定义一个麻将房间最大容纳桌子数量为100
#define MAX_TABLE 100

// 定义一个麻将桌子结构体，里面有verctor类型容纳4个Player，这个麻将桌子的无符号整型id号，以及麻将桌子状态标志
struct Table
{
    vector<Player> players;
    unsigned int id;
    TableState status;
};

// 定义一个麻将类型结构体，里面有map用来容纳麻将类型id号，以及麻将类型的名字
struct MahjongType
{
    map<unsigned int, string> m_MahjongType;
};

// 定义一个麻将房间结构体，里面有无符号整型类型的麻将房间id号，以及用map类型保存的麻将桌子结构体，以及这个麻将房间的状态标志，房间玩的麻将类型
struct Room
{
    unsigned int id;
    map<unsigned int, Table> tables;
    RoomStatus status;
    MahjongType type;
};

// 定义一个麻将大厅，用verctor构成，里面包含了所有的map类型的麻将room房间结构体
struct Hall
{
    vector<Room> rooms;
};

// 定义一个大厅玩家空闲队列，map类型，key为unsigned int，value为Player类型
map<unsigned int, Player> lobbyPlayerQueue;

// 定义一个玩家结构体，里面有无符号整型类型的玩家id号，玩家当前状态，以及玩家所在的麻将房间id号，以及玩家所在的麻将桌子id号，玩家的昵称，玩家的麻将类型
// 玩家身上的金币数量，玩家保险柜仓库里的金币数量
struct Player
{
    unsigned int id;
    PlayerStatus status;
    unsigned int roomId;
    unsigned int tableId;
    string name;
    unsigned int type;
    unsigned int gold;
    unsigned int safeBox;
};




















