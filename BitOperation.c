//变量var的第n位清0
#define BIT_CLEAN(var, n) var &= ~(1 << n)

//变量var的第n位置1
#define BIT_SET(var, n) var |= (1 << n)

//读取变量var的第n位
#define BIT_GET(var, n) (var >> n) & 0X01

//将var的其中n位(从m位开始的n位)清0
#define BIT_N_CLEAN(var, m, n) var &= ~(((1 << n) - 1) << m)

//将n位的data移到从第m位开始的位置
#define BIT_MOVE(data, m, n) data &= (((1 << n) - 1) << m)

//将var中从第m位开始的n位设置为data
#define BIT_N_SET(var, data, m, n) var &= (~(((1 << n) - 1) << m)) | ((data & ((1 << n) - 1)) << m)
