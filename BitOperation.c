//����var�ĵ�nλ��0
#define BIT_CLEAN(var, n) var &= ~(1 << n)

//����var�ĵ�nλ��1
#define BIT_SET(var, n) var |= (1 << n)

//��ȡ����var�ĵ�nλ
#define BIT_GET(var, n) (var >> n) & 0X01

//��var������nλ(��mλ��ʼ��nλ)��0
#define BIT_N_CLEAN(var, m, n) var &= ~(((1 << n) - 1) << m)

//��nλ��data�Ƶ��ӵ�mλ��ʼ��λ��
#define BIT_MOVE(data, m, n) data &= (((1 << n) - 1) << m)

//��var�дӵ�mλ��ʼ��nλ����Ϊdata
#define BIT_N_SET(var, data, m, n) var &= (~(((1 << n) - 1) << m)) | ((data & ((1 << n) - 1)) << m)
